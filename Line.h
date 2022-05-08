#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;
//not the most precisce line ever, but an efficient RectangleShap-ed model that easily apply
//Inspired from the argument of a complex number --> "rules" from Youmath.it/lezioni/analisi-matematica/numeri-complessi/762-modulo-e-argomento-di-un-numero-complesso.html
class Line
{
	private:
		int x1, y1, x2, y2;
		float thickness, length;
		float slope = 1;
		std::string color;
		RectangleShape lin;

	public:
		Line(int x1_, int y1_, int x2_, int y2_, std::string color = "", float thick = 2.0);
		void update(int x1_, int y1_, int point = 1);
		void control(int speed);
		RectangleShape line();
};

