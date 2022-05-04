
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Funcoes.h>

using namespace std;

void Ciclo(int* hortaCount, horta plantacao[], int* produtosNoArmazem, int* produtosCount, int* areasCount, int* fornecedoresCount, produto armazem[], int* tamanhoDoArmazem, produto armazemTEMP[], int* areasDiferentes, string areasDisponiveis[]);

int main() {

	srand(time(NULL));
	string input;

	produto* armazem;
	int tamanhoDoArmazem = 15;
	armazem = new produto[tamanhoDoArmazem];
	int produtosNoArmazem = 0;

	produto* armazemTEMP;
	armazemTEMP = new produto[tamanhoDoArmazem];

	horta plantacao[10];

	int numeroHortas = 0;
	int hortaCount = 0;

	int areasCount = 0;
	int produtosCount = 0;
	int fornecedoresCount = 0;

	string areasDisponiveis[15];
	int areasDiferentes = 0;

	cout << "Bem vindo á Plantação de EDA" << endl << endl;
	cout << "Deseja criar a plantação de raiz ou importar uma plantação existente?" << endl;
	cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
	cin >> input;

	//inicializaçao
	if (input == "1") {
		//atualizar numero de areas/produtos/fornecedores existentes nos ficheiros
		if (areasCount == 0 || produtosCount == 0 || fornecedoresCount == 0) {
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
		}


		numeroHortas = rand() % 6 + 5; 
		CriarNovaHorta(numeroHortas, &numeroHortas, &areasCount, &produtosCount, &fornecedoresCount, plantacao, &hortaCount, &areasDiferentes, areasDisponiveis);

		//criação dos 15 produtos random          
		tamanhoDoArmazem = tamanhoDoArmazem + 15;

		//atualizar para o tamanho correcto array armazem
		delete[] armazemTEMP;
		armazemTEMP = new produto[tamanhoDoArmazem];
		for (int i = 0; i < produtosNoArmazem; i++)
		{
			armazemTEMP[i] = armazem[i];
		}
		delete[] armazem;
		armazem = new produto[tamanhoDoArmazem];
		for (int i = 0; i < produtosNoArmazem; i++)
		{
			armazem[i] = armazemTEMP[i];
		}

		AdicionarProdutoAoArmazem(15, &produtosNoArmazem, &produtosCount, &areasCount, &fornecedoresCount, armazem, &tamanhoDoArmazem, &areasDiferentes, areasDisponiveis);
		//clear screen
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

		//Menu Gestão
		if (input == "g") { // GESTÃO
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
				ColheitaManual(input, plantacao, &hortaCount);
			}

			//Atualizar tempo de rega
			if (input == "2") {
				string produto;
				int tempo;
				cout << "produto a alterar:" << endl;
				cin >> produto;
				cout << "novo tempo: " << endl;
				cin >> tempo;
				AtualizarRega(produto, tempo, plantacao, &hortaCount, armazem, &produtosNoArmazem, &tamanhoDoArmazem);
			}

			//Fertilização
			if (input == "3") {
				string input1;
				int input2;
				cout << "Area a fertelizar: " << endl;
				cin >> input1;
				cout << "Duração da fertelização:" << endl;
				cin >> input2;
				Fertilizar(input1, input2, plantacao, &hortaCount);
			}

			//Gravar Plantação
			if (input == "4") {
				ExportarHortas(tamanhoDoArmazem, produtosNoArmazem, numeroHortas, hortaCount, areasCount, produtosCount, fornecedoresCount, areasDiferentes, plantacao, areasDisponiveis);
				ExportarArmazem(tamanhoDoArmazem, produtosNoArmazem, armazem);
			}

			//Carregar Plantação
			if (input == "5") {
				

				ImportHortas(&tamanhoDoArmazem, &produtosNoArmazem, &numeroHortas, &hortaCount, &areasCount, & produtosCount, &fornecedoresCount, &areasDiferentes, plantacao, areasDisponiveis);
				delete[] armazemTEMP;
				armazemTEMP = new produto[produtosNoArmazem+15];
				
				delete[] armazem;
				armazem = new produto[produtosNoArmazem + 15];
				
				ImportArmazem(&tamanhoDoArmazem, &produtosNoArmazem,armazem);


			}

			//Imprimir Plantação
			if (input == "6") {
				PrintProducts(plantacao, &hortaCount, armazem, &produtosNoArmazem, &tamanhoDoArmazem);
			}

			//Criar nova área
			if (input == "7") {
				string input;
				cout << "Introduza o nome da nova area: " << endl;
				cin >> input;
				CriarArea(input, &areasDiferentes, areasDisponiveis);
			}

			//Mostrar registo de agricultor
			if (input == "8") {
				cout << "introduza o nome do agricultor: " << endl;
				cin >> input;
				Backlog(input, plantacao, numeroHortas);
			}

			//Alterar área
			if (input == "9") {
				char nomeDaHorta;
				string novaArea;
				cout << "introduza o nome da horta: " << endl;
				cin >> nomeDaHorta;
				cout << "introduza a nova area: " << endl;
				cin >> novaArea;
				AlterarArea(plantacao, nomeDaHorta, novaArea, numeroHortas, &areasDiferentes, areasDisponiveis);
			}
		}

		//ativar novo ciclo
		if (input == "s")
		{
			delete[] armazemTEMP;
			armazemTEMP = new produto[tamanhoDoArmazem];
			for (int i = 0; i < produtosNoArmazem; i++)
			{
				armazemTEMP[i] = armazem[i];
			}
			delete[] armazem;
			armazem = new produto[tamanhoDoArmazem];
			for (int i = 0; i < produtosNoArmazem; i++)
			{
				armazem[i] = armazemTEMP[i];
			}
			Ciclo(&hortaCount, plantacao, &produtosNoArmazem, &produtosCount, &areasCount, &fornecedoresCount, armazem, &tamanhoDoArmazem, armazemTEMP, &areasDiferentes, areasDisponiveis);
		}

		// Testes
		else if (input == "z") {
			/*for (int i = 0; i < areasDiferentes; i++)
			{
				cout << areasDisponiveis[i] << endl;
			}
			for (int i = 0; i < hortaCount; i++)
			{
				cout << "Area: " << plantacao[i].area << "  | Horta " << plantacao[i].nome << " contem: " << endl;
				for (int x = 0; x < plantacao[i].tamanho; x++)
				{
					cout << x + 1 << ". " << plantacao[i].zona[x].nome << " Resistencia: " << plantacao[i].zona[x].resistencia << endl;
				}

			}
			cout << "Inventario do armazem:" << endl;
			for (int i = 0; i < produtosNoArmazem; i++)
			{
				cout << i + 1 << ". " << armazem[i].nome << " | " << armazem[i].area << endl;
			}
			cin >> input;*/

			cout << tamanhoDoArmazem << endl <<
				produtosNoArmazem << endl <<
				numeroHortas << endl <<
				hortaCount << endl <<
				areasCount << endl <<
				produtosCount << endl <<
				fornecedoresCount << endl <<
				areasDiferentes << endl;
			cin >> input;


		}

		else if (input == "0") { // SAIR DO PROGRAMA
			break;
		}
	}
	delete[] armazem;
	return 0;

}

