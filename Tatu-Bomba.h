#pragma once
#include "Organico.h"
#include "Zerg.h"
#define danoTatu 100
class TatuBomba : public Zerg,public Organico {
public:
	TatuBomba(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		(*it)->setVida((*it)->getVida() - danoTatu);
		this->setVida(0);

	}
	const char* getClass() override {
		return "TatuBomba";
	}
};