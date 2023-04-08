//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include <iostream>
#include <vector>
#include <string>
#include "Jogo.h"
#include "JogoPC.h"
#include "JogoConsole.h"
#include "EmpresaDesenvolvedora.h"
#include "PlataformaDigital.h"
#include "FuncoesDaMain.h"

//a ideia aqui era usar a funcao da parte 3 da lista de sala e adaptar somente na main.
//@ -- recebe: plataforma e o jogo
//@ -- printa: se o jogo foi presenteado ou transformado em dinheiro
//obs: a verificacao se ha dinheiro suficiente pra poder presentear é feita na main, no case 10;
void presenteVirtual(PlataformaDigital *pA, Jogo *presente) {
	unsigned int i, x = 0;
	presente->imprimeInfoJogo();

	size_t k = pA->getjogoscadastrados().size();
	// cout << " Valor de k: " << k << endl;
	for (i = 0; i < k; i++) {
		if (presente == pA->getjogoscadastrados()[i]) {

			cout << "O usuario ja possui este jogo, o valor sera convertido em creditos." << endl;
			pA->setcarteiraDigital( pA->getcarteiraDigital() + presente->getvalor() ) ;
			cout << "O usuario recebeu " << presente->getvalor() << " creditos de presente!" << endl;
			x = 1;
		}
	}

	if (x != 1) {
		pA->jogoscadastrados.push_back(presente);

		cout << "Jogo Presenteado." << endl;
		//pA->getjogoscadastrados()[0]->imprimeInfoJogo();
	}
}

