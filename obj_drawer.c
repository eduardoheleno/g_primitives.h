#include "obj_drawer.h"

char* read_file_line(FILE *f) {
    char char_buffer = fgetc(f);
    char *line = NULL;
    size_t line_size = 0;

    if (char_buffer == EOF) {
	return NULL;
    }

    while (char_buffer != '\n' && char_buffer != EOF) {
	line = realloc(line, ++line_size * sizeof(char));
	line[line_size - 1] = char_buffer;

	char_buffer = fgetc(f);
    }
    line = realloc(line, (line_size + 1) * sizeof(char));
    line[line_size] = '\0';

    return line;
}

int** parse_line_to_int(char *line) {
    size_t i = 2;
    size_t index_buffer = i;
    size_t int_size = 0;
    size_t int_index = 0;
    int **parsed_ints = malloc(sizeof(int*) * 3);

    while (line[i] != '\0') {
	while (line[i] != ' ' && line[i] != '\0') {
	    int_size++;
	    i++;
	}

	char c_buffer[int_size + 1];
	strncpy(c_buffer, line + index_buffer, int_size);
	c_buffer[int_size] = '\0';

	parsed_ints[int_index] = malloc(sizeof(atoi(c_buffer)));
	*parsed_ints[int_index] = atoi(c_buffer);

	index_buffer = ++i;
	int_index++;
	int_size = 0;
    }

    return parsed_ints;
}

void free_parsed_verts(int **parsed_verts) {
    for (int i = 0; i < 3; i++) {
	free(parsed_verts[i]);
    }
}

Vert** load_verts_from_obj_file(FILE *f) {
    Vert **verts = NULL;
    size_t verts_counter = 0;

    char *line = read_file_line(f);
    while (line != NULL) {
	if (line[0] == 'v') {
	    int **parsed_verts = parse_line_to_int(line);

	    Vert *v = malloc(sizeof(Vert));
	    v->v1 = *parsed_verts[0] * *parsed_verts[0];
	    v->v2 = *parsed_verts[1] * *parsed_verts[1];
	    v->v3 = *parsed_verts[2] * *parsed_verts[2];

	    verts = realloc(verts, sizeof(Vert*) * ++verts_counter);
	    verts[verts_counter - 1] = v;

	    free_parsed_verts(parsed_verts);
	}

	free(line);
	line = read_file_line(f);
    }
    rewind(f);

    return verts;
}
