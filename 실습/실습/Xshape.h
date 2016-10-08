#pragma once
#include "geomet.h"

void drawXshape(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);

class Xshape : public Geomet {

public:
	int start_x, start_y;
	int end_x, end_y;
	/*int mid_x, mid_y;
	int mid_r;
*/
	Xshape(const int& s_x, const int& s_y, const int& e_x, const int& e_y) {
		initialize(s_x, s_y, e_x, e_y);
	}
	void initialize(const int& s_x, const int& s_y, const int& e_x, const int& e_y);

	void draw();
};