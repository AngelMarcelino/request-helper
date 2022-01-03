#include <gtk/gtk.h>
#include "request_configuration.h"
#include "headers_configurator.h"

struct _PostmanAppRequestConfigurationPrivate {
    GtkTextView *bodyTextView;
    GtkBox *headersContainer;
};

typedef struct _PostmanAppRequestConfigurationPrivate PostmanAppRequestConfigurationPrivate;

struct _PostmanAppRequestConfiguration {
    GtkNotebook parent;
};

G_DEFINE_TYPE_WITH_PRIVATE (
    PostmanAppRequestConfiguration,
    postman_app_request_configuration,
    GTK_TYPE_NOTEBOOK
);

static void postman_app_request_configuration_init(PostmanAppRequestConfiguration* requestConfiguration) {
    gtk_widget_init_template(GTK_WIDGET(requestConfiguration));
    PostmanAppHeadersConfigurator *headersConfigurator =
        postman_app_headers_configurator_new();
    PostmanAppRequestConfigurationPrivate *priv =
        postman_app_request_configuration_get_instance_private(requestConfiguration);
    gtk_container_add(GTK_CONTAINER(priv->headersContainer), GTK_WIDGET(headersConfigurator));
}

static void postman_app_request_configuration_class_init(PostmanAppRequestConfigurationClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_configuration.ui"
    );
    gtk_widget_class_bind_template_child_private(class, PostmanAppRequestConfiguration, bodyTextView);
    gtk_widget_class_bind_template_child_private(class, PostmanAppRequestConfiguration, headersContainer);
}

static gchar *get_body(PostmanAppRequestConfiguration* requestConfiguration) {
    PostmanAppRequestConfigurationPrivate *priv =
        postman_app_request_configuration_get_instance_private(requestConfiguration);
    GtkTextBuffer *buffer =  gtk_text_view_get_buffer(GTK_TEXT_VIEW(priv->bodyTextView));
    GtkTextIter *start;
    gtk_text_buffer_get_start_iter(buffer, start);
    GtkTextIter *end;
    gtk_text_buffer_get_end_iter(buffer, end);
    return gtk_text_buffer_get_text(buffer, start, end, FALSE);
}

static GList *get_headers(PostmanAppRequestConfiguration *requestConfiguration) {
    GList *start = NULL;
    g_list_append(start, "Hola mundo");
    
}

RequestConfiguration postman_app_request_configuration_get_configuration(PostmanAppRequestConfiguration* requestConfiguration) {
    RequestConfiguration requestData;
    requestData.body = get_body(requestConfiguration);
    return requestData;
}

PostmanAppRequestConfiguration* postman_app_request_configuration_new() {
    return g_object_new(
        POSTMAN_APP_REQUEST_CONFIGURATION_TYPE,
        NULL
    );
}
