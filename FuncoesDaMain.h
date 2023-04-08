//Trabalho PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#ifndef _FUNCOESDAMAIN_H
#define _FUNCOESDAMAIN_H

#include <iostream>
#include <vector>
#include <string>
#include "PlataformaDigital.h"
#include "EmpresaDesenvolvedora.h"

#define n_generos 

using namespace std;

void clearTerminal();

int imprimeMenu();

int selecionaPlataformaDigital(vector <PlataformaDigital*> *vec);

int selecionaEmpresaDesenvolvedora(vector <EmpresaDesenvolvedora*> *vec);

#endif
