#pragma once
#include "Organico.h"
#include "Zerg.h"
#include "Random.h"
#include "Tatu-Bomba.h"
#include "Zerguinideo.h"
#include "Infestador.h"

class MestreDasCastas : public Zerg, public Organico {
public:
	MestreDasCastas(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Organico(nome, idade, peso, vida, vidaMax, mecanico) {}

	void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
        int sorteado = Random::randInt(100);
        std::vector<Guerreiro*>::iterator it;
        int i = 0;
        if (sorteado < 33) {
            for ( i = 0; i < 3; i++) {
                Aliados.push_back( new Zergnideo(this->getNome(), 0, 0, 50, 50, false));
            }

        }
        else if (sorteado < 66) {
            for (i = 0; i < 2; i++) {
                Aliados.push_back(new TatuBomba(this->getNome(), 0, 0, 50, 100, false));
            }

        }
        else {
            Aliados.push_back( new Infestador(this->getNome(), 0, 0, 100, 100, false));

        }
    }
	const char* getClass() override {
		return "MestreDasCastas";
	}
};