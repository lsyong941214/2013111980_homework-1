#pragma once
#include "geomet.h"

void drawSquare(const int& edge, const int& i0, const int& j0, const float& red, const float& green, const float& blue);

class Box : public Geomet {

public:
	int start_x, start_y;
	int edge;
	/*int mid_x, mid_y;
	int mid_r;*/

	Box(const int& _edge, const int& s_x, const int& s_y) {
		initialize(_edge, s_x, s_y);
	}

	void initialize(const int& _edge, const int& s_x, const int& s_y);
	void draw();
};