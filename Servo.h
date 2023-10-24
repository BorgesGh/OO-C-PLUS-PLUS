#pragma once
#include "Organico.h"
#include "Naga.h"
class Servo : public Naga, public Organico {
public:
	Servo(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();

		if (!(*it)->getMecanico()) {
			auto* ref = dynamic_cast<Organico*>((*it));
			ref->increaseBulbos();
		}
	}
	const char* getClass() override {
		return "Servo";
	}

};
