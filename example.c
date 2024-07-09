#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "primitives.h"

#define WIDTH 800
#define HEIGHT 600

static uint canvas[WIDTH*HEIGHT];

int main() {
    prim_fill(canvas, WIDTH, HEIGHT, 0xFB3809);
    prim_save_to_ppm_file(canvas, WIDTH, HEIGHT, "output.ppm");
}
