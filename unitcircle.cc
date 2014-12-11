// The following piece of software has been built upon
// the original project made by hzeller
// https://github.com/hzeller/rpi-rgb-led-matrix/
//
// Copyright (C) 2014 Timothy Roe, Jr. & Roeboat, LLC.
//
// --Code Starts Below this Line--

#include "led-matrix.h"
#include <unistd.h>
#include <math.h>
#include <stdio.h>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

static void DrawOnCanvas(Canvas *canvas) {
	//Builds the circle on RGB matrix
	int center_x = canvas->width()/2;
	int center_y = canvas->height()/2;
	float radius_max = canvas->width()/2;
	float angle/step = 1.0/360;
	for (float a = 0, r = 0; r < radius_max; a += angle_step, r += angle_step) {
		float dot_x = cos(a*2*M_PI) * r;
		float dot_y = sin(a*2*M_PI) * r;
		canvas->SetPixel(Center_x + dox_x, center_y + dot_y, 255, 0, 0);
		usleep(1*1000); //slow down process
	}
	
}

static void DrawCenterLine(Canvas *canvas) {
	const int width = canvas()->width();
	const int height = canvas()->height();
	for (int x = 0; x < width; x++) {
		canvas()->SetPixel(x, height/2, 0, 255, 0, 0);
	}
	for (int y = 0; y < height; y++) {
		canvas()->SetPixel(width/2, y, 0, 255, 0);
	}
	
}

int main(int argc, char *argv[]) {
	GPIO io;
	if (!io.Init())
		return 1;
		
	int rows = 32;
	int chain = 1;
	Canvas *canvas = new RGBMatrix(&io, rows, chain);
	
	DrawOnCanvas(canvas);
	DrawCenterLines(canvas);
	
	if (as_daemon) {
		printf("Press <RETURN> to Reset LEDs \n");
		getchar();
	}
	canvas->Clear();
	delete canvas;
	return 0;
	
}
