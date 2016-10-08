#include <iostream>
#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include "Line.h"
#include "Box.h"
#include "Circle.h"
#include "Ashape.h"
#include "Xshape.h"
#include "leftpoint.h"
#include "rightpoint.h"
#include "uppoint.h"
#include "downpoint.h"
#include "triangle.h"

void arroundCircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue, GLFWwindow *window);
void drawSquare_2(const int& edge, const int& i0, const int& j0, const float& red, const float& green, const float& blue, GLFWwindow *window);

GLFWwindow* window;

Geomet **my_object = new Geomet*[20];
//delete [] my_lines;

const int width = 1000;
const int height = 280;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i0 == i1) {
		for (int j = j0; j < j1; j++)
			drawPixel(i0, j, red, green, blue);
		return;
	}
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawLine_2(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawSquare_2(70, i0-10, j0-10, 0.0f, 0.0f, 1.0f,window);
	/*arroundCircle(i0 + 25, j0 + 25, 1.0f, 0.0f, 0.0f, window);*/
}

void drawSquare(const int& edge, const int& i0, const int& j0,const float& red, const float& green, const float& blue)
{
		drawLine(i0, j0, i0+edge, j0, 0.0f, 0.0f, 0.0f);
		drawLine(i0 + edge, j0, i0 + edge, j0 + edge, 0.0f, 0.0f, 0.0f);
		drawLine(i0, j0 + edge, i0+edge, j0 + edge, 0.0f, 0.0f, 0.0f);
		drawLine(i0, j0, i0, j0 + edge, 0.0f, 0.0f, 0.0f);
		/*arroundCircle(i0 + 25, j0 + 25, 1.0f, 0.0f, 0.0f, window);*/
		drawSquare_2(70, i0-10, j0-10, 0.0f, 0.0f, 1.0f,window);

}
void drawSquare_2(const int& edge, const int& i0, const int& j0, const float& red, const float& green, const float& blue, GLFWwindow *window)
{
	
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	ypos = height - ypos - 1;
	if (xpos <= i0 + edge && xpos >= i0 && ypos <= j0 + edge && ypos >= j0) {
		drawLine(i0, j0, i0 + edge, j0, 1.0f, 0.0f, 0.0f);
		drawLine(i0 + edge, j0, i0 + edge, j0 + edge, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0 + edge, i0 + edge, j0 + edge, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0, i0, j0 + edge, 1.0f, 0.0f, 0.0f);
	}
	else {
		drawLine(i0, j0, i0 + edge, j0, 0.0f, 0.0f, 1.0f);
		drawLine(i0 + edge, j0, i0 + edge, j0 + edge, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0 + edge, i0 + edge, j0 + edge, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0, i0, j0 + edge, 0.0f, 0.0f, 1.0f);

	}

	

}

