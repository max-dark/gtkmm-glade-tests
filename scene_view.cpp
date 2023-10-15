#include "scene_view.h"

SceneView::SceneView(BaseObjectType* object, const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::DrawingArea(object)
{}