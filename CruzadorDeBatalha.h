#pragma once
#include "Terrano.h"
#include "Mecanico.h"
#define danoCruzador 50
class Cruzador : public Terrano, public Mecanico {
private:
	int contadorFeixo;

public:
	Cruzador(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Mecanico(nome, idade, peso, vida, vidaMax, mecanico) {
		contadorFeixo = 0;
		}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		if (contadorFeixo == 2) {
			(*it)->setVida((*it)->getVida() - (*it)->getVida());
            Guerreiro::estourarBulbos(*it);
			contadorFeixo = 0;
		}
		else {
			(*it)->setVida((*it)->getVida() - danoCruzador);
            Guerreiro::estourarBulbos(*it);
			contadorFeixo++;
		}

	}
	const char* getClass() override {
		return "Cruzador";
	}

};