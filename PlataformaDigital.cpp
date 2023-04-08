//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "PlataformaDigital.h"

using namespace std;

//--construtores e destrutores
PlataformaDigital::PlataformaDigital(){
	this->carteiraDigital = 0;
    //cout << "Criado PlataformaDigital. Metodo construtivo convencional" << endl;
  }
PlataformaDigital::PlataformaDigital(string _nome) {
	this->nome = _nome;
	this->carteiraDigital = 0;
	//this->carteiraDigital = 100.00;
	//cout << "Criado PlataformaDigital. Metodo construtivo convencional" << endl;
}
PlataformaDigital::~PlataformaDigital(){
   // cout << "Destruido PlataformaDigital. Metodo destrutivo convencional" << endl;
}

//--metodos get e set
string PlataformaDigital::getnome() {
	return this->nome;
}
void PlataformaDigital::setnome(string _nome) {
	this->nome = _nome;
	return;
}

float PlataformaDigital::getcarteiraDigital() {
	return this->carteiraDigital;
}
void PlataformaDigital::setcarteiraDigital(float _carteiraDigital) {
	this->carteiraDigital = _carteiraDigital;
	return;
}

vector<Jogo*> PlataformaDigital::getjogosinstalados() {
	return this->jogosinstalados;
}

vector<Jogo*> PlataformaDigital::getjogoscadastrados() {
	return this->jogoscadastrados;
}

//--metodos restantes
void PlataformaDigital::imprimeJogosInstalados(){
    size_t k, n;
    k = this->jogosinstalados.size();

	if (k == 0) {
		cout << "Nao ha jogos instalados para serem impressos!" << endl;
		return;
	}

	cout << "Lista de Jogos Instalados: " << endl;

    for (n = 0; n < k; n++){
      cout << "[" << n << "] -> ";
      this->jogosinstalados[n]->imprimeInfoJogo();
    }

    return;
  }

void PlataformaDigital::imprimeJogosCadastrados(){
    size_t k, n;
    k = this->jogoscadastrados.size();

	if (k == 0) {
		cout << "Nao ha jogos para serem impressos!" << endl;
		return;
	}
	cout << "Lista de Jogos Cadastrados: " << endl;

    for (n = 0; n < k; n++){
      cout << "[" << n << "] -> ";
      this->jogoscadastrados[n]->imprimeInfoJogo();
    }
    return;
}

void PlataformaDigital::imprimeJogos(string _genero){
    int k, n;
    int contador = 0, contadorPC = 0, contadorConsole = 0;
    k = (int)this->jogoscadastrados.size();

	if (k == 0) {
		cout << "Nao ha jogos cadastrados para serem procurados!" << endl;
		return;
	}

    cout << "Jogos do genero \"" << _genero << "\":" << endl << endl;
    /*implementação futura:
    uppercase de genero
    uppercase de cada genero em jogos
    comparação com uppercase
    */
    for (n = 0; n < k; n++){
      if( this->jogoscadastrados[n]->getgenero()->getnome() == _genero){
		cout << "[" << n << "] -> ";
		this->jogoscadastrados[n]->imprimeInfoJogo();
		if (this->jogoscadastrados[n]->tipo == 1) {
			contadorPC++;
		}
		else {
			contadorConsole++;
		}
        contador++;
      }
    }
    if (contador == 0){
      cout << "Nao ha nenhum jogo cadastrado do genero " << _genero << " na lista de jogos cadastrados" << endl;
    } else{
      cout << "Total de " << contador << " jogo(s) do genero " << _genero << ". " << contadorPC << " Jogos de PC e " << contadorConsole << " de Console." << endl;
    }
    return;
}

void PlataformaDigital::acidicionarCreditorsCarteira(float creditos){
	this->carteiraDigital = this->carteiraDigital + creditos;
	cout << "Creditos totais: " << carteiraDigital << " reais." << endl << endl;
    return;
}