int main (){
	vector <EmpresaDesenvolvedora*> *EmpresasDesenvolvedoras = new vector <EmpresaDesenvolvedora*>;
	EmpresasDesenvolvedoras->resize(3);
	EmpresasDesenvolvedoras->at(0) = new EmpresaDesenvolvedora("Riot");
	EmpresasDesenvolvedoras->at(1) = new EmpresaDesenvolvedora("Blizzard");
	EmpresasDesenvolvedoras->at(2) = new EmpresaDesenvolvedora("Konami");

	vector <PlataformaDigital*> *PlataformasDigitais = new vector <PlataformaDigital*>;
	PlataformasDigitais->resize(3);
	PlataformasDigitais->at(0) = new PlataformaDigital("Steam1");
	PlataformasDigitais->at(1) = new PlataformaDigital("Steam2");
	PlataformasDigitais->at(2) = new PlataformaDigital("Steam3");

	int choose; //opçao do menu
	int breakcond = 0; //condicao de saida do programa
	char c; //string qualquer de entrada;

	choose = imprimeMenu();
	do{
		switch (choose) {
			case 1:{ // Criar jogo

			//selecionar qual empresa e depois chamar funcao
				int a = 0;
				do {

					int n;
					EmpresaDesenvolvedora *empresaEscolhida;

					n = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
					if (n == -1) {
						cout << "Saindo..." << endl;
						break;
					}

					empresaEscolhida = EmpresasDesenvolvedoras->at(n);

					empresaEscolhida->CriarJogo();
					int numeroDeJogos = empresaEscolhida->getnumerojogos();

					empresaEscolhida->getjogosdesenvolvidos()[ numeroDeJogos - 1 ]->imprimeInfoJogo();

					cout << endl;
					do {
						cout <<  "Deseja criar outro jogo?(S/N):";
						cin >> c;
						c = toupper(c);
					} while (c != 'S' && c != 'N');

					if (c == 'S') {
                        a = 1;
					}
					else {
						a = 0;
					}

				} while (a);

				break;
			}
			case 2:{ // Colocar jogo em promoção

                //----------------------------------------------------------------------IMPLEMENTAR>::::::
                // LISTAR TODOS OS JOGOS E DEPOIS SELECIONAR UM DA LISTA E DAR SEUS PULO

				//colocar jogo em promoção
				//selecionar qual empresa e chamar funcao

				EmpresaDesenvolvedora* empresaSelecionada;

				int n = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
				if (n == -1) {
					break;
				}

                empresaSelecionada = EmpresasDesenvolvedoras->at(n);

				if (!empresaSelecionada->getnumerojogos()) {
					cout << "Nao ha jogos nesta empresa!!" << endl;
					break;
				}

				empresaSelecionada->colocarJogoemPromocao();

				break;
			}
			case 3:{ // Tirar jogo de promoção
				EmpresaDesenvolvedora* empresaSelecionada;

				int n = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
				if (n == -1) {
					break;
				}

				empresaSelecionada = EmpresasDesenvolvedoras->at(n);

				if (!empresaSelecionada->getnumerojogos()) {
					cout << "Nao ha jogos nesta empresa!!" << endl;
					break;
				}

				empresaSelecionada->tirarJogoPromocao();

				break;
			}
			case 4:{ // Comprar jogo

				//comprar jogo
				//selecionar qual plataforma e depois qual empresa, listar jogos e enviar para a funcao o jogo

				int n;
                PlataformaDigital* plataformaCompradora;
                EmpresaDesenvolvedora* empresaVendedora;
                Jogo* jogoComprado;

				int n_compradora = selecionaPlataformaDigital(PlataformasDigitais);
				if (n_compradora == -1) {
					break;
				}

				plataformaCompradora = PlataformasDigitais->at(n_compradora);

				int n_vendedora = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
				if (n_vendedora == -1) {
					break;
				}

				empresaVendedora = EmpresasDesenvolvedoras->at(n_vendedora);

				int k = empresaVendedora->getnumerojogos();
				if (!k) {
					cout << "Nao ha jogos nesta empresa!!" << endl;
					break;
				}

				cout << "Selecione um dos jogos da lista" << endl;
				if ( !(empresaVendedora->getjogosdesenvolvidos().size()) ){
                    cout << "Nao ha jogos para serem comprados na empresa escolhida!" << endl;
                    break;
				}
				empresaVendedora->imprimeJogosdesenvolvidas();

				cin >> n;
				while ( (n < 0 || n > k - 1) && n != -1){
                    if (n < 0 || n > k - 1)
						cout << "Opcao INDISPONIVEL, digite uma opcao contida na lista ou -1 para sair: ";
                    cin >> n;
				}
				if (n == -1)
                    break;

                jogoComprado = empresaVendedora->getjogosdesenvolvidos().at(n);

				if (n != -1)//a funcao verifica se ele eh capaz de comprar o jogo
					plataformaCompradora->comprarJogo( jogoComprado );

				break;
			}
			case 5:{ // Adicionar créditos

                //Adicionar créditos a plataforma
                float _valor;
                PlataformaDigital* empresaCarteira;

				int n = selecionaPlataformaDigital(PlataformasDigitais);

				if (n == -1) {
					break;
				}

                empresaCarteira = PlataformasDigitais-> at(n);

				do{
					cout << "Digite o valor a ser adicionado: ";
					cin >> _valor;
					if (_valor < 0) {
						cout << "Trola nao brother, digita um valor humilde ai. " << endl;
					}
				} while (_valor < 0);

				empresaCarteira->acidicionarCreditorsCarteira(_valor);

				break;
			}
			case 6:{ // Instalar jogo
				//instalar jogo
                PlataformaDigital* plataformaSelecionada;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1) {
					break;
				}

				plataformaSelecionada = PlataformasDigitais->at(n);

				plataformaSelecionada->instalarJogo();

				break;
			}
			case 7:{ // Desistalar jogo

				//desistalar jogo

				PlataformaDigital* plataformaEscolhida;

				int n = selecionaPlataformaDigital(PlataformasDigitais);

				if (n == -1) {
					break;
				}

				plataformaEscolhida = PlataformasDigitais->at(n);

				plataformaEscolhida->desinstalarJogo();

				break;
			}
			case 8:{ // Imprimir jogos Cadastrados

				//imprimir jogos cadastados

				PlataformaDigital* plataformaSelecionada;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1) { //sai
					break;
				}

                plataformaSelecionada = PlataformasDigitais->at(n);

				plataformaSelecionada->imprimeJogosCadastrados();

				break;
			}
			case 9:{ // Imprimir jogos instalados
				//imprimir jogos instalados
                PlataformaDigital* plataformaDigitalSelecionada;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1) { //sai
					break;
				}

                plataformaDigitalSelecionada = PlataformasDigitais->at(n);

				plataformaDigitalSelecionada->imprimeJogosInstalados();

				break;
			}
			case 10:{ // Imprimir jogos cadastrados pelo gênero
				//imprimir jogos cadastrados pelo genero

				PlataformaDigital* plataformaDigitalSelecionada;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1) {
					break;
				}

				string genero;
				cout << "Escolha o nome do genero, por favor, da mesma forma que foi registrado no jogo." << endl;
				cin >> genero;

				plataformaDigitalSelecionada = PlataformasDigitais->at(n);

				plataformaDigitalSelecionada->imprimeJogos(genero);

				break;
			}
			case 11:{ // Presentear plataforma

                //presentear Plataform

				int n, n_comprador, n_presenteado, n_empresa;
				Jogo *jogoPresente;
				EmpresaDesenvolvedora *empresaSelecionada;
				PlataformaDigital *plataformaCompradora, *plataformaPresenteada;

				cout << "Selecione a Plataforma Digital compradora da lista." << endl;
				n_comprador = selecionaPlataformaDigital(PlataformasDigitais);
				if (n_comprador == -1) {
					cout << "Voce escolheu sair." << endl;
					break;
				}
				plataformaCompradora = PlataformasDigitais->at(n_comprador);

				cout << "Seleciona agora, a Plataforma Digital presenteada da lista." << endl;
				n_presenteado = selecionaPlataformaDigital(PlataformasDigitais);
				if (n_comprador == -1) {
					cout << "Voce escolheu sair." << endl;
					break;
				}
				plataformaPresenteada = PlataformasDigitais->at(n_presenteado);

				cout << "Selecione a EmpresaDesenvolvedora do jogo que deseja presentear." << endl;
				n_empresa = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
				if (n_empresa == -1) {
					cout << "Voce escolheu sair." << endl;
					break;
				}
				empresaSelecionada = EmpresasDesenvolvedoras->at(n_empresa);

				int i = empresaSelecionada->getnumerojogos(); //tamanho do vetor de jogos da empresa desenvolvedora
				if (i == 0) {
					cout << "Nao ha jogos para serem presentados nessa Empresa Desenvolvedora! Saindo..." << endl;
					break;
				}

				cout << "Selecione um dos jogos da lista desta empresa:" << endl;
				empresaSelecionada->imprimeJogosdesenvolvidas();


                cin >> n;
				while ( (n < 0 || n > i - 1) && n != -1){
                    if (n < 0 || n > i - 1)
                        cout << "Jogo escolhido INVALIDO, escolha um numero valido ou -1 para sair: ";
                    cin >> n;
				}
				if (n == -1) {
					cout << "Voce escolheu sair." << endl;
					break;
				}

				float valorDoJogo = empresaSelecionada->getjogosdesenvolvidos()[n]->getvalor();
				float valorDaCarteira = plataformaCompradora->getcarteiraDigital();
				jogoPresente = empresaSelecionada->getjogosdesenvolvidos()[n];

				if (valorDaCarteira >= valorDoJogo) {
					presenteVirtual(plataformaPresenteada, jogoPresente);
				}
				else {
					cout << "Nao ha dinheiro suficiente na carteira digital para presentear o jogo!" << endl;
					cout << "Voce possui: " << valorDaCarteira << " . E precisa de: " << valorDoJogo << endl;
				}

				break;
			}
			case 12:{ // Imprime quantidade de jogos criados

				Jogo::imprimeqtdJogos();
				size_t k = EmpresasDesenvolvedoras->size();
				unsigned int i;
				for (i = 0; i < k; i++) {
					cout << "[" << i << "] Jogos da plataforma " << EmpresasDesenvolvedoras->at(i)->getnome() << " : " << EmpresasDesenvolvedoras->at(i)->getnumerojogos() << endl;
				}
				break;
			}
			case 13:{ // Salvar Empresa Desenvolvedora
				EmpresaDesenvolvedora* empresaEscolhida;

				int n = selecionaEmpresaDesenvolvedora(EmpresasDesenvolvedoras);
				if (n == -1){
					cout << "Voce escolheu sair..." << endl;
					break;
				}

				empresaEscolhida = EmpresasDesenvolvedoras->at(n);
				empresaEscolhida->salvarDados();

				cout << "Operacao de escrita realizada com sucesso." << endl;

				break;
			}
			case 14:{ // Salvar Plataforma Digital
                PlataformaDigital* plataformaEscolhida;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1){
					cout << "Voce escolheu sair..." << endl;
					break;
				}

				plataformaEscolhida = PlataformasDigitais->at(n);
				plataformaEscolhida->salvarDados();

				cout << "Operacao de escrita realizada com sucesso" << endl;
				break;
			}
			case 15:{ // Carregar Empresa Desenvolvedora
				EmpresaDesenvolvedora* novaEmpresa;

				string entrada;
				ifstream arquivoEmpresa;
				string nomeDoArquivo;

				cout << "Digite o nome da Empresa Desenvolvedora que deseja carregar ou -1 para sair." << endl;

				cin >> entrada;
				if (entrada.compare("-1") == 0){
					cout << "Voce escolheu sair..." << endl;
					break;
				}

				nomeDoArquivo = entrada + ".txt";
				arquivoEmpresa.open(nomeDoArquivo);

				if(!arquivoEmpresa.is_open()){
					cout << "Nao existem dados a serem carregados do arquivo " << nomeDoArquivo << " da empresa." << endl;
					arquivoEmpresa.close();
					break;
				}
				arquivoEmpresa.close();

				char cqualquer = 'Q'; //Q de qualquer kk
				int i;
				int k = (int)EmpresasDesenvolvedoras->size();
				for (i = 0; i < k; i++){ //verificacao se a empresa ja existe
					if( entrada.compare( EmpresasDesenvolvedoras->at(i)->getnome() ) == 0){
						cout << "Empresa desenvolvedora " << EmpresasDesenvolvedoras->at(i)->getnome() << " ja existe." << endl;

						do {
							cout << "Deseja sobreescrever os dados? (S/N) (\"Nao\" voltara para o menu)" << endl;
							cin >> cqualquer;
							cqualquer = toupper(cqualquer);
						} while (cqualquer != 'S' && cqualquer != 'N');
						break;
					}

				}

				if (cqualquer == 'N'){
					break;
				}
				if (cqualquer == 'S'){
					EmpresasDesenvolvedoras->at(i)->carregarDados(nomeDoArquivo);
					cout << "Operacao de sobreescrita realizada com sucesso" << endl;
					break;
				}

				novaEmpresa = new EmpresaDesenvolvedora;

				novaEmpresa->carregarDados(nomeDoArquivo);

				EmpresasDesenvolvedoras->push_back(novaEmpresa);

				cout << "Operacao de leitura realizada com sucesso." << endl;
				break;
			}
			case 16:{ // Carregar Plataforma Digital
				PlataformaDigital* novaPlataforma;

				string entrada;
				ifstream arquivoPlataforma;
				string nomeDoArquivo;

				cout << "Digite o nome da Plataforma Digital que deseja carregar ou -1 para sair." << endl;

				cin >> entrada;
				if (entrada.compare("-1") == 0){
					cout << "Voce escolheu sair..." << endl;
					break;
				}

				nomeDoArquivo = entrada + ".txt";
				arquivoPlataforma.open(nomeDoArquivo);

				if(!arquivoPlataforma.is_open()){
					cout << "Nao existem dados a serem carregados do arquivo " << nomeDoArquivo << " da empresa." << endl;
					arquivoPlataforma.close();
					break;
				}

				char cqualquer = 'Q'; //Q de qualquer kk
				int i;
				int k = (int)PlataformasDigitais->size();
				for (i = 0; i < k; i++){ //verificacao se a empresa ja existe
					if( entrada.compare( PlataformasDigitais->at(i)->getnome() ) == 0){
						cout << "Empresa desenvolvedora " << PlataformasDigitais->at(i)->getnome() << " ja existe." << endl;

						do {
							cout << "Deseja sobreescrever os dados dela? (S/N ou 0 para sair)" << endl;
							cin >> cqualquer;
							cqualquer = toupper(cqualquer);
						} while (cqualquer != 'S' && cqualquer != 'N' && cqualquer != '0');
						break;
					}

				}

				if (cqualquer == '0' || cqualquer == 'N'){
					arquivoPlataforma.close();
					break;
				}
				if (cqualquer == 'S'){
					arquivoPlataforma.close();
					PlataformasDigitais->at(i)->carregarDados(nomeDoArquivo);
					cout << "Operacao de sobreescrita realizada com sucesso" << endl;
					break;
				}

				novaPlataforma = new PlataformaDigital;

				arquivoPlataforma.close();
				novaPlataforma->carregarDados(nomeDoArquivo);

				PlataformasDigitais->push_back(novaPlataforma);

				cout << "Operacao de leitura realizada com sucesso." << endl;
				break;
			}
			case 17:{ // Exportar biblioteca de uma Plataforma Digital
				PlataformaDigital* plataformaEscolhida;

				int n = selecionaPlataformaDigital(PlataformasDigitais);
				if (n == -1){
					cout << "Voce escolheu sair..." << endl;
					break;
				}

				plataformaEscolhida = PlataformasDigitais->at(n);
				plataformaEscolhida->exportarBibliotecaJogos();

				cout << "Biblioteca exportada para um arquivo .html com sucesso." << endl;

				break;

			}
			case 18:{ // Sair do programa
				breakcond = 1;
				break;
			}

			default:{
				cout << "Valor escolhido invalido!. Selecione um numero valido do menu" << endl;
			}

		} //fim switch
		if (breakcond != 1) {
			cout << "Digite qualquer letra para voltar para o menu." << endl;
			cin >> c;
			clearTerminal();
			choose = imprimeMenu();
		}

	} while (breakcond == 0);

	EmpresasDesenvolvedoras->clear();
	delete (EmpresasDesenvolvedoras);

	PlataformasDigitais->clear();
	delete PlataformasDigitais;

  return 0;
}
