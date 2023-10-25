#pragma once
#include "Organico.h"
#include "Naga.h"
#define danoEmpala 50
class Empalador : public Organico, public Naga {
public:
	Empalador(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		std::vector<Guerreiro*>::iterator itAliados;
		
		itAliados = Aliados.begin();
		it = Inimigos.begin();

		(*it)->setVida((*it)->getVida() - danoEmpala); // Atacar inimigo
        Guerreiro::estourarBulbos(*it);

		if (this->getVida() <= 100) {
			if (!(itAliados == (Aliados.end() - 1))) {//verificação se ele está sozinho
				itAliados++;//Segundo Guerreiro da fila
				Aliados.erase(itAliados);
				this->setVida(this->getVidaMax());
			}
			//O empalador esta sozinho na fila
		}

	}
	const char* getClass() override {
		return "Empalador";
	}
};