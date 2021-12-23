#ifndef __POSTMANAPPREQUESTTREECONTAINER_H
#define __POSTMANAPPREQUESTTREECONTAINER_H

#include <gtk/gtk.h>


#define POSTMAN_APP_REQUEST_TREE_CONTAINER_TYPE (postman_app_request_tree_container_get_type ())
G_DECLARE_FINAL_TYPE (
    PostmanAppRequestTreeContainer,
    postman_app_request_tree_container, POSTMAN, APP_REQUEST_TREE_CONTAINER, GtkBox
)

PostmanAppRequestTreeContainer *postman_app_request_tree_container_new ();

#endif /* __POSTMANAPPREQUESTTREECONTAINER_H */
