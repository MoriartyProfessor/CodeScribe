#ifndef HELPERS_H
#define HELPERS_H

#include <gtk/gtk.h>
#include "menu_objects.h"

#define MAX_TAB_WIDTH 8

GdkPixbuf* create_icon(const char* filename)
{
    GdkPixbuf* icon;
    GError* error = NULL;

    icon = gdk_pixbuf_new_from_file(filename, &error);

    if(icon==NULL)
    {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }

    return icon;
}

FindDialog* create_find_dlg(MetaData* meta_data, FindDialog* dial_data)
{
    GtkWidget *vbox;
    GtkWidget *frame1;
    GtkWidget *table;
    GtkWidget *label;
    GtkWidget *hbtweak;
    GtkWidget *hbox;
    GtkWidget *btnfind;
    GtkWidget *btnclose;

    guint i;

    if (!(dial_data->dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL))) {
        g_printf ("create_find_dlg() gtk_window_new() failure.");
        return NULL;
    }
    gtk_window_set_position (GTK_WINDOW (dial_data->dialog), GTK_WIN_POS_CENTER);
    gtk_window_set_title (GTK_WINDOW (dial_data->dialog), "Find");

    gtk_window_set_modal (GTK_WINDOW(dial_data->dialog), TRUE);
    gtk_window_set_transient_for (GTK_WINDOW(dial_data->dialog),
                                    GTK_WINDOW(meta_data->window));
    gtk_container_set_border_width (GTK_CONTAINER (dial_data->dialog), 5);

    vbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (dial_data->dialog), vbox);
    gtk_widget_show (vbox);

    frame1 = gtk_frame_new (NULL);
    gtk_frame_set_label (GTK_FRAME (frame1), "Find");
    gtk_frame_set_label_align (GTK_FRAME (frame1), 0.0, 0.5);
    gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_ETCHED_OUT);
    gtk_container_set_border_width (GTK_CONTAINER (frame1), 5);

    table = gtk_table_new (3, 2, TRUE);
    gtk_table_set_row_spacings (GTK_TABLE (table), 5);
    gtk_table_set_col_spacings (GTK_TABLE (table), 3);
    gtk_container_set_border_width (GTK_CONTAINER (table), 5);
    gtk_container_add (GTK_CONTAINER (frame1), table);

    label = gtk_label_new_with_mnemonic ("_Text to search for:");
    hbtweak = gtk_hbox_new (FALSE, 0);
    gtk_box_pack_start (GTK_BOX (hbtweak), label, FALSE, FALSE, 0);
    gtk_table_attach_defaults (GTK_TABLE (table), hbtweak, 0, 1, 0, 1);
    gtk_widget_show (hbtweak);
    gtk_table_set_row_spacing (GTK_TABLE (table), 0, 0);

    dial_data->text_entry = gtk_combo_box_text_new_with_entry();
    gtk_label_set_mnemonic_widget (GTK_LABEL (label), dial_data->text_entry);
    gtk_table_attach_defaults (GTK_TABLE (table), dial_data->text_entry, 0, 2, 1, 2);
    gtk_table_set_row_spacing (GTK_TABLE (table), 1, 10);
    for (i = 0; i < meta_data->find_entries_n; i++)
        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(dial_data->text_entry),
                                        meta_data->find_entries[i]);

    dial_data->case_sense_chk = gtk_check_button_new_with_mnemonic ("Match case");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (dial_data->case_sense_chk), meta_data->case_sense_option);
    gtk_table_attach_defaults (GTK_TABLE (table), dial_data->case_sense_chk, 0, 1, 2, 3);

    gtk_widget_show (dial_data->text_entry);
    gtk_widget_show (label);
    gtk_widget_show (hbtweak);
    gtk_widget_show (dial_data->case_sense_chk);
    gtk_widget_show (table);
    gtk_widget_show (frame1);

    gtk_box_pack_start (GTK_BOX (vbox), frame1, FALSE, FALSE, 0);

    hbox = gtk_hbox_new (FALSE, 0);
    gtk_box_set_spacing (GTK_BOX (hbox), 5);
    gtk_container_set_border_width (GTK_CONTAINER (hbox), 5);

    dial_data->forward_btn = gtk_button_new_with_label("Next");
    dial_data->backward_btn = gtk_button_new_with_label("Previous");
    dial_data->cancel_btn = gtk_button_new_with_label("Close");

    gtk_box_pack_end (GTK_BOX (hbox), dial_data->cancel_btn, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (hbox), dial_data->forward_btn, FALSE, FALSE, 0);
    gtk_box_pack_end (GTK_BOX (hbox), dial_data->backward_btn, FALSE, FALSE, 0);
    gtk_widget_show (dial_data->forward_btn);
    gtk_widget_show (dial_data->backward_btn);
    gtk_widget_show (dial_data->cancel_btn);

    gtk_box_pack_end (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
    gtk_widget_show (hbox);

    meta_data->dial_data = dial_data;

    return (dial_data);
}

