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
		Line();
		Line(int x1_, int y1_, int x2_, int y2_, std::string color = "", float thick = 2.0);
		void resetPosition();
		void setLen(int size);
		void setStart(int x1_ , int y1_);
		void setEnd(int x2_ , int y2_); //SETS A MID (OR END) POINT TO SET THE SLOPE
		void setSlope();
		void update(int x1_, int y1_, int point = 1);
		void control(int speed);
		RectangleShape line();
};