//@-- faz somente a operacao de verificar de ha como comprar o jogo
//@-- retorna 1 se foi comprado ou 0 se nao foi, ja imprimindo o motivo
int PlataformaDigital::comprarJogo(Jogo* novoJogo){
    size_t n, k;
    k = this->jogoscadastrados.size();

    for (n = 0; n < k; n++){
      if (novoJogo == this->jogoscadastrados[n]){ //verifica se o jogo ja foi comprado
        cout << "Voce ja possui esse jogo cadastrado na Plataforma!" << endl;
        return 0;
      }
    }

    if ( this->carteiraDigital >= novoJogo->getvalor() ){
      this->jogoscadastrados.push_back(novoJogo);
      this->carteiraDigital = this->carteiraDigital - novoJogo->getvalor();
	  cout << "Jogo comprado com sucesso" << endl;
	  cout << "Creditos atuais " << this->carteiraDigital << " reais." << endl;
      return 1;//comprou
    }
    else{
      cout << "Nao possui creditos suficientes para comprar esse jogo!" << endl;
	  cout << "Creditos que possui: " << this->carteiraDigital << ". O quanto precisa: " << novoJogo->getvalor() << endl;
      return 0;//falhou
    }

}

//@-- ja imprime o vector e pede qual jogo instalar
void PlataformaDigital::instalarJogo(){
    this->imprimeJogosCadastrados();

	int k, j;//pega o tamanho dos vetores
	k = (int)this->jogoscadastrados.size();
	j = (int)this->jogosinstalados.size();

	if (k == 0) {
		return;
	}

	int n; //entrada do usuario
	int i; //iteratores para percorrer os vetores

    cout << "Digite o numero do jogo desejado a ser instalado: ";
	n = -2; //primeira iteração
	while (n < 0 || n > k - 1) {
		if (n == -1) {
			cout << "Nenhum jogo foi instalado" << endl;
			return;
		}
		if (n != -2) {
			cout << "Opcao INDISPONIVEL, digite uma opcao contida na lista ou -1 para sair: ";
		}
		cin >> n;
	}

	int x = 0;

	for (i = 0; i < j ; i++) {
		if (this->jogoscadastrados[n] == jogosinstalados[i]) {
			cout << " Voce ja possui este jogo instalado." << endl;
			x = 1;
		}
	}

	if (x != 1) {
		this->jogosinstalados.push_back( this->jogoscadastrados[n] );
		cout << "Jogo Instalado." << endl;
	}

    return;
}

//@-- ja imprime o vector e pede qual jogo desistalar
void PlataformaDigital::desinstalarJogo(){
    this->imprimeJogosInstalados();

	int n; //interator para posição do vetor
	int breakcond; //condicional de saida do loop
	int k; //tamanho do vector jogos instalados
	k = (int)jogosinstalados.size();
	if (k == 0) {
		cout << "Nao ha jogos instalados." << endl;
		return;
	}

    cout << "Digite o numero do jogo desejado a ser desinstalado ou digite -1 para sair: ";
    do { //breakcond depende de apenas um jogo sendo desistalado com sucesso ou -1
      cin >> n;
	  if (n == -1) {
		  cout << "Nenhum jogo foi desistalado." << endl;
		  return;
	  }
      if (n <= k-1 && n >= 0){
        jogosinstalados.erase(jogosinstalados.begin() + n);
		cout << "Jogo DESISTALADO com sucesso." << endl;
        breakcond = 1;
      }
	  else{
		if (n == -1) { //sai do loop
			breakcond = 1;
		} else {
			cout << "Numero do jogo fora do range! Digite outro numero, dentro do range" << endl;
			breakcond = 0;
		}
      }
    } while (breakcond == 0);

    return;
}

