#include <gtk/gtk.h>
#include <stdio.h>
#include "postmanapp.h"
#include "postmanwindow.h"
#include "nav/side_options.h"


struct _PostmanAppWindow {
    GtkApplicationWindow parent;
    GtkWidget* mainbox;
    PostmanApp* application;
};

G_DEFINE_TYPE(PostmanAppWindow, postman_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void postman_app_window_init(PostmanAppWindow* win) {
    gtk_widget_init_template (GTK_WIDGET (win));
    PostmanAppSideOptions *sideOptions = postman_app_side_options_new();
    gtk_container_add(GTK_CONTAINER(win->mainbox), GTK_WIDGET(sideOptions));
}

static void postman_app_window_class_init(PostmanAppWindowClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/org/marce/desktop/resources/ui-templates/window.ui");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), PostmanAppWindow, mainbox);
}

PostmanAppWindow*
postman_app_window_new(PostmanApp* app)
{
    return g_object_new(postman_app_window_get_type(), "application", app, NULL);
}


void postman_app_window_open(PostmanAppWindow* win, GFile* file) {


}
