#include "core.h"

void initialize_mesh(char *filename, mesh *model){
    model->count_vertices = 0;
    model->count_polygons = 0;

    FILE *pf = fopen(filename, "r");  

    char *line = NULL;
    size_t len = 0;
    
	while (getline(&line, &len, pf) != -1){
		if (line[0] == 'v'){
            model->count_vertices++;
		} 
        if (line[0] == 'f'){
            model->count_polygons++;
		}
	}
    model->vertices = calloc(model->count_vertices + 1, sizeof(vertex));
    model->polygons = calloc(model->count_polygons + 1, sizeof(polygon) + sizeof(int *));
    free(line);
    fclose(pf);
}

mesh load_object_file(char *filename){
	
    FILE *pf = fopen(filename, "r");  
    if (!pf) exit(EXIT_FAILURE);

    mesh model;
    initialize_mesh(filename, &model);
    
    unsigned int vertices = model.count_vertices;
    unsigned int polygons = model.count_polygons;
    
    char *line = NULL;
    size_t len = 0;
    char *ptr = NULL;
	while (getline(&line, &len, pf) != -1){
		char junk;
		if (line[0] == 'v'){
            vertices++;
		} 
        if (line[0] == 'f'){
            polygons++;
		}
	}
    // free mesh
    free(line);
    fclose(pf);
    return model;
}