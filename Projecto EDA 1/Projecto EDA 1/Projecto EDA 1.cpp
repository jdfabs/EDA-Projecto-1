
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>

<<<<<<< Updated upstream
=======
#include "funcoes.h"
#include "ciclo.h"
#include "menus.h"

>>>>>>> Stashed changes
using namespace std;



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


	MenuInicial(&areasCount, &produtosCount, &fornecedoresCount, &numeroHortas, plantacao, &hortaCount, &areasDiferentes, areasDisponiveis, &tamanhoDoArmazem, &armazemTEMP, &armazem, &produtosNoArmazem);

	MenuGestao(&areasCount, &produtosCount, &fornecedoresCount, &numeroHortas, plantacao, &hortaCount, &areasDiferentes, areasDisponiveis, &tamanhoDoArmazem, &armazemTEMP, &armazem, &produtosNoArmazem);
	
	delete[] armazem;
	return 0;

}






