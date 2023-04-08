//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "JogoConsole.h"

using namespace std;

JogoConsole::JogoConsole() :Jogo() {
	//cout << "Criacao metodo normal jogo console" << endl;
	this->tipo = 2;
}
JogoConsole::JogoConsole(string _nome, float _valor, bool _emPromocao, string _genero, bool mult) : Jogo(_nome, _valor, _emPromocao, _genero) {
	this->possuiMultiplayer = mult;
	this->tipo = 2;
	//cout << "Criacao metodo parametrizado jogo console" << endl;
}
JogoConsole::~JogoConsole() {
	delete(this->genero);
	//cout << "Estou sendo destruiiido" << endl;
	Jogo::qtdJogos--;
}

float JogoConsole::getvaloremPromocao() {
	if (this->emPromocao) {
		return this->valor*(float)0.9;
	}
	else {
		return this->valor;
	}
}

void JogoConsole::imprimeInfoJogo() {
	cout << "Nome do JogoConsole: " << this->getnome() << ". Valor: " << this->getvaloremPromocao() << " reais. Genero: " << this->genero->getnome() << ". Multiplayer: ";
	if (this->possuiMultiplayer)
		cout << "sim;" << endl;
	else
		cout << "nao;" << endl;
}

bool JogoConsole::getPossuiMultiplayer() {
	return this->possuiMultiplayer;
}
void JogoConsole::setPossuiMultiplayer(bool mul) {
	this->possuiMultiplayer = mul;
	return;
}

int JogoConsole::getTipo(){
	return this->tipo;
}

void JogoConsole::escreveJogoTxt(ofstream &arquivo){
	arquivo << "2" << endl <<
	this->getnome() << endl <<
	this->getvalor() << endl <<
	this->getEmpromocao() << endl <<
	this->getgenero()->getnome() << endl <<
	this->getPossuiMultiplayer() << endl;

	return;
}

void JogoConsole::escreveJogoHtml(ofstream &arquivo, int indice, bool instalado){
	if(indice % 2 == 0){
		arquivo << "				<tr class=\"linhasConsole2\">" << endl;
	}
	else{
		arquivo << "				<tr class=\"linhasConsole1\">" << endl;
	}

	arquivo << "					<td align=\"center\"><b>" << indice <<  "</b></td>" << endl
			<< "       			    <td>" << this->nome << "</td>" << endl
			<< "      	 	   	  	<td>R$ " << this->valor << " reais</td>" << endl
			<< "					<td>" << this->genero->getnome() << "</td>" << endl;
	if (this->possuiMultiplayer){
		arquivo << "					<td>" << "Sim" << "</td>" << endl;
	}
	else {
		arquivo << "					<td>" << "Nao" << "</td>" << endl;
	}
	if (instalado){
		arquivo << "					<td style=\"color:rgb(15,130,15)\">" << "Sim" << "</td>" << endl;
	}
	else {
		arquivo << "					<td style=\"color:rgb(255,30,30)\">" << "Nao" << "</td>" << endl;
	}
	arquivo << "				</tr>" << endl;

	return;
}

