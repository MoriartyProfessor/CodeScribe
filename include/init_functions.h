#ifndef INIT_FUNCTIONS_H
#define INIT_FUNCTIONS_H

#include <gtk/gtk.h>
#include <vte/vte.h>
#include <gdk/gdk.h>
#include "helpers.h"
#include "init_menus.h"
#include "init_toolbar.h"
#include "init_terminal.h"
#include "init_notebook.h"
#include "WindowDependecies.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

GtkWidget *init_code_scribe()
{
    GtkWidget *window;
    GdkPixbuf *icon;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Code Scribe");
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);

    icon = create_icon("resources/CodeScribeIcon64x64.png");
    gtk_window_set_icon(GTK_WINDOW(window), icon);
    g_object_unref(icon);

    return window;
}

GtkWidget *create_menu_vbox(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data, GtkWidget** n, GtkWidget** t)
{
    GtkWidget *vbox;
    GtkWidget *tbox;
    GtkWidget *menubar;
    GtkWidget *toolbar;
    GtkWidget *notebook;

    vbox = gtk_vbox_new(FALSE, 0);
    menubar = create_menubar(win_dep, menubar_obj, meta_data);
    toolbar = create_toolbar(win_dep, meta_data);
    notebook = create_notebook(meta_data);

    meta_data->notebook = notebook;

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), notebook, TRUE, TRUE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (notebook), 4);

    *n = notebook;
    return vbox;
}

#endif
