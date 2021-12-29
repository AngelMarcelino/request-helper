#include <gtk/gtk.h>
#include "request_form.h"
#include "logic/request_service.h"
#include <stdlib.h>

struct _PostmanAppRequestForm {
    GtkBox parent;
};

typedef struct _PostmanAppRequestFormPrivate PostmanAppRequestFormPrivate;

struct _PostmanAppRequestFormPrivate {
    GtkButton* sendRequest;
    GtkEntry* endpoint;
    GtkComboBoxText* methodSelector;
};


G_DEFINE_TYPE_WITH_PRIVATE(PostmanAppRequestForm, postman_app_request_form, GTK_TYPE_BOX)

static void send_request_clicked(GtkWidget* widget, gpointer data) {
    PostmanAppRequestFormPrivate* priv = postman_app_request_form_get_instance_private(
        POSTMAN_APP_REQUEST_FORM(data)
    );
    const gchar* uri = gtk_entry_get_text(GTK_ENTRY(priv->endpoint));
    const gchar* method_raw = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(priv->methodSelector));
    const GString* method = g_string_new(method_raw);
    if (g_string_equal(method, g_string_new("GET"))) {
        GString* result = postman_app_get(uri);
    }
    else if (g_string_equal(method, g_string_new("POST"))) {
        GString* result = postman_app_post(uri, "{\"hola\": \"mundo\"}");
    }
}


static void postman_app_request_form_init(PostmanAppRequestForm* requestForm) {
    gtk_widget_init_template(GTK_WIDGET(requestForm));
    PostmanAppRequestFormPrivate* priv = postman_app_request_form_get_instance_private(requestForm);
    g_signal_connect(G_OBJECT(priv->sendRequest), "clicked", G_CALLBACK(send_request_clicked), requestForm);
}

static void postman_app_request_form_class_init(PostmanAppRequestFormClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_form.ui"
    );
    gtk_widget_class_bind_template_child_private(
        GTK_WIDGET_CLASS(class),
        PostmanAppRequestForm,
        sendRequest
    );
    gtk_widget_class_bind_template_child_private(
        GTK_WIDGET_CLASS(class),
        PostmanAppRequestForm,
        endpoint
    );
    gtk_widget_class_bind_template_child_private(
        GTK_WIDGET_CLASS(class),
        PostmanAppRequestForm,
        methodSelector
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
