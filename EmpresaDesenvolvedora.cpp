//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "EmpresaDesenvolvedora.h"

using namespace std;

//--metodos construtores e destrutores
EmpresaDesenvolvedora::EmpresaDesenvolvedora(){
    //cout << "Criado empresa. Metodo construtivo convencional" << endl;
    this->numerojogos = 0;
}
EmpresaDesenvolvedora::EmpresaDesenvolvedora(string _nome){
    this->nome = _nome;
    this->numerojogos = 0;
    //cout << "Criado empresa. Metodo construtivo parametrizado: " << this->nome << endl;
}
EmpresaDesenvolvedora::~EmpresaDesenvolvedora(){
    //cout << "Destruido empresa. Metodo destrutivo convencional: " << this->nome << endl;
	size_t k, i;
	k = this->jogosdesenvolvidos.size();
	for (i = 0; i < k; i++) {
		if (this->jogosdesenvolvidos[i] != NULL) { //evitar o caso de double free
			delete(this->jogosdesenvolvidos[i]);
		}
	}
}

//--metodos get e set
string EmpresaDesenvolvedora::getnome() {
	return this->nome;
}
void EmpresaDesenvolvedora::setnome(string _nome) {
	this->nome = _nome;
	return;
}
vector<Jogo*> EmpresaDesenvolvedora::getjogosdesenvolvidos() {
	return this->jogosdesenvolvidos;
}
int EmpresaDesenvolvedora::getnumerojogos() {
	return this->numerojogos;
}

//--metodos restantes

void EmpresaDesenvolvedora::colocarJogoemPromocao() {
	vector<Jogo*>* jogosForaDePromocao;
	int k, i, n;

	jogosForaDePromocao = getJogosForaDePromocao();
	k = (int) jogosForaDePromocao->size();

	if ( k == 0 ){
		cout << "Nao existem jogos na lista de jogos desenvolvidos fora de promocao na empresa " << this->getnome() << "." << endl;
		return;
	}

	cout << "Selecione um dos jogos da lista: " << endl;

	for (i = 0; i < k; i++){
		cout << "[" << i << "] -> ";
		jogosForaDePromocao->at(i)->imprimeInfoJogo();
	}

	cin >> n;
	while ( (n < 0 || n > k - 1) && n != -1) {
		if (n != -2)
			cout << "Valor invalido, digite outro valor";
		cin >> n;
	}
	if (n == -1){
		cout << "Voltando para o menu..." << endl;
		delete(jogosForaDePromocao);
		return;
	}

	jogosForaDePromocao->at(n)->setEmpromocao(true);

	cout << "Jogo " << jogosForaDePromocao->at(n)->getnome() << " colocado de promocao com sucesso!" << endl;

	delete(jogosForaDePromocao);
	return;
}

void EmpresaDesenvolvedora::tirarJogoPromocao(){
	//cout << "chegou";
	vector<Jogo*>* jogosEmPromocao;
	int i, n, k;

	jogosEmPromocao = getJogosEmPromocao();
	k = (int)(jogosEmPromocao->size());

	if ( k == 0 ){
		cout << "Nao existem jogos na lista de jogos em promocao da empresa " << this->getnome() << "." << endl;
		return;
	}

	cout << "Selecione um dos jogos da lista: " << endl;

	for (i = 0; i < k; i++){
		cout << "[" << i << "] -> ";
		jogosEmPromocao->at(i)->imprimeInfoJogo();
	}

	cin >> n;
	while ((n < 0 || n > k - 1) && n != -1) {
		if (n < 0 || n > k - 1)
			cout << "Valor invalido, digite outro valor ou -1 para voltar para o menu" << endl;
		cin >> n;
	}
	if (n == -1){
		cout << "Voltando para o menu..." << endl;
		delete(jogosEmPromocao);
		return;
	}

	jogosEmPromocao->at(n)->setEmpromocao(false);

	cout << "Jogo " << jogosEmPromocao->at(n)->getnome() << " tirado de promocao com sucesso!" << endl;

	delete(jogosEmPromocao);
	return;
}

void EmpresaDesenvolvedora::imprimeJogosdesenvolvidas() {
	size_t i, k = this->jogosdesenvolvidos.size();

	if (k == 0) {
		cout << "Nao existe jogo para ser impresso!" << endl;
		return;
	}
	for (i = 0; i < k; i++) {
		cout << "[" << i << "] -> ";
		this->jogosdesenvolvidos[i]->imprimeInfoJogo();
	}
	return;
}

