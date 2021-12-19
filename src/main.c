#include <gtk/gtk.h>
#include "postmanapp.h"

int main(int argc, char *argv[]) {
    return g_application_run(G_APPLICATION(postman_app_new()), argc, argv);
}