#ifndef __POSTMANAPPWIN_H
#define __POSTMANAPPWIN_H

#include <gtk/gtk.h>
#include "postmanapp.h"


#define POSTMAN_APP_WINDOW_TYPE (postman_app_window_get_type ())
G_DECLARE_FINAL_TYPE (PostmanAppWindow, postman_app_window, POSTMAN, APP_WINDOW, GtkApplicationWindow)


PostmanAppWindow       *postman_app_window_new          (PostmanApp *app);
void                    postman_app_window_open         (PostmanAppWindow *win,
                                                         GFile            *file);


#endif /* __POSTMANAPPWIN_H */
