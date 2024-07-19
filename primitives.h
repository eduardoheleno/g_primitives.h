#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <stdlib.h>
#include <stdio.h>

// todo:
// rect (x)
// line (x)
// fill rect
// draw mesh
// triangle

void prim_fill(uint *canvas, size_t width, size_t height, uint color);
void prim_fill_rect(uint *canvas, size_t width, size_t height, size_t x1, size_t y1, size_t x2, size_t y2, 
    uint color);
void prim_draw_line(uint *canvas, size_t width, size_t height, int x1, int y1, int x2, int y2,
    uint color);
void prim_draw_rect(uint *canvas, size_t width, size_t height, int x1, int y1, int x2, int y2,
    uint color);
void prim_draw_obj(FILE *f);
void prim_save_to_ppm_file(uint *canvas, size_t width, size_t height, const char *file_path);

#endif
