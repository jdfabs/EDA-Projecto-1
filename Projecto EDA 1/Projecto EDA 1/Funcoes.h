
<<<<<<< Updated upstream
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Funcoes.h>
=======
#include "structs.h"
>>>>>>> Stashed changes

using namespace std;



ifstream areas;
ifstream produtos;
ifstream fornecedores;
string input;


//METODOS DE GESTÃO
void ColheitaManual(string produtoQuery, horta plantacao[], int* hortasCount) {
	produtoQuery = produtoQuery + " "; //produto a colher
	for (int i = 0; i < *hortasCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome == produtoQuery)
			{
				cout << "produto encontrado - a remover" << endl;
				for (int y = 0; y < 100; y++) //adiciona o produto ao backlog
				{
					if (plantacao[i].backlog[y] == "") {
						plantacao[i].backlog[y] = plantacao[i].zona[x].nome;
						break;
					}
				}
				// muda os valores do produto para os default
				plantacao[i].zona[x].nome = "N/A";
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

void ExportarHortas(int tamanhoDoArmazem, int produtosNoArmazem, int numeroHortas, int hortaCount, int areasCount, int produtosCount, int fornecedoresCount, int areasDiferentes, horta plantacao[], string areasDisponiveis[]) {
	ofstream save;
	save.open("Save.txt");
	//Guardar variaveis simples
	save << tamanhoDoArmazem << "\n"
		<< produtosNoArmazem << "\n"
		<< numeroHortas << "\n"
		<< hortaCount << "\n"
		<< areasCount << "\n"
		<< produtosCount << "\n"
		<< fornecedoresCount << "\n"
		<< areasDiferentes << "\n" << "||Plantacao||" << "\n";
	//Guardar as hortas
	for (int i = 0; i < 10; i++)
	{
		save << plantacao[i].nome << "\n"
			<< plantacao[i].agricultor << "\n"
			<< plantacao[i].tamanho << "\n"
			<< plantacao[i].area << "\n"
			<< plantacao[i].fertelizado << "\n"
			<< plantacao[i].campanhaTempo << "\n" << "\n";
		//gravar cada zona na horta
		for (int x = 0; x < 9; x++)
		{
			save << plantacao[i].zona[x].nome << "\n"
				<< plantacao[i].zona[x].area << "\n"
				<< plantacao[i].zona[x].rega << "\n"
				<< plantacao[i].zona[x].resistencia << "\n"
				<< plantacao[i].zona[x].fornecedores << "\n"
				<< plantacao[i].zona[x].regaCooldown << "\n" << "\n";
		}
		//gravar backlog
		for (int x = 0; x < 100; x++)
		{
			save << plantacao[i].backlog[x] << "\n";
		}

	}
	//guardar as areas existentes
	for (int i = 0; i < 15; i++)
	{
		save << areasDisponiveis[i] << "\n";
	}
	save.close();

}
void ExportarArmazem(int tamanhoDoArmazem, int produtosNoArmazem, produto armazem[]) {

	ofstream save;
	save.open("SaveArmazem.txt");
	for (int i = 0; i < produtosNoArmazem; i++)
	{
		save << armazem[i].nome << "\n"
			<< armazem[i].area << "\n"
			<< armazem[i].rega << "\n"
			<< armazem[i].resistencia << "\n"
			<< armazem[i].fornecedores << "\n"
			<< armazem[i].regaCooldown << "\n" << "\n";
	}
	save.close();
}

void ImportHortas(int* tamanhoDoArmazem, int* produtosNoArmazem, int* numeroHortas, int* hortaCount, int* areasCount, int* produtosCount, int* fornecedoresCount, int* areasDiferentes, horta plantacao[], string areasDisponiveis[]) {

	ifstream save;
	save.open("Save.txt");
	if (save.is_open()) {
		string line;
		//importar variaveis simples
		getline(save, line);
		*tamanhoDoArmazem = stoi(line);
		getline(save, line);
		*produtosNoArmazem = stoi(line);
		getline(save, line);
		*numeroHortas = stoi(line);
		getline(save, line);
		*hortaCount = stoi(line);
		getline(save, line);
		*areasCount = stoi(line);
		getline(save, line);
		*produtosCount = stoi(line);
		getline(save, line);
		*fornecedoresCount = stoi(line);
		getline(save, line);
		*areasDiferentes = stoi(line);
		getline(save, line);
		//importar hortas
		for (int i = 0; i < 10; i++)
		{
			getline(save, line);
			plantacao[i].nome = line[0];
			getline(save, line);
			plantacao[i].agricultor = line;
			getline(save, line);
			plantacao[i].tamanho = stoi(line);
			getline(save, line);
			plantacao[i].area = line;
			getline(save, line);
			if (line[0] == '1') {
				plantacao[i].fertelizado = true;
			}
			else {
				plantacao[i].fertelizado = false;
			}
			getline(save, line);
			plantacao[i].campanhaTempo = stoi(line);
			//importar cada zona das hortas
			for (int x = 0; x < 9; x++)
			{
				getline(save, line);
				getline(save, line);
				plantacao[i].zona[x].nome = line;
				getline(save, line);
				plantacao[i].zona[x].area = line;
				getline(save, line);
				plantacao[i].zona[x].rega = stoi(line);
				getline(save, line);
				plantacao[i].zona[x].resistencia = stoi(line);
				getline(save, line);
				plantacao[i].zona[x].fornecedores = line;
				getline(save, line);
				plantacao[i].zona[x].regaCooldown = stoi(line);

			}
			getline(save, line);
			//importar o backlog
			for (int y = 0; y < 100; y++)
			{

				getline(save, line);
				plantacao[i].backlog[y] = line;
			}

		}
		//importar areas existentes
		for (int i = 0; i < 15; i++)
		{
			getline(save, line);
			areasDisponiveis[i] = line;
		}

		save.close();

	}
}
void ImportArmazem(int* tamanhoDoArmazem, int* produtosNoArmazem, produto armazem[]) {

	ifstream save;
	save.open("SaveArmazem.txt");
	if (save.is_open()) {
		string line;

		for (int i = 0; i < *produtosNoArmazem; i++)
		{
			getline(save, line);
			armazem[i].nome = line;
			getline(save, line);
			armazem[i].area = line;
			getline(save, line);
			armazem[i].rega = stoi(line);
			getline(save, line);
			armazem[i].resistencia = stoi(line);
			getline(save, line);
			armazem[i].fornecedores = line;
			getline(save, line);
			armazem[i].regaCooldown = stoi(line);
			getline(save, line);

		}
		save.close();
	}
}

void PrintProducts(horta plantacao[], int* hortasCount, produto armazem[], int* produtosNoArmazem, int* tamanhoDoArmazem) { // 0 para ordem alfabetica e 1 para tempo de plantação (não implementado)
	system("cls");
	for (int i = 0; i < *hortasCount; i++)
	{
		int numProdutos = 0;
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome != "N/A") {
				numProdutos++;
			}
		}
		cout << "Horta: " << plantacao[i].nome <<
			" | Responsavel: " << plantacao[i].agricultor <<
			" | Capacidade: " << plantacao[i].tamanho <<
			" | Produtos: " << numProdutos <<
			" | Area: " << plantacao[i].area << endl;
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome != "N/A") {
				cout << "Produto: " << plantacao[i].zona[x].nome <<
					"| Rega: " << plantacao[i].zona[x].regaCooldown <<
					" | Resistencia: " << plantacao[i].zona[x].resistencia << "%" << endl;
			}

		}
		cout << "---------------------------------" << endl;
	}
	cout << "Inventario do armazem:" << endl << endl;
	for (int i = 0; i < *produtosNoArmazem; i++)
	{
		cout << "Produto: " << armazem[i].nome
			<< "| Resistencia: " << armazem[i].resistencia
			<< " | Area: " << armazem[i].area
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

			areasDisponiveis[i] = area; //retira a area anterior e cria nova
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
			for (int x = 0; x < 100; x++)
			{
				if (plantacao[i].backlog[x] != "")
				{
					cout << x + 1 << ". " << plantacao[i].backlog[x] << endl;
				}
			}
		}
	}
	getline(cin, input);
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
	}
	*produtosNoArmazem = *produtosNoArmazem + quantidade;
}

void CriarNovaHorta(int quantidade, int* numeroDeHortas, int* areasCount, int* produtosCount, int* fornecedoresCount, horta plantacao[], int* hortaCount, int* areasDiferentes, string areasDisponiveis[]) {
	system("cls");
	cout << "Foram criadas " << quantidade << " novas!" << endl << endl;

	//Para cada horta a ser criada
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
		cin >> plantacao[i].agricultor;
		*hortaCount = *hortaCount + 1;
		cout << endl;
	}
}

