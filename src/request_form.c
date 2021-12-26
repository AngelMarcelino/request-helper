#include <gtk/gtk.h>
#include "request_form.h"

struct _PostmanAppRequestForm {
    GtkBox parent;
};

G_DEFINE_TYPE(PostmanAppRequestForm, postman_app_request_form, GTK_TYPE_BOX)

static void postman_app_request_form_init(PostmanAppRequestForm* requestForm) {
    gtk_widget_init_template(GTK_WIDGET(requestForm));
}

static void postman_app_request_form_class_init (PostmanAppRequestFormClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_form.ui"
    );
}

PostmanAppRequestForm* postman_app_request_form_new() {
    return g_object_new(
        POSTMAN_APP_REQUEST_FORM_TYPE,
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10,
        NULL
    );
}
