#pragma once
#include "Proton.h"
#include "Mecanico.h"
#define danoTrans 25
class Transportadora : public Proton, public Mecanico {
private:
	int contadorInterceptadores = 1;
public:
	Transportadora(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Mecanico(nome, idade, peso, vida, vidaMax, mecanico) {}
	
	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override{
		std::vector<Guerreiro*>::iterator it;
		it = Inimigos.begin();
		
		(*it)->setVida((*it)->getVida() - (danoTrans * contadorInterceptadores));
        Guerreiro::estourarBulbos(*it);

		if (contadorInterceptadores < 8) { contadorInterceptadores++; }

		recuperacaoGelada(*this);

	}
	const char* getClass() override {
		return "Transportadora";
	}
};