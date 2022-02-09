#ifndef INIT_NOTEBOOK_H_INCLUDED
#define INIT_NOTEBOOK_H_INCLUDED

#include <gtk/gtk.h>
#include "helpers.h"
#include "menu_objects.h"
#include "WindowDependecies.h"
#include "init_source.h"
#include "callbacks.h"

GtkWidget *create_notebook(MetaData* meta_data)
{
    GtkWidget* notebook = gtk_notebook_new();
    meta_data->notebook = notebook;
    gtk_notebook_set_scrollable(notebook, TRUE);
    gtk_notebook_popup_enable(notebook);
    new_file_callback(NULL, meta_data);

    return notebook;
}

#endif // INIT_NOTEBOOK_H_INCLUDED
