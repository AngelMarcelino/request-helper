#ifndef REQUEST_CONFIGURATION_DATA_H
#define REQUEST_CONFIGURATION_DATA_H

#include <gtk/gtk.h>

struct RequestConfiguration {
    gchar *uri;
    gchar *body;
    gchar *method;
    GList *headers;
};

typedef struct RequestConfiguration RequestConfiguration; 

#endif