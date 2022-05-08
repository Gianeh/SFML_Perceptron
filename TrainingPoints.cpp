#include "TrainingPoints.h"
#include <random>
#include <ctime>

//sets by default the function to x > y, use setFunction(m,q)
TrainingPoints::TrainingPoints(unsigned int num, RenderWindow* s, int _rad) {
	number = num;
	points = new point[number];
	rad = _rad;
	srand(time(0));
	screen = s;
	division.setStart(0,0);
	division.setLen(screen->getSize().x); //set Line::length -> diagonal of screen
	division.setEnd(screen->getSize().x, screen->getSize().y);
	division.setSlope();
	division.resetPosition();
	if(screen != nullptr){
		for (int i = 0; i < number; i++) {
			points[i].bias = 1;
			points[i].body.setRadius(rad);
			points[i].x = rand() % int(screen->getSize().x);
			points[i].y = rand() % int(screen->getSize().y);
			//sets the label x > y
			points[i].x > points[i].y ? points[i].label = 1 : points[i].label = -1;
		}
	}
	else {
		std::cout << "\nNull screen pointer received as argument, return"; return;
	}
	
	
}
TrainingPoints::~TrainingPoints(){
	if(points != nullptr){
		delete[] points;
		std::cerr << std::endl << "Burnt trainset" << std::endl;
	}
}
point TrainingPoints::getPoint(int i) {
	return points[i];
}

//RETURN THE Y VALUE BASED ON M AND Q
int f(int x, float m, float q){
	return m * x + q;
}
void TrainingPoints::setFunction(float m, float q){
	for(int i = 0; i < number; i++){
		points[i].y > f(points[i].x,m,q) ? points[i].label = 1 : points[i].label = -1;
		
	}
	//RESETS THE DIVISION LINE BASED ON FUNCTION
	division.setStart(0,f(0, m, q));
	division.setEnd(screen->getSize().x, f(screen->getSize().x, m, q));
	division.setSlope();
	division.resetPosition();
}

int TrainingPoints::radius() {
	return rad;
}

int TrainingPoints::len() {
	return number;
}

void TrainingPoints::show() {
	if (screen == nullptr) return;
	for (int i = 0; i < number; i++) {
		points[i].label == 1 ? points[i].body.setFillColor(Color::Black) : points[i].body.setFillColor(Color::White);
		points[i].body.setPosition(Vector2f(points[i].x, points[i].y));
		screen->draw(points[i].body);
	}
	screen->draw(division.line());
}