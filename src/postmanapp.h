#ifndef __POSTMANAPP_H
#define __POSTMANAPP_H

#include <gtk/gtk.h>


G_DECLARE_FINAL_TYPE (PostmanApp, postman_app, POSTMAN, APP, GtkApplication)


PostmanApp     *postman_app_new         (void);


#endif /* __POSTMANAPP_H */

