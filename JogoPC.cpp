//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include "JogoPC.h"

using namespace std;

JogoPC::JogoPC() :Jogo() {
	//cout << "Metodo construtivo normal de jogoPC" << endl;
	this->tipo = 1;
	//Jogo::qtdJogos++;
}
JogoPC::JogoPC(string _nome, float _valor, bool _emPromocao, string _genero, float _espacoDiscoRequerido) : Jogo(_nome, _valor, _emPromocao, _genero){
	this->espacoDiscoRequerido = _espacoDiscoRequerido;
	this->tipo = 1;
	//cout << "Metodo construtivo parametrizado de JogoPC" << endl;
	//Jogo::qtdJogos++;
}
JogoPC::~JogoPC() {
	delete(this->genero);
	//cout << "estou sendo destruido" << endl;
	Jogo::qtdJogos--;
}

float JogoPC::getvaloremPromocao() {
	if (this->emPromocao) {
		return this->valor*(float)0.7;
	}
	else {
		return this->valor;
	}
}

int JogoPC::getTipo(){
	return this->tipo;
}

void JogoPC::imprimeInfoJogo() {
	cout << "Nome do JogoPC: " << this->getnome() << ". Valor: " << this->getvaloremPromocao() << " reais. Genero: ";
	this->genero->imprimenome();
	cout << ". Espaco em disco requerido: " << this->getEspacoDiscoReq() << " Gbs" << endl;
}

float JogoPC::getEspacoDiscoReq() {
	return this->espacoDiscoRequerido;
}
void JogoPC::setEspacoDiscoReq(float _espaco) {
	this->espacoDiscoRequerido = _espaco;
	return;
}

void JogoPC::escreveJogoTxt(ofstream &arquivo){
	arquivo << "1" << endl <<
	this->getnome() << endl <<
	this->getvalor() << endl <<
	this->getEmpromocao() << endl <<
	this->getgenero()->getnome() << endl <<
	this->getEspacoDiscoReq() << endl;

	return;
}

void JogoPC::escreveJogoHtml(ofstream &arquivo, int indice, bool instalado){
	if (indice % 2 == 0){
		arquivo << "				<tr class=\"linhasPc2\">" << endl;
	}else{
		arquivo << "				<tr class=\"linhasPc1\">" << endl;
	}

	arquivo << "					<td align=\"center\"><b>" << indice <<  "</b></td>" << endl
			<< "      		 	    <td>" << this->nome << "</td>" << endl
			<< "       		   	  	<td>R$ " << this->valor << " reais</td>" << endl
			<< "					<td>" << this->genero->getnome() << "</td>" << endl
			<< "					<td>" << this->espacoDiscoRequerido << "GBs</td>" << endl;
	if (instalado){
		arquivo << "					<td style=\"color:rgb(20,90,20)\">" << "Sim" << "</td>" << endl;
	}
	else {
		arquivo << "					<td style=\"color:rgb(255,30,30)\">" << "Nao" << "</td>" << endl;
	}
	arquivo << "				</tr>" << endl;

	return;
}
