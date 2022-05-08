#include "Input.h"

Input::Input(unsigned int m, bool manual) {
	i_len = m;
	inputs = new float[i_len];
	
	if(manual){
		//ask the user to load inputs (floats)
		std::cout << "\nPlease enter your inputs (float) in order: \n";
		for (int i = 0; i < i_len; i++) {
			std::cin >> inputs[i];
			std::cout << std::endl;
		}
	//by deafult (manual = false) loads random inputs
	}else{
		srand(time(0));
		for (int i = 0; i < i_len; i++) {
			inputs[i] = rand();
		}
	}
}
Input::~Input(){
	if(inputs != nullptr){
		delete[] inputs;
		std::cerr << std::endl << "Burnt temp" << std::endl;
	}
}
unsigned int Input::len() {
	return i_len;
}

void Input::load(int i, unsigned int _new) {
	inputs[i] = _new;
}

float Input::getValue(unsigned int i) {
	return inputs[i];
}