// Projecto EDA 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;



struct produto {
    string nome;
    string classe;
    int rega;
    int duracao;
    int resistencia;
};

struct horta {
    char nome;
    string agricultor;
    string backlog;
    produto produto;
    int tamanho;
};



//METODOS DE GESTÃO
void ColheitaManual(string produto) {

   

}

void AtualizarRega(string produto, int tempo) {

}

void Fertilizar(string area, int tempo) {

}

void Export() {

}

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
    /*while (input != "1" || input != "2" || input != "3" || input != "4" || input != "5" || input != "6" || input != "7" || input != "8" || input != "9" || input != "0") {
        

    }  */ 
    if (input == "1") {
        system("cls");
        cout << "----Colheita Manual----" << endl;
        cout << "Indique o produto a colher" << endl;
        cin >> input;


        ColheitaManual(input);
    }


}




int main() {

    srand(time(NULL));
    string input;

   /* // Create a text file
    ofstream MyWriteFile("filename.txt");
    // Write to the file
    MyWriteFile << "Files can be tricky, but it is fun enough!";
    // Close the file
    MyWriteFile.close();
    // Create a text string, which is used to output the text file
    string myText;
    // Read from the text file
    ifstream MyReadFile("filename.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }
    // Close the file
    MyReadFile.close();


    string plantacao [10];

    struct {             // Structure declaration
        int myNum;         // Member (int variable)
        string myString;   // Member (string variable)
    } myStructure;       // Structure variable */


    
    horta hortas[10];
    string produtos[10];
    int numeroHortas;

    cout << "Bem vindo á Plantação de EDA" << endl << endl;
    cout << "Deseja criar a plantação de raiz ou importar uma plantação existente?" << endl;
    cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
    cin >> input;

    if (input == "1") {
        system("cls");
        numeroHortas = rand() % 6 + 5;
        cout << "Foram criadas " << numeroHortas << " novas!" << endl << endl;

        //Para cada horta criada
        for (size_t i = 0; i < 10; i++) 
        {
            if (i < numeroHortas) {
                hortas[i].nome = 65 + i;
                hortas[i].tamanho = rand() % 6 + 3;
                cout << "A horta " << hortas[i].nome << " foi criada com o tamanho de: " << hortas[i].tamanho << endl;
                cout << "Introduza o nome do responsavel:" << endl;
                cin >> hortas[i].agricultor;
                cout << endl;
            }
            else {  //HORTA não existente
                hortas[i].nome = 'Z';
                hortas[i].tamanho = 0;
                hortas[i].agricultor = "N/A";
                hortas[i].backlog = "N/A";
                hortas[i].produto.nome = "N/A";
                hortas[i].produto.classe = "N/A";
                hortas[i].produto.duracao = 0;
                hortas[i].produto.rega = 0;
                hortas[i].produto.resistencia = 0;
            }

        }
    }
    else if (input == "2") { //IMPORT FILES
        //Import code
    }




    while (input != "0") {

        system("cls");
        cout << "Horta" << endl;
        cout << "G + enter para menu de gestão" << endl;
        cout << "S + ENTER - esqueci-me o que é" <<endl;
        cout << "1 print hortas existentes" << endl;
        cout << "0 - Exit" << endl;
   
        cin >> input;

        if (input == "g") { // GESTÃO
            MenuGestao();
        }
        else if (input == "1") // PRINT HORTAS EXISTENTES
        {
            system("cls");
            cout << "Numero de Hortas existentes: " << numeroHortas << endl;

            for (size_t i = 0; i < 10; i++)
            {
                if (hortas[i].nome != 'Z') {
                    cout << hortas[i].nome << endl;
                }
                
            }
            cout << endl << endl << endl << "Press 0 to return to main menu" << endl;
            cin >> input;

        }

        else if (input == "0") { // SAIR DO PROGRAMA
            break;
        }

    }

   

   
    return 0;

}




