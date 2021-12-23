#include <gtk/gtk.h>
#include "application-config.h"
#include "postmanapp.h"
#include "postmanwindow.h"

struct _PostmanApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(PostmanApp, postman_app, GTK_TYPE_APPLICATION);

static void postman_app_init(PostmanApp* app) {

}

static void postman_app_activate(GApplication* app) {
    PostmanAppWindow* window;
    window = postman_app_window_new(POSTMAN_APP(app));
    gtk_widget_show_all(GTK_WIDGET(window));
}


static void postman_app_class_init(PostmanAppClass* class) {
    G_APPLICATION_CLASS(class)->activate = postman_app_activate;
}

PostmanApp* postman_app_new(void) {
    return g_object_new(postman_app_get_type(), "application_id", "org.gtk.example", "flags", G_APPLICATION_FLAGS_NONE, NULL);
}
