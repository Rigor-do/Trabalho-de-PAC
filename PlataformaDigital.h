//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _PLATAFORMADIGITAL_H
#define _PLATAFORMADIGITAL_H

#include <iostream>
#include <vector>
#include <string>
#include "Jogo.h"
#include "JogoPC.h"
#include "JogoConsole.h"

//using namespace std;

class Jogo;
//class JogoPC;
//class JogoConsole;

class PlataformaDigital{
private:

  string nome;
  float carteiraDigital; //valor do dinheiro na conta
  vector<Jogo*> jogosinstalados; //jogos instalados
  vector<Jogo*> jogoscadastrados; //jogos comprados

public:

  PlataformaDigital();
  PlataformaDigital(string _nome);
  ~PlataformaDigital();

  string getnome();
  void setnome(string _nome);
  float getcarteiraDigital();
  void setcarteiraDigital(float _carteiraDigital);
  vector<Jogo*> getjogosinstalados();
  vector<Jogo*> getjogoscadastrados();

  void imprimeJogosInstalados();
  void imprimeJogosCadastrados();
  void imprimeJogos(string genero);
  void acidicionarCreditorsCarteira(float creditos);
  int comprarJogo(Jogo* novoJogo);
  void instalarJogo();
  void desinstalarJogo();

  void salvarDados();
  void carregarDados(string nomeArquivo);

  vector<Jogo*>* getJogosPCCadastrados();
  vector<Jogo*>* getJogodConsoleCadastrados();

  void exportarBibliotecaJogos();

  friend void presenteVirtual(PlataformaDigital *pA, Jogo *presente);
};


#endif
