#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "primitives.h"

#define WIDTH 800
#define HEIGHT 600

static uint canvas[WIDTH*HEIGHT];

int main() {
    prim_fill(canvas, WIDTH, HEIGHT, 0x0000FF);

    prim_draw_line(canvas, WIDTH, HEIGHT, WIDTH / 2, HEIGHT, WIDTH / 2, 0, 0xABFF56);
    prim_draw_line(canvas, WIDTH, HEIGHT, 0, 0, WIDTH, HEIGHT, 0xABFF56);
    prim_draw_line(canvas, WIDTH, HEIGHT, 0, HEIGHT, WIDTH, 0, 0xABFF56);

    prim_save_to_ppm_file(canvas, WIDTH, HEIGHT, "output.ppm");
}
