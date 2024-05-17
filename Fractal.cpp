#include "Fractal.h"
#include "stdafx.h"
float x_position = 0.0;
float y_position = 0.0;
float angle = 0.0;
float a = 0;
int state = 0;
const float pi = 3.14159265359;
//std::vector<Point> arr = {Point(0,0)};
std::list<Point> arr = { Point(0,0) };

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//clears to the bg color
	glLoadIdentity();

	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (auto now : arr) {
		glColor3f(rand() % 2, rand() % 2, rand() % 2);
		now.draw();
	}
	glEnd();

	glTranslatef(x_position, y_position, 0);
	glRotatef(angle, 0, 0, 1);

	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1, 1);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glEnd();

	glColor3f(1, 0, 0);
	glPointSize(8);
	glBegin(GL_POINTS);
	glVertex2f(0, 0);
	glEnd();

	/*
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(-1, 1);
	glColor3f(1, 1, 0);
	glVertex2f(-1, -1);
	glColor3f(0, 1, 0);
	glVertex2f(1, -1);
	glColor3f(0, 0, 1);
	glVertex2f(1, 1);
	glEnd();
	*/

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void myInit() {
	glClearColor(1, 1, 1, 0); //sets the bg color
	glColor3f(1, 0, 0); //Sets the current color
	glPointSize(1); //specifies the diameter of rasterized points
	//glMatrixMode(GL_PROJECTION); //create orthohonal 2D coorfdinate
	//glLoadIdentity(); //replaces the current matrix with the identity matrix
	//gluOrtho2D(-500, 500, -500, 500); //defines a 2D orthographic projection matrix
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	switch (state) {
	case 1:
		if (a > -180) {
			a -= 0.05;
			y_position = (0 - 5 * cos(a));
			x_position = (0 - 5 * sin(a));

			/*arr.push_back(Point(x_position, y_position));
			if (arr.size() > 70) arr.erase(arr.begin());
			angle += 3 * pi;*/
		}
		else
			state = -1;
		break;
	case -1:
		if (a < 180) {
			a += 0.05;
			y_position = (0 - 5 * cos(a));
			x_position = (0 - 5 * sin(a));

			/*arr.push_back(Point(x_position, y_position));
			if (arr.size() > 70) arr.erase(arr.begin());
			angle += 3 * pi;*/
		}
		else
			state = 1;
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		state = 1;
		break;
	case 'w':
		state = 0;
		break;
	case 'e':
		state = -1;
		break;
	}
}