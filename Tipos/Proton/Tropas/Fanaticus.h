#pragma once
#include "Tipos/Proton/Proton.h"
#include "ClassesBase/Organico.h"
#define danoFana 30
class Fanaticus : public Proton, public Organico {
public:
	Fanaticus(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		(*it)->setVida((*it)->getVida() - danoFana);
        Guerreiro::estourarBulbos(*it);
		recuperacaoGelada(*this);
	}
	const char* getClass() override {
		return "Fanaticus";
	}

};