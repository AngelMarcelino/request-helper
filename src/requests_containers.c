#include <gtk/gtk.h>

#include "requests_containers.h"
#include "request_panel.h"

struct _PostmanAppRequestsContainer {
    GtkBox parent;
};
typedef struct _PostmanAppRequestsContainerPrivate PostmanAppRequestsContainerPrivate;

struct _PostmanAppRequestsContainerPrivate {
    GtkBox *requestContent;
};

G_DEFINE_TYPE_WITH_PRIVATE(PostmanAppRequestsContainer, postman_app_requests_container, GTK_TYPE_BOX)

static void postman_app_requests_container_init(PostmanAppRequestsContainer* requestsContainer) {
    gtk_widget_init_template(GTK_WIDGET(requestsContainer));
    PostmanAppRequestsContainerPrivate *priv = postman_app_requests_container_get_instance_private(requestsContainer);
    PostmanAppRequestPanel *requestPanel = postman_app_request_panel_new();
    gtk_container_add(GTK_CONTAINER(priv->requestContent), GTK_WIDGET(requestPanel));
}

static void postman_app_requests_container_class_init(PostmanAppRequestsContainerClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/requests_container.ui"
    );
    gtk_widget_class_bind_template_child_private (
        GTK_WIDGET_CLASS(class),
        PostmanAppRequestsContainer,
        requestContent
    );
}

PostmanAppRequestsContainer* postman_app_requests_container_new() {
    return g_object_new(
        POSTMAN_APP_REQUESTS_CONTAINER_TYPE,
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10,
        NULL
    );
}
