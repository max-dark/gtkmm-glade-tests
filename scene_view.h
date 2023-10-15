#ifndef GLADEDEMOS_SCENE_VIEW_H
#define GLADEDEMOS_SCENE_VIEW_H

#include <gtkmm.h>

class SceneView: public Gtk::DrawingArea
{
public:
    SceneView(BaseObjectType* object, const Glib::RefPtr<Gtk::Builder>& builder);
};

#endif //GLADEDEMOS_SCENE_VIEW_H
