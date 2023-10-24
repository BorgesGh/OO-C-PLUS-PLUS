#pragma once
#include "Organico.h"
#include "Terrano.h"
#define danoSoldado 20

class Soldado : public Terrano, public Organico {
public:
	Soldado(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}
	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		(*it)->setVida((*it)->getVida() - danoSoldado);

	}
	const char* getClass() override {
		return "Soldado";
	}
};