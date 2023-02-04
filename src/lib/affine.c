#include "core.h"

void translate_x(mesh *model, float shift) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    model->vertices[i].x += shift;
  }
}

void translate_y(mesh *model, float shift) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    model->vertices[i].y += shift;
  }
}

void translate_z(mesh *model, float shift) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    model->vertices[i].z += shift;
  }
}

void scale(mesh *model, float scale) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    model->vertices[i].x *= scale;
    model->vertices[i].y *= scale;
    model->vertices[i].z *= scale;
  }
}

void rotate_ox(mesh *model, float alpha) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    float y = model->vertices[i].y;
    float z = model->vertices[i].z;
    model->vertices[i].y = y * cos(alpha) - z * sin(alpha);
    model->vertices[i].z = z * cos(alpha) + y * sin(alpha);
  }
}

void rotate_oy(mesh *model, float alpha) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    float x = model->vertices[i].x;
    float z = model->vertices[i].z;
    model->vertices[i].x = x * cos(alpha) - z * sin(alpha);
    model->vertices[i].z = z * cos(alpha) + x * sin(alpha);
  }
}

void rotate_oz(mesh *model, float alpha) {
  for (unsigned int i = 0; i < model->count_vertices; i++) {
    float x = model->vertices[i].x;
    float y = model->vertices[i].y;
    model->vertices[i].x = x * cos(alpha) - y * sin(alpha);
    model->vertices[i].y = y * cos(alpha) + x * sin(alpha);
  }
}

