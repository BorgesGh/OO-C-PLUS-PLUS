#pragma once
#include "Guerreiro.h"
class Organico :public Guerreiro{
	//Organico � a tropa n�o mec�nica
private:
	int contBulbos;
public:
	Organico(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico) :
		Guerreiro(nome, idade, peso, vida, vidaMax, mecanico), contBulbos(0) {
	}
	int getBulbos() const {
		return contBulbos;
	}
	void increaseBulbos() {
		contBulbos++;
	}
    void receberDanoBulbo(){
        this->setVida(this->getVida() - contBulbos);
    }

};