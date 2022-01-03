#ifndef __POSTMANAPPREQUESTPANEL_H
#define __POSTMANAPPREQUESTPANEL_H

#include <gtk/gtk.h>

#define POSTMAN_APP_REQUEST_PANEL_TYPE (postman_app_request_panel_get_type())

G_DECLARE_FINAL_TYPE(
    PostmanAppRequestPanel,
    postman_app_request_panel,
    POSTMAN,
    APP_REQUEST_PANEL,
    GtkBox
)

PostmanAppRequestPanel* postman_app_request_panel_new();

#endif