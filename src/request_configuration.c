#include <gtk/gtk.h>
#include "request_configuration.h"

struct _PostmanAppRequestConfiguration {
    GtkNotebook parent;
};

G_DEFINE_TYPE(
    PostmanAppRequestConfiguration,
    postman_app_request_configuration,
    GTK_TYPE_NOTEBOOK
);

static void postman_app_request_configuration_init(PostmanAppRequestConfiguration* requestConfiguration) {
    gtk_widget_init_template(GTK_WIDGET(requestConfiguration));
}

static void postman_app_request_configuration_class_init(PostmanAppRequestConfigurationClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_configuration.ui"
    );
}

PostmanAppRequestConfiguration* postman_app_request_configuration_new() {
    return g_object_new(
        POSTMAN_APP_REQUEST_CONFIGURATION_TYPE,
        NULL
    );
}
