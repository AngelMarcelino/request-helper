#ifndef __POSTMANAPPREQUESTFORM_H
#define __POSTMANAPPREQUESTFORM_H

#include <gtk/gtk.h>
#include "request_configuration.h"

#define POSTMAN_APP_REQUEST_FORM_TYPE (postman_app_request_form_get_type())

G_DECLARE_FINAL_TYPE (
    PostmanAppRequestForm,
    postman_app_request_form,
    POSTMAN,
    APP_REQUEST_FORM,
    GtkBox
);

typedef  void (*RequestSentCallback)(RequestConfiguration *requestConfiguration, gpointer customData);

void postman_app_request_form_on_request_sent(PostmanAppRequestForm* requestForm, RequestSentCallback callback, gpointer data);
PostmanAppRequestForm *postman_app_request_form_new();


#endif