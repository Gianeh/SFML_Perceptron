//PERCEPTRON LEARNS TO RECOGNIZE POINTS IN SPACE - INSPIRED BY "THE CODING TRAIN" - WROTE from scratch FOR C++ SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Line.h"
#include "Perceptron.h"
#include "TrainingPoints.h"

using namespace sf;
int main() {

	//MAIN SCREEN SETUP
	unsigned int size = 800;
	RenderWindow screen(VideoMode(size, size), "Perceptron Guess!", Style::Close | Style::Titlebar);
	
	//TRAINING SET, BRAIN & INPUTS SETUP
	unsigned int train_set_size = 500;
	TrainingPoints points(train_set_size, &screen);

	points.setFunction(1,0); //doesn't work with negatives

	Perceptron brain(3, 0.1);	//2 weights, in this case x and y coordinates of training points, + bias and learning rate
	brain.showWeights(); //just prints the random starting weights
	Input temp(3);

	//Reusable point
	CircleShape mark(5);

	//Event object to monitor screen
	Event e;

	//Framerate Limit
	screen.setFramerateLimit(2);

	//Generation counter and learning point 
	int gen = 0;
	int start_train_gen = 3;
	
	//DRAW LOOP
	while (screen.isOpen()) {
		while (screen.pollEvent(e)) {
			if (e.type == e.Closed) screen.close();
		}
		screen.clear(Color::Magenta); //background color

		//draws the training set before applying the "correctness" marks [GREEN,RED]
		points.show();
		
		//GUESS LOOP, EVERY FRAME THE BRAIN MAKES IT'S CHOICE FOR EVERY POINT, IF WAS RIGHT -> MARKS WITH GREEN, RED OTHERWISE
		for (int i = 0; i < train_set_size; i++) {
			//LOAD IN THE TEMPORANEUS INPUT OBJECT
			temp.load(0, points.getPoint(i).x);
			temp.load(1, points.getPoint(i).y);
			temp.load(3, points.getPoint(i).bias);

			//ACTUAL CALL TO TRAIN FUNCTION ONLY HAPPENS AFTER GEN "start_train_gen", UNTILL THEN BRAIN OUTPUTS RANDOMLY ( every single point )
			if(gen >= start_train_gen)  brain.train(&temp, points.getPoint(i).label);

			//BEFORE TRAINING GENERATIONS START THE BRAIN RESETS IT'S WEIGHTS AFTER EVERY POINT
			if (gen < start_train_gen) brain.randWeights();

			int guess = brain.guess(&temp);
			
			//MARK THE CORRECT CHOICE WITH GREEN, WRONG WITH RED
			mark.setPosition(Vector2f(points.getPoint(i).x , points.getPoint(i).y));
			guess == points.getPoint(i).label ? mark.setFillColor(Color::Green) : mark.setFillColor(Color::Red);
				
			screen.draw(mark);
		}
	
		brain.showWeights();
		
		screen.display();
		printf("\nGeneration: %d ", gen); gen++;

		
	}

	return 0;
}