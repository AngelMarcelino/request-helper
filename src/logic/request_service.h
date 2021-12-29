#ifndef _REQUEST_SERVICE
#define _REQUEST_SERVICE

#include <gtk/gtk.h>

GString *postman_app_get(gchar* uri);
GString *postman_app_post(gchar* uri, gchar* body);

#endif