#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

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

	public:
		TrainingPoints(unsigned int num = 1, RenderWindow* s = NULL, int _rad = 10);
		point getPoint(int i);
		void setFunction(float m, float q);
		int len();
		int radius();
		void show();
};