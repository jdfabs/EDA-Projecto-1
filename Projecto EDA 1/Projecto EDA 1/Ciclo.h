

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
	system("cls");
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
	cout << "Remocao de produtos" << endl;
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
					plantacao[x].zona[y].fornecedores = armazem[i].fornecedores;
					plantacao[x].zona[y].rega = armazem[i].rega;
					plantacao[x].zona[y].resistencia = armazem[i].resistencia;
					plantacao[x].zona[y].regaCooldown = armazem[i].rega;
					zonaDone = true;

					//compactar armazem (mover os produtos para o inicio do array)
					for (int y = i; y < *produtosNoArmazem + 1; y++)
					{
						armazem[y].area = armazem[y + 1].area;
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
	cout << "Pragas" << endl;

	for (int i = 0; i < *hortaCount; i++)
	{
		for (int x = 0; x < plantacao[i].tamanho; x++)
		{
			if (plantacao[i].zona[x].regaCooldown == 0 && plantacao[i].zona[x].nome != "N/A")
			{
				int random = rand() % 100;
				if (plantacao[i].zona[x].resistencia < random)
				{
					cout << "Uma produção de " << plantacao[i].zona[x].nome << "na horta " << plantacao[i].nome << " foi perdida!" << endl;
					plantacao[i].zona[x].nome = "N/A";
					plantacao[i].zona[x].fornecedores = "N/A";
					plantacao[i].zona[x].rega = 999;
					plantacao[i].zona[x].resistencia = 100;
				}
			}
		}
	}
	cin >> input;
}
