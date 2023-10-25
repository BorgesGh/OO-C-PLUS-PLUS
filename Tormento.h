#pragma once
#include "Proton.h"
#include "Organico.h"
#define danoTormento 30

class Tormento : public Proton, public Organico {
public:
	Tormento(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico):
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator inimigo;
		inimigo = Inimigos.begin();
		std::vector<Guerreiro*>::iterator tormento;
		tormento = Aliados.begin();

		(*inimigo)->setVida((*inimigo)->getVida() - danoTormento);
        Guerreiro::estourarBulbos(*inimigo);
		if (primeiro) {
			
			Aliados.insert(Aliados.begin(), new Tormento(this->getNome(),
                                                         this->getIdade(),
                                                         this->getPeso(),
                                                         50, // Vida inicial
                                                         this->getVidaMax(),
                                                         this->getMecanico())); // Insere o clone na fila
            // Envia o tormento para o fim
            Aliados.push_back(*tormento);
            Aliados.erase(tormento);

		}
		recuperacaoGelada(*this);
	}
	const char* getClass() override {
		return "Tormento";
	}


};