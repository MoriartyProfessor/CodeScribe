#ifndef INIT_TERMINAL_H_INCLUDED
#define INIT_TERMINAL_H_INCLUDED

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <vte/vte.h>
#include <unistd.h>

#include "helpers.h"
#include "menu_objects.h"
#include "WindowDependecies.h"
#include "terminal_palette.h"

void child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_data)
{
    if (!terminal) return;
    if (pid == -1) gtk_main_quit();
}

GtkWidget* create_terminal()
{
    GtkWidget* terminal;

    char project_path[255];

    getcwd(project_path, sizeof(project_path));
    terminal = vte_terminal_new();

    gchar** envp = g_get_environ();
    gchar* arr[] = {g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    gchar** command = arr;

    g_strfreev(envp);

    vte_terminal_spawn_async(VTE_TERMINAL(terminal), VTE_PTY_DEFAULT, project_path,
        command, NULL, (GSpawnFlags)0, NULL, NULL, NULL, -1, NULL, child_ready,
        NULL);

    vte_terminal_set_size ((VteTerminal *)terminal, 256, 10);

    GdkRGBA foreground;
    GdkRGBA background;
    GdkRGBA tmp_clr;
    GdkRGBA palette[16];

    gdk_rgba_parse (&tmp_clr, COLOR0);
    palette[0] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR1);
    palette[1] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR2);
    palette[2] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR3);
    palette[3] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR4);
    palette[4] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR5);
    palette[5] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR6);
    palette[6] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR7);
    palette[7] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR8);
    palette[8] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR9);
    palette[9] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR10);
    palette[10] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR11);
    palette[11] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR12);
    palette[12] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR13);
    palette[13] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR14);
    palette[14] = tmp_clr;
    gdk_rgba_parse (&tmp_clr, COLOR15);
    palette[15] = tmp_clr;

    gdk_rgba_parse (&foreground, FOREGROUND);
    gdk_rgba_parse (&background, BACKGROUND);

    vte_terminal_set_colors((VteTerminal *)terminal, &foreground, &background, palette, 16 );

    gtk_scrollable_set_vscroll_policy(GTK_SCROLLABLE(terminal),  GTK_SCROLL_NATURAL);
    gtk_widget_show(terminal);

    return terminal;
}

#endif // INIT_TERMINAL_H_INCLUDED
