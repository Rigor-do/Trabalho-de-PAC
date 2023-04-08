//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _EMPRESADESENVOLVEDORA_H
#define _EMPRESADESENVOLVEDORA_H

#include <iostream>
#include <vector>
#include <string>
#include "Jogo.h"
#include "JogoPC.h"
#include "JogoConsole.h"
#include <fstream>

//using namespace std;
//----------------------------------------------implementar: destrutor para acabar com todos os jogos existentes da empresa

class EmpresaDesenvolvedora{
private:

  string nome;
  int numerojogos;
  vector<Jogo*> jogosdesenvolvidos; //lista de todos os jogos desenvolvidos por ela

public:

  EmpresaDesenvolvedora();
  EmpresaDesenvolvedora(string _nome);
  ~EmpresaDesenvolvedora();

  string getnome();
  void setnome(string _nome);
  vector<Jogo*> getjogosdesenvolvidos();
  int getnumerojogos();

  void colocarJogoemPromocao();
  void tirarJogoPromocao();
  void imprimeJogosdesenvolvidas();
  vector<Jogo*>* getJogosEmPromocao();
  vector<Jogo*>* getJogosForaDePromocao();

  void salvarDados();
  void carregarDados(string nomeArquivo);

  void CriarJogo ();
  //relacoes com outras classes
};

#endif
