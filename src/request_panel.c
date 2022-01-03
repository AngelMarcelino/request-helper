#include <gtk/gtk.h>
#include "request_panel.h"
#include "request_configuration.h"
#include "request_form.h"
#include "logic/request_service.h"

struct _PostmanAppRequestPanelPrivate {
    PostmanAppRequestConfiguration *requestConfiguration;
};

typedef struct _PostmanAppRequestPanelPrivate PostmanAppRequestPanelPrivate;

struct _PostmanAppRequestPanel {
    GtkBox private;
};

G_DEFINE_TYPE_WITH_PRIVATE(
    PostmanAppRequestPanel,
    postman_app_request_panel,
    GTK_TYPE_BOX
)

static void postman_app_on_request_sent(RequestConfiguration *requestConfiguration, gpointer data) {
    PostmanAppRequestPanel *requestPanel = (PostmanAppRequestPanel*) data;
    PostmanAppRequestPanelPrivate *priv = postman_app_request_panel_get_instance_private(requestPanel);
    RequestConfiguration requestBodyHeaders = postman_app_request_configuration_get_configuration(priv->requestConfiguration);
    requestConfiguration->body = requestBodyHeaders.body;
    requestConfiguration->headers = requestBodyHeaders.headers;
    postman_app_make_request(requestConfiguration);
}

static void postman_app_request_panel_init(PostmanAppRequestPanel* requestPanel) {
    gtk_widget_init_template(GTK_WIDGET(requestPanel));
    PostmanAppRequestForm *requestForm = postman_app_request_form_new();
    PostmanAppRequestConfiguration *requestConfiguration = postman_app_request_configuration_new();
    PostmanAppRequestPanelPrivate *priv = postman_app_request_panel_get_instance_private(requestPanel);
    priv->requestConfiguration = requestConfiguration;
    postman_app_request_form_on_request_sent(requestForm, postman_app_on_request_sent, requestPanel);
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