void PlataformaDigital::salvarDados (){
    ofstream arquivo1;
    string NomedoArquivo;
    int i, k, k2;
    vector<Jogo*> vetorDeJogosCadastrados;
	vector<Jogo*> vetorDeJogosInstalados;

    NomedoArquivo = this->getnome() + ".txt";

    arquivo1.open( NomedoArquivo.c_str() , ios_base::trunc);

    if (!arquivo1.is_open()){
        cout<< "Nao foi possivel abrir o arquivo de escrita."<<endl;
        return;
    }

    arquivo1 << this->getnome() << endl
    << this->getcarteiraDigital() << endl;

    vetorDeJogosCadastrados = this->getjogoscadastrados();
    k = (int)vetorDeJogosCadastrados.size();

	arquivo1 << k << endl;

    for(i = 0; i < k; i++){
        vetorDeJogosCadastrados[i]->escreveJogoTxt(arquivo1);
	}

	vetorDeJogosInstalados = this->getjogosinstalados();
    k2 = (int)vetorDeJogosInstalados.size();

	arquivo1 << k2 << endl;

    for(i = 0; i < k2; i++){
        vetorDeJogosInstalados[i]->escreveJogoTxt(arquivo1);
	}

    arquivo1.close();
    return;
}

vector<Jogo*>* PlataformaDigital::getJogosPCCadastrados(){
	vector<Jogo*>* vec = new vector<Jogo*>;
	int i;
	int k = this->jogoscadastrados.size();
	for (i = 0; i < k; i++){
		if (this->jogoscadastrados[i]->getTipo() == 1){
			vec->push_back(this->jogoscadastrados[i]); //pega a referencia do jogo criado
		}
	}
	return vec;
}

vector<Jogo*>* PlataformaDigital::getJogodConsoleCadastrados(){
	vector<Jogo*>* vec = new vector<Jogo*>;
	int i;
	int k = this->jogoscadastrados.size();
	for (i = 0; i < k; i++){
		if (this->jogoscadastrados[i]->getTipo() == 2){
			vec->push_back(this->jogoscadastrados[i]); //pega a referencia do jogo criado
		}
	}
	return vec;
}

void PlataformaDigital::carregarDados(string nomeArquivo){
	ifstream arquivoDeLeitura;
	int i, j, k, tipoDeJogo;
	int tamanho1, tamanho2;

	string nomeJogo, genero;
	bool emPromocao;
	float valor;

	arquivoDeLeitura.open(nomeArquivo);

	if(!arquivoDeLeitura.is_open()){
		cout << "Nao existem dados a serem carregados do arquivo " << nomeArquivo << " da plataforma." << endl;
		arquivoDeLeitura.close();
		return;
	}

	//preparaçao: remover os jogos ja existentes
	if ((int)this->jogoscadastrados.size() != 0){
		this->jogoscadastrados.clear();
		this->jogosinstalados.clear();
	}
	//
	arquivoDeLeitura >> this->nome;
	arquivoDeLeitura >> this->carteiraDigital;

	arquivoDeLeitura >> tamanho1;

	for(i = 0; i < tamanho1; i++){
		arquivoDeLeitura >> tipoDeJogo;
		if(tipoDeJogo == 1){
			float tamanho;
			arquivoDeLeitura >> nomeJogo;
			arquivoDeLeitura >> valor;
			arquivoDeLeitura >> emPromocao;
			arquivoDeLeitura >> genero;
			arquivoDeLeitura >> tamanho;

			JogoPC* jogoDePc;
			jogoDePc = new JogoPC(nomeJogo, valor, emPromocao, genero, tamanho);
			this->jogoscadastrados.push_back(jogoDePc);
		}
		else {
			bool possuiMultiplayer;
			arquivoDeLeitura >> nomeJogo;
			arquivoDeLeitura >> valor;
			arquivoDeLeitura >> emPromocao;
			arquivoDeLeitura >> genero;
			arquivoDeLeitura >> possuiMultiplayer;

			JogoConsole* jogodeConsole;
			jogodeConsole = new JogoConsole(nomeJogo, valor, emPromocao, genero, possuiMultiplayer);
			this->jogoscadastrados.push_back(jogodeConsole);
		}
	}

	k = (int)this->jogoscadastrados.size();
	arquivoDeLeitura >> tamanho2;

	for(i = 0; i < tamanho2; i++){
		arquivoDeLeitura >> tipoDeJogo;

		if(tipoDeJogo == 1){
			float tamanho;
			arquivoDeLeitura >> nomeJogo;
			arquivoDeLeitura >> valor;
			arquivoDeLeitura >> emPromocao;
			arquivoDeLeitura >> genero;
			arquivoDeLeitura >> tamanho;
		}
		else {
			bool possuiMultiplayer;
			arquivoDeLeitura >> nomeJogo;
			arquivoDeLeitura >> valor;
			arquivoDeLeitura >> emPromocao;
			arquivoDeLeitura >> genero;
			arquivoDeLeitura >> possuiMultiplayer;
		}

		//por ultimo verifica se o jogo realmente ja foi comprado pelo player
		//a comparacao é feita pelo nome do jogo
		for (j = 0; j < k; j++){
			if ( nomeJogo.compare( this->jogoscadastrados[j]->getnome() ) == 0 ){
				this->jogosinstalados.push_back(this->jogoscadastrados[i]);
			}
		}

	}

	arquivoDeLeitura.close();
	return;
}

