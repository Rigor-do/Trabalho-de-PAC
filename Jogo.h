//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _JOGO_H
#define _JOGO_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include "PlataformaDigital.h"

using namespace std;

class PlataformaDigital;

class Jogo{
protected:

  string nome;
  float valor;
  bool emPromocao;
  int id;

    class Genero{
    private:

      string nome;

    public:
      Genero();
      Genero(string _nome);
      ~Genero();

      string getnome();
      void setnome(string _nome);

      void imprimenome();
    };
  Genero *genero;



public:

  static int qtdJogos;
  int tipo; //esse interator de tipo ja havia desde a versão da parte 1 do trabalho.
  //Ele serve para que, na contagem de jogos de cada empresa, ele saiba
  // quantos sao os de PC e quantos sao os de Console.

  //construtores e destrutores
  Jogo();
  Jogo(string _nome, float _valor, bool _emPromocao, string _genero);
  virtual ~Jogo();

  //get e set
  string getnome();
  void setnome(string _nome);
  float getvalor();
  void setvalor(float _valor);
  Genero* getgenero();
  string getgeneronome();
  void setgenero(Genero* _genero);
  static int getqtdJogos();
  void setEmpromocao(bool _var);
  bool getEmpromocao();
  void setId(int _id);
  int getId();
  virtual int getTipo() = 0;

  //--------------------------------------------------------atenção: implementar virtual puro para getvaloremPromocao
  virtual float getvaloremPromocao() = 0;

  //restante
  virtual void imprimeInfoJogo() = 0;
  static void imprimeqtdJogos();

//  virtual bool getPossuiMultiplayer();
//  virtual float getEspacoDiscoReq();

  virtual void escreveJogoTxt(ofstream &arquivo) = 0;
  virtual void escreveJogoHtml(ofstream &arquivo, int indice, bool instalado) = 0;

  friend void presenteVirtual(PlataformaDigital* pA, Jogo* presente);
};

#endif
