/* This program is a modification of
** Julien Guertault's "Demonstration of vertex array"
** by AceOneWorks (Muhammad Nizami - Erick Chandra - Fathul Asrar Alfansuri)
** See the license below
*/
/* ============================================================================
**
** Demonstration of vertex array
** Copyright (C) 2009  Julien Guertault
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
** ========================================================================= */

#include	<stdlib.h>
#include	<GL/glut.h>
#include	<math.h>

/* One face per line */
GLfloat		vertices[] =
  {
    -1, -1, -1,   -1, -1,  1,   -1,  1,  1,   -1,  1, -1,
     1, -1, -1,    1, -1,  1,    1,  1,  1,    1,  1, -1,
    -1, -1, -1,   -1, -1,  1,    1, -1,  1,    1, -1, -1,
    -1,  1, -1,   -1,  1,  1,    1,  1,  1,    1,  1, -1,
    -1, -1, -1,   -1,  1, -1,    1,  1, -1,    1, -1, -1,
    -1, -1,  1,   -1,  1,  1,    1,  1,  1,    1, -1,  1
  };

GLfloat		colors[] =
  {
    1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,
    0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,
    0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,
    1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0,
    0, 1, 1,   0, 1, 1,   0, 1, 1,   0, 1, 1,   
    1, 0, 1,   1, 0, 1,   1, 0, 1,   1, 0, 1,
  };

/*
** Function called to update rendering
*/
void		DisplayFunc(void)
{
  static float alpha = 30;

  /* Clear the buffer, clear the matrix */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  /* A step backward, then spin the cube */
  glTranslatef(0, 0, -10);
  glRotatef(30, 1, 0, 0);
  glRotatef(alpha, 0, 1, 0);
  glRotatef(alpha, 0, 0, 1);

  /* We have a color array and a vertex array */
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColorPointer(3, GL_FLOAT, 0, colors);

  /* Send data : 24 vertices */
  glDrawArrays(GL_QUADS, 0, 24);

  /* Cleanup states */
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);


  /* Rotate a bit more */
  alpha = alpha + 0.1;

  /* End */
  glFlush();
  glutSwapBuffers();

  /* Update again and again */
  glutPostRedisplay();
}

/*
** Function called when the window is created or resized
*/
void		ReshapeFunc(int width, int height)
{
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  gluPerspective(20, width / (float) height, 5, 15);
  glViewport(0, 0, width, height);

  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

/*
** Function called when a key is hit
*/
void		KeyboardFunc(unsigned char key, int x, int y)
{
  int foo;

  foo = x + y; /* Has no effect: just to avoid a warning */
  if ('q' == key || 'Q' == key || 27 == key)
      exit(0);
}


int		main(int argc, char **argv)
{
  /* Creation of the window */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Spinning cube");

  /* OpenGL settings */
  glClearColor(0, 0, 0, 0);
  glEnable(GL_DEPTH_TEST);

  /* Declaration of the callbacks */
  glutDisplayFunc(&DisplayFunc);
  glutReshapeFunc(&ReshapeFunc);
  glutKeyboardFunc(&KeyboardFunc);

  /* Loop */
  glutMainLoop();

  /* Never reached */
  return 0;
}

/* ========================================================================= */
