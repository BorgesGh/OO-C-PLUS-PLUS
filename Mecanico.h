#pragma once
#include "Guerreiro.h"
class Mecanico :public Guerreiro {
	//A classe atualmente est� vazia....
	//Entretanto est� disponivel para possiveis altera��es futuras
	//Caso a classe mec�nico precise de implementa��o
public:
	Mecanico(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Guerreiro(nome, idade, peso, vida, vidaMax, mecanico) {}
};