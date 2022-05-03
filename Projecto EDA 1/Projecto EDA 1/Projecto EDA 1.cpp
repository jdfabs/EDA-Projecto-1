// Projecto EDA 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Funcoes.h>


using namespace std;


struct produto {
    string nome = "N/A";
    string area = "N/A";
    int rega = 0;
    int duracao = 0;
    int resistencia = 0;
    string fornecedores = "N/A";
};

struct horta {
    char nome = 'Z';
    string agricultor = "N/A";
    string backlog[100];
    produto produto;
    int tamanho = 0;
    string area = "N/A";
    int regaCooldown = 0;
};



int main() {

    srand(time(NULL));
    string input;
    produto armazem[100];
    int produtosNoArmazem = 0;
    int numeroHortas = 0;
    horta plantacao[15];

    int hortaCount = 0;

    cout << "Bem vindo � Planta��o de EDA" << endl << endl;
    cout << "Deseja criar a planta��o de raiz ou importar uma planta��o existente?" << endl;
    cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
    cin >> input;

    if (input == "1") {

        int areasCount = 0;
        int produtosCount = 0;
        int fornecedoresCount = 0;

        ifstream areas;
        ifstream produtos;
        ifstream fornecedores;


        areas.open("area.txt");
        if (areas.is_open()) {
            string line;
            while (getline(areas, line)) {
                areasCount++;
            }
            areas.close();
        }     

              
        produtos.open("produtos.txt");
        if (produtos.is_open()) {
            string line;
            while (getline(produtos, line)) {
                produtosCount++;
            }
            produtos.close();
        }       

        
        fornecedores.open("fornecedores.txt");
        if (fornecedores.is_open()) {
            string line;
            while (getline(fornecedores, line)) {
                fornecedoresCount++;
            }
            fornecedores.close();
        }

            numeroHortas = rand() % 6 + 5;

            system("cls");
            cout << "Foram criadas " << numeroHortas << " novas!" << endl << endl;

            //Para cada horta criada
            for (int i = 0; i < numeroHortas; i++)
            {
                string areaRandom;
                areas.open("area.txt");
                string line;
                int random = rand() % areasCount;
                for (int i = 0; i < random; i++)
                {
                    
                    getline(areas, line);
                }
                areas.close();
                plantacao[i].area = line;
                plantacao[i].nome = 65 + i;
                plantacao[i].tamanho = rand() % 6 + 3;
                cout << "A horta " << plantacao[i].nome << " foi criada com o tamanho de: " << plantacao[i].tamanho << endl;
                cout << "Introduza o nome do responsavel:" << endl;
                cin >> plantacao[i].agricultor;
                hortaCount++;
                cout << endl;
            }
            //cria��o dos 15 produtos random
            for ( int i = 0; i < 15; i++)
            {  
                    string produtoRandom;
                    string areaRandom;
                    string fornecedorRandom;

                    string line;
                    int random;

                    produtosNoArmazem++;
                    produtos.open("produtos.txt");                    
                    random = rand() % produtosCount;
                    for (int i = 0; i < random; i++)
                    {
                            getline(produtos, line);                
                    }
                    produtos.close();
                    armazem[i].nome = line;

                    areas.open("area.txt");
                    random = rand() % areasCount;
                    for (int i = 0; i < random; i++)
                    {
                        getline(areas, line);
                    }
                    areas.close();
                    armazem[i].area = line;

                    fornecedores.open("fornecedores.txt");
                    random = rand() % fornecedoresCount;
                    for (int i = 0; i < random; i++)
                    {
                        getline(fornecedores, line);
                    }
                    fornecedores.close();
                    armazem[i].fornecedores = line;

                    
                    armazem[i].rega = rand() % 5 + 1;

            }
            system("cls");
            for (int i = 0; i < produtosNoArmazem ; i++)
            {
                cout << armazem[i].nome << endl;
            }
            cin >> input;
        }
        else if (input == "2") { //IMPORT FILES
            //Import code
        }


        //menu geral

        while (input != "0") {

            system("cls");
            cout << "Horta" << endl;
            cout << "G + enter para menu de gest�o" << endl;
            cout << "S + ENTER - esqueci-me o que �" << endl;

            cout << "0 - Exit" << endl;

            cin >> input;

            if (input == "g") { // GEST�O
                //MenuGestao();
                MenuGestao();

            }
            else if (input == "z") { // Testes
                for (int i = 0; i < numeroHortas; i++) {
                    cout << plantacao[i].agricultor << " ";
                    cout << plantacao[i].nome << " ";
                    cout << plantacao[i].tamanho << " " << endl;
                }
                cin >> input;

            }
            else if (input == "0") { // SAIR DO PROGRAMA
                break;
            }



        }

        return 0;

    }


    void Ciclo(int hortaCount, horta plantacao[], int produtosNoArmazem, fstream produtos, fstream areas, fstream fornecedores, int produtosCount, int areasCount, int fornecedoresCount, produto armazem[]) {
        //colheita de Produtos
        for (int i = 0; i < hortaCount; i++)
        {
            int random = rand() % 4;
            if (random == 4) {
                for (int x = 0; x < 100; x++)
                {
                    if (plantacao[i].backlog[x] == "") {
                        plantacao[i].backlog[x] = plantacao[i].produto.nome;
                    }
                 }                
                plantacao[i].produto.nome = "N/A";
            }
        }        
        //Rega
        for (int i = 0; i < hortaCount; i++)
        {
            if (plantacao[i].regaCooldown == 0)
            {
                plantacao[i].regaCooldown = plantacao[i].produto.rega;
            }
            else
            {
                plantacao[i].regaCooldown--;
            }
        }        
        //Cria��o produtos
         //cria��o dos 10 produtos random
        for (int i = 0; i < 10; i++)
        {
            string produtoRandom;
            string areaRandom;
            string fornecedorRandom;

            string line;
            int random;

            produtosNoArmazem++;
            produtos.open("produtos.txt");
            random = rand() % produtosCount;
            for (int i = 0; i < random; i++)
            {
                getline(produtos, line);
            }
            produtos.close();
            armazem[i+ produtosNoArmazem].nome = line;

            areas.open("area.txt");
            random = rand() % areasCount;
            for (int i = 0; i < random; i++)
            {
                getline(areas, line);
            }
            areas.close();
            armazem[i+ produtosNoArmazem].area = line;

            fornecedores.open("fornecedores.txt");
            random = rand() % fornecedoresCount;
            for (int i = 0; i < random; i++)
            {
                getline(fornecedores, line);
            }
            fornecedores.close();
            armazem[i+ produtosNoArmazem].fornecedores = line;


            armazem[i+ produtosNoArmazem].rega = rand() % 5 + 1;

        }
        
        //Remo��o de produtos (plantar)
        for (int i = 0; i < 10; i++)
        {

        }
        
        //pragas


    }




