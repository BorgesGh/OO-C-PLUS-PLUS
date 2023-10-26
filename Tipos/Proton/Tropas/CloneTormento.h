#include "Tipos/Proton/Tropas/Tormento.h"

class CloneTormento : public Tormento{

public:
    CloneTormento(char* nome, int idade, double peso, double vida, double vidaMax, bool mecanico):
            Tormento(nome, idade, peso, vida, vidaMax, mecanico) {}

    void atacar(std::vector<Guerreiro*> &Aliados, std::vector<Guerreiro*> &Inimigos, bool primeiro) override {
        //Não faz nada...
    }

    const char* getClass()override{
        return "CloneTormento";
    }
};