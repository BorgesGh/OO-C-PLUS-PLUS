#include "Tipos/Proton/Tropas/Tormento.h"
#include "CloneTormento.h"

void Tormento::atacar(std::vector<Guerreiro *> &Aliados, std::vector<Guerreiro *> &Inimigos, bool primeiro) {
    std::vector<Guerreiro*>::iterator inimigo;
    inimigo = Inimigos.begin();

    (*inimigo)->setVida((*inimigo)->getVida() - danoTormento);
    Guerreiro::estourarBulbos(*inimigo);
    if (primeiro) {

        Aliados.insert(Aliados.begin(), new CloneTormento(this->getNome(),
                                                     this->getIdade(),
                                                     this->getPeso(),
                                                     50, // Vida inicial
                                                     this->getVidaMax(),
                                                     this->getMecanico())); // Insere o clone na fila
        // Envia o tormento para o fim

        Aliados.push_back(*(Aliados.begin() + 1));
        Aliados.erase(Aliados.begin() + 1);

    }
    recuperacaoGelada(*this);
}

