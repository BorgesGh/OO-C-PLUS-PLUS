#pragma once
#include "Naga.h"
#include "Organico.h"
class Devoradora : public Naga, public Organico {
public:
	Devoradora(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator itSegundo;
		std::vector<Guerreiro*>::iterator itDevoradora;
		std::vector<Guerreiro*>::iterator itInimigo;
		int dano = 0;

		itDevoradora = Aliados.begin();
		itSegundo = Aliados.begin() + 1;// Vai para a segunda posição da fila
		itInimigo = Inimigos.begin();

		if (itDevoradora == Aliados.end() - 1) {
			//Não existe ninguem para devorar...
			dano = 0;
		}
		else {
			//Existe alguem para ser devorado
			if (strcmp("Empalador", (*itSegundo)->getClass()) == 0) {
				//Devoradora não pode comer um empalador
				Aliados.erase(itDevoradora);
			}
			else {
				dano = (*itSegundo)->getVida() * 2;
				Aliados.erase(itSegundo);
			}
		}

		(*itInimigo)->setVida((*itInimigo)->getVida() - dano);
        Guerreiro::estourarBulbos(*itInimigo);
	}
	const char* getClass() override {
		return "Devoradora";
	}
};