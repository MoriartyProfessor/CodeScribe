#ifndef WINDOW_DEPENDECIES_H
#define WINDOW_DEPENDECIES_H

#include <gtk/gtk.h>

typedef struct {
    GtkWindow* window;
    GtkWindow* accel_group;
} WindowDependecies;

#endif
