#include "Line.h"
#define PI 3.1415926535897

Line::Line(int x1_, int y1_, int x2_, int y2_, std::string color, float thick) {
	x1 = x1_; y1 = y1_; x2 = x2_; y2 = y2_;
	thickness = thick;
	length = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	if (x1 < x2){
		slope = atan(abs(y1 - y2) / abs(x1 - x2)) * 180/PI;
	}else if(x1 >= x2 && y1 < y2){
		slope = (atan(abs(y1 - y2) / abs(x1 - x2)) * 180 / PI) + PI;
	}
	lin.setSize(Vector2f(length,thickness));
	lin.setRotation(slope);
	float dx, dy;
	dx = thickness/2 * cos(slope);
	dy = thickness/2 * sin(slope);
	lin.setPosition(x1 + dx , y1 - dy);


	//sets color, if NULL -> black
	if (color == "black" || color == "Black") {
		lin.setFillColor(Color::Black);
	}else if (color == "white" || color == "White") {
		lin.setFillColor(Color::White);
	}else if (color == "green" || color == "Green") {
		lin.setFillColor(Color::Green);
	}else {
		lin.setFillColor(Color::Black);
	}
	
	

}

RectangleShape Line::line() {
	return lin;
}