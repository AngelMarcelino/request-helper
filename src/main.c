#include <gtk/gtk.h>
#include "postmanapp.h"

static void
print_hello(GtkWidget* widget,
    gpointer   data)
{
    g_print("Hello World\n");
}

int main(int   argc, char* argv[]) {
    int status;
    PostmanApp* app;
    app = postman_app_new();
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}