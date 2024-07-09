#include "primitives.h"

#include <stdio.h>

void prim_fill(uint *canvas, size_t width, size_t height, uint color) {
    for (size_t i = 0; i < width*height; i++) {
	canvas[i] = color;
    }
}

void prim_save_to_ppm_file(uint *canvas, size_t width, size_t height, const char *file_path) {
    FILE *f = fopen(file_path, "wb");
    fprintf(f, "P6\n%zu %zu 255\n", width, height);

    for (size_t i = 0; i < width*height; i++) {
	uint pixel = canvas[i];
	u_int8_t bytes[3] = {
	    (pixel >> 16)&0xFF,
	    (pixel >> 8)&0xFF,
	    (pixel >> 0)&0xFF
	};

	fwrite(bytes, sizeof(bytes), 1, f);
    }

    fclose(f);
}