void Ciclo(int* hortaCount, horta plantacao[], int* produtosNoArmazem, int* produtosCount, int* areasCount, int* fornecedoresCount, produto armazem[], int* tamanhoDoArmazem, produto armazemTEMP[], int* areasDiferentes, string areasDisponiveis[]) {
	ifstream areas;
	ifstream produtos;
	ifstream fornecedores;
	string input;
	plantacao[0].fertelizado;
	plantacao[0].campanhaTempo;

	//check if fertelizado
	for (int i = 0; i < *hortaCount; i++)
	{
		if (plantacao[i].fertelizado == true)
		{
			plantacao[i].campanhaTempo--;
			for (int x = 0; x < plantacao[i].tamanho; x++)
			{
				plantacao[i].zona[x].resistencia = plantacao[i].zona[x].resistencia + 10;
				if (plantacao[i].zona[x].resistencia > 100)
				{
					plantacao[i].zona[x].resistencia = 100;
				}
			}
			if (plantacao[i].campanhaTempo < 0)
			{
				plantacao[i].fertelizado = false;
			}
		}
	}

	//colheita de Produtos
	cout << "Colheita de produtos" << endl;
	for (int i = 0; i < *hortaCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			int random = rand() % 4;
			if (random == 3 && plantacao[i].zona[x].nome != "N/A") {
				for (int y = 0; y < 100; y++)
				{
					if (plantacao[i].backlog[y] == "") {
						plantacao[i].backlog[y] = plantacao[i].zona[x].nome;
						break;
					}
				}
				plantacao[i].zona[x].nome = "N/A";
			}
		}

	}

	//Rega
	cout << "Rega" << endl;
	for (int i = 0; i < *hortaCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].nome != "N/A")
			{
				if (plantacao[i].zona[x].regaCooldown <= 0)
				{
					plantacao[i].zona[x].regaCooldown = plantacao[i].zona[x].rega;
				}
				else
				{
					plantacao[i].zona[x].regaCooldown--;
				}
			}
		}
	}

	//criação dos 10 produtos random
	cout << "criação de produtos" << endl;
	*tamanhoDoArmazem = *tamanhoDoArmazem + 10;
	AdicionarProdutoAoArmazem(10, produtosNoArmazem, produtosCount, areasCount, fornecedoresCount, armazem, tamanhoDoArmazem, areasDiferentes, areasDisponiveis);

	//Remoção de produtos (plantar)
	cout << "remocao de produtos" << endl;
	bool zonaDone = false;
	for (int x = 0; x < *hortaCount; x++)
	{
		for (int y = 0; y < plantacao[x].tamanho; y++)
		{
			zonaDone = false;
			for (int i = 0; i < *produtosNoArmazem; i++)
			{
				if (armazem[i].area == plantacao[x].area && zonaDone == false && plantacao[x].zona[y].nome == "N/A")
				{
					plantacao[x].zona[y].nome = armazem[i].nome;
					plantacao[x].zona[y].duracao = armazem[i].duracao;
					plantacao[x].zona[y].fornecedores = armazem[i].fornecedores;
					plantacao[x].zona[y].rega = armazem[i].rega;
					plantacao[x].zona[y].resistencia = armazem[i].resistencia;
					plantacao[x].zona[y].regaCooldown = armazem[i].rega;
					zonaDone = true;

					//compactar armazem (mover os produtos para o inicio do array)
					for (int y = i; y < *produtosNoArmazem + 1; y++)
					{
						armazem[y].area = armazem[y + 1].area;
						armazem[y].duracao = armazem[y + 1].duracao;
						armazem[y].fornecedores = armazem[y + 1].fornecedores;
						armazem[y].nome = armazem[y + 1].nome;
						armazem[y].rega = armazem[y + 1].rega;
						armazem[y].resistencia = armazem[y + 1].resistencia;
					}
					*produtosNoArmazem = *produtosNoArmazem - 1;
				}
			}
		}
	}

	//pragas
	cout << "pragas" << endl;

	for (int i = 0; i < *hortaCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].regaCooldown == 0 && plantacao[i].zona[x].nome != "N/A")
			{
				int random = rand() % 100;
				if (plantacao[i].zona[x].resistencia < random)
				{
					cout << "Uma produção foi perdida" << endl;
					plantacao[i].zona[x].nome = "N/A";
					plantacao[i].zona[x].duracao = 999;
					plantacao[i].zona[x].fornecedores = "N/A";
					plantacao[i].zona[x].rega = 999;
					plantacao[i].zona[x].resistencia = 100;
				}
			}
		}
	}
}





