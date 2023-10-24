#pragma once
#include "Guerreiro.h"
class Proton {
protected:
	void recuperacaoGelada(Guerreiro& Proton) {
		if (Proton.getVida() <= (0.5 * Proton.getVidaMax())) {
			Proton.setVida(Proton.getVida() + (0.05 * Proton.getVidaMax())); // Recuperado 5% da vida maxima
		}
	}

};