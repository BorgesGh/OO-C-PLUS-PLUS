#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Random {
public:
	static int randInt(int max) {
        std::srand(std::time(nullptr));

        int numero_aleatorio = (std::rand());
        int result = (int)numero_aleatorio % max;
        return  result;

	}
	static int randBinarie() {
		//Retorna um valor aleatório 1 ou 0
		unsigned seed = time(0);
		srand(seed);
		return (int)((rand() % 2));
	}
};