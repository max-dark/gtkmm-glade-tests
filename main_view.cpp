#include "main_view.h"

#include "scene_view.h"

MainView::MainView(BaseObjectType* object, const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::ApplicationWindow(object)
{
    builder->get_widget_derived("scene_view", scene);
}

MainView::~MainView()
{
    delete scene;
}
