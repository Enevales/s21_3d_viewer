#include "core.h"

void draw_vertices(mesh model) {
  double coordinates[model.count_vertices * DIM];
  int j = 0;
  for (int i = 1; i < model.count_vertices + 1; i++) {
    coordinates[j] = model.vertices[i].x;
    j++;
    coordinates[j] = model.vertices[i].y;
    j++;
    coordinates[j] = model.vertices[i].z;
    j++;
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(DIM, GL_DOUBLE, 0, &coordinates);
  glColor3d(0, 0, 3);
  glPointSize(5);
  glDrawArrays(GL_POINTS, 0, model.count_vertices);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void draw_edges() {
        // SAMPLE TRIANGLE
  double lines[] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
                    0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0};

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(DIM, GL_DOUBLE, 0, &lines);
  glColor3d(1, 0, 0);
  glDrawArrays(GL_LINES, 0, 6);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void display() {
  
 /*--------------------  EXAMPLE OF MANUALLY PARSED DATA  --------------------*/ 
  mesh model;
  model.count_vertices = 3;

  model.vertices = calloc(model.count_vertices + 1, sizeof(vertex));

  model.vertices[1].x = 0;
  model.vertices[1].y = 0;
  model.vertices[1].z = 0;
  model.vertices[2].x = 0;
  model.vertices[2].y = 1;
  model.vertices[2].z = 0;
  model.vertices[3].x = 1;
  model.vertices[3].y = 0;
  model.vertices[3].z = 1;

/*-------------------- SHOULD BE REMOVED AFTERWARDS --------------------*/

  glEnable(GL_DEPTH_TEST);
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  draw_vertices(model);
  draw_edges(model);

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Sample");

  glutDisplayFunc(display);

  glutMainLoop();
}
