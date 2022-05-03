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

void Ciclo(int* hortaCount, horta plantacao[], int* produtosNoArmazem, int* produtosCount, int* areasCount, int* fornecedoresCount, produto armazem[]);


int main() {

    srand(time(NULL));
    string input;
    produto armazem[100];
    horta plantacao[15];



    int produtosNoArmazem = 0;
    int numeroHortas = 0;
    

    int hortaCount = 0;

    ifstream areas;
    ifstream produtos;
    ifstream fornecedores;

    int areasCount = 0;
    int produtosCount = 0;
    int fornecedoresCount = 0;


    cout << "Bem vindo á Plantação de EDA" << endl << endl;
    cout << "Deseja criar a plantação de raiz ou importar uma plantação existente?" << endl;
    cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
    cin >> input;

    if (input == "1") {

        
        


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
            //criação dos 15 produtos random
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
                    armazem[i].resistencia = rand() % 100;

            }
            system("cls");
        }
        else if (input == "2") { //IMPORT FILES
            //Import code
        }


        //menu geral

        while (input != "0") {

            system("cls");
            cout << "Horta" << endl;
            cout << "G + enter para menu de gestão" << endl;
            cout << "S + ENTER - Avançar ciclo" << endl;
            cout << "0 - Exit" << endl;

            cin >> input;

            if (input == "g") { // GESTÃO
                //MenuGestao();
                MenuGestao();

            }

            if (input == "s")
            {
                Ciclo(&hortaCount, plantacao, &produtosNoArmazem, &produtosCount, &areasCount, &fornecedoresCount, armazem);
            }
            else if (input == "z") { // Testes
                /*for (int i = 0; i < produtosNoArmazem; i++) {
                    cout  << armazem[i].nome << endl;
                }

                cout << produtosNoArmazem << endl;
                cin >> input;*/

                for (int i = 0; i < hortaCount; i++)
                {
                    cout << plantacao[i].nome << " " << plantacao[i].produto.nome << " " << plantacao[i].area << " " << plantacao[i].regaCooldown << " " << endl;
                }
                

                cout << "armazem: " << produtosNoArmazem << endl;
                for (int i = 0; i < produtosNoArmazem; i++)
                {
                    cout << armazem[i].nome << " " << armazem[i].area << " "  << endl;
                }
                cin >> input;

            }
            else if (input == "0") { // SAIR DO PROGRAMA
                break;
            }



        }

        return 0;

    }

    void Ciclo(int* hortaCount, horta plantacao[], int* produtosNoArmazem, int* produtosCount, int* areasCount, int* fornecedoresCount, produto armazem[]) {
        ifstream areas;
        ifstream produtos;
        ifstream fornecedores;
        string input;

        //colheita de Produtos
        cout << "Colheita de produtos" << endl;

        for (int i = 0; i < *hortaCount; i++)
        {
            
            int random = rand() % 4;
            
            if (random == 3) {
             
                for (int x = 0; x < 100; x++)
                {
                   
                    if (plantacao[i].backlog[x] == "") {
                        
                        plantacao[i].backlog[x] = plantacao[i].produto.nome;
                        break;
                    }
                }
                plantacao[i].produto.nome = "N/A";
                
            }
        }
      

        //Rega
        cout << "Rega" << endl;
        for (int i = 0; i < *hortaCount; i++)
        {
            if (plantacao[i].produto.nome != "N/A")
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
            
        }
        

        //criação dos 10 produtos random
        cout << "criação de produtos" << endl;
        for (int i = 0; i < 10; i++)
        {
            string produtoRandom;
            string areaRandom;
            string fornecedorRandom;

            string line;
            int random;

            

            produtos.open("produtos.txt");
            random = rand() % *produtosCount;
            cout << "001" << endl;
            for (int i = 0; i < random; i++)
            {
                getline(produtos, line);
            }
            produtos.close();
            cout << "002" << endl;

            armazem[i + *produtosNoArmazem].nome = line;
            areas.open("area.txt");
            random = rand() % *areasCount;
            for (int i = 0; i < random; i++)
            {
                getline(areas, line);
            }
            areas.close();
            armazem[i + *produtosNoArmazem].area = line;

            fornecedores.open("fornecedores.txt");
            random = rand() % *fornecedoresCount;
            for (int i = 0; i < random; i++)
            {
                getline(fornecedores, line);
            }
            fornecedores.close();
            armazem[i + *produtosNoArmazem].fornecedores = line;
            armazem[i + *produtosNoArmazem].rega = rand() % 5 + 1;
            
        }
        *produtosNoArmazem = *produtosNoArmazem + 10;

        for (int i = 0; i < *produtosNoArmazem; i++)
        {
            cout << armazem[i].nome << endl;
        }
        


        //Remoção de produtos (plantar)
        cout << "remocao de produtos" << endl;

            bool hortaDone = false;
            for (int x = 0; x < *hortaCount; x++)                
            {
                hortaDone = false;
                
                for (int i = 0; i < *produtosNoArmazem; i++)
                {
                    
                    if (armazem[i].area == plantacao[x].area && hortaDone == false && plantacao[x].produto.nome == "N/A")
                    {
                        plantacao[x].produto.nome = armazem[i].nome;
                        plantacao[x].produto.duracao = armazem[i].duracao;
                        plantacao[x].produto.fornecedores = armazem[i].fornecedores;
                        plantacao[x].produto.rega = armazem[i].rega;
                        plantacao[x].produto.resistencia = armazem[i].resistencia;
                        plantacao[x].regaCooldown = armazem[i].rega;
                        hortaDone = true;
                        for (int y = i; y < *produtosNoArmazem+1; y++)
                        {
                            armazem[y].area = armazem[y + 1].area;
                            armazem[y].duracao = armazem[y + 1].duracao;
                            armazem[y].fornecedores = armazem[y + 1].fornecedores;
                            armazem[y].nome = armazem[y + 1].nome;
                            armazem[y].rega = armazem[y + 1].rega;
                            armazem[y].resistencia = armazem[y + 1].resistencia;
                        }
                        *produtosNoArmazem = *produtosNoArmazem -1;                    
                    }
                }
            }

   
       

        //pragas
        cout << "pragas" << endl;

        for (int i = 0; i < *hortaCount; i++)
        {
            if (plantacao[i].regaCooldown = 1 && plantacao[i].produto.nome != "N/A")
            {
                int random = rand() % 100;
                if (plantacao[i].produto.resistencia < random)
                {
                    cout << "Uma produção foi perdida" << endl;
                    plantacao[i].produto.nome = "N/A";
                };
            }
        }


        cin >> input;


    }

    




