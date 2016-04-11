#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#ifdef _WIN32
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <cstdio>

/* a point data type*/
typedef GLfloat point2[2];
/* initial triangle – global variables */
point2 v[]={{-1.0, -0.58}, {1.0, -0.58},
{0.0, 1.15}};
int n; /* number of recursive steps */

void divide_triangle(point2,point2,point2,int);
void triangle( point2 a, point2 b, point2 c);
void myinit();
void display();

int main(int argc, char **argv)
{
	if (argc<2){
		fprintf(stderr,"usage: 03-Sierpinski-Removing-Triangle <num-iter>\n");
		return 1;
	}

n = atoi(argv[1]);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutCreateWindow("2D Gasket");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
divide_triangle(v[0], v[1], v[2], n);
glFlush();
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
glMatrixMode(GL_MODELVIEW);
glClearColor (1.0, 1.0, 1.0,1.0);
glColor3f(0.0,0.0,0.0);
}
void divide_triangle(point2 a, point2 b, point2 c, int m)
{
/* triangle subdivision using vertex coordinates */
point2 v0, v1, v2;
int j;
if(m>0)
{
for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
divide_triangle(a, v0, v1, m-1);
divide_triangle(c, v1, v2, m-1);
divide_triangle(b, v2, v0, m-1);
}
else(triangle(a,b,c));
/* draw triangle at end of recursion */
}
void triangle( point2 a, point2 b, point2 c)
/* display one triangle */
{
glBegin(GL_TRIANGLES);
glVertex2fv(a);
glVertex2fv(b);
glVertex2fv(c);
glEnd();
}
