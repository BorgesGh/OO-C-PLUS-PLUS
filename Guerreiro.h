#pragma once
#include <vector>
#include <cstring>
#include "Object.h"
class Guerreiro : public Object {
	/*
	Um possivel problema que pode ocorrer é o fato do vector ser "Guerreiro" e não "Guerreiro*" */


private:
	char nome[30]{};
	int idade;
	double peso;
	double vida;
	double vidaMax;// Limite superior de vida que cada personages possui
	bool mecanico;
public:
	Guerreiro(const char * nome, int idade, double peso,double vida,double vidaMax,bool mecanico);
	virtual void atacar(
            std::vector<Guerreiro *> &Aliados,
            std::vector<Guerreiro *> &Inimigos,
            bool primeiro //Primeiro a atacar
		) = 0; // Função virtual pura.

						
	char* getNome() {
		return nome;
	}
	int getIdade() const {
		return idade;
	}
	double getPeso() const {
		return peso;
	}
	double getVida() const {
		return vida;
	}
	double getVidaMax() const {
		return vidaMax;
	}
	void setVida(double valor);

	bool getMecanico() const {
		return mecanico;
	}

};
Guerreiro::Guerreiro(const char *nome, int idade, double peso, double vida, double vidaMax, bool mecanico) {
    strcpy(this->nome, nome);
    this->idade = idade;
    this->peso = peso;
    this->vida = vida;
    this->vidaMax = vidaMax;
    this->mecanico = mecanico;
}
void Guerreiro::setVida(double valor) {
    this->vida = valor;
}
