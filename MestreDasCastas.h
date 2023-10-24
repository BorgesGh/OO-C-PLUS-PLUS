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
        it = Aliados.begin();

        if (sorteado < 33) {
            Zergnideo Z(this->getNome(), 0, 0, 50, 50, false);
            for (int i = 0; i < 3; i++) {
                Aliados.insert(it, &Z);
            }

        }
        else if (sorteado < 66) {
            TatuBomba T(this->getNome(), 0, 0, 50, 100, false);
            for (int i = 0; i < 2; i++) {
                Aliados.insert(it, &T);
            }

        }
        else {
            Infestador I(this->getNome(), 0, 0, 100, 100, false);
            Aliados.insert(it, &I);
        }
        Aliados.push_back(*it);
        Aliados.erase(it);
    }
	const char* getClass() override {
		return "MestreDasCastas";
	}
};