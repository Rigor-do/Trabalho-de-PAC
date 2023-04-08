//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "FuncoesDaMain.h"
#include <stdlib.h>
#include <fstream>

//troque isso caso esteja em outra plataforma. Só altera a limpeza do terminal
#define isWindows 1
#define isLinux 0

using namespace std;

int imprimeMenu() {
	int acao;

	cout << "================================================================================" << endl;
	cout << "[1] Criar Jogo;" << endl;
	cout << "[2] Colocar Jogo em Promocao;" << endl;
	cout << "[3] Tirar Jogo de Promocao;" << endl;
	cout << "[4] Comprar Jogo;" << endl;
	cout << "[5] Adicionar Creditos a Carteira;" << endl;
	cout << "[6] Instalar Jogo;" << endl;
	cout << "[7] Desisntalar Jogo;" << endl;
	cout << "[8] Imprimir Jogos Cadastrados;" << endl;
	cout << "[9] Imprimir Jogos Instalados;" << endl;
	cout << "[10] Imprimir Jogos Cadastrados por Genero;" << endl;
	cout << "[11] Presentear Plataforma;" << endl;
	cout << "[12] Imprimir Quantidade de Jogos;" << endl;
	cout << "[13] Salvar Empresa Desenvolvedora;" << endl;
	cout << "[14] Salvar Plataforma Digital;" << endl;
	cout << "[15] Carregar Empresa Desenvolvedora;" << endl;
	cout << "[16] Carregar Plataforma Digital;" << endl;
	cout << "[17] Exportar Biblioteca de uma Plataforma Digital;" << endl;
	cout << "[18] Sair do programa." << endl;
	cout << "================================================================================" << endl;

	cout << "Escolha uma Funcao: ";
	cin >> acao;

	return acao;
}

void clearTerminal() {
    if (isWindows)
        system("cls");
	else if (isLinux)
		system("clear");
	else{
		int i;
		for (i = 0; i < 2; i++)
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	}
    return;
}

int selecionaPlataformaDigital(vector <PlataformaDigital*> *vec) {
	unsigned int i;
	int n;
	size_t k = vec->size();

	cout << "Escolha a PlataformaDigital para a operacao:" << endl;
	for (i = 0; i < k; i++) {
		cout << "[" << i << "] -> Plataforma Digital: " << vec->at(i)->getnome() << endl;
	}
	cout << "Plataforma: ";

	cin >> n;
	while ( (n < 0 || n >(int)(k - 1)) && n != -1) {
		if ( (n < 0 || n >(int)(k - 1)) )
			cout << "Numero invalido, digite um numero valido ou -1 para sair. Plataforma: ";
		cin >> n;
	}

	return n;
}

int selecionaEmpresaDesenvolvedora(vector <EmpresaDesenvolvedora*> *vec) {
	unsigned int i;
	int n;
	size_t k = vec->size();

	cout << "Escolha a Empressa Desenvolvedora para a operacao:" << endl;
	for (i = 0; i < k; i++) {
		cout << "[" << i << "] -> Empressa Desenvolvedora: " << vec->at(i)->getnome() << endl;
	}
	cout << "Empresa: ";

	cin >> n;
	while ( (n < 0 || n >(int)(k - 1)) && n != -1) {
		if ( (n < 0 || n >(int)(k - 1)) )
			cout << "Numero invalido, digite um numero valido ou -1 para sair. Empresa: ";
		cin >> n;
	}

	return n;
}

