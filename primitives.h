#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <stdlib.h>

// todo:
// line
// triangle
// opacity (maybe)

void prim_fill(uint *canvas, size_t width, size_t height, uint color);
void prim_save_to_ppm_file(uint *canvas, size_t width, size_t height, const char *file_path);

#endif
