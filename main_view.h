#ifndef GLADEDEMOS_MAIN_VIEW_H
#define GLADEDEMOS_MAIN_VIEW_H

#include <gtkmm.h>

class SceneView;

class MainView: public Gtk::ApplicationWindow
{
public:
    MainView(BaseObjectType* object, const Glib::RefPtr<Gtk::Builder>& builder);

    ~MainView() override;
private:
    SceneView* scene = nullptr;
};

#endif //GLADEDEMOS_MAIN_VIEW_H
