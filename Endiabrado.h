#pragma once
#include "Terrano.h"
#include "Mecanico.h"
#define danoInicial 15

class Endiabrado : public Terrano, public Mecanico {
public:
	Endiabrado(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Mecanico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		int contador = 0;
		int decremento = 0;
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		while (contador != 3 && it != Inimigos.end()) {
			(*it)->setVida((*it)->getVida() - (danoInicial - decremento));
            Guerreiro::estourarBulbos(*it);
			contador++;
			decremento += 5;
			it++;

		}

	}
	const char* getClass() override {
		return "Endiabrado";
	}
};