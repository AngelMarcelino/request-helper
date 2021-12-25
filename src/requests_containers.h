#ifndef __POSTMANAPPREQUESTCONTAINERS_H
#define __POSTMANAPPREQUESTCONTAINERS_H

#include <gtk/gtk.h>

#define POSTMAN_APP_REQUESTS_CONTAINER_TYPE (postman_app_requests_container_get_type())

G_DECLARE_FINAL_TYPE (PostmanAppRequestsContainer, postman_app_requests_container, POSTMAN, APP_REQUESTS_CONTAINER, GtkBox)

PostmanAppRequestsContainer *postman_app_requests_container_new();

#endif 