#pragma once
#include <iostream>
#include "Input.h"


class Perceptron
{
private:
	float* weights;
	unsigned int w_len;
	float learn_rate;
public:
	Perceptron(unsigned int n, double lr = 0);
	void randWeights();
	int guess(Input input);
	void showWeights();
	void train(Input input, int label);
};

