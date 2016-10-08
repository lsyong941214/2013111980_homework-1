#include "Circle.h"

void Circle::initialize(const int& _r, const int& s_x, const int& s_y) {
	start_x = s_x;
	start_y = s_y;
	r = _r;
}

void Circle::draw() {
	drawCircle(r, start_x, start_y, 0.0f, 0.0f, 0.0f);
}