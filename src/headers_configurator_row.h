#ifndef __HEADERS_CONFIGURATOR_ROW
#define __HEADERS_CONFIGURATOR_ROW

#include <gtk/gtk.h>

G_DECLARE_FINAL_TYPE(
    PostmanAppHeadersConfiguratorRow,
    postman_app_headers_configurator_row,
    POSTMAN,
    APP_HEADERS_CONFIGURATOR_ROW,
    GtkBox
)

GString *postman_app_headers_configurator_row_get_content();
void postman_app_headers_configurator_row_set_content(
    PostmanAppHeadersConfiguratorRow* headersConfiguratorRow,
    GList *content
);

PostmanAppHeadersConfiguratorRow *postman_app_headers_configurator_row_new();

#endif


