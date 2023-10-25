#include <vector>
#include "Fila.h"
#include "Random.h"
#include <fstream>
#include <fstream>

static void goBack(std::vector<Guerreiro *> &Aliados){
    //Envia o primeiro guerreiro para o fim após atacar
    Aliados.push_back(*(Aliados.begin()));
    Aliados.erase(Aliados.begin());
}

void limparFila(std::vector<Guerreiro *> &fila){
    auto it = fila.begin();
    while(it != fila.end()){
        if((*it)->getVida() <= 0){
            fila.erase(it);
            it = fila.begin();
        }
        else{
            it++;
        }
    }

}
//Execeções
bool InfestadorEAmbunave(std::vector<Guerreiro *> &TerranosProtos, std::vector<Guerreiro *> &ZergNagas){
    auto it = TerranosProtos.begin();
    auto it2 = ZergNagas.begin();

    int contOutroTipo = 0;

    while(it != TerranosProtos.end()){
        if((strcmp((*it)->getClass(),"Ambunave")) != 0){
            //Existem outros tipo além da ambunave
            contOutroTipo++;
        }
        it++;
    }
    while(it2 != ZergNagas.end()){
        if((strcmp((*it2)->getClass(),"Infestador")) != 0){
            //Existem outros tipos além do Infestador
            contOutroTipo++;
        }
        it2++;
    }
    if(!contOutroTipo) {
        //Só existem Infestadores e ambunaves
        return true;
    }
    return false;
}

void leituraDeArquivo(std::vector<Guerreiro *> &TerranosProtos, std::vector<Guerreiro *> &ZergNagas) {
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
                TerranosProtos.push_back(novo);
                break;

            case 2:
                TerranosProtos.push_back((new Endiabrado(nome, idade, peso, 100, 100, true)));
                break;

            case 3:
                TerranosProtos.push_back(new Ambunave(nome, idade, peso, 100, 100, true));
                break;

            case 4:
                TerranosProtos.push_back((new Cruzador(nome, idade, peso, 1000, 1000, true)));
                break;

                //========= Protons...

            case 5:
                TerranosProtos.push_back((new Fanaticus(nome, idade, peso, 100, 200, false)));
                break;

            case 6:
                novo = new Tormento(nome, idade, peso, 100, 100, false);
                TerranosProtos.push_back(novo);
                break;

            case 7:
                TerranosProtos.push_back((new Colosso(nome, idade, peso, 100, 100, true)));
                break;

            case 8:
                TerranosProtos.push_back((new Transportadora(nome, idade, peso, 500, 500, true)));
                break;
        }//switch

    }//while

    arquivo.close();
    //===== ZERGS E NAGAS =======
    std::fstream arquivo2(R"(C:\Projetos C++\TestandoCoisas\lado2.txt)");
    if(arquivo2.is_open()){
        std:: cout << "\nArquivo abriu!\n";
    }
    while (!arquivo2.eof()) {
        arquivo2 >> tipo >> nome >> idade >> peso;

        switch (tipo) {

            //========= Zergs...

            case 1:
                ZergNagas.push_back((new Zergnideo(nome, idade, peso, 50, 50, false)));
                break;

            case 2:
                ZergNagas.push_back((new TatuBomba(nome, idade, peso, 100, 100, false)));
                break;

            case 3:
                ZergNagas.push_back(new Infestador(nome, idade, peso, 100, 100, false));
                break;

            case 4:
                novo = new MestreDasCastas(nome, idade, peso, 200, 200, false) ;
                ZergNagas.push_back(novo);
                break;

                //========= NAGAS...

            case 5:
                ZergNagas.push_back(new Servo(nome, idade, peso, 100, 100, false));
                break;

            case 6:
                ZergNagas.push_back((new Devoradora(nome, idade, peso, 100, 100, false)));
                break;

            case 7:
                ZergNagas.push_back((new Empalador(nome, idade, peso, 400, 400, false)));
                break;

        }//switch
    }//while
}//leituraDeArquivo

