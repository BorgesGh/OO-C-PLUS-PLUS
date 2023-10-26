#pragma once
#include "Tipos/Proton/Proton.h"
#include "ClassesBase/Organico.h"
#define danoTormento 30

class Tormento : public Proton, public Organico {
public:
	Tormento(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico):
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override;

	const char* getClass() override {
		return "Tormento";
	}


};