#include <gtk/gtk.h>
#include "application-config.h"
#include "postmanapp.h"
#include "postmanwindow.h"

struct _PostmanApp {
    GtkApplication parent;
};

G_DEFINE_TYPE(PostmanApp, postman_app, GTK_TYPE_APPLICATION);

static void postman_app_init(PostmanApp *app) {

}

static void postman_app_activate (GApplication *app) {
    PostmanAppWindow *win;
    win = postman_app_window_new(POSTMAN_APP (app));
    gtk_window_present(GTK_WINDOW (win));
}

static void postman_app_open(GApplication *app, GFile **files, int n_files, const char *hint) {

}

static void postman_app_class_init (PostmanAppClass *class) {
    G_APPLICATION_CLASS (class)->activate = postman_app_activate;
    G_APPLICATION_CLASS (class)->open = postman_app_open;
}

PostmanApp *postman_app_new(void) {
    return g_object_new(postman_app_get_type(), "application-id", "org.marce.desktop.PostmanLike", "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}
