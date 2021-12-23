#include <gtk/gtk.h>
#include "side_options.h"


struct _PostmanAppSideOptions {
    GtkBox parent;
};

G_DEFINE_TYPE(PostmanAppSideOptions, postman_app_side_options, GTK_TYPE_BOX)

static void postman_app_side_options_init(PostmanAppSideOptions* sideOptions) {
    gtk_widget_init_template(GTK_WIDGET(sideOptions));
}

static void postman_app_side_options_class_init(PostmanAppSideOptionsClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(class), "/org/marce/desktop/resources/ui-templates/side_options.ui");
}

PostmanAppSideOptions* postman_app_side_options_new() {
    return g_object_new(
        POSTMAN_APP_SIDE_OPTIONS_TYPE,
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10, NULL);
}

