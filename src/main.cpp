#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <random>

using namespace std;

// GLOBAL VARIABLES
int _initWindowWidth = 500;
int _initWindowHeight = 500;
bool _spin = false;
float _angle = 0.0f;
float _boxAngleX = 0.0f;
float _boxAngleY = 0.0f;
float pi = 3.1415;

int scene = 1;

void initialize(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Initialize Window
    glutInitWindowSize(_initWindowWidth,_initWindowHeight);
    glutCreateWindow("Opengl");

    // Enables
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR);
}

void drawWindow(int w, int h) {
    // Set perspective
	glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        (double)w/(double)h,
        1.0f,
        100.0f
    );
}
void idleFunc() {
    glutPostRedisplay();
}

void scene1();
void scene2();
void scene3();

void initScene() {
    // Clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set drawing mode
    glMatrixMode(GL_MODELVIEW);

    // Draw scene
    switch (scene) {
        case 1: scene1(); break;
        case 3: scene3(); break;
    }

    glutSwapBuffers();
}

void key1(unsigned char key, int x, int y);
void key2(unsigned char key, int x, int y);
void key3(unsigned char key, int x, int y);

void handleKeypress(unsigned char key, int x, int y) {
    switch (scene) {
        case 1: key1(key,x,y); break;
        case 3: key3(key,x,y); break;
    }
}

int main(int argc, char** argv) {
    initialize(argc, argv);

    glutDisplayFunc(initScene);
    glutReshapeFunc(drawWindow);
    glutKeyboardFunc(handleKeypress);
    glutIdleFunc(idleFunc);

    glutMainLoop();
return 0;
}

void key1(unsigned char key, int x, int y) {
    switch (key) {
        case 'q': exit(0); break;
        case 'a': _boxAngleY += 2.0f; break;
        case 'd': _boxAngleY -= 2.0f; break;
        case 'w': _boxAngleX += 2.0f; break;
        case 's': _boxAngleX -= 2.0f; break;
        case 'z': scene = 1; break;
        case 'c': scene = 3; break;
    }
}

void scene1() {
    // Reset transformation matrix
    glLoadIdentity();
    float BOX_SIZE = 3.f;

    glTranslatef(0.0f,0.0f,-10.0f);
    glRotatef(-_boxAngleX,1.0f,0.0f,0.0f);
    glRotatef(-_boxAngleY,0.0f,1.0f,0.0f);
	glBegin(GL_QUADS);
        //Top face
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);

        //Bottom face
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

        //Left face
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);

        //Right face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

        //Front face
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);

        //Back face
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
        glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);

	glEnd();

}

void key3(unsigned char key, int x, int y) {
    switch (key) {
        case 'q': exit(0); break;
        case 'a': _boxAngleY += 2.0f; break;
        case 'd': _boxAngleY -= 2.0f; break;
        case 'w': _boxAngleX += 2.0f; break;
        case 's': _boxAngleX -= 2.0f; break;
        case 'z': scene = 1; break;
        case 'c': scene = 3; break;
    }
}

void scene3() {
    int i;
    int n = 10;
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-10.0f);

    glBegin(GL_TRIANGLES);
        glPushMatrix();
        glScalef(3.0f,3.0f,1.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(cos(pi/2),sin(pi/2),1.0f);
        glVertex3f(cos(7*pi/6),sin(7*pi/6),1.0f);
        glVertex3f(cos(-pi/6),sin(-pi/6),1.0f);
        glPopMatrix();
    glEnd();
}
