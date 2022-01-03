#ifndef __HEADERS_CONFIGURATOR
#define __HEADERS_CONFIGURATOR

#include <gtk/gtk.h>

G_DECLARE_FINAL_TYPE(
    PostmanAppHeadersConfigurator,
    postman_app_headers_configurator,
    POSTMAN,
    APP_HEADERS_CONFIGURATOR,
    GtkBox
);


PostmanAppHeadersConfigurator *postman_app_headers_configurator_new();

#endif