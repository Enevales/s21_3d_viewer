
#ifndef CORE_H_
#define CORE_H_

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DIM 3 // dimension 

typedef struct vertex_t {
  unsigned int x;
  unsigned int y;
  unsigned int z;
}vertex;

typedef struct polygon_t {
  int *vertices;
  int count_edges;
}polygon;

typedef struct mesh_t {
  int count_vertices;
  int count_polygons;
  vertex * vertices;
  polygon*polygons;
}mesh;

#endif  // CORE_H