#include "Box.h"

void Box :: initialize(const int& _edge, const int& s_x, const int& s_y) {
	start_x = s_x;
	start_y = s_y;
	edge = _edge;
}

void Box::draw() {
	drawSquare(edge, start_x, start_y, 0.0f, 0.0f, 0.0f);
}