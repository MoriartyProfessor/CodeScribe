#ifndef INIT_SOURCE_H_INCLUDED
#define INIT_SOURCE_H_INCLUDED

#include <gtk/gtk.h>

#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview-3.0/gtksourceview/gtksourcestyleschememanager.h>
#include <gtksourceview-3.0/gtksourceview/gtksourcespacedrawer.h>

#include "helpers.h"
#include "init_terminal.h"
#include "menu_objects.h"
#include "WindowDependecies.h"

SourceObject* create_source(MetaData *meta_data)
{
    SourceObject* source_object;
    GtkSourceBuffer* buffer;

    if(meta_data->lang_manager==NULL)
    {
        meta_data->lang_manager = gtk_source_language_manager_new();
        meta_data->lang = gtk_source_language_manager_get_language(GTK_SOURCE_LANGUAGE_MANAGER(meta_data->lang_manager), "cpp");

        meta_data->scheme_manager = gtk_source_style_scheme_manager_new();
        meta_data->scheme = gtk_source_style_scheme_manager_get_scheme(meta_data->scheme_manager, "oblivion");

        meta_data->justify = GTK_JUSTIFY_LEFT;
        meta_data->auto_indent = TRUE;
        meta_data->space_tabs = FALSE;
        meta_data->line_numbers = TRUE;
        meta_data->visualize_spaces = FALSE;
        meta_data->highlight_line = TRUE;
        meta_data->wrap_mode = GTK_WRAP_NONE;

        meta_data->case_sense_option = TRUE;
        meta_data->regex_option = FALSE;
        meta_data->find_entries_n = 0;
        meta_data->find_entry_curr = 0;
        meta_data->find_entries = (gchar**)malloc(sizeof(gchar*)*MAX_FIND_ENTRIES);
    }

    buffer = gtk_source_buffer_new_with_language(meta_data->lang);

    gtk_source_buffer_set_style_scheme(buffer, meta_data->scheme);

    source_object = g_new(SourceObject, 1);
    source_object->scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    source_object->textview = gtk_source_view_new_with_buffer(buffer);
    source_object->tab_label = gtk_label_new("Untitled");
    source_object->terminal = create_terminal(meta_data);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(source_object->scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(source_object->scrolled_window), GTK_SHADOW_IN);

    gtk_container_set_border_width(GTK_CONTAINER(source_object->scrolled_window), 3);

    gtk_text_view_set_left_margin((GtkTextView*)source_object->textview, 3);
    gtk_text_view_set_right_margin((GtkTextView*)source_object->textview, 3);
    gtk_text_view_set_pixels_above_lines((GtkTextView*)source_object->textview, 1);
    gtk_text_view_set_justification((GtkTextView*)source_object->textview, meta_data->justify);

    gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(source_object->textview), TRUE);
    gtk_source_view_set_highlight_current_line (GTK_SOURCE_VIEW(source_object->textview), TRUE);
    gtk_source_view_set_auto_indent(GTK_SOURCE_VIEW(source_object->textview), TRUE);

    gtk_widget_modify_font(source_object->textview, meta_data->font_desc);

    gtk_container_add(GTK_CONTAINER(source_object->scrolled_window), source_object->textview);

    //GSettings settings;
    //gtk_source_space_drawer_bind_matrix_setting(drawer, &settings, "->", G_SETTINGS_BIND_DEFAULT);

    return source_object;
}

#endif // INIT_SOURCE_H_INCLUDED
