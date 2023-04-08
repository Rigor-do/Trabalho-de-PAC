// Lista PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

//desculpe a desordem de ponteiros. Fizemos o codigo em linux e nao alteramos em casa por causa da disponibilidade da Pthread.lib para o Windows

class Parametro{
public:
    string* nomeDoArquivo;
    vector<int>* vetor;

    ~Parametro(){
        delete(this->nomeDoArquivo);
    }
};

void * leitura (void * _parametro){
    int n;

    Parametro* parametro = (Parametro*)_parametro;

    ifstream file;
    file.open(parametro->nomeDoArquivo->c_str());

    if (file.is_open())
        cout << "Arquivo " << pthread_self() << " aberto com sucesso!" << endl;
    else{
        cout << "Nao foi possivel abrir o arquivo " << pthread_self() << "." << endl;
        file.close();
        return (void*) -1;
    }

    while (!file.eof()){
        file >> n;
        parametro->vetor->push_back(n);
    }

    file.close();

    return (void*) 0;
}


int main (){
    cout << "0" << endl;

	//pthread é C afinal, ne. Famoso Malloc
    pthread_attr_t *attr = (pthread_attr_t*)malloc(1*sizeof(pthread_attr_t));
    pthread_attr_init(attr);
    cout << "2" << endl;
    pthread_t *t1 = (pthread_t*) malloc(1*sizeof(pthread_t));
    pthread_t *t2 = (pthread_t*) malloc(1*sizeof(pthread_t));

    int i;

    vector<int> *v1 = new vector<int>;
    vector<int> *v2 = new vector<int>;
    vector<int> *v3 = new vector<int>;

    Parametro *p1 = new Parametro;
    Parametro *p2 = new Parametro;

    p1->vetor = v1;
    p2->vetor = v2;

    p1->nomeDoArquivo = new string("Entrada1.txt");
    p2->nomeDoArquivo = new string("Entrada2.txt");

    cout << "1" << endl;

    pthread_create(t1, attr, leitura, (void*)p1);
    pthread_create(t2, attr, leitura, (void*)p2);

    pthread_join(*t1, NULL);
    pthread_join(*t2, NULL);

    ofstream file3;

    file3.open("Saida.txt");

    int k1 = (int)v1->size();
    int k2 = (int)v2->size();

    if (k1 != k2){
        cout << "Vetores de tamanho diferentes" << endl;
        return -2;
    }

    int n;
    for (i=0; i < k1; i++){
        n = v1->at(i) + v2->at(i);
        v3->push_back(n);
        file3 << v3->at(i) << endl;
    }

    file3.close();

	//"""Destrutores""" de C
    free(attr);
    free(t1);
    free(t2);

    delete(v1);
    delete(v2);
    delete(v3);

    delete(p1);
    delete(p2);

    return 0;
}
