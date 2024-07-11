#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "primitives.h"

#define WIDTH 800
#define HEIGHT 600

static uint canvas[WIDTH*HEIGHT];

int main() {
    // prim_draw_line(canvas, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, 0xABFF56);
    prim_draw_line(canvas, WIDTH, HEIGHT, 100, 100, 150, 50, 0xABFF56);

    // prim_draw_rect(canvas, WIDTH, HEIGHT, 0, 0, 20, 20, 0xFB3809);
    // prim_draw_rect(canvas, WIDTH, HEIGHT, 20, 20, 40, 40, 0xFB4444);
    prim_save_to_ppm_file(canvas, WIDTH, HEIGHT, "output.ppm");
}
