#pragma once
#include <iostream>
#include "TrainingPoints.h"
#include "random"
#include <time.h>

//class is mainly needed to dynamically allocate a float vector

class Input
{
	private:
		float* inputs;
		unsigned int i_len;
	public:
		Input(unsigned int m, bool manual = false);
		unsigned int len();
		void load(int i, unsigned int _new);
		float getValue(unsigned int i);
};

