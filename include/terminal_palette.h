#ifndef TERMINAL_PALLETE_H
#define TERMINAL_PALLETE_H

#define DARK
// This seems to be the most popular terminal pallete choice

// Common colors

#define S_yellow        "#b58900"
#define S_orange        "#cb4b16"
#define S_red           "#dc322f"
#define S_magenta       "#d33682"
#define S_violet        "#6c71c4"
#define S_blue          "#268bd2"
#define S_cyan          "#2aa198"
#define S_green         "#859900"


#ifdef DARK

#define S_base03        "#002b36"
#define S_base02        "#073642"
#define S_base01        "#586e75"
#define S_base00        "#657b83"
#define S_base0         "#839496"
#define S_base1         "#93a1a1"
#define S_base2         "#eee8d5"
#define S_base3         "#fdf6e3"

#endif

#ifndef DARK

#define S_base03        "#fdf6e3"
#define S_base02        "#eee8d5"
#define S_base01        "#93a1a1"
#define S_base00        "#839496"
#define S_base0         "#657b83"
#define S_base1         "#586e75"
#define S_base2         "#073642"
#define S_base3         "#002b36"

#endif

#define BACKGROUND   S_base03
#define FOREGROUND   S_base0


#define COLOR0  S_base02
#define COLOR1  S_red
#define COLOR2  S_green
#define COLOR3  S_yellow
#define COLOR4  S_blue
#define COLOR5  S_magenta
#define COLOR6  S_cyan
#define COLOR7  S_base2
#define COLOR9  S_orange
#define COLOR8  S_base03
#define COLOR10 S_base01
#define COLOR11 S_base00
#define COLOR12 S_base0
#define COLOR13 S_violet
#define COLOR14 S_base1
#define COLOR15 S_base3

#endif // TERMINAL_PALLETE_H
