//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _JOGOCONSOLE_H
#define _JOGOCONSOLE_H

#include "Jogo.h"

//using namespace std;

//class Jogo;

class JogoConsole : public Jogo {
private:
	bool possuiMultiplayer;
public:
	JogoConsole();
	JogoConsole(string _nome, float _valor, bool _emPromocao, string _genero, bool mult);
	~JogoConsole();

	float getvaloremPromocao();
	void imprimeInfoJogo();

	bool getPossuiMultiplayer();
	void setPossuiMultiplayer(bool mul);
	int getTipo();

	void escreveJogoTxt(ofstream &arquivo);
	void escreveJogoHtml(ofstream &arquivo, int indice, bool instalado);
};

#endif
