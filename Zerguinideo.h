#pragma once
#include "Organico.h"
#include "Zerg.h"
#define danoZerg 5
class Zergnideo : public Organico, public Zerg {
public:
	Zergnideo(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		(*it)->setVida((*it)->getVida() - danoZerg);

	}
	const char* getClass() override {
		return "Zerguinideo";
	}

};