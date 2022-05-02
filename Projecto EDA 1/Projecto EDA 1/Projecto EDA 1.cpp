// Projecto EDA 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Funcoes.h>


using namespace std;

int main();

struct produto {
    string nome = "N/A";
    string classe = "N/A";
    int rega = 0;
    int duracao = 0;
    int resistencia = 0;
};

struct horta {
    char nome = 'Z';
    string agricultor = "N/A";
    string backlog = "N/A";
    produto produto;
    int tamanho = 0;
};









int main() {

    srand(time(NULL));
    string input;
    //o cheiro e gay
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


    
    
    string *produtos;
    int numeroHortas = 0;
    horta hortas[15];
        
    

    cout << "Bem vindo á Plantação de EDA" << endl << endl;
    cout << "Deseja criar a plantação de raiz ou importar uma plantação existente?" << endl;
    cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
    cin >> input;

    if (input == "1") {
        numeroHortas = rand() % 6 + 5;
        system("cls");
       
        cout << "Foram criadas " << numeroHortas << " novas!" << endl << endl;

        //Para cada horta criada
        for (int i = 0; i < numeroHortas; i++) 
        {

                hortas[i].nome = 65 + i;
                hortas[i].tamanho = rand() % 6 + 3;
                cout << "A horta " << hortas[i].nome << " foi criada com o tamanho de: " << hortas[i].tamanho << endl;
                cout << "Introduza o nome do responsavel:" << endl;
                cin >> hortas[i].agricultor;
                cout << endl;
            

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

        cout << "0 - Exit" << endl;
   
        cin >> input;

        if (input == "g") { // GESTÃO
            //MenuGestao();
            MenuGestao();
            
        }
        else if (input == "z") { // Testes
            for (int i = 0; i < numeroHortas; i++) {
                cout << hortas[i].agricultor << " " ;                
                cout << hortas[i].nome << " " ;
                cout << hortas[i].tamanho << " " << endl;
                }
            cin >> input;
            
        }
        else if (input == "0") { // SAIR DO PROGRAMA
            break;
        }

        

    }

   

   
    return 0;

}




