#ifndef MENU_OBJECTS_H_INCLUDED
#define MENU_OBJECTS_H_INCLUDED

#include <vte/vte.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <gtksourceview-3.0/gtksourceview/gtksourcestyleschememanager.h>

#define MAX_FIND_ENTRIES 3
#define MAX_ENTRY_CHAR 255

typedef struct
{
    GtkWidget *settings_menu;       //Gtk::Menu
    GtkWidget *settings_mi;         //Gtk::MenuItem
    GtkWidget *theme_mi;            //Gtk::MenuItem
    GtkWidget *compilers_mi;        //Gtk::MenuItem
    GtkWidget *highlighting_mi;     //Gtk::MenuItem
}SettingsMenu;                      // Settings Submenu

typedef struct
{
    GtkWidget *file_menu;           // Gtk::Menu
    GtkWidget *file_mi;             //Gtk::MenuItem
    GtkWidget *new_mi;              //Gtk::MenuItem
    GtkWidget *open_mi;             //Gtk::MenuItem
    GtkWidget *close_mi;            //Gtk::MenuItem
    GtkWidget *sep1;                //Gtk::Separetor
    GtkWidget *save_mi;             //Gtk::MenuItem
    GtkWidget *save_as_mi;          //Gtk::MenuItem
    GtkWidget *sep2;                //Gtk::Separetor
    GtkWidget *settings_mi;         //Gtk::MenuItem
    GtkWidget *sep3;                //Gtk::Separetor
    GtkWidget *quit_mi;             //Gtk::MenuItem
}FileMenu;                          // File Menu

typedef struct
{
    GtkWidget *edit_menu;           //Gtk::Menu
    GtkWidget *edit_mi;             //Gtk::MenuItem
    GtkWidget *undo_mi;             //Gtk::MenuItem
    GtkWidget *redo_mi;             //Gtk::MenuItem
    GtkWidget *sep1;                //Gtk::Separetor
    GtkWidget *cut_mi;              //Gtk::MenuItem
    GtkWidget *copy_mi;             //Gtk::MenuItem
    GtkWidget *paste_mi;            //Gtk::MenuItem
    GtkWidget *sep2;                //Gtk::Separetor
    GtkWidget *comment_mi;          //Gtk::MenuItem
    GtkWidget *uncomment_mi;        //Gtk::MenuItem
    GtkWidget *sep3;
    GtkWidget *insert_date_mi;
}EditMenu;                          // Edit Menu

typedef struct
{
    GtkWidget* format_menu;
    GtkWidget* format_mi;
    GtkWidget* auto_indent_mi;
    GtkWidget* space_tabs_mi;
    GtkWidget* line_numbers_mi;
    GtkWidget* visualize_spaces_mi;
    GtkWidget* wrap_words_mi;
    GtkWidget* tab_width_head_mi;
    GtkWidget* justify_left_mi;
    GtkWidget* justify_right_mi;
    GtkWidget* justify_center_mi;
    GtkWidget* justify_fill_mi;
}FormatMenu;                          // Format Menu

typedef struct
{
    GtkWidget *search_menu;         //Gtk::Menu
    GtkWidget *search_mi;           //Gtk::MenuItem
    GtkWidget *find_mi;             //Gtk::MenuItem
    GtkWidget *replace_mi;          //Gtk::MenuItem
    GtkWidget *goto_mi;             //Gtk::MenuItem
}SearchMenu;                        // Search Menu

typedef struct
{
    GtkWidget *build_menu;          //Gtk::Menu
    GtkWidget *build_mi;            //Gtk::MenuItem
    GtkWidget *compile_mi;          //Gtk::MenuItem
    GtkWidget *run_mi;              //Gtk::MenuItem
    GtkWidget *compile_and_run_mi;  //Gtk::MenuItem
}BuildMenu;                        // Build Menu

typedef struct
{
    GtkWidget *help_menu;           //Gtk::Menu
    GtkWidget *help_mi;             //Gtk::MenuItem
    GtkWidget *about_mi;            //Gtk::MenuItem
    GtkWidget *docs_mi;             //Gtk::MenuItem
    GtkWidget *sep;                 //Gtk::MenuItem
}HelpMenu;                          // Help Menu

typedef struct
{
    FileMenu* file_menu;
    EditMenu* edit_menu;
    FormatMenu* format_menu;
    SearchMenu* search_menu;
    BuildMenu* build_menu;
    HelpMenu* help_menu;
}MenuBar;

typedef struct
{
    GtkWidget* scrolled_window;
    GtkWidget* terminal;
    GtkWidget* textview;
    GtkWidget* tab_label;
}SourceObject;

typedef struct
{
    gchar* filename;
    gint tab_number;
}TabData;

typedef struct
{
    GtkWidget* dialog;
    GtkWidget* forward_btn;
    GtkWidget* backward_btn;
    GtkWidget* case_sense_chk;
    GtkWidget* regex_chk;
    GtkWidget* text_entry;
    GtkWidget* cancel_btn;
}FindDialog;

typedef struct
{
    GtkWidget* window;
    GtkWidget* notebook;
    GList* filename_data;

    GtkJustification justify;
    gboolean auto_indent;
    gboolean space_tabs;
    gboolean line_numbers;
    gboolean visualize_spaces;
    gboolean highlight_line;
    GtkWrapMode wrap_mode;

    FindDialog* dial_data;
    gint find_entries_n;
    gint find_entry_curr;
    gchar** find_entries;
    gboolean regex_option;
    gboolean case_sense_option;

    gint tab_width;
    PangoFontDescription* font_desc;
    GtkSourceLanguage* lang;
    GtkSourceLanguageManager* lang_manager;
    GtkSourceStyleScheme* scheme;
    GtkSourceStyleSchemeManager* scheme_manager;
}MetaData;

#endif // MENU_OBJECTS_H_INCLUDED
