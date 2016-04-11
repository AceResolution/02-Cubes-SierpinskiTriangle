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

#include <cstdlib>

class Point{
	public:
	Point();
	Point(float x, float y);
	float x;
	float y;
	Point operator+(const Point& rhs);
	Point operator/(const float& divisor);
};
#include <cstdio>
int iter = 1000;
void drawSierpinski()
{

	// Set every pixel in the frame buffer to the current clear color.
	glClear(GL_COLOR_BUFFER_BIT);

	//algoritma: https://en.wikipedia.org/wiki/Sierpinski_triangle#Chaos_game
	const Point p[3] = {
		Point(-1,-1),
		Point(0,1),
		Point(1,-1)
	};

	int r = rand()%3;
	Point v(p[r]);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS); 
	for (int i=0; i<iter; i++){
		glVertex2f(v.x, v.y);
		r = rand()%3;
		v=(v+p[r])/2;		
	}
	glEnd();
	glFlush();
	printf("drawing done\n");
}

int main(int argc, char **argv)
{
	if (argc<2){
		fprintf(stderr,"usage: 02-Sierpinski-Chaos <num-iter>");
		return 1;
	}
	iter = atoi(argv[1]);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL - Sierpinski");
	glutDisplayFunc(drawSierpinski);
	glutMainLoop();
	return 0;
}


Point::Point(){};
Point::Point(float _x, float _y):x(_x),y(_y){};

Point Point::operator+(const Point& rhs){
	return Point(x+rhs.x,y+rhs.y);	
}

Point Point::operator/(const float& divisor){
	return Point(x/divisor,y/divisor);
}
