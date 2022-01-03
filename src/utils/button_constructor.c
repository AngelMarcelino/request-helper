#include "button_constructor.h"


GtkWidget *postman_app_construct_button(const gchar *label) {
    GtkWidget *button = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(button), label);
    return button;
}
