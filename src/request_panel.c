#include <gtk/gtk.h>
#include "request_panel.h"
#include "request_configuration.h"
#include "request_form.h"

struct _PostmanAppRequestPanel {
    GtkBox private;
};

G_DEFINE_TYPE(PostmanAppRequestPanel, postman_app_request_panel, GTK_TYPE_BOX)

static void postman_app_request_panel_init(PostmanAppRequestPanel* requestPanel) {
    gtk_widget_init_template(GTK_WIDGET(requestPanel));
    PostmanAppRequestForm *requestForm = postman_app_request_form_new();
    PostmanAppRequestConfiguration *requestConfiguration = postman_app_request_configuration_new();
    gtk_container_add(GTK_CONTAINER(requestPanel), GTK_WIDGET(requestForm));
    gtk_container_add(GTK_CONTAINER(requestPanel), GTK_WIDGET(requestConfiguration));
}

static void postman_app_request_panel_class_init(PostmanAppRequestPanelClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_panel.ui"
    );
}

PostmanAppRequestPanel* postman_app_request_panel_new() {
    return g_object_new(
        POSTMAN_APP_REQUEST_PANEL_TYPE,
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10,
        NULL
    );
}
