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
		it = Inimigos.begin();
		if (primeiro) {


            Aliados.insert(Aliados.begin(), (*it));
            Inimigos.erase(Inimigos.begin());

            it = Aliados.begin();
			//Agora o primeiro inimigo está na fila aliada
			(*it)->atacar(Aliados, Inimigos,false);//Não considerei a manipulação do infestador como
			//Primeiro ataque

            Inimigos.insert(Inimigos.begin(), (*it));
            Aliados.erase(Aliados.begin());
			//O inimigo é devolvido para a sua respectiva fila

		}
		else {
			Aliados.insert(Aliados.begin(), new Zergnideo(this->getNome(),
                                                          this->getIdade(),
                                                          this->getPeso(),
                                                          50, // Vida inicial
                                                          this->getVidaMax(),
                                                          this->getMecanico()));
            it = Aliados.begin() + 1;// Segundo da fila que é o infestador
            Aliados.push_back(*it);
            Aliados.erase(Aliados.begin() + 1);

		}


	}
	const char* getClass() override {
		return "Infestador";
	}

};

