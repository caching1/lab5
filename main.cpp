#include "stdafx.h"
void main(int argc, char** argv) {
	glutInit(&argc, argv); //initializes the GLUT library
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //sets the initial display mode
	glutInitWindowSize(1000, 1000); //sets the initial window size
	glutCreateWindow("PascalTriangle"); //creates a top-level window
	glutDisplayFunc(myDisplay); //sets the display callback for the current window
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, timer, 0);
	myInit();
	glutMainLoop(); //enters the GLUT event processing loop
}