void PlataformaDigital::exportarBibliotecaJogos(){
	ofstream arquivo;
	string nomeDoArquivo;
	Jogo* jogoASerPrintado;

	vector<Jogo*>* jogosDePC = this->getJogosPCCadastrados();
	vector<Jogo*>* jogosDeConsole = this->getJogodConsoleCadastrados();

	int contadorDeJogos, i, j, k;
	bool instalado;
	int tamanhoDoVetorInstalados = this->jogosinstalados.size();

	nomeDoArquivo = this->nome + ".html";

	arquivo.open(nomeDoArquivo);

	if(!arquivo.is_open()){
		cout << "Nao foi possivel criar " << nomeDoArquivo << " para a escrita dos dados."<< endl;
		arquivo.close();
		return;
	}

	arquivo << "<html>" << endl
			<< "<head>" << endl
			<< "    <title>"
			<< this->nome
			<< " - Biblioteca de Jogos</title>" << endl
			<< "    <style>" << endl
			<< "        .row {" << endl
			<< "            width: 100%;" << endl
			<< "            display: flex;" << endl
			<< "        }" << endl
			<< "" << endl
			<< "        .col-6 {" << endl
			<< "            width: 100%;" << endl
			<< "            font-family: sans-serif;" << endl
			<< "            text-align: center; " << endl
			<< "            margin-top: 0px;" << endl
			<< "        }" << endl
			<< "" << endl
			<< "        .col-6 h3 {" << endl
			<< "            <!-- text-decoration: italic; -->" << endl
			<< "        }" << endl
			<< "        .linhasConsole1{" << endl
			<< "            background-color: rgb(100, 255, 100);" << endl
			<< "            text-align: left;" << endl
			<< "            border: 1px solid #000000;" << endl
			<< "            padding: 4px;" << endl
			<< "        }" << endl
			<< "        .linhasConsole2{" << endl
			<< "            background-color: rgb(150, 255, 150);" << endl
			<< "            text-align: left;" << endl
			<< "            border: 1px solid #000000;" << endl
			<< "            padding: 4px;" << endl
			<< "        }" << endl
			<< "        .linhasPc1{" << endl
			<< "            background-color: rgb(130, 130, 255);" << endl
			<< "            text-align: left;" << endl
			<< "            border: 1px solid #000000;" << endl
			<< "            padding: 4px;" << endl
			<< "        }" << endl
			<< "        .linhasPc2{" << endl
			<< "            background-color: rgb(180, 180, 255);" << endl
			<< "            text-align: left;" << endl
			<< "            border: 1px solid #000000;" << endl
			<< "            padding: 4px;" << endl
			<< "        }" << endl
			<< "        .tituloTabela {" << endl
			<< "            color: #990000;" << endl
			<< "            margin-bottom: 7px;" << endl
			<< "            margin-top: 40px;" << endl
			<< "        }" << endl
			<< "        table {" << endl
			<< "            width: 100%;" << endl
			<< "            border: 0.5px outset white;" << endl
			<< "            font-family: Arial, sans-serif;" << endl
			<< "            border-radius: 4px;" << endl
			<< "            <!--border-collapse: collapse;-->" << endl
			<< "            align-items: center;" << endl
			<< "        }" << endl
			<< "        th{" << endl
			<< "            border: 1px solid #000000;" << endl
			<< "            padding: 8px;" << endl
			<< "        }" << endl
			<< "        .trheader{" << endl
			<< "            background-color: rgb(51, 51, 255);" << endl
			<< "            color: white;" << endl
			<< "            <!-- margin: 6px; -->" << endl
			<< "        }" << endl
			<< "    </style>" << endl
			<< "</head>" << endl
			<< "" << endl
			<< "<body style=\"background-color: rgb(255, 235, 235)\">" << endl
			<< "    <h2 style=\"text-align: center; color: #990000;\">"
			<< this->nome
			<< "- Biblioteca de jogos</h2>" << endl
			<< "    <div class=\"row\">" << endl
			<< "        <div class=\"col-6\">" << endl
			<< "            <table>" << endl
			<< "                <h4 class=\"tituloTabela\">" << endl
			<< "                    Jogos de PC" << endl
			<< "                </h4>" << endl
			<< "                <tr class=\"trheader\">" << endl
			<< "                    <th>#</th>" << endl
			<< "                    <th>Nome</th>" << endl
			<< "                    <th>Valor</th>" << endl
			<< "                    <th>Genero</th>" << endl
			<< "                    <th>Tamanho</th>" << endl
			<< "                    <th>Instalado</th>" << endl
			<< "                </tr>" << endl;

			k = (int)jogosDePC->size();

			for (j = 0, contadorDeJogos = 1; j < k; j++){
				jogoASerPrintado = jogosDePC->at(j);

				instalado = false;
				for (i = 0; i < k; i++){
					if (tamanhoDoVetorInstalados && jogoASerPrintado->getnome().compare( this->jogosinstalados[i]->getnome() ) == 0) { //compara se pelo nome o jogo esta instalado
						instalado = true;
						break;
					}
				}
				jogoASerPrintado->escreveJogoHtml(arquivo, contadorDeJogos, instalado);
				contadorDeJogos++;
			}

	arquivo << "            </table>" << endl
			<< "" << endl
			<< "            <table>" << endl
			<< "                <h4 class=\"tituloTabela\">" << endl
			<< "                    Jogos de Console" << endl
			<< "                </h4>" << endl
			<< "                <tr class=\"trheader\">" << endl
			<< "					<th>#</th>" << endl
			<< "                    <th>Nome</th>" << endl
			<< "                    <th>Valor</th>" << endl
			<< "                    <th>Genero</th>" << endl
			<< "                    <th>Multiplayer</th>" << endl
			<< "                    <th>Instalado</th>" << endl
			<< "                </tr>" << endl;

			k = (int)jogosDeConsole->size();

			for (j = 0, contadorDeJogos = 1; j < k; j++){
				jogoASerPrintado = jogosDeConsole->at(j);

				instalado = false;
				for (i = 0; i < k; i++){
					if (tamanhoDoVetorInstalados && jogoASerPrintado->getnome().compare( this->jogosinstalados[i]->getnome() ) ==  0){ //compara se pelo nome o jogo esta instalado
						instalado = true;
						break;
					}
				}
				jogoASerPrintado->escreveJogoHtml(arquivo, contadorDeJogos, instalado);
				contadorDeJogos++;
			}

	arquivo << "            </table>" << endl
			<< "        </div>" << endl
			<< "    </div>" << endl
			<< "</body>" << endl
			<< "</html>" << endl;

	arquivo.close();
	return;
}


