#pragma once

#include <string>

using namespace std;

int Main() {

    return 0;
}



//METODOS DE GEST�O

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


void PrintProducts(int order) { // 0 para ordem alfabetica e 1 para tempo de planta��o

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
    cout << "(3).Fertiliza��o" << endl;
    cout << "(4).Gravar Planta��o" << endl;
    cout << "(5).Carregar Planta��o" << endl;
    cout << "(6).Imprimir Planta��o" << endl;
    cout << "(7).Criar nova �rea" << endl;
    cout << "(8).Mostrar registo de agricultor" << endl;
    cout << "(9).Alterar �rea" << endl;
    cout << "(0).Voltar" << endl;
    cout << "Seleccione a sua op��o :" << endl;

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
    //Fertiliza��o
    if (input == "3") {


    }

    //Gravar Planta��o
    if (input == "4") {


    }
    //Carregar Planta��o
    if (input == "5") {


    }
    //Imprimir Planta��o
    if (input == "6") {


    }
    //Criar nova �rea
    if (input == "7") {


    }
    //Mostrar registo de agricultor
    if (input == "8") {


    }
    //Alterar �rea
    if (input == "9") {


    }

}