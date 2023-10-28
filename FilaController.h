#include <vector>
#include "Tipos/Naga/Tropas/Devoradora.h"
#include "Tipos/Naga/Tropas/Empalador.h"
#include "Tipos/Naga/Tropas/Servo.h"
#include "Tipos/Proton/Tropas/Colosso.h"
#include "Tipos/Proton/Tropas/Fanaticus.h"
#include "Tipos/Proton/Tropas/Tormento.h"
#include "Tipos/Proton/Tropas/Transportadora.h"
#include "Tipos/Terrano/Tropas/Ambunave.h"
#include "Tipos/Terrano/Tropas/CruzadorDeBatalha.h"
#include "Tipos/Terrano/Tropas/Endiabrado.h"
#include "Tipos/Terrano/Tropas/Soldado.h"
#include "Tipos/Zerg/Tropas/Infestador.h"
#include "Tipos/Zerg/Tropas/MestreDasCastas.h"
#include "Tipos/Zerg/Tropas/Tatu-Bomba.h"
#include "Random.h"
#include <fstream>

class FilaController {
private:
    std::vector<Guerreiro*> TerranosProtos;
    std::vector<Guerreiro*> ZergNagas;

    double PesosTerranos;
    double PesosZergs;

    double vidaFila1; // marcador de vida
    double vidaFila2;

    int contSemDano;
    int situacao; // vitoria, derrota e empate

    char* nomeMaisVelho;

public:
    FilaController(){
        leituraDeArquivo();
        PesosTerranos = contarPesos(TerranosProtos);
        PesosZergs = contarPesos(ZergNagas);
        nomeMaisVelho = maisVelho();
        vidaFila2 = 0;
        vidaFila1 = 0;
        situacao = 0;
        contSemDano = 0;
    }

    void executar();
    static void goBack(std::vector<Guerreiro *> &Aliados);

private:
    double contarPesos(std::vector<Guerreiro *> &fila);
    void leituraDeArquivo();
    char* maisVelho();
    void limparFila(std::vector<Guerreiro *> &fila);
    void filaPassiva(double vidaDoPrimeiroTP, double vidaDoPrimeiroZG);
    int verificarFim();
    void imprimirResultado();

};


