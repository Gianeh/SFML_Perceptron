#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;
//not the most precisce line ever, but an efficient RectangleShap-ed model that easily apply
class Line
{
	private:
		int x1, y1, x2, y2;
		float thickness, length;
		float slope;
		std::string color;
		RectangleShape lin;

	public:
		Line(int x1_, int y1_, int x2_, int y2_, std::string color = "", float thick = 2.0);
		RectangleShape line();
};

