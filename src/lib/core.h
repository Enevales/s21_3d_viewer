
#ifndef CORE_H_
#define CORE_H_


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define DIM 3
#define M_PI 3.14159265358979323846
#define STRING_BUFFER 10000

typedef struct vertex_t {
  float x;
  float y;
  float z;
}vertex;

typedef struct polygon_t {
  unsigned int num_of_edges;
  int *vertices; //indices
}polygon;

typedef struct mesh_t {
  int     is_valid_file;
  int     count_vertices;
  int     count_polygons;
  int     count_edges; 
  vertex  *vertices;
  polygon *polygons;
}mesh;



typedef struct parse_info_t {
  int     current_vertex;
  int     current_polygon;
}   parse_info;

typedef struct view_setting {
  char projection_type;
  int bg_red;
  int bg_green;
  int bg_blue;
  int bg_transp;
}view;

typedef struct vertex_setting_t {
  char vertex_type;
  int v_red;
  int v_green;
  int v_blue;
  int vertex_size;
}vertex_setting;

typedef struct edge_setting_t {
  char line_type;
  int l_red;
  int l_green;
  int l_blue;
  int thickness;
}edge_setting;

int parser(const char* filename, mesh *data);

mesh load_object_file(char *filename);
void initialize_mesh(char *filename, mesh *model);

void translate_x(mesh *model, float shift);
void translate_y(mesh *model, float shift);
void translate_z(mesh *model, float shift);

void scale(mesh *model, float scale);

void rotate_ox(mesh *model, float alpha);
void rotate_oy(mesh *model, float alpha);
void rotate_oz(mesh *model, float alpha);

#endif  // CORE_H