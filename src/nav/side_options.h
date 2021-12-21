#ifndef __POSTMANAPPSIDEOPTIONS_H
#define __POSTMANAPPSIDEOPTIONS_H

#include <gtk/gtk.h>


#define POSTMAN_APP_SIDE_OPTIONS_TYPE (postman_app_side_options_get_type ())
G_DECLARE_FINAL_TYPE (PostmanAppSideOptions, postman_app_side_options, POSTMAN, APP_WINDOW_SIDE_OPTIONS, GtkBox)


PostmanAppSideOptions       *postman_app_side_options_new          ();

#endif /* __POSTMANAPPSIDEOPTIONS_H */
