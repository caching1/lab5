#include "stdafx.h"
#include "Point.h"

void Point::setX(float x) {
	this->valueX = x;
}
void Point::setY(float y) {
	this->valueY = y;
}

float Point::getX() {
	return this->valueX;
}

float Point::getY() {
	return this->valueY;
}
void Point::print() {
	std::cout << this->valueX << ' ' << this->valueY << std::endl;
}

void Point::draw() {
	glVertex2f(valueX, valueY);
}