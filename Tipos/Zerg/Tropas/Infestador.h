#pragma once
#include "ClassesBase/Organico.h"
#include "Tipos/Zerg/Tropas/Zerguinideo.h"
#include "Tipos/Zerg/Zerg.h"
class Infestador : public Organico, public Zerg  {
public:
	Infestador(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
		std::vector<Guerreiro*>::iterator it;
		if (primeiro) {

            trocarGuerreiroLista(Aliados,Inimigos);

            it = Aliados.begin();
			//Agora o primeiro inimigo está na fila aliada
            try {
                (*it)->atacar(Aliados, Inimigos, false);//Não considerei a manipulação do infestador como
                //Primeiro ataque
            }catch(const std::exception& erro){
                //A fila do outro lado pode estar vazia...
            };
            trocarGuerreiroLista(Inimigos,Aliados);
			//O inimigo é devolvido para a sua respectiva fila

		}
		else {
			Aliados.insert(Aliados.begin(), new Zergnideo(this->getNome(),
                                                          this->getIdade(),
                                                          this->getPeso(),
                                                          50, // Vida inicial
                                                          100,
                                                          this->getMecanico()));
            it = Aliados.begin() + 1;// Segundo da fila que é o infestador
            Aliados.push_back(*it);
            Aliados.erase(Aliados.begin() + 1);

		}
	}
	const char* getClass() override {
		return "Infestador";
	}
private:
    static void trocarGuerreiroLista(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos){
        Aliados.insert(Aliados.begin(), *(Inimigos.begin()));
        Inimigos.erase(Inimigos.begin());
    }

};

