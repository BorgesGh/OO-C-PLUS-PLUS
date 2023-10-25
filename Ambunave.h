#pragma once
#include "Mecanico.h"
#include "Terrano.h"
#define cura 50

class Ambunave : public Terrano, public Mecanico {

public:
	Ambunave(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Mecanico(nome, idade, peso, vida, vidaMax, mecanico) {}


	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Aliados.begin();// Iterator apontando para o inicio da fila
		while (it != Aliados.end()) {
			if (!(*it)->getMecanico()) {
				if ((*it)->getVida() + cura >= (*it)->getVidaMax()) {//Controle de exceder o limite de vida
					(*it)->setVida((*it)->getVidaMax());
				}
				else {
					(*it)->setVida((*it)->getVida() + cura);
				}
			}
			it++;
		}

	}
	const char* getClass() override {
		return "Ambunave";
	}

};