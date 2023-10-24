#pragma once
#include "Organico.h"
#include "Zerguinideo.h"
#include "Zerg.h"
class Infestador : public Organico, public Zerg  {
public:
	Infestador(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
        std::vector<Guerreiro *>::iterator itTroca;
		it = Aliados.begin();
		if (primeiro) {

            itTroca = Inimigos.begin();
            Aliados.insert(Aliados.begin(), (*it));
            Inimigos.erase(it);

			//Agora o primeiro inimigo está na fila aliada
			(*it)->atacar(Aliados, Inimigos,false);//Não considerei a manipulação do infestador como
			//Primeiro ataque

            itTroca = Aliados.begin();
            Inimigos.insert(Inimigos.begin(), (*it));
            Aliados.erase(it);
			//O inimigo é devolvido para a sua respectiva fila

		}
		else {
			Aliados.insert(it, gerarZergnideo());
            Aliados.push_back(*it);
            Aliados.erase(it);

		}

	}
	const char* getClass() override {
		return "Infestador";
	}

private:
	
	Guerreiro * gerarZergnideo() {
		Zergnideo novo(
			this->getNome(),
			this->getIdade(),
			this->getPeso(),
			50, // Vida inicial
			this->getVidaMax(),
			this->getMecanico()
		);
		return &novo;
	}
};

