#ifndef __POSTMANAPPREQUESTCONFIGURATION_H
#define __POSTMANAPPREQUESTCONFIGURATION_H

#include <gtk/gtk.h>

#define POSTMAN_APP_REQUEST_CONFIGURATION_TYPE (postman_app_request_configuration_get_type())

G_DECLARE_FINAL_TYPE (
    PostmanAppRequestConfiguration,
    potman_app_request_configuration,
    POSTMAN,
    APP_REQUEST_CONFIGURATION,
    GtkNotebook
)

PostmanAppRequestConfiguration *postman_app_request_configuration_new();

#endif