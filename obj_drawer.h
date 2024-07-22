#ifndef OBJ_DRAWER_H_
#define OBJ_DRAWER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Vert {
    int v1;
    int v2;
    int v3;
} Vert;

char* read_file_line(FILE *f);
int** parse_line_to_int(char *line);
Vert** load_verts_from_obj_file(FILE *f);
void free_parsed_int(int **parsed_int);

#endif
