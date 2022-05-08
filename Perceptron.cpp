#include "Perceptron.h"
#include <random>
#include <ctime>



Perceptron::Perceptron(unsigned int n, double lr) {
	//dynamic allocation of pointers based on arguments
	w_len = n;
	weights = new float[w_len];
	learn_rate = lr;
	srand(time(0));

	//Random weights init
	for (int i = 0; i < w_len; i++) {		//divide float(rand()) by rand() to obtain a random float then take it's remainder with 1.0 -> (0,1)
		rand() % 2 ? weights[i] = std::remainder(-float(rand())/rand(), 1.0) : weights[i] = std::remainder(float(rand()) / rand(), 1.0);
	}//50% randomness for the sign					//positive (0,1)						//negative (-1,0)
}
Perceptron::~Perceptron(){
	if(weights != nullptr){
		delete[] weights;
		std::cerr << std::endl << "Burnt brain" << std::endl;
	}
}
void Perceptron::randWeights() {
	for (int i = 0; i < w_len; i++) {		//divide float(rand()) by rand() to obtain a random float then take it's remainder with 1.0 -> (0,1)
		rand() % 2 ? weights[i] = std::remainder(-float(rand()) / rand(), 1.0) : weights[i] = std::remainder(float(rand()) / rand(), 1.0);
	}//50% randomness for the sign					//positive (0,1)						//negative (-1,0)
}

int Perceptron::guess(Input* input) {
	if (w_len != input->len()) {
		std::cout << "\nWrong Input size, doesn't correspond to weights lenght -> return 0" << std::endl;
		return 0;
	}
	float sum = 0;
	for (int i = 0; i < w_len; i++) {
		sum += weights[i] * input->getValue(i);
	}
	int guess = 0;
	sum >= 0 ? guess = 1 : guess = -1; //sign(sum) but if zero --> positive
	return guess;
	
}

void Perceptron::showWeights() {
	for (int i = 0; i < w_len; i++) {
		std::cout << "\nW[" << i << "] = " << weights[i];
	}
}

void Perceptron::train(Input* input, int label) {
	if (w_len != input->len()) {
		std::cout << "\nWrong Input size, doesn't correspond to weights lenght -> return" << std::endl;
		return;
	}
	int temp_guess = guess(input);
	int error = label - temp_guess;

	//temporaneus monitor for weights correction
	if(error == 0) std::cout << std::endl << "Error is: 0!" << std::endl;
	else std::cout << std::endl << "Error is: " << error << std::endl;

	for (int i = 0; i < w_len; i++) {
		weights[i] += error * input->getValue(i) * learn_rate;
	}
}