#include "primitives.h"

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define PRIM_SWAP(a, b, T) { T SWAP = a; a = b; b = SWAP; }

void prim_fill(uint *canvas, size_t width, size_t height, uint color) {
    for (size_t i = 0; i < width*height; i++) {
	canvas[i] = color;
    }
}

void prim_fill_rect(uint *canvas, size_t width, size_t height, size_t x1, size_t y1, size_t x2, size_t y2, 
    uint color) {
    if (x1 > x2) PRIM_SWAP(x1, x2, size_t);
    if (y1 > y2) PRIM_SWAP(y1, y2, size_t);

    for (size_t dy = y1; dy < y2; dy++) {
	if (dy < height) {
	    for (size_t dx = x1; dx < x2; dx++) {
		if (dx < width) {
		    canvas[dy * width + dx] = color;
		}
	    }
	}
    }
}

void prim_draw_rect(uint *canvas, size_t width, size_t height, int x1, int y1, int x2, int y2,
    uint color) {
    if (x1 > x2) PRIM_SWAP(x1, x2, int);
    if (y1 > y2) PRIM_SWAP(y1, y2, int);

    for (int dy = y1; dy < y2; dy++) {
	if (dy < (int)height) {
	    if (dy == y1 || dy == y2 - 1) {
		for (int dx = x1; dx <= x2; dx++) {
		    if (dx < (int)width) {
			canvas[dy * width + dx] = color;
		    }
		}
	    } else {
		canvas[dy * width + x1] = color;
		canvas[dy * width + x2] = color;
	    }
	}
    }
}

void prim_draw_line(uint *canvas, size_t width, size_t height, int x1, int y1, int x2, int y2,
    uint color) {
    bool up = false;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    float error = 0;

    if (x1 > x2) PRIM_SWAP(x1, x2, int);
    if (y1 > y2) up = true;

    if (dx >= dy) {
	float m = fabsf((float)dy / dx);
	int y = y1;

	for (int x = x1; x < x2; x++) {
	    if (y < (int)height && x < (int)width) {
		canvas[y * width + x] = color;
	    }

	    error += m;
	    if (error >= 0.5) {
		if (up) y--;
		if (!up) y++;
		error -= 1;
	    }
	}
    } else {
	float m = (float)dx / dy;
	int x = x1;

	if (up) {
	    for (int y = y1; y > y2; y--) {
		if (y < (int)height && x < (int)width) {
		    canvas[y * width + x] = color;
		}

		error += m;
		if (error >= 0.5) {
		    x++;
		    error -= 1;
		}
	    }
	} else {
	    for (int y = y1; y < y2; y++) {
		if (y < (int)height && x < (int)width) {
		    canvas[y * width + x] = color;
		}

		error += m;
		if (error >= 0.5) {
		    x++;
		    error -= 1;
		}
	    }
	}
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
