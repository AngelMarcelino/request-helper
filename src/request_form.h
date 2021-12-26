#ifndef __POSTMANAPPREQUESTFORM_H
#define __POSTMANAPPREQUESTFORM_H

#include <gtk/gtk.h>

#define POSTMAN_APP_REQUEST_FORM_TYPE (postman_app_request_form_get_type())

G_DECLARE_FINAL_TYPE (
    PostmanAppRequestForm,
    postman_app_request_form,
    POSTMAN,
    APP_REQUEST_FORM,
    GtkBox
)

PostmanAppRequestForm *postman_app_request_form_new();

#endif