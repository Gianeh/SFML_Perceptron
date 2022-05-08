#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Line.h"

using namespace sf;

struct point {
			int x, y;
			int bias;
			int label;
			CircleShape body;
		};

class TrainingPoints
{
	private:
		point* points;
		int number;
		RenderWindow* screen;
		int rad;
		Line division;

	public:
		TrainingPoints(unsigned int num = 1, RenderWindow* s = nullptr, int _rad = 10);
		~TrainingPoints();
		point getPoint(int i);
		void setFunction(float m, float q);
		int len();
		int radius();
		void show();
};