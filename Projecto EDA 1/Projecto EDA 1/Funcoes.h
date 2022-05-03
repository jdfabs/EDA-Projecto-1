#pragma once

#include <string>

using namespace std;

int Main() {

    return 0;
}



//METODOS DE GESTÃO

void ColheitaManual(string produto) {



}

void AtualizarRega(string produto, int tempo) {

}

void Fertilizar(string area, int tempo) {

}/*
void Exportar(horta hortas[], string produtos[], int numeroDeHortas) {
    ofstream save;
    save.open("Saves/save.txt");
    save << "Writing this to a file.\n";
    save.close();
  
}*/

void Import(string path) {

}


void PrintProducts(int order) { // 0 para ordem alfabetica e 1 para tempo de plantação

}
void CriarArea(string area) {

}
void AlterarArea(char horta, string area) {

}
void Backlog(string agricultor) {

}



void MenuGestao() {
    system("cls"); //LIMPAR CONSOLA
    string input;


    cout << "*****Bem Vindo Gestor*****" << endl;
    cout << "(1).Colher Produto" << endl;
    cout << "(2).Atualizar tempo de rega" << endl;
    cout << "(3).Fertilização" << endl;
    cout << "(4).Gravar Plantação" << endl;
    cout << "(5).Carregar Plantação" << endl;
    cout << "(6).Imprimir Plantação" << endl;
    cout << "(7).Criar nova área" << endl;
    cout << "(8).Mostrar registo de agricultor" << endl;
    cout << "(9).Alterar área" << endl;
    cout << "(0).Voltar" << endl;
    cout << "Seleccione a sua opção :" << endl;

    cin >> input;

    // Colher Produto
    if (input == "1") {
        system("cls");
        cout << "----Colheita Manual----" << endl;
        cout << "Indique o produto a colher" << endl;
        cin >> input;


        ColheitaManual(input);
    }
    //Atualizar tempo de rega
    if (input == "2") {


    }
    //Fertilização
    if (input == "3") {


    }

    //Gravar Plantação
    if (input == "4") {


    }
    //Carregar Plantação
    if (input == "5") {


    }
    //Imprimir Plantação
    if (input == "6") {


    }
    //Criar nova área
    if (input == "7") {


    }
    //Mostrar registo de agricultor
    if (input == "8") {


    }
    //Alterar área
    if (input == "9") {


    }

}