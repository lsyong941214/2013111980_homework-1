#include "triangle.h"

void triangle::initialize(const int& s_x, const int& s_y, const int& e_x, const int& e_y) {
	start_x = s_x;
	start_y = s_y;
	end_x = e_x;
	end_y = e_y;
}

void triangle::draw() {
	drawtriangle(start_x, start_y, 0.0f, 0.0f, 0.0f);
}