#ifndef INIT_TOOLBAR_H_INCLUDED
#define INIT_TOOLBAR_H_INCLUDED

#include <gtk/gtk.h>
#include "helpers.h"
#include "menu_objects.h"
#include "WindowDependecies.h"

#define ICON_SIZE 4

GtkWidget *create_toolbar(WindowDependecies* win_dep, MetaData* meta_data)
{
    GtkWidget *toolbar;
    GtkWidget *newTb;
    GtkWidget *openTb;
    GtkWidget *saveTb;
    GtkWidget *saveAsTb;
    GtkWidget *closeTb;
    GtkWidget *sep1;
    GtkWidget *undoTb;
    GtkWidget *redoTb;
    GtkWidget *cutTb;
    GtkWidget *copyTb;
    GtkWidget *pasteTb;
    GtkWidget *sep2;
    GtkWidget *fontTb;
    GtkWidget *zoomInTb;
    GtkWidget *zoomOutTb;
    GtkWidget *sep3;
    GtkWidget *runTb;
    GtkWidget *compileTb;
    GtkWidget *compile_and_runTb;
    GtkWidget *search_bar;
    GtkWidget *sep4;
    GtkWidget *aboutTb;
    GtkWidget *exitTb;

    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

    newTb = gtk_tool_button_new(gtk_image_new_from_icon_name("document-new", ICON_SIZE), "New");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

    openTb = gtk_tool_button_new(gtk_image_new_from_icon_name("document-open", ICON_SIZE), "Open");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

    saveTb = gtk_tool_button_new(gtk_image_new_from_icon_name("document-save", ICON_SIZE), "Save");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

    saveAsTb = gtk_tool_button_new(gtk_image_new_from_icon_name("document-save-as", ICON_SIZE), "Save As");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveAsTb, -1);

    closeTb = gtk_tool_button_new(gtk_image_new_from_icon_name("window-close", ICON_SIZE), "Close");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), closeTb, -1);

    sep1 = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep1, -1);

    undoTb = gtk_tool_button_new(gtk_image_new_from_icon_name("edit-undo", ICON_SIZE), "Undo");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), undoTb, -1);

    redoTb = gtk_tool_button_new(gtk_image_new_from_icon_name("edit-redo", ICON_SIZE), "Redo");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), redoTb, -1);

    cutTb = gtk_tool_button_new(gtk_image_new_from_icon_name("edit-cut", ICON_SIZE), "Cut");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), cutTb, -1);

    copyTb = gtk_tool_button_new(gtk_image_new_from_icon_name("edit-copy", ICON_SIZE), "Copy");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), copyTb, -1);

    pasteTb = gtk_tool_button_new(gtk_image_new_from_icon_name("edit-paste", ICON_SIZE), "Paste");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), pasteTb, -1);

    sep2 = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep2, -1);

    zoomInTb = gtk_tool_button_new(gtk_image_new_from_icon_name("zoom-in", ICON_SIZE), "Zoom In");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), zoomInTb, -1);

    zoomOutTb = gtk_tool_button_new(gtk_image_new_from_icon_name("zoom-out", ICON_SIZE), "Zoom Out");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), zoomOutTb, -1);

    fontTb = gtk_tool_button_new(gtk_image_new_from_icon_name("preferences-desktop-font", ICON_SIZE), "Font");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), fontTb, -1);

    sep3 = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

    runTb = gtk_tool_button_new(gtk_image_new_from_icon_name("media-playback-start", ICON_SIZE), "Run");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), runTb, -1);

    compileTb = gtk_tool_button_new(gtk_image_new_from_icon_name("system-run", ICON_SIZE), "Compile");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), compileTb, -1);

    compile_and_runTb = gtk_tool_button_new(gtk_image_new_from_icon_name("media-eject", ICON_SIZE), "Compile and Run");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), compile_and_runTb, -1);

    sep4 = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep4, -1);

    aboutTb = gtk_tool_button_new(gtk_image_new_from_icon_name("help-about", ICON_SIZE), "About");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), aboutTb, -1);

    exitTb = gtk_tool_button_new(gtk_image_new_from_icon_name("application-exit", ICON_SIZE), "Quit");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

    g_signal_connect(G_OBJECT(newTb), "clicked",
        G_CALLBACK(new_file_callback), meta_data);

    g_signal_connect(G_OBJECT(openTb), "clicked",
        G_CALLBACK(open_file_callback), meta_data);

    g_signal_connect(G_OBJECT(saveTb), "clicked",
        G_CALLBACK(save_file_callback), meta_data);

    g_signal_connect(G_OBJECT(saveAsTb), "clicked",
        G_CALLBACK(save_as_file_callback), meta_data);

    g_signal_connect(G_OBJECT(closeTb), "clicked",
        G_CALLBACK(close_file_callback), meta_data);

    g_signal_connect(G_OBJECT(undoTb), "clicked",
        G_CALLBACK(undo_callback), meta_data);

    g_signal_connect(G_OBJECT(redoTb), "clicked",
        G_CALLBACK(redo_callback), meta_data);

    g_signal_connect(G_OBJECT(cutTb), "clicked",
        G_CALLBACK(cut_callback), meta_data);

    g_signal_connect(G_OBJECT(copyTb), "clicked",
        G_CALLBACK(copy_callback), meta_data);

    g_signal_connect(G_OBJECT(pasteTb), "clicked",
        G_CALLBACK(paste_callback), meta_data);

    g_signal_connect(G_OBJECT(runTb), "clicked",
        G_CALLBACK(run_callback), meta_data);

    g_signal_connect(G_OBJECT(compileTb), "clicked",
        G_CALLBACK(compile_callback), meta_data);

    g_signal_connect(G_OBJECT(compile_and_runTb), "clicked",
        G_CALLBACK(compile_and_run_callback), meta_data);

    g_signal_connect(G_OBJECT(fontTb), "clicked",
        G_CALLBACK(font_settings_callback), meta_data);

    g_signal_connect(G_OBJECT(zoomInTb), "clicked",
        G_CALLBACK(zoom_in_callback), meta_data);

    g_signal_connect(G_OBJECT(zoomOutTb), "clicked",
        G_CALLBACK(zoom_out_callback), meta_data);

    g_signal_connect(G_OBJECT(aboutTb), "clicked",
        G_CALLBACK(about_callback), (gpointer) win_dep->window);

    g_signal_connect(G_OBJECT(exitTb), "clicked",
        G_CALLBACK(gtk_main_quit), NULL);


    gtk_toolbar_set_style(toolbar, GTK_TOOLBAR_BOTH);
    return toolbar;
}

#endif // INIT_TOOLBAR_H_INCLUDED
