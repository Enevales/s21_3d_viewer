
#ifndef CORE_H_
#define CORE_H_

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DIM 3 // dimension 

typedef struct vertex_t {
  int x;
  int y;
  int z;
}vertex;

typedef struct polygon_t {
  unsigned int count_edges;
  int vertices[];
}polygon;

typedef struct mesh_t {
  unsigned int count_vertices;
  unsigned int count_polygons;
  vertex *vertices;
  polygon *polygons;
}mesh;

#endif  // CORE_H