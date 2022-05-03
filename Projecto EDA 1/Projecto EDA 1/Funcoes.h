#pragma once

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

int Main() {

    return 0;
}



//METODOS DE GESTÃO

void ColheitaManual(string produtoQuery, horta plantacao[], int* hortasCount) {

    produtoQuery = produtoQuery + " ";
    
    for (int i = 0; i < *hortasCount; i++)
    {
                if (plantacao[i].produto.nome == produtoQuery)
        {
          
            cout << "produto encontrado - a remover" << endl;
            plantacao[i].produto.nome = "N/A";
        }
    }
}

void AtualizarRega(string produtoQuery, int tempo, horta plantacao[], int* hortasCount, produto armazem[], int* produtosNoArmazem) {
    produtoQuery = produtoQuery + " ";
    string input;

    for (int i = 0; i < *hortasCount; i++)
    {
        if (plantacao[i].produto.nome == produtoQuery)
        {

            cout << "produto encontrado - alterando tempo de rega - horta" << endl;
            plantacao[i].produto.rega = tempo;
        }
    }
    for (int i = 0; i < *produtosNoArmazem; i++)
    {
        if (armazem[i].nome == produtoQuery)
        {
            cout << "produto encontrado - alterando tempo de rega - armazem" << endl;
            armazem[i].rega = tempo;
        }
    }
    cin >> input;
}

void Fertilizar(string area, int tempo) {

}


/*
void Exportar(horta hortas[], string produtos[], int numeroDeHortas) {
    ofstream save;
    save.open("Saves/save.txt");
    save << "Writing this to a file.\n";
    save.close();
  
}*/

void Import(string path) {

}


void PrintProducts(horta plantacao[], int* hortasCount, produto armazem[], int* produtosNoArmazem) { // 0 para ordem alfabetica e 1 para tempo de plantação

    system("cls");
    for (int i = 0; i < *hortasCount; i++)
    {
        cout << "Horta " << plantacao[i].nome << " contem: " << plantacao[i].produto.nome << endl;
    }
    cout << "Inventario do armazem:" << endl;
    for (int i = 0; i < *produtosNoArmazem; i++)
    {
        cout << i+1 << ". " << armazem[i].nome << endl;
    }

    string input;
    cin >> input;

}
void CriarArea(string area) {

}
void AlterarArea(horta plantacao[], char nome, string area, int numeroDeHortas) {
    string input;
    
    for (int i = 0; i < numeroDeHortas; i++)
    {
        if (plantacao[i].nome == nome ) {
            cout << " 001" << endl;
            cin >> input;
            plantacao[i].area = area;
        }
    }
}
void Backlog(string agricultor, horta plantacao[],int numeroDeHortas) {
    
    for (int i = 0; i < numeroDeHortas; i++)
    {
        if (plantacao[i].agricultor == agricultor)
        {
            for (int x = 0; x < 100; x++)
            {
                cout << x << ". " << plantacao[i].backlog[x] << endl;
            }
            
            cin >> agricultor;
        }
    }

}