void drawCircle(const int&r, const int& i0, const int& j0, const float& red, const float& green, const float& blue) {

	for (int i = i0 - r; i < i0 + r; i++) {
		for (int j = j0 - r; j < j0 + r; j++) {
			int n = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 1)*(r - 1) + 2 * r - 1;
			int n2 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 2)*(r - 2) + 4 * r - 4;
			if (n < 0 && n2>0) {
				drawPixel(i, j, 0.0f, 0.0f, 0.0f);
			}
		}
	}
	/*arroundCircle(i0, j0, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 35, j0 - 35, 0.0f, 0.0f, 1.0f,window);

}

void drawAshape(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j0+1, i1, j1+1, 0.0f, 0.0f, 0.0f);
	drawLine(i1, j1, i1+25, j0, 0.0f, 0.0f, 0.0f);
	drawLine(i1, j1+1, i1 + 25, j0+1, 0.0f, 0.0f, 0.0f);
	drawLine(i0+10, j0+20, i0+40, j0+20, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0+25, j0+20, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 10, j0 - 10, 0.0f, 0.0f, 1.0f,window);


}
void drawXshape(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j0+1, i1, j1+1, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j1, i1, j0, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j1+1, i1, j0+1, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0+25, j0+25, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 10, j0 - 10, 0.0f, 0.0f, 1.0f,window);

}
void drawleftpoint(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j0, i0+25, j0+25, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j0, i0 + 25, j0 - 25, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0 + 25, j0, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0-10, j1-35, 0.0f, 0.0f, 1.0f,window);

}
void drawrightpoint(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i1-25, j1+25, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i1-25, j1-25, i1, j1, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0 + 25, j0, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 10, j1 - 35, 0.0f, 0.0f, 1.0f,window);

}
void drawuppoint(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i0, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0 - 25, j1-25, i0, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j1, i0+25, j1-25, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0, j0+25, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 35, j0 - 10, 0.0f, 0.0f, 1.0f,window);

}
void drawdownpoint(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
	drawLine(i1 - 25, j0+25, i1, j0, 0.0f, 0.0f, 0.0f);
	drawLine(i1, j0, i1+25, j0+25, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0, j0 + 25, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 35, j0 - 10, 0.0f, 0.0f, 1.0f,window);

}

void drawtriangle(const int& i0, const int& j0, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i0+50, j0, 0.0f, 0.0f, 0.0f);
	drawLine(i0, j0, i0+25, j0+50, 0.0f, 0.0f, 0.0f);
	drawLine(i0+25, j0+50, i0+50, j0, 0.0f, 0.0f, 0.0f);
	/*arroundCircle(i0+25, j0 + 25, 1.0f, 0.0f, 0.0f, window);*/
	drawSquare_2(70, i0 - 10, j0 - 10, 0.0f, 0.0f, 1.0f,window);

}
void arroundCircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue, GLFWwindow *window) {
	int r = 40;
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	ypos = height - ypos - 1;
	int n3 = (xpos - i0)*(xpos - i0) + (ypos - j0)*(ypos - j0) - r*r;
	
		for (int i = i0 - r; i < i0 + r; i++) {
			for (int j = j0 - r; j < j0 + r; j++) {
				int n = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;
				int n2 = (i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 1)*(r - 1) + 2 * r - 1;
				if (n < 0 && n2>0) {
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
					if (n3 < 0)
						drawPixel(i, j, 0.0f, 0.0f, 1.0f);
				}
			}
		}
}

void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
	for (int i = 0; i < 20; i++) {
		my_object[i]->draw();
	}

	//TODO: try moving object
}

int main(void)
{

		for (int i = 0; i < 10; i++) {
			if (i < 2) {
				my_object[i] = new Line(30 + 85 * i, 30, 80 + 85*i, 80);
			}
			else if (i >= 2 && i < 4)
				my_object[i] = new Box(50, 40+85 * i, 30);

			else if (i >= 4 && i < 6)

				my_object[i] = new Circle(25, 80+85* i, 52);

			else if (i >= 6 && i < 8)

				my_object[i] = new Ashape(50 + 90 * i, 30, 75 + 90 * i, 80);

			else if (i >= 8 && i < 10)
				my_object[i] = new triangle(50 + 90 * i, 30, 75 + 90 * i, 80);
		}
		for (int j = 0; j < 10; j++) {
		if (j<2)
			my_object[j+10] = new Xshape(30 + 85 * j, 200, 80 + 85 * j, 250);
			
		else if (j >= 2 && j < 4)
			my_object[j + 10] = new leftpoint(30 + 90 * j, 225, 80 + 90 * j, 225);

		else if (j >= 4 && j < 6)
			my_object[j + 10] = new rightpoint(30 + 90 * j, 225, 80 + 90 * j, 225);
			
		else if (j >= 6 && j < 8)
			my_object[j + 10] = new uppoint(30 + 95 * j, 200, 30 + 95 * j, 250);

		else if (j >= 8 && j < 10)
			my_object[j + 10] = new downpoint(30 + 95 * j, 200, 30 + 95 * j, 250);
			
		}

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}