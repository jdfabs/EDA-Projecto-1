#pragma once


void MenuInicial(int* areasCount, int* produtosCount, int* fornecedoresCount, int* numeroHortas,horta plantacao[], int* hortaCount, int* areasDiferentes, string* areasDisponiveis, int* tamanhoDoArmazem, produto* armazemTEMP[], produto* armazem[], int* produtosNoArmazem) {

	cout << "Bem vindo á Plantação de EDA" << endl << endl;
	cout << "Deseja criar a plantação de raiz ou importar uma plantação existente?" << endl;
	cout << "(1) Nova" << endl << "(2) Importar" << endl << "(0) Sair do programa" << endl;
	cin >> input;

	//inicializaçao
	if (input == "1") {
		//atualizar numero de areas/produtos/fornecedores existentes nos ficheiros
		if (*areasCount == 0 || *produtosCount == 0 || *fornecedoresCount == 0) {
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


		*numeroHortas = rand() % 6 + 5;
		CriarNovaHorta(*numeroHortas, numeroHortas, areasCount, produtosCount, fornecedoresCount, plantacao, hortaCount, areasDiferentes, areasDisponiveis);

		//criação dos 15 produtos random          
		*tamanhoDoArmazem = *tamanhoDoArmazem + 15;

		//atualizar para o tamanho correcto array armazem
		delete[] armazemTEMP;
		*armazemTEMP = new produto[*tamanhoDoArmazem];
		for (int i = 0; i < *produtosNoArmazem; i++)
		{
			armazemTEMP[i] = armazem[i];
		}
		delete[] armazem;
		*armazem = new produto[*tamanhoDoArmazem];
		for (int i = 0; i < *produtosNoArmazem; i++)
		{
			armazem[i] = armazemTEMP[i];
		}

		AdicionarProdutoAoArmazem(15, produtosNoArmazem, produtosCount, areasCount, fornecedoresCount, *armazem, tamanhoDoArmazem, areasDiferentes, areasDisponiveis);
		//clear screen
		system("cls");
	}

	else if (input == "2") { //IMPORT FILES
		system("cls");
		cout << "Plantação importada.";
		ImportHortas(tamanhoDoArmazem, produtosNoArmazem, numeroHortas, hortaCount, areasCount, produtosCount, fornecedoresCount, areasDiferentes, plantacao, areasDisponiveis);
		delete[] armazemTEMP;
		*armazemTEMP = new produto[*produtosNoArmazem + 15];

		delete[] armazem;
		*armazem = new produto[*produtosNoArmazem + 15];

		ImportArmazem(tamanhoDoArmazem, produtosNoArmazem, *armazem);
	}

}

void MenuGestao(int* areasCount, int* produtosCount, int* fornecedoresCount, int* numeroHortas, horta plantacao[], int* hortaCount, int* areasDiferentes, string* areasDisponiveis, int* tamanhoDoArmazem, produto* armazemTEMP[], produto* armazem[], int* produtosNoArmazem) {
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
				ColheitaManual(input, plantacao, hortaCount);
			}

			//Atualizar tempo de rega
			if (input == "2") {
				system("cls");
				string produto;
				int tempo;
				cout << "Produto a alterar:" << endl;
				cin >> produto;
				cout << "Novo tempo: " << endl;
				cin >> tempo;
				AtualizarRega(produto, tempo, plantacao, hortaCount, *armazem, produtosNoArmazem, tamanhoDoArmazem);
			}

			//Fertilização
			if (input == "3") {
				string input1;
				system("cls");
				int input2;
				cout << "Area a fertelizar: " << endl;
				cin >> input1;
				cout << "Duração da fertelização:" << endl;
				cin >> input2;
				Fertilizar(input1, input2, plantacao, hortaCount);
			}

			//Gravar Plantação
			system("cls");
			if (input == "4") {
				cout << "Plantação gravada.";
				ExportarHortas(*tamanhoDoArmazem, *produtosNoArmazem, *numeroHortas, *hortaCount, *areasCount, *produtosCount, *fornecedoresCount, *areasDiferentes, plantacao, areasDisponiveis);
				ExportarArmazem(*tamanhoDoArmazem, *produtosNoArmazem, *armazem);
				cin >> input;
			}

			//Carregar Plantação
			if (input == "5") {
				system("cls");
				cout << "Plantação carregada.";
				ImportHortas(tamanhoDoArmazem, produtosNoArmazem, numeroHortas, hortaCount, areasCount, produtosCount, fornecedoresCount, areasDiferentes, plantacao, areasDisponiveis);
				delete[] armazemTEMP;
				*armazemTEMP = new produto[*produtosNoArmazem + 15];

				delete[] armazem;
				*armazem = new produto[*produtosNoArmazem + 15];

				ImportArmazem(tamanhoDoArmazem, produtosNoArmazem, *armazem);
				cin >> input;

			}

			//Imprimir Plantação
			if (input == "6") {
				system("cls");
				PrintProducts(plantacao, hortaCount, *armazem, produtosNoArmazem, tamanhoDoArmazem);
			}

			//Criar nova área
			if (input == "7") {
				string input;
				system("cls");
				cout << "Introduza o nome da nova area: " << endl;
				cin >> input;
				CriarArea(input, areasDiferentes, areasDisponiveis);
			}

			//Mostrar registo de agricultor
			if (input == "8") {
				system("cls");
				cout << "Introduza o nome do agricultor: " << endl;
				cin >> input;
				Backlog(input, plantacao, *numeroHortas);
			}

			//Alterar área
			if (input == "9") {
				char nomeDaHorta;
				string novaArea;
				system("cls");
				cout << "Introduza o nome da horta: " << endl;
				cin >> nomeDaHorta;
				cout << "Introduza a nova area: " << endl;
				cin >> novaArea;
				AlterarArea(plantacao, nomeDaHorta, novaArea, *numeroHortas, areasDiferentes, areasDisponiveis);
			}
		}

		//ativar novo ciclo
		else if (input == "s")
		{
			delete[] &armazemTEMP;
			*armazemTEMP = new produto[*tamanhoDoArmazem];
			for (int i = 0; i < *produtosNoArmazem; i++)
			{
				armazemTEMP[i] = armazem[i];
			}
			delete[] armazem;
			*armazem = new produto[*tamanhoDoArmazem];
			for (int i = 0; i < *produtosNoArmazem; i++)
			{
				armazem[i] = armazemTEMP[i];
			}
			Ciclo(hortaCount, plantacao, produtosNoArmazem, produtosCount, areasCount, fornecedoresCount, *armazem, tamanhoDoArmazem, *armazemTEMP, areasDiferentes, areasDisponiveis);
		}


		else if (input == "0") { // SAIR DO PROGRAMA
			break;
		}
	}
}