gboolean entry_exists(MetaData* meta_data, gchar* entry)
{
    for(int i=0;i<meta_data->find_entries_n;++i)
    {
        if(strcmp(entry, meta_data->find_entries[i])==0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void display_error_message(MetaData* meta_data, gchar* err_msg)
{
    GtkDialogFlags flags = GTK_DIALOG_MODAL;
    GtkWidget* dialog = gtk_message_dialog_new (meta_data->window,
                                  flags,
                                  GTK_MESSAGE_ERROR,
                                  GTK_BUTTONS_CLOSE,
                                  err_msg);

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}

void add_find_entry(MetaData* meta_data, FindDialog* dial_data)
{
    gchar* entry = gtk_combo_box_text_get_active_text(dial_data->text_entry);
    if(entry_exists(meta_data, entry))
    {
        return;
    }
    if(meta_data->find_entries_n!=MAX_FIND_ENTRIES)
    {
        for(int i=meta_data->find_entries_n;i>0;--i)
        {
            strcpy(meta_data->find_entries[i], meta_data->find_entries[i-1]);
        }
        strcpy(meta_data->find_entries[0], entry);
        gtk_combo_box_text_prepend_text(dial_data->text_entry, entry);
        meta_data->find_entries_n++;
    }
    else
    {
        for(int i=MAX_FIND_ENTRIES-1;i>0;--i)
        {
            strcpy(meta_data->find_entries[i], meta_data->find_entries[i-1]);
        }
        strcpy(meta_data->find_entries[0], entry);
        gtk_combo_box_text_prepend_text(dial_data->text_entry, entry);
        gtk_combo_box_text_remove(dial_data->text_entry, meta_data->find_entries_n);
    }
}

GList* get_status_list(MetaData* meta_data, gint curr_page)
{
    GtkWidget* box;
    GtkWidget* terminal;
    GtkWidget* statusbox;
    GtkWidget* statusbar_shell;
    GList* box_children;

    box = gtk_notebook_get_nth_page(meta_data->notebook, curr_page);
    box_children = gtk_container_get_children(GTK_CONTAINER(box));
    box_children = box_children->next->next;
    statusbox = box_children->data;
    box_children = gtk_container_get_children(GTK_CONTAINER(statusbox));
    return box_children;
}

GtkWidget* retrieve_page_filename_label(MetaData* meta_data, gint page_num)
{
    GtkWidget* notebook = meta_data->notebook;
    GtkWidget* box = gtk_notebook_get_nth_page(notebook, page_num);
    GList* box_children = gtk_container_get_children(box);
    box_children = box_children->next->next->next;
    return box_children->data;
}

void set_page_filename(MetaData* meta_data, gint page_num, const char* filename)
{
    GtkWidget* filename_label = retrieve_page_filename_label(meta_data, page_num);
    gtk_label_set_text(filename_label, filename);
}

void get_page_filename(MetaData* meta_data, gint page_num, char* filename)
{
    GtkWidget* filename_label = retrieve_page_filename_label(meta_data, page_num);
    strcpy(filename, gtk_label_get_text(filename_label));
}

GtkWidget* get_current_page_view(MetaData* meta_data)
{
    GList *child_list;
    GtkWidget* curr_page;
    GtkWidget* curr_scrolled;
    GtkWidget* textview;
    GtkSourceBuffer *buffer;
    gint current_page_index = gtk_notebook_get_current_page(meta_data->notebook);
    if(current_page_index==-1)
        return NULL;

    curr_page = gtk_notebook_get_nth_page(meta_data->notebook, current_page_index);
    child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
    child_list = gtk_container_get_children(child_list->data);

    textview = child_list->data;
    return textview;
}

GtkWidget* get_last_page_view(MetaData* meta_data)
{
    GList *child_list;
    GtkWidget* last_page;
    GtkWidget* curr_scrolled;
    GtkWidget* textview;
    GtkSourceBuffer *buffer;
    int last_page_index = gtk_notebook_get_n_pages(meta_data->notebook)-1;
    if(last_page_index==-1)
        return NULL;

    last_page = gtk_notebook_get_nth_page(meta_data->notebook, last_page_index);
    child_list = gtk_container_get_children(GTK_CONTAINER(last_page));
    child_list = gtk_container_get_children(child_list->data);

    textview = child_list->data;
    return textview;
}

GtkSourceBuffer* get_current_page_buffer(MetaData* meta_data)
{
    GtkWidget* textview;
    GtkSourceBuffer *buffer;

    textview = get_current_page_view(meta_data);
    buffer = gtk_text_view_get_buffer((GtkTextView*)textview);
    return buffer;
}

void close_file(MetaData* meta_data, int page_number)
{
    GtkWidget* box;
    GtkWidget* terminal;
    GtkWidget* buffer = get_current_page_buffer(meta_data);
    box = gtk_notebook_get_nth_page(meta_data->notebook, page_number);
    GList* children = gtk_container_get_children(box);
    children = children->next;
    terminal = children->data;
    gtk_widget_destroy(terminal);
    g_object_unref(G_OBJECT(buffer));
    gtk_widget_destroy(box);
}

void switch_to_last_page(MetaData* meta_data)
{
    gint current_page = gtk_notebook_get_current_page(meta_data->notebook);
    while(current_page!=gtk_notebook_get_n_pages(meta_data->notebook)-1)
    {
        gtk_notebook_next_page(meta_data->notebook);
        current_page = gtk_notebook_get_current_page(meta_data->notebook);
    }
}

GtkWidget* create_menu_item_with_icon(const char* filename, const char* lab, guint key_val)
{
    GtkWidget *menu_item;
    GtkWidget *box;
    GtkWidget *icon;
    GtkWidget *label;
    GtkWidget *accel_group;

    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    icon = gtk_image_new_from_icon_name(filename, GTK_ICON_SIZE_MENU);
    menu_item = gtk_menu_item_new();

    gtk_container_add (GTK_CONTAINER (box), icon);

    if(key_val == NULL)
    {
        label = gtk_label_new(lab);
    }
    else
    {
        label = gtk_accel_label_new(lab);
        accel_group = gtk_accel_group_new();
        gtk_label_set_use_underline (GTK_LABEL (label), TRUE);
        gtk_label_set_xalign (GTK_LABEL (label), 0.0);

        gtk_widget_add_accelerator (menu_item, "activate", accel_group, key_val, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

        gtk_accel_label_set_accel_widget(GTK_ACCEL_LABEL (label), menu_item);
        gtk_box_pack_end (GTK_BOX (box), label, TRUE, TRUE, 0);
    }
    gtk_container_add(GTK_CONTAINER (menu_item), box);
    return menu_item;
}

void apply_font(MetaData* meta_data)
{
   GList* child_list;
   GList* status_list;
   GtkWidget* status_font;
   gchar* status_msg;
   GtkWidget* curr_page;
   int page_cnt = gtk_notebook_get_n_pages(GTK_NOTEBOOK(meta_data->notebook));

   for (int i = 0; i < page_cnt; i++)
    {
      curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
      status_list = get_status_list(meta_data, i);
      status_font = status_list->next->next->data;
      gtk_statusbar_pop(status_font, 0);
      status_msg = g_strdup_printf("Font: %s", pango_font_description_to_string(meta_data->font_desc));
      gtk_statusbar_push(status_font, 0, status_msg);
      g_free(status_msg);
      child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
      child_list = gtk_container_get_children(child_list->data);
      if (GTK_IS_TEXT_VIEW(child_list->data))
         gtk_widget_modify_font(child_list->data, meta_data->font_desc);
    }
}

void apply_tab_width(MetaData* meta_data)
{
   GList* child_list;
   GList* status_list;
   GtkWidget* status_tab_width;
   gchar* status_msg;
   GtkWidget* curr_page;
   int page_cnt = gtk_notebook_get_n_pages(GTK_NOTEBOOK(meta_data->notebook));

   for (int i = 0; i < page_cnt; i++)
    {
      curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
      status_list = get_status_list(meta_data, i);
      status_tab_width = status_list->next->next->next->data;
      gtk_statusbar_pop(status_tab_width, 0);
      status_msg = g_strdup_printf("Tab width: %d", meta_data->tab_width);
      gtk_statusbar_push(status_tab_width, 0, status_msg);
      g_free(status_msg);
      child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
      child_list = gtk_container_get_children(child_list->data);
      if (GTK_IS_TEXT_VIEW(child_list->data))
         gtk_source_view_set_tab_width(child_list->data, meta_data->tab_width);
    }
}

void apply_language(MetaData* meta_data)
{
    GtkSourceBuffer *buffer;
    buffer = get_current_page_buffer(meta_data);
    gtk_source_buffer_set_language(buffer, meta_data->lang);
    g_signal_emit_by_name(buffer, "changed");
/*
   for (int i = 0; i < page_cnt; i++)
   {
      curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
      child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
      textview = child_list->data;
      buffer = gtk_text_view_get_buffer((GtkTextView*)textview);
      gtk_source_buffer_set_language(buffer, meta_data->lang);
   }
*/
}

void apply_scheme(MetaData* meta_data)
{
    GList *child_list;
    GtkWidget *curr_page;
    GtkSourceBuffer *buffer;
    GtkWidget* textview;
    int page_cnt = gtk_notebook_get_n_pages(GTK_NOTEBOOK(meta_data->notebook));

    for (int i = 0; i < page_cnt; i++)
    {
        curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
        child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
        child_list = gtk_container_get_children(GTK_CONTAINER(child_list->data));
        textview = child_list->data;
        buffer = gtk_text_view_get_buffer((GtkTextView*)textview);
        gtk_source_buffer_set_style_scheme(buffer, meta_data->scheme);
    }
}

void apply_specification(MetaData* meta_data)
{
    GList *child_list;
    GtkWidget *curr_page;
    GtkSourceBuffer *buffer;
    GtkWidget* textview;
    int page_cnt = gtk_notebook_get_n_pages(GTK_NOTEBOOK(meta_data->notebook));

    for (int i = 0; i < page_cnt; i++)
    {
        curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
        child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
        child_list = gtk_container_get_children(GTK_CONTAINER(child_list->data));
        textview = child_list->data;
        gtk_text_view_set_justification(GTK_TEXT_VIEW(textview), meta_data->justify);
    }
}

void apply_format_prefs(MetaData* meta_data)
{
    GList *child_list;
    GtkWidget *curr_page;
    GtkSourceBuffer *buffer;
    GtkWidget* textview;
    GtkSourceSpaceDrawerClass* drawer;

    int page_cnt = gtk_notebook_get_n_pages(GTK_NOTEBOOK(meta_data->notebook));

    gboolean change_auto_indent;
    gboolean change_space_tabs;
    gboolean change_line_numbers;
    gboolean change_visualize_spaces;
    gboolean change_highlight_line;
    gboolean change_wrap_words;

    for (int i = 0; i < page_cnt; i++)
    {
        curr_page = gtk_notebook_get_nth_page(meta_data->notebook, i);
        child_list = gtk_container_get_children(GTK_CONTAINER(curr_page));
        child_list = gtk_container_get_children(GTK_CONTAINER(child_list->data));
        textview = child_list->data;
        drawer = gtk_source_view_get_space_drawer(textview);
        if(i == 0)
        {
            change_auto_indent = meta_data->auto_indent!=gtk_source_view_get_auto_indent(textview);
            change_space_tabs = meta_data->space_tabs!=gtk_source_view_get_insert_spaces_instead_of_tabs(textview);
            change_line_numbers = meta_data->line_numbers!=gtk_source_view_get_show_line_numbers(textview);
            change_visualize_spaces = meta_data->visualize_spaces!=gtk_source_space_drawer_get_enable_matrix(drawer);
            change_highlight_line = meta_data->highlight_line!=gtk_source_view_get_highlight_current_line(textview);
            change_wrap_words = meta_data->wrap_mode!=gtk_text_view_get_wrap_mode(textview);
        }
        if(change_auto_indent)
        {
            gtk_source_view_set_auto_indent(textview, meta_data->auto_indent);
        }
        if(change_space_tabs)
        {
            gtk_source_view_set_insert_spaces_instead_of_tabs(textview, meta_data->space_tabs);
        }
        if(change_visualize_spaces)
        {
            gtk_source_space_drawer_set_enable_matrix(drawer, meta_data->visualize_spaces);
            printf("%d\n", meta_data->visualize_spaces);
        }
        if(change_line_numbers)
        {
            gtk_source_view_set_show_line_numbers(textview, meta_data->line_numbers);
        }
        if(change_highlight_line)
        {
            gtk_source_view_set_highlight_current_line(textview, meta_data->highlight_line);
        }
        if(change_wrap_words)
        {
            gtk_text_view_set_wrap_mode(textview, meta_data->wrap_mode);
        }
    }
}

void calc_compile_command(MetaData* meta_data, gchar* command, gchar* filename)
{
    GtkSourceBuffer* buffer = get_current_page_buffer(meta_data);
    GtkSourceLanguage* lang = gtk_source_buffer_get_language(buffer);
    gchar* lang_name = g_strdup_printf("%s", gtk_source_language_get_name(lang));

    if(strcmp(lang_name, "C")==0)
    {
        strcpy(command, "gcc -o");
        strcat(command, filename);
        strcat(command, ".o ");
        strcat(command, filename);
        strcat(command, "\n");
    }

    if(strcmp(lang_name, "C++")==0)
    {
        strcpy(command, "g++ -o");
        strcat(command, filename);
        strcat(command, ".o ");
        strcat(command, filename);
        strcat(command, "\n");
    }

    if(strcmp(lang_name, "Python 3")==0)
    {
        strcpy(command, "python3 ");
        strcat(command, filename);
        strcat(command, "\n");
    }

    g_free(lang_name);
}

void calc_run_command(MetaData* meta_data, gchar* command, gchar* filename)
{
    GtkSourceBuffer* buffer = get_current_page_buffer(meta_data);
    GtkSourceLanguage* lang = gtk_source_buffer_get_language(buffer);
    gchar* lang_name = g_strdup_printf("%s", gtk_source_language_get_name(lang));

    if(strcmp(lang_name, "C")==0||strcmp(lang_name, "C++")==0)
    {
        strcpy(command, filename);
        strcat(command, ".o");
        strcat(command, "\n");
    }

    if(strcmp(lang_name, "Python 3")==0||strcmp(lang_name, "Python")==0)
    {
        strcpy(command, "python3 ");
        strcat(command, filename);
        strcat(command, "\n");
    }

    g_free(lang_name);
}

void calc_lang_comment(MetaData* meta_data, gchar* comment)
{
    GtkSourceBuffer* buffer = get_current_page_buffer(meta_data);
    GtkSourceLanguage* lang = gtk_source_buffer_get_language(buffer);
    gchar* lang_name = g_strdup_printf("%s", gtk_source_language_get_name(lang));

    if(strcmp(lang_name, "Ada")==0||strcmp(lang_name, "Eiffel")==0||strcmp(lang_name, "Haskell")==0||strcmp(lang_name, "Lua")==0||strcmp(lang_name, "SQL")==0||
       strcmp(lang_name, "VHDL")==0)
    {
    	strcpy(comment, "--");
    }
    if(strcmp(lang_name, "C")==0||strcmp(lang_name, "C++")==0||strcmp(lang_name, "C/ObjC Header")==0||strcmp(lang_name, "Cg")==0||strcmp(lang_name, "C#")==0||strcmp(lang_name, "CUDA")==0||
       strcmp(lang_name, "GLSL")==0||strcmp(lang_name, "F#")==0||strcmp(lang_name, "Go")==0||strcmp(lang_name, "Groovy")==0||strcmp(lang_name, "Java")==0||
       strcmp(lang_name, "JavaScript")==0||strcmp(lang_name, "Kotlin")==0||strcmp(lang_name, "OpenCL")==0||strcmp(lang_name, "Pascal")==0||strcmp(lang_name, "Rust")==0||
       strcmp(lang_name, "Scala")==0||strcmp(lang_name, "Swift")==0||strcmp(lang_name, "Vala")==0||strcmp(lang_name, "Verilog")==0)
    {
        strcpy(comment, "//");
    }
    if(strcmp(lang_name, "Python 3")==0||strcmp(lang_name, "Python")==0||strcmp(lang_name, "Julia")==0||strcmp(lang_name, "Makefile")==0||strcmp(lang_name, "Meson")==0||strcmp(lang_name, "Perl")==0||
       strcmp(lang_name, "PHP")==0||strcmp(lang_name, "R")==0||strcmp(lang_name, "Ruby")==0||strcmp(lang_name, "sh")==0||strcmp(lang_name, "YAML")==0)
    {
        strcpy(comment, "#");
    }
    if(strcmp(lang_name, "COBOL")==0)
    {
    	strcpy(comment, "*>");
    }
    if(strcmp(lang_name, "Fortran 95")==0)
    {
    	strcpy(comment, "!");
    }
    if(strcmp(lang_name, "LaTeX")==0)
    {
    	strcpy(comment, "%");
    }

/*
    C#
    if(strcmp(label, "Cmake")==0)
    {
    	lang_code = "cmake";
    }
    if(strcmp(label, "Css")==0)
    {
    	lang_code = "css";
    }
    if(strcmp(label, "HTML")==0)
    {
    	lang_code = "html";
    }
    if(strcmp(label, "Meson")==0)
    {
    	lang_code = "meson";
    }
    if(strcmp(label, "OCaml")==0)
    {
    	lang_code = "ocaml";
    }
    if(strcmp(label, "XML")==0)
    {
    	lang_code = "xml";
    }
*/
    g_free(lang_name);
}

void calc_date(gchar* date_str)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strcpy(date_str, asctime(tm));
}

void add_filename(gchar* filename, gint tab_number, MetaData* meta_data)
{
    gint found = FALSE;
    TabData* tab_data = g_new(TabData, 1);
    GList* node = g_list_alloc();
    tab_data->filename = filename;
    tab_data->tab_number = tab_number;
    node->data = tab_number;

    if (meta_data->filename_data == NULL)
        meta_data->filename_data = node;
    else
    {
        GList *list = meta_data->filename_data;

        while (list != NULL)
        {
            if (((TabData*) list->data)->tab_number == tab_number)
            {
                found = TRUE;
                ((TabData*) list->data)->filename = filename;
                break;
            }
            else
            list = g_list_next(list);
        }
        if (!found)
            list = g_list_append(meta_data->filename_data, node);
    }
}

gchar *get_filename(gint tab_number, MetaData* meta_data)
{
    GList *list = meta_data->filename_data;
    while (list != NULL)
    {
        if (((TabData*) list->data)->tab_number == tab_number)
            return ((TabData*) list->data)->filename;
        else
            list = g_list_next(meta_data->filename_data);
    }
    return NULL;
}

#endif
