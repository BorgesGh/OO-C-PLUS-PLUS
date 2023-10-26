#pragma once
#include "Tipos/Proton/Proton.h"
#include "ClassesBase/Mecanico.h"
#define danoColosso 20
class Colosso :public Proton, public Mecanico {

public:
	Colosso(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Mecanico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator inimigo;
		inimigo = Inimigos.begin();

		while (inimigo != Inimigos.end()) {
			(*inimigo)->setVida((*inimigo)->getVida() - danoColosso);
            Guerreiro::estourarBulbos(*inimigo);
            inimigo++;
		}
		recuperacaoGelada(*this);

	}
	const char* getClass() override {
		return "Colosso";
	}
};