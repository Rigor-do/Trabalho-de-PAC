//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _JOGOPC_H
#define _JOGOPC_H

#include "Jogo.h"
#include <iostream>

//using namespace std;

class JogoPC : public Jogo {
private:
	float espacoDiscoRequerido;

public:
	JogoPC();
	JogoPC(string _nome, float _valor, bool _emPromocao , string _genero, float _espacoDiscoRequerido);
	~JogoPC();

	float getvaloremPromocao();
	void imprimeInfoJogo();

	float getEspacoDiscoReq();
	void setEspacoDiscoReq(float espaco);
	int getTipo();

	void escreveJogoTxt(ofstream &arquivo);
	void escreveJogoHtml(ofstream &arquivo, int indice, bool instalado);

};

#endif
