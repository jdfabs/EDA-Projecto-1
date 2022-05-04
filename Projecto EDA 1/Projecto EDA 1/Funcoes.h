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
	int regaCooldown = 0;
};

struct horta {
	char nome = 'Z';
	string agricultor = "N/A";
	string backlog[100];
	produto zona[9];
	int tamanho = 0;
	string area = "N/A";
	bool fertelizado = false;
	int campanhaTempo = 0;
};

ifstream areas;
ifstream produtos;
ifstream fornecedores;

string input;

int Main() {

	return 0;
}



//METODOS DE GESTÃO

void ColheitaManual(string produtoQuery, horta plantacao[], int* hortasCount) {

	produtoQuery = produtoQuery + " ";

	for (int i = 0; i < *hortasCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome == produtoQuery)
			{

				cout << "produto encontrado - a remover" << endl;
				for (int y = 0; y < 100; y++)
				{
					if (plantacao[i].backlog[y] == "") {
						plantacao[i].backlog[y] = plantacao[i].zona[x].nome;
						break;
					}
				}
				plantacao[i].zona[x].nome = "N/A";
				plantacao[i].zona[x].duracao = 999;
				plantacao[i].zona[x].fornecedores = "N/A";
				plantacao[i].zona[x].rega = 999;
				plantacao[i].zona[x].resistencia = 100;


			}
		}

	}
}

void AtualizarRega(string produtoQuery, int tempo, horta plantacao[], int* hortasCount, produto armazem[], int* produtosNoArmazem, int* tamanhoDoArmazem) {
	produtoQuery = produtoQuery + " ";
	string input;

	for (int i = 0; i < *hortasCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome == produtoQuery)
			{
				cout << "produto encontrado - alterando tempo de rega - horta" << endl;
				plantacao[i].zona[x].rega = tempo;
			}
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
	getline(cin, input);;
}

void Fertilizar(string area, int tempo, horta plantacao[], int* hortasCount) {
	for (int i = 0; i < *hortasCount; i++)
	{

		if (plantacao[i].area == area)
		{
			plantacao[i].fertelizado = true;
			plantacao[i].campanhaTempo = tempo;
		}
	}
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


void PrintProducts(horta plantacao[], int* hortasCount, produto armazem[], int* produtosNoArmazem, int* tamanhoDoArmazem) { // 0 para ordem alfabetica e 1 para tempo de plantação (não implementado)

	system("cls");
	for (int i = 0; i < *hortasCount; i++)
	{
		int numProdutos=0;
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome != "N/A") {
				numProdutos++;
			}
		}
		cout << "Horta: " << plantacao[i].nome <<
			" | Responsavel: "<< plantacao[i].agricultor <<
			" | Capacidade: " << plantacao[i].tamanho <<
			" | Produtos: "<< numProdutos<<
			" | Area: "<< plantacao[i].area << endl;
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			cout  << "Produto: " << plantacao[i].zona[x].nome <<
				"| Rega: "<< plantacao[i].zona[x].regaCooldown<<
				" | Resistencia: "<< plantacao[i].zona[x].resistencia << "%" << endl;
		}
		cout << "---------------------------------" << endl;
	}
	cout << "Inventario do armazem:" << endl << endl;
	for (int i = 0; i < *produtosNoArmazem; i++)
	{
		cout <<  "Produto: " << armazem[i].nome 
			<< "| Resistencia: " << armazem[i].resistencia 
			<< " | Area: " << armazem[i].area 
			// << " | Fornecedor: " << armazem[i].fornecedores
			<< endl;
	}

	string input;
	cin >> input;
	

}
void CriarArea(string area, int* areasDiferentes, string areasDisponiveis[]) {

	areasDisponiveis[*areasDiferentes] = area;
	*areasDiferentes = *areasDiferentes + 1;

}
void AlterarArea(horta plantacao[], char nome, string area, int numeroDeHortas, int* areasDiferentes, string areasDisponiveis[]) {


	string input;

	for (int i = 0; i < numeroDeHortas; i++)
	{
		if (plantacao[i].nome == nome) {

			areasDisponiveis[i] = area;
			plantacao[i].area = area;
		}
	}
}
void Backlog(string agricultor, horta plantacao[], int numeroDeHortas) {
	string input;
	for (int i = 0; i < numeroDeHortas; i++)
	{
		if (plantacao[i].agricultor == agricultor)
		{
			cout << "000" << endl;
			for (int x = 0; x < 100; x++)
			{
				if (plantacao[i].backlog[x] != "")
				{
					cout << x + 1 << ". " << plantacao[i].backlog[x] << endl;
				}
			}

		}
	}
	getline(cin, input);;

}


//Fuções Gerais

void AdicionarProdutoAoArmazem(int quantidade, int* produtosNoArmazem, int* produtosCount, int* areasCount, int* fornecedoresCount, produto armazem[], int* tamanhoDoArmazem, int* areasDiferentes, string areasDisponiveis[]) {
	string produtoRandom;
	string areaRandom;
	string fornecedorRandom;

	for (int i = 0; i < quantidade; i++)
	{
		string line;
		int random;
		cout << "002" << endl;



		produtos.open("produtos.txt");
		random = rand() % *produtosCount;
		for (int i = 0; i < random; i++)
		{
			getline(produtos, line);
		}
		produtos.close();

		armazem[i + *produtosNoArmazem].nome = line;




		random = rand() % *areasDiferentes;

		armazem[i + *produtosNoArmazem].area = areasDisponiveis[random];



		fornecedores.open("fornecedores.txt");
		random = rand() % *fornecedoresCount;
		for (int i = 0; i < random; i++)
		{
			getline(fornecedores, line);
		}
		fornecedores.close();

		armazem[i + *produtosNoArmazem].fornecedores = line;
		armazem[i + *produtosNoArmazem].rega = rand() % 5 + 1;
		armazem[i + *produtosNoArmazem].regaCooldown = armazem[i + *produtosNoArmazem].rega;
		armazem[i + *produtosNoArmazem].resistencia = rand() % 50 + 50;

		cout << "003" << endl;

	}
	cout << "004" << endl;


	*produtosNoArmazem = *produtosNoArmazem + quantidade;
}

void CriarNovaHorta(int quantidade, int* numeroDeHortas, int* areasCount, int* produtosCount, int* fornecedoresCount, horta plantacao[], int* hortaCount, int* areasDiferentes, string areasDisponiveis[]) {


	system("cls");
	cout << "Foram criadas " << quantidade << " novas!" << endl << endl;

	//Para cada horta criada
	string line;
	for (int i = 0; i < quantidade; i++)
	{

		areas.open("area.txt");
		int random = rand() % *areasCount;
		for (int i = 0; i < random; i++)
		{
			getline(areas, line);
		}
		areas.close();
		plantacao[i].area = line;

		areasDisponiveis[i] = line;
		*areasDiferentes = *areasDiferentes + 1;

		plantacao[i].nome = 65 + i;
		plantacao[i].tamanho = rand() % 6 + 3;
		cout << "A horta " << plantacao[i].nome << " foi criada com o tamanho de: " << plantacao[i].tamanho << endl;
		cout << "Introduza o nome do responsavel:" << endl;
		getline(cin, plantacao[i].agricultor);
		cin >> plantacao[i].agricultor;
		*hortaCount = *hortaCount + 1;
		cout << endl;
	}
}