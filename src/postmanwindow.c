#include <gtk/gtk.h>
#include <stdio.h>
#include "postmanapp.h"
#include "postmanwindow.h"
#include "nav/side_options.h"
#include "request_tree.h"
#include "application-config.h"
#include "requests_containers.h"


struct _PostmanAppWindow {
    GtkApplicationWindow parent;
    GtkWidget* mainbox;
    PostmanApp* application;
};

G_DEFINE_TYPE(PostmanAppWindow, postman_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void postman_app_window_init(PostmanAppWindow* win) {
    gtk_widget_init_template (GTK_WIDGET (win));
    gtk_window_resize(GTK_WINDOW(win), POSTMAN_APP_SIZE_WIDTH, POSTMAN_APP_SIZE_HEIGHT);
    PostmanAppSideOptions *sideOptions = postman_app_side_options_new();
    PostmanAppRequestTreeContainer *requestTreeContainer = postman_app_request_tree_container_new();
    PostmanAppRequestsContainer *requestsContainer = postman_app_requests_container_new();
    gtk_container_add(GTK_CONTAINER(win->mainbox), GTK_WIDGET(sideOptions));
    gtk_container_add(GTK_CONTAINER(win->mainbox), GTK_WIDGET(requestTreeContainer));
    gtk_container_add(GTK_CONTAINER(win->mainbox), GTK_WIDGET(requestsContainer));
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
