#pragma once
#include "geomet.h"

void drawCircle(const int&r, const int& i0, const int& j0, const float& red, const float& green, const float& blue);

class Circle : public Geomet {

public:
	int start_x, start_y;
	int r;
	/*int mid_x, mid_y;
	int mid_r;
*/
	Circle(const int& _r, const int& s_x, const int& s_y) {
		initialize(_r, s_x, s_y);
	}

	void initialize(const int& _r, const int& s_x, const int& s_y);

	void draw();
};