#pragma once
#include "ClassesBase/Organico.h"
#include "Tipos/Zerg/Zerg.h"

class MestreDasCastas : public Zerg, public Organico {
public:
	MestreDasCastas(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override;

	const char* getClass() override {
		return "MestreDasCastas";
	}
};