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

    double vidaFila1;
    double vidaFila2;

    int contSemDano;
    int situacao;

    char* nomeMaisVelho;
};

