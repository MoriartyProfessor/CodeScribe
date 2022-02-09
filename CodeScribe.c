#include <gtk/gtk.h>
#include "include/callbacks.h"
#include "include/menu_objects.h"
#include "include/init_functions.h"
#include "include/helpers.h"
#include "include/WindowDependecies.h"
#include "include/tree.h"

#include <vte/vte.h>
#include <gdk/gdk.h>

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *terminal;
  GtkWidget *broswer_view;
  GtkWidget *notebook;
  GtkWidget *statusbar;
  GtkTreeSelection *selection;
  GtkWidget *vbox;
  GtkWidget *accel_group;

  WindowDependecies win_dep;
  MetaData meta_data;
  MenuBar menubar_obj;

  gtk_init(&argc, &argv);

  window = init_code_scribe();

  accel_group = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

  win_dep.window = window;
  win_dep.accel_group = accel_group;

  meta_data.window = window;
  meta_data.filename_data = NULL;
  meta_data.font_desc = pango_font_description_from_string("Monospace normal 12");
  meta_data.notebook = NULL;
  meta_data.lang = NULL;
  meta_data.lang_manager = NULL;

  FileMenu file_menu;
  EditMenu edit_menu;
  FormatMenu format_menu;
  SearchMenu search_menu;
  BuildMenu build_menu;
  HelpMenu help_menu;
  menubar_obj.file_menu = &file_menu;
  menubar_obj.edit_menu = &edit_menu;
  menubar_obj.format_menu = &format_menu;
  menubar_obj.search_menu = &search_menu;
  menubar_obj.build_menu = &build_menu;
  menubar_obj.help_menu = &help_menu;

  vbox = create_menu_vbox(&win_dep, &menubar_obj, &meta_data, &notebook, &terminal);

  //broswer_view = create_view_and_model();
  //selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(broswer_view));

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}

