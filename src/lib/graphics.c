#include "core.h"

void draw_vertices(float *coordinates, mesh model) {


  glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(DIM, GL_FLOAT, 0, coordinates);
    glColor3d(0, 0, 1);
    glPointSize(5);
    glDrawArrays(GL_POINTS, 0, model.count_vertices);
  glDisableClientState(GL_VERTEX_ARRAY);

}

void draw_edges(float *vertices, mesh model) {
  unsigned int *indices = calloc(model.count_edges*2 , sizeof(int));
  int l = 0;
  for (int i = 0; i < model.count_polygons ;i++){
    for (int k = 0; k < model.polygons[i].num_of_edges; k++){
      indices[l] = model.polygons[i].vertices[k];
      l++;
    }
  }

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3, GL_FLOAT, 0, vertices);


glDrawElements(GL_LINES, model.count_edges*2, GL_UNSIGNED_INT, indices);


glDisableClientState(GL_VERTEX_ARRAY);
}

void display() {
  
  const char *filename = "samples/monkey_3_points_in_polygon.obj";
  mesh model;
  parser(filename, &model);


  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);


    char projectionMode = 0;
    int max = 1;
  GLdouble Near = 0.1;  
  GLdouble Far = 10;

  if (projectionMode == 0) { 

    GLdouble fov = 65;
    GLdouble height = tan(fov / 360 * M_PI) * Near;
    GLdouble width = height;

    glFrustum(-width , width , -height, height, Near, Far);
    glTranslatef(0, 0, -1);
  } else {
    glOrtho(-1, 1, -1, 1, -1, Far);
  }
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
  scale(&model, 0.4);
  rotate_oy(&model, 0.2);
  rotate_ox(&model, 0.75);

  
  float *coordinates = calloc((model.count_vertices * DIM)+3, sizeof(float));
  int j = 3;
  for (int i = 0; i < model.count_vertices; i++) {
    coordinates[j] = model.vertices[i].x;
    j++;
    coordinates[j] = model.vertices[i].y;
    j++;
    coordinates[j] = model.vertices[i].z;
    j++;
  }
  draw_vertices(coordinates, model);
  draw_edges(coordinates, model);

  glFlush();
}

int main(int argc, char** argv) {
 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(640, 640);
  glutCreateWindow("Sample");
  glutDisplayFunc(display);

  glutMainLoop();  char k;
}