int verificarFim(std::vector<Guerreiro *> &TerranosProtos, std::vector<Guerreiro *> &ZergNagas){
    auto it = TerranosProtos.begin();
    auto it2 = ZergNagas.begin();

    if(InfestadorEAmbunave(TerranosProtos, ZergNagas)){
        //Só tem ambunaves e infestador
        return 2; // Empate
    }
    int contVivosTerranos = 0;
    int contVivosNagas = 0;
    while(it != TerranosProtos.end()){
        if((*it)->getVida() > 0){
            //Tem algum vivo na fila...
            contVivosTerranos++;
        }
        it++;
    }
    while(it2 != ZergNagas.end()){
        if((*it2)->getVida() > 0){
            contVivosNagas++;
        }
        it2++;
    }
    if(contVivosNagas > 0 && !contVivosTerranos){
        //Os nagas venceram!
        return -1;
    }
    if(contVivosTerranos > 0 && !contVivosNagas){
        //Os terranos venceram!
        return 1;
    }
    return 0;
}

int main() {

    std::vector<Guerreiro*> TerranosProtos;
    std::vector<Guerreiro*> ZergNagas;
    leituraDeArquivo(TerranosProtos,ZergNagas);
    int situacao = 0;

    auto itTerranoProton = TerranosProtos.begin();
    auto itZergNagas = ZergNagas.begin();

    while(!situacao){
        if(Random::randInt(100) < 50) {
            (*itTerranoProton)->atacar(TerranosProtos, ZergNagas,true);
            //Atualização de ponteiros
            itTerranoProton = TerranosProtos.begin();
            itZergNagas = ZergNagas.begin();

            if((*itZergNagas)->getVida() > 0){
                //Atualização de ponteiros
                itTerranoProton = TerranosProtos.begin();
                itZergNagas = ZergNagas.begin();

                (*itZergNagas)->atacar(ZergNagas, TerranosProtos,false);
            }
        }
        else{
            (*itZergNagas)->atacar(ZergNagas, TerranosProtos,true);
            //Atualização de ponteiros
            itTerranoProton = TerranosProtos.begin();
            itZergNagas = ZergNagas.begin();

            if((*itTerranoProton)->getVida() > 0){
                //Atualização de ponteiros
                itTerranoProton = TerranosProtos.begin();
                itZergNagas = ZergNagas.begin();

                (*itTerranoProton)->atacar(TerranosProtos,ZergNagas,false);
            }
        }
        //Atualização de ponteiros
        itTerranoProton = TerranosProtos.begin();
        itZergNagas = ZergNagas.begin();

        goBack(TerranosProtos);
        goBack(ZergNagas);

        situacao = verificarFim(TerranosProtos,ZergNagas);
        if(!situacao){
            //Enquanto o jogo continua, pode-se limpar a fila
            limparFila(TerranosProtos);
            limparFila(ZergNagas);
        }

        itTerranoProton = TerranosProtos.begin();
        itZergNagas = ZergNagas.begin();

        (*itTerranoProton)->toString();
        (*itZergNagas)->toString();
    }//While

    if(situacao == 1){
        std::cout << "Terranos e Protons Venceram!!";
        std::cout << "\n" <<(*itZergNagas)->getNome() << ", " << (*itZergNagas)->getIdade() << ", " << (*itZergNagas)->getPeso();
        std::cout << "\n" <<(*itTerranoProton)->getNome() << ", " << (*itTerranoProton)->getIdade() << ", " << (*itTerranoProton)->getPeso();
    }
    else if(situacao == -1){
        std::cout << "\nZergs e Nagas Venceram!!";
        std::cout << "\n" << (*itTerranoProton)->getNome() << ", " << (*itTerranoProton)->getIdade() << ", " << (*itTerranoProton)->getPeso();
        std::cout << "\n" <<(*itZergNagas)->getNome() << ", " << (*itZergNagas)->getIdade() << ", " << (*itZergNagas)->getPeso();
    }
    else{
        std::cout << "\nHouve um empate!, As filas só contem Infestador(es) e Ambunave(s)";
    }

	return 0;
}


