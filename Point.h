#ifndef POINT_H
#define POINT_H
#include "glut.h"
class Point {
private:
	float valueX, valueY;
public:
	Point() :valueX(0.0), valueY(0.0) {}
	Point(float x, float y) : valueX(x), valueY(y) {}

	void setX(float x);
	void setY(float y);

	float getX();
	float getY();

	void draw();
	void print();
};

#endif