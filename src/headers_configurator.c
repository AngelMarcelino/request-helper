#include <gtk/gtk.h>
#include "headers_configurator.h"
#include "utils/button_constructor.h"
#include "headers_configurator_row.h"

struct _PostmanAppHeadersConfiguratorPrivate {
    GtkButton* addHeaderButton;
    GList* headersUI;
};

typedef struct _PostmanAppHeadersConfiguratorPrivate PostmanAppHeadersConfiguratorPrivate;

struct _PostmanAppHeadersConfigurator {
    GtkBox parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(
    PostmanAppHeadersConfigurator,
    postman_app_headers_configurator,
    GTK_TYPE_BOX
);

static PostmanAppHeadersConfiguratorRow* construct_row(gchar* headerName, gchar* headerValue) {
    GList* start = NULL;
    start = g_list_append(start, g_string_new(headerName));
    start = g_list_append(start, g_string_new(headerValue));
    PostmanAppHeadersConfiguratorRow* row = postman_app_headers_configurator_row_new();
    postman_app_headers_configurator_row_set_content(row, start);
    return row;
}

static void add_header_row(PostmanAppHeadersConfigurator* headersConfigurator, gchar* headerName, gchar* headerValue) {
    PostmanAppHeadersConfiguratorRow* row = construct_row(headerName, headerValue);
    gtk_widget_set_visible(row, TRUE);
    gtk_container_add(GTK_CONTAINER(headersConfigurator), GTK_WIDGET(row));
    gtk_widget_show_all(GTK_WIDGET(headersConfigurator));
}

static void on_add_header_clicked(GtkWidget* button, gpointer data) {
    PostmanAppHeadersConfigurator* headerConfigurator = (PostmanAppHeadersConfigurator*)data;
    add_header_row(headerConfigurator, "", "");
    g_print("adios\n");
}


static void build_interface(PostmanAppHeadersConfigurator* headersConfigurator) {
    PostmanAppHeadersConfiguratorPrivate* priv =
        postman_app_headers_configurator_get_instance_private(headersConfigurator);
    priv->addHeaderButton = postman_app_construct_button("Add");
    gtk_container_add(GTK_BOX(headersConfigurator), GTK_WIDGET(priv->addHeaderButton));
    add_header_row(headersConfigurator, "Content-Type", "application/json");
}

static void postman_app_headers_configurator_init(PostmanAppHeadersConfigurator* headersConfigurator) {
    PostmanAppHeadersConfiguratorPrivate* priv =
        postman_app_headers_configurator_get_instance_private(headersConfigurator);
    build_interface(headersConfigurator);
    g_signal_connect(
        G_OBJECT(priv->addHeaderButton),
        "clicked",
        G_CALLBACK(on_add_header_clicked),
        headersConfigurator
    );
}

static void postman_app_headers_configurator_class_init(PostmanAppHeadersConfiguratorClass* class) {

}

PostmanAppHeadersConfigurator* postman_app_headers_configurator_new() {
    PostmanAppHeadersConfigurator* instance = g_object_new(
        postman_app_headers_configurator_get_type(),
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10,
        NULL
    );
    PostmanAppHeadersConfiguratorPrivate* priv =
        postman_app_headers_configurator_get_instance_private(instance);
    priv->headersUI = NULL;
    return instance;
}
