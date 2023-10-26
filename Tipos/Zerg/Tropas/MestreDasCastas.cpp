#include "Random.h"
#include "Tipos/Zerg/Tropas/Tatu-Bomba.h"
#include "Tipos/Zerg/Tropas/Zerguinideo.h"
#include "Tipos/Zerg/Tropas/Infestador.h"
#include "Tipos/Zerg/Tropas/MestreDasCastas.h"

void MestreDasCastas::atacar(std::vector<Guerreiro *> &Aliados, std::vector<Guerreiro *> &Inimigos, bool primeiro) {
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
