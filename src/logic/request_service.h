#ifndef _REQUEST_SERVICE
#define _REQUEST_SERVICE

#include <gtk/gtk.h>
#include "../request_configuration_data.h"

GString *postman_app_get(gchar* uri);
GString *postman_app_post(gchar* uri, gchar* body);
GString *postman_app_make_request(RequestConfiguration *requestConfiguration);

#endif