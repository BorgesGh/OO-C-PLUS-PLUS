#include <vector>
#include "Fila.h"
#include <fstream>
#include <fstream>

void leituraDeArquivo(std::vector<Guerreiro *> &fila1, std::vector<Guerreiro *> &fila2) {
    Guerreiro *novo;
    std::fstream arquivo(R"(C:\Projetos C++\TestandoCoisas\lado1.txt)");
    if(arquivo.is_open()){
        std:: cout << "\nArquivo abriu!\n";
    }
    int tipo;
    char nome[30];
    int idade;
    double peso;

    while (!arquivo.eof()) {
        arquivo >> tipo >> nome >> idade >> peso;
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

    arquivo.close();
    //===== ZERGS E NAGAS =======
    std::fstream arquivo2(R"(C:\Projetos C++\TestandoCoisas\lado1.txt)");
    if(arquivo2.is_open()){
        std:: cout << "\nArquivo abriu!\n";
    }
    while (!arquivo2.eof()) {
        arquivo2 >> tipo >> nome >> idade >> peso;

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

int main() {

    std::vector<Guerreiro*> fila1;
    std::vector<Guerreiro*> fila2;

    fila1.push_back(new Soldado("Carlos",20,101,200,200,false));

    auto it = fila1.begin();
    auto it2 = fila2.begin();
    std::cout << (*it)->getVida();
    std::cout << "\n" << (*it)->getNome();

    leituraDeArquivo(fila1,fila2);

    it = fila1.begin();
    while (it != fila1.end()){
        std::cout << "\nO nome do fei: " << (*it)->getClass();
        it++;
    }
    it2 = fila2.begin();
    while (it2 != fila2.end()){
        std::cout << "\nO nome do fei 2: " << (*it2)->getClass();
        it2++;
    }

	return 0;
}


