#include <gtk/gtk.h>
#include "headers_configurator_row.h"

static struct ConcatenateNameValueForeachData {
    GString* completeHeader;
    int iterationCounter;
};

typedef struct ConcatenateNameValueForeachData ConcatenateNameValueForeachData;

static ConcatenateNameValueForeachData* initialize_concatenate_name_value_foreach_data() {
    struct ConcatenateNameValueForeachData* data = malloc(sizeof(ConcatenateNameValueForeachData));
    data->completeHeader = g_string_new("");
    data->iterationCounter = 0;
    return data;
}

struct _PostmanAppHeadersConfiguratorRowPrivate {
    GList* entries;
};

typedef struct _PostmanAppHeadersConfiguratorRowPrivate PostmanAppHeadersConfiguratorRowPrivate;

struct _PostmanAppHeadersConfiguratorRow {
    GtkBox parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(
    PostmanAppHeadersConfiguratorRow,
    postman_app_headers_configurator_row,
    GTK_TYPE_BOX
)

static void add_entries_foreach_header(gpointer data, gpointer headersConfiguratorRow) {
    GString* stringData = (GString*)data;
    PostmanAppHeadersConfiguratorRowPrivate* priv =
        postman_app_headers_configurator_row_get_instance_private(headersConfiguratorRow);
    GtkWidget* entry = gtk_entry_new();
    gtk_entry_set_text(entry, stringData->str);
    gtk_container_add(GTK_CONTAINER(headersConfiguratorRow), entry);
    g_list_append(priv->entries, entry);
}

static void postman_app_headers_configurator_row_init(PostmanAppHeadersConfiguratorRow* headersConfiguratorRow) {
    PostmanAppHeadersConfiguratorRowPrivate* priv =
        postman_app_headers_configurator_row_get_instance_private(headersConfiguratorRow);
}

void postman_app_headers_configurator_row_set_content(
    PostmanAppHeadersConfiguratorRow* headersConfiguratorRow,
    GList* content
) {
    PostmanAppHeadersConfiguratorRowPrivate* priv =
        postman_app_headers_configurator_row_get_instance_private(headersConfiguratorRow);
    GList* children, * iter;
    children = gtk_container_get_children(GTK_CONTAINER(headersConfiguratorRow));
    for (iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);
    g_list_foreach(content, add_entries_foreach_header, headersConfiguratorRow);
}

static void postman_app_headers_configurator_row_class_init(PostmanAppHeadersConfiguratorRowClass* class) {

}

static void concatenate_headers(gpointer data, gpointer user_data) {
    ConcatenateNameValueForeachData* castedUserData = (ConcatenateNameValueForeachData*)user_data;
    g_string_append(castedUserData->completeHeader, gtk_entry_get_text(GTK_ENTRY(data)));
    if (castedUserData->iterationCounter == 0) {
        g_string_append(castedUserData->completeHeader, ": ");
    }
    castedUserData->iterationCounter++;
}

GString* postman_app_headers_configurator_row_get_content(PostmanAppHeadersConfiguratorRow* headersConfiguratorRow) {
    PostmanAppHeadersConfiguratorRowPrivate* priv =
        postman_app_headers_configurator_row_get_instance_private(headersConfiguratorRow);
    ConcatenateNameValueForeachData* data = initialize_concatenate_name_value_foreach_data();
    g_list_foreach(priv->entries, concatenate_headers, data);
    return data->completeHeader;
}

PostmanAppHeadersConfiguratorRow* postman_app_headers_configurator_row_new(GList* headerContent) {
    PostmanAppHeadersConfiguratorRow* instance = g_object_new(
        postman_app_headers_configurator_row_get_type(),
        "orientation",
        GTK_ORIENTATION_HORIZONTAL,
        "spacing",
        10,
        NULL
    );
    return instance;
}
