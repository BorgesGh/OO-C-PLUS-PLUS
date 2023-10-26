#include "ClassesBase/Guerreiro.h"
#include "Organico.h"

void Guerreiro::estourarBulbos(Guerreiro* inimigo) {
    if(!inimigo->getMecanico()){
        //É organico
        auto* ref = dynamic_cast<Organico*>(inimigo);
        ref->setVida(ref->getVida() - ref->getBulbos());
    }
}
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