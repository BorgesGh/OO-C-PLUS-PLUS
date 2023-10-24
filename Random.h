#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Random {
public:
	static int randInt(int max) {
		unsigned seed = time(0);
		srand(seed);
		return 1 + ((int)(rand() % max)); //1 a max

	}
	static int randBinarie() {
		//Retorna um valor aleatório 1 ou 0
		unsigned seed = time(0);
		srand(seed);
		return (int)((rand() % 2));
	}
};