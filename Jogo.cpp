//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "Jogo.h"

using namespace std;

//--construtores e destrutores
Jogo::Jogo(){
    //cout << "Criado jogo. Metodo construtivo convencional" << endl;
	this->genero = new Genero;
	Jogo::qtdJogos++;
	this->id = Jogo::qtdJogos;
}
Jogo::Jogo(string _nome, float _valor, bool _emPromocao, string _genero){
	this->genero = new Genero(_genero);
	this->nome = _nome;
    this->valor = _valor;
	this->emPromocao = _emPromocao;

	Jogo::qtdJogos++;
	this->id = qtdJogos;
}

Jogo::~Jogo(){
    //cout << "Objeto jogo destruido." << endl;
	delete(this->genero);
	Jogo::qtdJogos--;
}

Jogo::Genero::Genero(){
}

Jogo::Genero::Genero(string _nome){
    this->nome = _nome;
}

Jogo::Genero::~Genero(){
}

string Jogo::Genero::getnome(){
    return this->nome;
}

void Jogo::Genero::setnome(string _nome){
    this->nome = _nome;
    return;
}

void Jogo::Genero::imprimenome(){
    cout << this->nome;
    return;
}
//--metodos get e set
string Jogo::getnome() {
	return this->nome;
}
void Jogo::setnome(string _nome) {
	this->nome = _nome;
	return;
}

float Jogo::getvalor() {
	return this->valor;
}
void Jogo::setvalor(float _valor) {
	this->valor = _valor;
	return;
}
string Jogo::getgeneronome() {
	return this->genero->getnome();
}
Jogo::Genero* Jogo::getgenero() {
	return this->genero;
}
void Jogo::setgenero(Genero* _genero) {
	this->genero = _genero;
	return;
}

int Jogo::getqtdJogos() {
	return Jogo::qtdJogos;
}
//-- metodos restantes

//@-- da cout no valor de qtdJogos atual
void Jogo::imprimeqtdJogos() {
	cout << "Quantidade de jogos disponiveis na plataforma eh: " << Jogo::qtdJogos << endl;
	return;
}

void Jogo::setEmpromocao(bool _var) {
	this->emPromocao = _var;
	return;
}

bool Jogo::getEmpromocao() {
	return this->emPromocao;
}

void Jogo::setId(int _id){
	this->id = _id;
	return;
}

int Jogo::getId(){
	return this->id;
}

int Jogo::qtdJogos = 0;
