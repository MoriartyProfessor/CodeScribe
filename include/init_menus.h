#ifndef INIT_MENUS_H_INCLUDED
#define INIT_MENUS_H_INCLUDED

#include <gtk/gtk.h>
#include "helpers.h"
#include "menu_objects.h"
#include "WindowDependecies.h"

void *create_schemes_modes_submenu(WindowDependecies* win_dep, GtkWidget **s_menu, GtkWidget **s_mi, MetaData* meta_data)
{
    GtkWidget *schemes_menu;
    GtkWidget *schemes_mi;
    GSList *group = NULL;

    GtkWidget *classic_mi = gtk_radio_menu_item_new_with_label (group, "Classic");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (classic_mi));
    GtkWidget *cobalt_mi = gtk_radio_menu_item_new_with_label (group, "Cobalt");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (cobalt_mi));
    GtkWidget *kate_mi = gtk_radio_menu_item_new_with_label (group, "Kate");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (kate_mi));
    GtkWidget *oblivion_mi = gtk_radio_menu_item_new_with_label (group, "Oblivion");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (oblivion_mi));
    GtkWidget *solarized_light_mi = gtk_radio_menu_item_new_with_label (group, "Solarized-Light");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (solarized_light_mi));
    GtkWidget *solarized_dark_mi = gtk_radio_menu_item_new_with_label (group, "Solarized-Dark");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (solarized_dark_mi));
    GtkWidget *tango_mi = gtk_radio_menu_item_new_with_label (group, "Tango");
    group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (tango_mi));

    gtk_check_menu_item_set_active(oblivion_mi, TRUE);

    schemes_menu = gtk_menu_new();

    schemes_mi = gtk_menu_item_new_with_label("Themes");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(schemes_mi), schemes_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), classic_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), kate_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), oblivion_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), tango_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), cobalt_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), solarized_light_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(schemes_menu), solarized_dark_mi);

    g_signal_connect(G_OBJECT(classic_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(kate_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(oblivion_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(tango_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cobalt_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(solarized_light_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(solarized_dark_mi), "toggled", G_CALLBACK(scheme_settings_callback), meta_data);

    *s_menu = schemes_menu;
    *s_mi = schemes_mi;
}

void *create_shells_submenu(WindowDependecies* win_dep, GtkWidget **s_menu, GtkWidget **s_mi, MetaData* meta_data)
{
    GtkWidget *shells_menu;
    GtkWidget *shells_mi;

    GtkWidget *sh_mi = gtk_menu_item_new_with_label("Bourne shell");
    GtkWidget *bash_mi = gtk_menu_item_new_with_label("Bourne-Again shell");
    GtkWidget *ksh_mi = gtk_menu_item_new_with_label("Koch shell");
    GtkWidget *dash_mi = gtk_menu_item_new_with_label("Debian Almquist shell");

    shells_menu = gtk_menu_new();

    shells_mi = gtk_menu_item_new_with_label("Shells");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(shells_mi), shells_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(shells_menu), sh_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(shells_menu), bash_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(shells_menu), ksh_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(shells_menu), dash_mi);

    g_signal_connect(G_OBJECT(sh_mi), "activate", G_CALLBACK(shell_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(bash_mi), "activate", G_CALLBACK(shell_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(ksh_mi), "activate", G_CALLBACK(shell_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(dash_mi), "activate", G_CALLBACK(shell_settings_callback), meta_data);

    *s_menu = shells_menu;
    *s_mi = shells_mi;
}

void *create_highlights_modes_submenu(WindowDependecies* win_dep, GtkWidget **h_menu, GtkWidget **h_mi, MetaData* meta_data)
{
    GtkWidget *highlighting_menu;
    GtkWidget *highlighting_mi;
    GtkWidget *ada_mi = gtk_menu_item_new_with_label("Ada");
    GtkWidget *cg_mi = gtk_menu_item_new_with_label("Cg");
    GtkWidget *c_mi = gtk_menu_item_new_with_label("C");
    GtkWidget *cpp_mi = gtk_menu_item_new_with_label("C++");
    GtkWidget *csharp_mi = gtk_menu_item_new_with_label("C#");
    GtkWidget *cmake_mi = gtk_menu_item_new_with_label("CMake");
    GtkWidget *cobol_mi = gtk_menu_item_new_with_label("Cobol");
    GtkWidget *css_mi = gtk_menu_item_new_with_label("CSS");
    GtkWidget *cuda_mi = gtk_menu_item_new_with_label("Cuda");
    GtkWidget *eiffel_mi = gtk_menu_item_new_with_label("Eiffel");
    GtkWidget *fortran_mi = gtk_menu_item_new_with_label("Fortran");
    GtkWidget *fsharp_mi = gtk_menu_item_new_with_label("F#");
    GtkWidget *glsl_mi = gtk_menu_item_new_with_label("GLSL");
    GtkWidget *go_mi = gtk_menu_item_new_with_label("Go");
    GtkWidget *groovy_mi = gtk_menu_item_new_with_label("Groovy");
    GtkWidget *haskell_mi = gtk_menu_item_new_with_label("Haskell");
    GtkWidget *html_mi = gtk_menu_item_new_with_label("HTML");
    GtkWidget *java_mi = gtk_menu_item_new_with_label("Java");
    GtkWidget *javascript_mi = gtk_menu_item_new_with_label("JavaScript");
    GtkWidget *julia_mi = gtk_menu_item_new_with_label("Julia");
    GtkWidget *kotlin_mi = gtk_menu_item_new_with_label("Kotlin");
    GtkWidget *latex_mi = gtk_menu_item_new_with_label("LaTeX");
    GtkWidget *lua_mi = gtk_menu_item_new_with_label("Lua");
    GtkWidget *makefile_mi = gtk_menu_item_new_with_label("Makefile");
    GtkWidget *meson_mi = gtk_menu_item_new_with_label("Meson");
    GtkWidget *ocaml_mi = gtk_menu_item_new_with_label("OCaml");
    GtkWidget *opencl_mi = gtk_menu_item_new_with_label("OpenCL");
    GtkWidget *pascal_mi = gtk_menu_item_new_with_label("Pascal");
    GtkWidget *perl_mi = gtk_menu_item_new_with_label("Perl");
    GtkWidget *php_mi = gtk_menu_item_new_with_label("PHP");
    GtkWidget *python3_mi = gtk_menu_item_new_with_label("Python");
    GtkWidget *R_mi = gtk_menu_item_new_with_label("R");
    GtkWidget *ruby_mi = gtk_menu_item_new_with_label("Ruby");
    GtkWidget *rust_mi = gtk_menu_item_new_with_label("Rust");
    GtkWidget *scala_mi = gtk_menu_item_new_with_label("Scala");
    GtkWidget *sh_mi = gtk_menu_item_new_with_label("Bourne Shell");
    GtkWidget *sql_mi = gtk_menu_item_new_with_label("SQL");
    GtkWidget *swift_mi = gtk_menu_item_new_with_label("Swift");
    GtkWidget *vala_mi = gtk_menu_item_new_with_label("Vala");
    GtkWidget *verilog_mi = gtk_menu_item_new_with_label("Verilog");
    GtkWidget *vhdl_mi = gtk_menu_item_new_with_label("VHDL");
    GtkWidget *xml_mi = gtk_menu_item_new_with_label("XML");
    GtkWidget *yaml_mi = gtk_menu_item_new_with_label("YAML");

    highlighting_menu = gtk_menu_new();

    highlighting_mi = gtk_menu_item_new_with_label("Highlighting modes");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(highlighting_mi), highlighting_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), ada_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), cg_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), c_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), cpp_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), csharp_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), cmake_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), cobol_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), css_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), cuda_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), eiffel_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), fortran_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), fsharp_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), glsl_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), go_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), groovy_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), haskell_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), html_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), java_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), javascript_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), julia_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), kotlin_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), latex_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), lua_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), makefile_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), meson_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), ocaml_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), opencl_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), pascal_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), perl_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), php_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), python3_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), R_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), ruby_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), rust_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), scala_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), sh_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), sql_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), swift_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), vala_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), verilog_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), vhdl_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), xml_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(highlighting_menu), yaml_mi);

    g_signal_connect(G_OBJECT(ada_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cg_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(c_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cpp_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(csharp_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cmake_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cobol_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(css_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(cuda_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(eiffel_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(fortran_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(fsharp_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(glsl_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(go_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(groovy_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(haskell_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(html_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(java_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(javascript_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(julia_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(kotlin_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(latex_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(lua_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(makefile_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(meson_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(ocaml_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(opencl_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(pascal_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(perl_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(php_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(python3_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(R_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(ruby_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(rust_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(scala_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(swift_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(sh_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(sql_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(vala_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(verilog_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(vhdl_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(xml_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(yaml_mi), "activate", G_CALLBACK(highlighting_settings_callback), meta_data);

    *h_menu = highlighting_menu;
    *h_mi = highlighting_mi;
}

void *create_settings_submenu(WindowDependecies* win_dep, GtkWidget **s_menu, GtkWidget **s_mi, MetaData* meta_data)
{
    GtkWidget *settings_menu;
    GtkWidget *settings_mi;
    GtkWidget *font_mi;
    GtkWidget *compilers_mi;

    GtkWidget *highlighting_mi;
    GtkWidget *schemes_mi;
    GtkWidget *shells_mi;

    GtkWidget *schemes_menu;
    GtkWidget *shells_menu;
    GtkWidget *highlighting_menu;

    GtkWidget *accel_group = win_dep->accel_group;

    settings_menu = gtk_menu_new();

    settings_mi = gtk_menu_item_new_with_label("Settings");
    font_mi = gtk_menu_item_new_with_label("Font");
    compilers_mi = gtk_menu_item_new_with_label("Compilers");

    create_highlights_modes_submenu(win_dep, &highlighting_menu, &highlighting_mi, meta_data);
    create_schemes_modes_submenu(win_dep, &schemes_menu, &schemes_mi, meta_data);
    create_shells_submenu(win_dep, &shells_menu, &shells_mi, meta_data);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(settings_mi), settings_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), font_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), compilers_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), shells_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), schemes_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), highlighting_mi);

    g_signal_connect(G_OBJECT(font_mi), "activate", G_CALLBACK(font_settings_callback), meta_data);
    g_signal_connect(G_OBJECT(compilers_mi), "activate", G_CALLBACK(compilers_settings_callback), NULL);

    gtk_widget_add_accelerator(GTK_MENU_ITEM(font_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_t, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(compilers_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_l, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(highlighting_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_h, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    *s_menu = settings_menu;
    *s_mi = settings_mi;
}

void *create_file_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *file_menu;
    GtkWidget *file_mi;
    GtkWidget *new_mi;
    GtkWidget *open_mi;
    GtkWidget *close_mi;
    GtkWidget *sep1;
    GtkWidget *save_mi;
    GtkWidget *save_as_mi;
    GtkWidget *sep2;
    GtkWidget *settings_mi;
    GtkWidget *sep3;
    GtkWidget *quit_mi;

    GtkWidget *settings_menu;

    GtkWidget *accel_group = win_dep->accel_group;

    file_menu = gtk_menu_new();

    file_mi = gtk_menu_item_new_with_mnemonic("_File");
    new_mi = gtk_menu_item_new_with_label("New");
    open_mi = gtk_menu_item_new_with_label("Open");
    close_mi = gtk_menu_item_new_with_label("Close");

    sep1 = gtk_separator_menu_item_new();

    save_mi = gtk_menu_item_new_with_label("Save");
    save_as_mi = gtk_menu_item_new_with_label("Save as");

    sep2 = gtk_separator_menu_item_new();

    create_settings_submenu(win_dep, &settings_menu, &settings_mi, meta_data);

    sep3 = gtk_separator_menu_item_new();

    quit_mi = gtk_menu_item_new_with_label("Quit");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_mi), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), close_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep1);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_as_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep2);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), settings_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), sep3);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_mi);

    g_signal_connect(G_OBJECT(new_mi), "activate", G_CALLBACK(new_file_callback), meta_data);
    g_signal_connect(G_OBJECT(open_mi), "activate", G_CALLBACK(open_file_callback), meta_data);
    g_signal_connect(G_OBJECT(close_mi), "activate", G_CALLBACK(close_file_callback), meta_data);
    g_signal_connect(G_OBJECT(save_mi), "activate", G_CALLBACK(save_file_callback), meta_data);
    g_signal_connect(G_OBJECT(save_as_mi), "activate", G_CALLBACK(save_as_file_callback), meta_data);

    g_signal_connect(G_OBJECT(quit_mi), "activate", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_add_accelerator(GTK_MENU_ITEM(new_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(open_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(close_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_w, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(save_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(quit_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    menubar_obj->file_menu->file_menu = file_menu;
    menubar_obj->file_menu->file_mi = file_mi;
    menubar_obj->file_menu->new_mi = new_mi;
    menubar_obj->file_menu->open_mi = open_mi;
    menubar_obj->file_menu->close_mi = close_mi;
    menubar_obj->file_menu->sep1 = sep1;
    menubar_obj->file_menu->save_as_mi = save_as_mi;
    menubar_obj->file_menu->sep2 = sep2;
    menubar_obj->file_menu->settings_mi = settings_mi;
    menubar_obj->file_menu->sep3 = sep3;
    menubar_obj->file_menu->quit_mi = quit_mi;
}

void *create_edit_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *edit_menu;
    GtkWidget *edit_mi;
    GtkWidget *undo_mi;
    GtkWidget *redo_mi;
    GtkWidget *sep1;
    GtkWidget *cut_mi;
    GtkWidget *copy_mi;
    GtkWidget *paste_mi;
    GtkWidget *sep2;
    GtkWidget *comment_mi;
    GtkWidget *uncomment_mi;
    GtkWidget *sep3;
    GtkWidget *insert_date_mi;

    GtkWidget *accel_group = win_dep->accel_group;

    edit_menu = gtk_menu_new();

    edit_mi = gtk_menu_item_new_with_mnemonic("_Edit");
    undo_mi = gtk_menu_item_new_with_label("Undo");
    redo_mi = gtk_menu_item_new_with_label("Redo");

    sep1 = gtk_separator_menu_item_new();

    cut_mi = gtk_menu_item_new_with_label("Cut");
    copy_mi = gtk_menu_item_new_with_label("Copy");
    paste_mi = gtk_menu_item_new_with_label("Paste");

    sep2 = gtk_separator_menu_item_new();

    comment_mi = gtk_menu_item_new_with_label("Comment");
    uncomment_mi = gtk_menu_item_new_with_label("Uncomment");

    sep3 = gtk_separator_menu_item_new();
    insert_date_mi = gtk_menu_item_new_with_label("Insert Date/Time");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_mi), edit_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), undo_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), redo_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), sep1);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), cut_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), copy_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), paste_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), sep2);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), comment_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), uncomment_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), sep3);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), insert_date_mi);

    g_signal_connect(G_OBJECT(undo_mi), "activate", G_CALLBACK(undo_callback), meta_data);
    g_signal_connect(G_OBJECT(redo_mi), "activate", G_CALLBACK(redo_callback), meta_data);
    g_signal_connect(G_OBJECT(cut_mi), "activate", G_CALLBACK(cut_callback), meta_data);
    g_signal_connect(G_OBJECT(copy_mi), "activate", G_CALLBACK(copy_callback), meta_data);
    g_signal_connect(G_OBJECT(paste_mi), "activate", G_CALLBACK(paste_callback), meta_data);
    g_signal_connect(G_OBJECT(comment_mi), "activate", G_CALLBACK(comment_callback), meta_data);
    g_signal_connect(G_OBJECT(uncomment_mi), "activate", G_CALLBACK(uncomment_callback), meta_data);
    g_signal_connect(G_OBJECT(insert_date_mi), "activate", G_CALLBACK(insert_date_callback), meta_data);

    gtk_widget_add_accelerator(GTK_MENU_ITEM(undo_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_z, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(cut_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_x, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(copy_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_c, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(paste_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_v, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    menubar_obj->edit_menu->edit_menu = edit_menu;
    menubar_obj->edit_menu->edit_mi = edit_mi;
    menubar_obj->edit_menu->undo_mi = undo_mi;
    menubar_obj->edit_menu->redo_mi = redo_mi;
    menubar_obj->edit_menu->sep1 = sep1;
    menubar_obj->edit_menu->cut_mi = cut_mi;
    menubar_obj->edit_menu->copy_mi = copy_mi;
    menubar_obj->edit_menu->paste_mi = paste_mi;
    menubar_obj->edit_menu->sep2 = sep2;
    menubar_obj->edit_menu->comment_mi = comment_mi;
    menubar_obj->edit_menu->uncomment_mi = uncomment_mi;
    menubar_obj->edit_menu->sep3 = sep3;
    menubar_obj->edit_menu->insert_date_mi = insert_date_mi;
}

void create_tab_width_menu(MetaData* meta_data, GtkWidget** twh_mi)
{
    GtkWidget* tab_width_menu;
    GtkWidget* tab_width_head_mi;
    GSList* group = NULL;
    GtkWidget* tab_width_mis[MAX_TAB_WIDTH];

    for(int i=0;i<MAX_TAB_WIDTH;++i)
    {
        gchar* label = g_strdup_printf("Tab width: %d", i+1);
        tab_width_mis[i] = gtk_radio_menu_item_new_with_label (group, label);
        group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (tab_width_mis[i]));
        g_free(label);
    }
    gtk_check_menu_item_set_active(tab_width_mis[meta_data->tab_width-1], TRUE);
    tab_width_menu = gtk_menu_new();

    tab_width_head_mi = gtk_menu_item_new_with_label("Tab width");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(tab_width_head_mi), tab_width_menu);
    for(int i=0;i<MAX_TAB_WIDTH;++i)
    {
        gtk_menu_shell_append(GTK_MENU_SHELL(tab_width_menu), tab_width_mis[i]);
        g_signal_connect(G_OBJECT(tab_width_mis[i]), "toggled", G_CALLBACK(tab_width_menu_callback), meta_data);
    }
    *twh_mi = tab_width_head_mi;
}

void *create_format_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GList* group = NULL;
    GtkWidget* format_menu;
    GtkWidget* format_mi;
    GtkWidget* justify_smenu;
    GtkWidget* justify_smi;
    GtkWidget* auto_indent_mi;
    GtkWidget* space_tabs_mi;
    GtkWidget* highlight_line_mi;
    GtkWidget* line_numbers_mi;
    GtkWidget* visualize_spaces_mi;
    GtkWidget* wrap_words_mi;
    GtkWidget* justify_left_mi;
    GtkWidget* justify_right_mi;
    GtkWidget* justify_center_mi;
    GtkWidget* justify_fill_mi;
    GtkWidget* tab_width_head_mi;

    GtkWidget *accel_group = win_dep->accel_group;

    format_menu = gtk_menu_new();
    justify_smenu = gtk_menu_new();

    format_mi = gtk_menu_item_new_with_mnemonic("F_ormat");
    justify_smi = gtk_menu_item_new_with_label("Justify");
    auto_indent_mi = gtk_check_menu_item_new_with_label("Enable Auto-Indent");
    gtk_check_menu_item_set_active(auto_indent_mi, TRUE);
    space_tabs_mi = gtk_check_menu_item_new_with_label("Insert spaces instead of tabs");
    highlight_line_mi = gtk_check_menu_item_new_with_label("Highlight current line");
    gtk_check_menu_item_set_active(highlight_line_mi, TRUE);
    line_numbers_mi = gtk_check_menu_item_new_with_label("Display line numbers");
    gtk_check_menu_item_set_active(line_numbers_mi, TRUE);
    visualize_spaces_mi = gtk_check_menu_item_new_with_label("Display spaces as symbols");
    wrap_words_mi = gtk_check_menu_item_new_with_label("Text wrapping");
    create_tab_width_menu(meta_data, &tab_width_head_mi);

    justify_left_mi = gtk_radio_menu_item_new_with_label(group, "Align Left");
    group = gtk_radio_menu_item_get_group(justify_left_mi);
    justify_center_mi = gtk_radio_menu_item_new_with_label(group, "Align Center");
    group = gtk_radio_menu_item_get_group(justify_center_mi);
    justify_right_mi = gtk_radio_menu_item_new_with_label(group, "Align Right");
    group = gtk_radio_menu_item_get_group(justify_right_mi);
    justify_fill_mi = gtk_radio_menu_item_new_with_label(group, "Align Fill");
    group = gtk_radio_menu_item_get_group(justify_fill_mi);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(format_mi), format_menu);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(justify_smi), justify_smenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), auto_indent_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), space_tabs_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), line_numbers_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), visualize_spaces_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), highlight_line_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), wrap_words_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), tab_width_head_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(format_menu), justify_smi);
    gtk_menu_shell_append(GTK_MENU_SHELL(justify_smenu), justify_left_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(justify_smenu), justify_center_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(justify_smenu), justify_right_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(justify_smenu), justify_fill_mi);

    g_signal_connect(G_OBJECT(auto_indent_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(space_tabs_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(line_numbers_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(visualize_spaces_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(highlight_line_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(wrap_words_mi), "toggled", G_CALLBACK(format_callback), meta_data);
    g_signal_connect(G_OBJECT(justify_left_mi), "activate", G_CALLBACK(justify_menu_callback), meta_data);
    g_signal_connect(G_OBJECT(justify_center_mi), "activate", G_CALLBACK(justify_menu_callback), meta_data);
    g_signal_connect(G_OBJECT(justify_right_mi), "activate", G_CALLBACK(justify_menu_callback), meta_data);
    g_signal_connect(G_OBJECT(justify_fill_mi), "activate", G_CALLBACK(justify_menu_callback), meta_data);

    //gtk_widget_add_accelerator(GTK_MENU_ITEM(undo_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_z, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    //gtk_widget_add_accelerator(GTK_MENU_ITEM(cut_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_x, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    //gtk_widget_add_accelerator(GTK_MENU_ITEM(copy_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_c, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    //gtk_widget_add_accelerator(GTK_MENU_ITEM(paste_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_v, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    menubar_obj->format_menu->format_menu = format_menu;
    menubar_obj->format_menu->format_mi = format_mi;
    menubar_obj->format_menu->auto_indent_mi = auto_indent_mi;
    menubar_obj->format_menu->space_tabs_mi = space_tabs_mi;
    menubar_obj->format_menu->line_numbers_mi = line_numbers_mi;
    menubar_obj->format_menu->visualize_spaces_mi = visualize_spaces_mi;
    menubar_obj->format_menu->wrap_words_mi = wrap_words_mi;
    menubar_obj->format_menu->justify_left_mi = justify_left_mi;
    menubar_obj->format_menu->justify_center_mi = justify_center_mi;
    menubar_obj->format_menu->justify_right_mi = justify_right_mi;
    menubar_obj->format_menu->justify_fill_mi = justify_fill_mi;
}

void *create_search_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *search_menu;
    GtkWidget *search_mi;
    GtkWidget *find_mi;
    GtkWidget *replace_mi;
    GtkWidget *goto_mi;

    GtkWidget *accel_group = win_dep->accel_group;

    search_menu = gtk_menu_new();

    search_mi = gtk_menu_item_new_with_mnemonic("_Search");
    find_mi = gtk_menu_item_new_with_label("Find");
    replace_mi = gtk_menu_item_new_with_label("Replace");
    goto_mi = gtk_menu_item_new_with_label("Go to line");


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(search_mi), search_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), find_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), replace_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(search_menu), goto_mi);

    g_signal_connect(G_OBJECT(find_mi), "activate", G_CALLBACK(find_callback), meta_data);
    g_signal_connect(G_OBJECT(replace_mi), "activate", G_CALLBACK(replace_callback), meta_data);
    g_signal_connect(G_OBJECT(goto_mi), "activate", G_CALLBACK(goto_callback), meta_data);

    gtk_widget_add_accelerator(GTK_MENU_ITEM(find_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_f, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(replace_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_r, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(goto_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_g, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    menubar_obj->search_menu->search_menu = search_menu;
    menubar_obj->search_menu->search_mi = search_mi;
    menubar_obj->search_menu->find_mi = find_mi;
    menubar_obj->search_menu->replace_mi = replace_mi;
    menubar_obj->search_menu->goto_mi = goto_mi;

}

void *create_build_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *build_menu;
    GtkWidget *build_mi;
    GtkWidget *compile_mi;
    GtkWidget *run_mi;
    GtkWidget *compile_and_run_mi;

    GtkWidget *accel_group = win_dep->accel_group;

    build_menu = gtk_menu_new();

    build_mi = gtk_menu_item_new_with_mnemonic("_Build");
    compile_mi = gtk_menu_item_new_with_label("Compile");
    run_mi = gtk_menu_item_new_with_label("Run");
    compile_and_run_mi = gtk_menu_item_new_with_label("Compile and run");


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(build_mi), build_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(build_menu), compile_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(build_menu), run_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(build_menu), compile_and_run_mi);

    g_signal_connect(G_OBJECT(compile_mi), "activate", G_CALLBACK(compile_callback), meta_data);
    g_signal_connect(G_OBJECT(run_mi), "activate", G_CALLBACK(run_callback), meta_data);
    g_signal_connect(G_OBJECT(compile_and_run_mi), "activate", G_CALLBACK(compile_and_run_callback), meta_data);

    gtk_widget_add_accelerator(GTK_MENU_ITEM(compile_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_F9, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(run_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_F10, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_MENU_ITEM(compile_and_run_mi), "activate", GTK_ACCEL_GROUP(accel_group), GDK_KEY_F11, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    menubar_obj->build_menu->build_menu = build_menu;
    menubar_obj->build_menu->build_mi = build_mi;
    menubar_obj->build_menu->compile_mi = compile_mi;
    menubar_obj->build_menu->run_mi = run_mi;
    menubar_obj->build_menu->compile_and_run_mi = compile_and_run_mi;

}

void *create_help_menu(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *help_menu;
    GtkWidget *help_mi;
    GtkWidget *about_mi;
    GtkWidget *docs_mi;
    GtkWidget *sep;

    help_menu = gtk_menu_new();

    help_mi = gtk_menu_item_new_with_mnemonic("_Help");
    about_mi = gtk_menu_item_new_with_label("About");
    docs_mi = gtk_menu_item_new_with_label("Documentation");
    sep = gtk_separator_menu_item_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_mi), help_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), docs_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), sep);
    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about_mi);

    g_signal_connect(G_OBJECT(about_mi), "activate", G_CALLBACK(about_callback), win_dep->window);
    g_signal_connect(G_OBJECT(docs_mi), "activate", G_CALLBACK(docs_callback), meta_data);

    menubar_obj->help_menu->help_menu = help_menu;
    menubar_obj->help_menu->help_mi = help_mi;
    menubar_obj->help_menu->docs_mi = docs_mi;
    menubar_obj->help_menu->sep = sep;
    menubar_obj->help_menu->about_mi = about_mi;
}

GtkWidget *create_menubar(WindowDependecies* win_dep, MenuBar* menubar_obj, MetaData* meta_data)
{
    GtkWidget *menubar;

    menubar = gtk_menu_bar_new();
    create_file_menu(win_dep, menubar_obj, meta_data);
    create_edit_menu(win_dep, menubar_obj, meta_data);
    create_format_menu(win_dep, menubar_obj, meta_data);
    create_search_menu(win_dep, menubar_obj, meta_data);
    create_build_menu(win_dep, menubar_obj, meta_data);
    create_help_menu(win_dep, menubar_obj, meta_data);

    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->file_menu->file_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->edit_menu->edit_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->format_menu->format_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->search_menu->search_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->build_menu->build_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menubar_obj->help_menu->help_mi);

    return menubar;
}

#endif // INIT_MENUS_H_INCLUDED
