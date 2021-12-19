#include <gtk/gtk.h>

#include "postmanapp.h"
#include "postmanwindow.h"


struct _PostmanAppWindow {
    GtkApplicationWindow parent;
    GtkWidget *stack;
    PostmanApp *application;
};

G_DEFINE_TYPE (PostmanAppWindow, postman_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void postman_app_window_init(PostmanAppWindow *win) {
    gtk_widget_init_template(GTK_WIDGET(win));
}

static void postman_app_window_class_init(PostmanAppWindowClass *class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/org/gtk/exampleapp/window.ui");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), PostmanAppWindow, stack);
}

PostmanAppWindow *
postman_app_window_new (PostmanApp *app)
{
  return g_object_new (postman_app_window_get_type(), "application", app, NULL);
}


void postman_app_window_open(PostmanAppWindow *win, GFile *file) {

}
