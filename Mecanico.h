#pragma once
#include "Guerreiro.h"
class Mecanico :public Guerreiro {
	//A classe atualmente está vazia....
	//Entretanto está disponivel para possiveis alterações futuras
	//Caso a classe mecânico precise de implementação
public:
	Mecanico(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Guerreiro(nome, idade, peso, vida, vidaMax, mecanico) {}
};