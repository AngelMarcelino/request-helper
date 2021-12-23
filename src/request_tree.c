#include <gtk/gtk.h>
#include "request_tree.h"

struct _PostmanAppRequestTreeContainer {
    GtkBox parent;
};

//Tree example

enum
{
  COL_FIRST_NAME = 0,
  COL_LAST_NAME,
  NUM_COLS
} ;

static GtkTreeModel *
create_and_fill_model (void)
{
  GtkTreeStore  *treestore;
  GtkTreeIter    toplevel, child;

  treestore = gtk_tree_store_new(NUM_COLS, G_TYPE_STRING, G_TYPE_STRING);

  /* Append a top level row and leave it empty */
  gtk_tree_store_append(treestore, &toplevel, NULL);

  /* Append a second top level row, and fill it with some data */
  gtk_tree_store_append(treestore, &toplevel, NULL);
  gtk_tree_store_set(treestore, &toplevel,
                     COL_FIRST_NAME, "Joe",
                     COL_LAST_NAME, "Average",
                     -1);

  /* Append a child to the second top level row, and fill in some data */
  gtk_tree_store_append(treestore, &child, &toplevel);
  gtk_tree_store_set(treestore, &child,
                     COL_FIRST_NAME, "Jane",
                     COL_LAST_NAME, "Average",
                     -1);

  return GTK_TREE_MODEL(treestore);
}

static GtkWidget *
create_view_and_model (void)
{
  GtkTreeViewColumn   *col;
  GtkCellRenderer     *renderer;
  GtkWidget           *view;
  GtkTreeModel        *model;

  view = gtk_tree_view_new();

  /* --- Column #1 --- */

  col = gtk_tree_view_column_new();

  /* pack tree view column into tree view */
  gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

  renderer = gtk_cell_renderer_text_new();

  /* pack cell renderer into tree view column */
  gtk_tree_view_column_pack_start(col, renderer, TRUE);

  /* set 'text' property of the cell renderer */
  g_object_set(renderer, "text", "Boooo!", NULL);


  model = create_and_fill_model();

  gtk_tree_view_set_model(GTK_TREE_VIEW(view), model);

  g_object_unref(model); /* destroy model automatically with view */

  gtk_tree_selection_set_mode(gtk_tree_view_get_selection(GTK_TREE_VIEW(view)),
                              GTK_SELECTION_NONE);

  return view;
}

//End tree example


G_DEFINE_TYPE(PostmanAppRequestTreeContainer, postman_app_request_tree_container, GTK_TYPE_BOX)

static void postman_app_request_tree_container_init(PostmanAppRequestTreeContainer* requestTreeContainer) {
    GtkWidget *tree = create_view_and_model();
    gtk_widget_init_template(GTK_WIDGET(requestTreeContainer));
    gtk_container_add(GTK_CONTAINER(requestTreeContainer), tree);
}

static void postman_app_request_tree_container_class_init(PostmanAppRequestTreeContainerClass* class) {
    gtk_widget_class_set_template_from_resource(
        GTK_WIDGET_CLASS(class),
        "/org/marce/desktop/resources/ui-templates/request_tree_container.ui"
    );
}

PostmanAppRequestTreeContainer* postman_app_request_tree_container_new() {
    return g_object_new(
        POSTMAN_APP_REQUEST_TREE_CONTAINER_TYPE,
        "orientation",
        GTK_ORIENTATION_VERTICAL,
        "spacing",
        10,
        NULL);
}

