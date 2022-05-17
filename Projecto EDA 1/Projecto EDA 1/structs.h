
using namespace std;

struct produto {
	string nome = "N/A";
	string area = "N/A";
	int rega = 0;
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