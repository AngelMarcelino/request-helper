#include <gtk/gtk.h>

#include "requests_containers.h"

struct _PostmanAppRequestsContainer {
    GtkBox parent;
};

G_DEFINE_TYPE(PostmanAppRequestsContainer, postman_app_requests_container, GTK_TYPE_BOX)

static void postman_app_requests_container_init(PostmanAppRequestsContainer* requestsContainer) {
    gtk_widget_init_template(GTK_WIDGET(requestsContainer));
}

static void postman_app_requests_container_class_init(PostmanAppRequestsContainerClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/requests_container.ui"
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
