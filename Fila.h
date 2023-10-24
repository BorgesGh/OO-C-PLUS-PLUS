//Tipos de Guerreiros
#include "Devoradora.h"
#include "Empalador.h"
#include "Servo.h"
#include "Colosso.h"
#include "Fanaticus.h"
#include "Tormento.h"
#include "Transportadora.h"
#include "Ambunave.h"
#include "CruzadorDeBatalha.h"
#include "Endiabrado.h"
#include "Soldado.h"
#include "Infestador.h"
#include "MestreDasCastas.h"
#include "Tatu-Bomba.h"
#include "Zerguinideo.h"

//Essa arquivo está dando erro de redefinição ao ser incluido em um outro arquivo
class Fila {
public:
    static void goBack(std::vector<Guerreiro *>::iterator it, std::vector<Guerreiro *> &fila) {
        //Envia uma cópia do guerreiro para o fim da fila
        fila.push_back(*it);
        fila.erase(it);
    }

    static void removerCorpos(std::vector<Guerreiro *> &fila) {
        //Percorre a lista e remove quem está morto
        auto it = fila.begin();
        while (it != fila.end()) {
            if ((*it)->getVida() <= 0) {
                //O guerreiro está morto
                fila.erase(it);
            }
            it++;
        }//while
    }

    static void tradeWarriorList(std::vector<Guerreiro *> &filaReceptora, std::vector<Guerreiro *> &filaRemocao) {
        std::vector<Guerreiro *>::iterator it;
        it = filaRemocao.begin();
        filaReceptora.insert(filaReceptora.begin(), (*it));
        filaRemocao.erase(it);

    }

    static void leituraDeArquivo(std::vector<Guerreiro *> &fila1, std::vector<Guerreiro *> &fila2) {

        FILE *arq;
        arq = fopen("lado1.txt", "rd");

        //Variaveis buffer da leitura de arquivo;
        //tipo-nome-idade-peso
        int tipo, idade;
        char nome[30];
        float peso;
        Guerreiro *novo;
        while (!feof(arq)) {
            fscanf(arq, "%d", &tipo);
            fscanf(arq, "%s", nome);
            fscanf(arq, "%d", &idade);
            fscanf(arq, "%.2f", &peso);

            switch (tipo) {

                //========= Terranos...
                case 1:
                    novo = new Soldado(Soldado(nome, idade, peso, 100, 100, false));
                    fila1.push_back(novo);
                    break;

                case 2:
                    fila1.push_back((new Endiabrado(nome, idade, peso, 100, 100, true)));
                    break;

                case 3:
                    fila1.push_back(new Ambunave(nome, idade, peso, 100, 100, true));
                    break;

                case 4:
                    fila1.push_back((new Cruzador(nome, idade, peso, 1000, 1000, true)));
                    break;

                    //========= Protons...

                case 5:
                    fila1.push_back((new Fanaticus(nome, idade, peso, 100, 200, false)));
                    break;

                case 6:
                    novo = new Tormento(nome, idade, peso, 100, 100, false);
                    fila1.push_back(novo);
                    break;

                case 7:
                    fila1.push_back((new Colosso(nome, idade, peso, 100, 100, true)));
                    break;

                case 8:
                    fila1.push_back((new Transportadora(nome, idade, peso, 500, 500, true)));
                    break;
            }//switch

        }//while

        fclose(arq);
        //===== ZERGS E NAGAS =======
        arq = fopen("lado2.txt", "rd");

        while (!feof(arq)) {
            fscanf(arq, "%d", &tipo);
            fscanf(arq, "%s", nome);
            fscanf(arq, "%d", &idade);
            fscanf(arq, "%.2f", &peso);

            switch (tipo) {

                //========= Zergs...

                case 1:
                    fila2.push_back((new Zergnideo(nome, idade, peso, 50, 50, false)));
                    break;

                case 2:
                    fila2.push_back((new TatuBomba(nome, idade, peso, 100, 100, false)));
                    break;

                case 3:
                    fila2.push_back(new Infestador(nome, idade, peso, 100, 100, false));
                    break;

                case 4:
                    novo = new MestreDasCastas(nome, idade, peso, 200, 200, false) ;
                    fila2.push_back(novo);
                    break;

                    //========= NAGAS...

                case 5:
                    fila2.push_back(new Servo(nome, idade, peso, 100, 100, false));
                    break;

                case 6:
                    fila2.push_back((new Devoradora(nome, idade, peso, 100, 100, false)));
                    break;

                case 7:
                    fila2.push_back((new Empalador(nome, idade, peso, 400, 400, false)));
                    break;

            }//switch
        }//while
    }//leituraDeArquivo
};