void EmpresaDesenvolvedora::CriarJogo (){
	int n;
	cout << "O jogo sera de PC ou Console?" << endl << "Digite 1 para de PC e 2 para de Console: ";

	cin >> n;

	while ( n != 1 && n != 2 ) {
		cout << "Entrada incorreta, digite 1 para criar um Jogo de PC ou 2 para Jogo de Console: ";
		cin >> n;
	}

	Jogo* j;

	string _nome;
	float _valor;

	string _genero;

    cout << "Digite o nome do jogo: ";
	cin >> _nome;
    cout << "Digite o valor do jogo: ";
	cin >> _valor;
    cout << "Digite o genero do jogo: ";
	cin >> _genero;

	if (n == 1) {
		float _espacoreq;
		cout << "Digite o espaco requerido do jogo: ";
		cin >> _espacoreq;
		bool _emPromocao = false;
		j = new JogoPC(_nome, _valor, _emPromocao , _genero, _espacoreq);
	}
	else {
		bool mult;
		char _mult = 0;
		cout << "O jogo tem multiplayer?(S/N): ";
		while (_mult != 'S' && _mult != 'N') {
			if (_mult != 0)
				cout << "Opcao invalida, digite S para sim ou N para nao: ";
			cin >> _mult;
			_mult = toupper(_mult);
		}
		if (_mult == 'S') {
			mult = true;
		}
		else {
			mult = false;
		}
		bool _emPromocao = false;
		j = new JogoConsole(_nome, _valor, _emPromocao, _genero, mult);
	}

	//joga o _gen para o jogo, uma vez que nao ha uma ctz que a associacao tera de ser publica.
	//Dessa forma funciona mesmo sendo privada. Se for privada, nao poderia alterar o nome de genero diretamente

    this->jogosdesenvolvidos.push_back(j);
	this->numerojogos++;

	return;
}

vector<Jogo*>* EmpresaDesenvolvedora::getJogosEmPromocao(){
	vector<Jogo*>* vec = new vector<Jogo*>;
	int i, k;
	k = (int) this->getjogosdesenvolvidos().size();

	for (i = 0; i < k; i++){
		if (this->getjogosdesenvolvidos()[i]->getEmpromocao()){
			vec->push_back(this->getjogosdesenvolvidos()[i]);
		}
	}
	return vec;
}

vector<Jogo*>* EmpresaDesenvolvedora::getJogosForaDePromocao(){
	vector<Jogo*>* vec = new vector<Jogo*>;
	int i, k;
	k = (int) this->getjogosdesenvolvidos().size();

	for (i = 0; i < k; i++){
		if (!this->getjogosdesenvolvidos()[i]->getEmpromocao()){
			vec->push_back(this->getjogosdesenvolvidos()[i]);
		}
	}

	return vec;
}

void EmpresaDesenvolvedora::salvarDados (){
    ofstream arquivo1;
    string NomedoArquivo;
    int i, k;
    vector<Jogo*> vetorDeJogos;

    NomedoArquivo = this->getnome() + ".txt";
    arquivo1.open(NomedoArquivo.c_str(), ios_base::trunc);

    if (!arquivo1.is_open()){
        cout<< "Nao foi possivel abrir o arquivo de escrita."<<endl;
        return;
    }

    arquivo1 << this->getnome() << endl
    << this->getnumerojogos() << endl;
	//aqui em cima escrevo o numero de jogos do vetor

    vetorDeJogos = this->getjogosdesenvolvidos();
    k = (int)vetorDeJogos.size();

    for(i = 0; i < k; i++){
        vetorDeJogos[i]->escreveJogoTxt(arquivo1);
	}

    arquivo1.close();
    return;
}

void EmpresaDesenvolvedora::carregarDados(string nomeArquivo){
	ifstream arquivoDeLeitura;
	int i, tipoDeJogo;

	string nomeJogo, genero;
	bool emPromocao;
	float valor;

	arquivoDeLeitura.open(nomeArquivo);

	if(!arquivoDeLeitura.is_open()){
		cout << "Nao existem dados a serem carregados do arquivo " << nomeArquivo << " da empresa." << endl;
		arquivoDeLeitura.close();
		return;
	}

	//inicialmente pensei somente em sobreescrita dos dados
	//preparaçao: remover os jogos ja existentes, caso a empresa desenvolvedora esteja sendo sobreescrita
    if ((int)this->getjogosdesenvolvidos().size() != 0){
		//cout << "Aqui dentro" << endl;
    	this->jogosdesenvolvidos.clear();
    	this->numerojogos = 0; //o delete de Jogo ja diminui o iterador, acho que nao eh necessario isso
    }
	//

	arquivoDeLeitura >> this->nome;
	arquivoDeLeitura >> this->numerojogos;

	//cout << "Aqui foi com " << this->numerojogos << " numero de jogos" << endl;

	for(i = 0; i < this->numerojogos; i++){
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
			this->jogosdesenvolvidos.push_back(jogoDePc);
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
			this->jogosdesenvolvidos.push_back(jogodeConsole);
		}
		//cout << "Dentro do while" << endl;
	}

	arquivoDeLeitura.close();
	return;
}

