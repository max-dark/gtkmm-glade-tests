#include <memory>
#include <string>
#include <iostream>

#include "main_view.h"

#include <gtkmm.h>

int main(int argc, char** argv)
{
    const std::string path = argc > 1 ? argv[1] : ".";

    std::cout << "Start" << std::endl;

    Gio::ApplicationFlags flags = Gio::APPLICATION_HANDLES_OPEN | Gio::APPLICATION_HANDLES_COMMAND_LINE;
    auto app = Gtk::Application::create(argc, argv, "io.github.max-dark.gmm-demo", flags);
    auto builder = Gtk::Builder::create();

    std::cout << "Load Form" << std::endl;
    auto ok = builder->add_from_file(path + "/resources/main_view.glade");
    std::cout << "Load: " << ok << std::endl;

    MainView* mainView = nullptr;
    builder->get_widget_derived("main_view", mainView);
    std::shared_ptr<MainView> view{mainView};

    std::cout << "App signals" << std::endl;
    app->signal_startup().connect([&app, view](){
        std::cout << "sig app::start" << std::endl;
        view->set_application(app); // app do not start without windows
        view->show_all();
    });
    app->signal_shutdown().connect([]() {
        std::cout << "sig app::stop" << std::endl;
    });

    std::cout << "View signals" << std::endl;
    view->signal_show().connect([view](){
        std::cout << "sig view::show" << std::endl;
    });
    view->signal_hide().connect([view]() {
        std::cout << "sig view::hide" << std::endl;
        view->unset_application(); // last window -> app::quit()
    });

    std::cout << "App run" << std::endl;
    return app->run(*view);
}
