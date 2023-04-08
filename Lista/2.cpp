// Lista PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename tipo2,typename tipo1>
class Setor {
    protected:
        tipo2 Codigo_Generico;
        vector<tipo1*> membros;
    public:
		~Setor(){
			int k = (int)this->membros.size();
			int i;
			for (i = 0; i < k; i++){
				delete(this->membros[i]);
				cout << "Elemento i: " << i << " do setor destruido." << endl;
			}
		}
        //adiciona elemento
        void addNovosMembros(tipo1* membro){
            this->membros.push_back(membro);
            return;
        }

        //remove o ultimo elemento
        void removeUltimoMembro(){
            this->membros.pop_back();
            return;
        }

        tipo2 getCodigo_Generico(){
            return this->Codigo_Generico;
        }
        void setCodigo_Generico(tipo2 _Codigo_Generico){
            this->Codigo_Generico = _Codigo_Generico;
        }

        vector<tipo1*> getMembros(){
            return membros;
        }
        void setMembros(tipo1* _Membros){
            this->membros = _Membros;
        }
};

//classe abstrata
class Funcionarios {
    private:
        string nome;
        string matricula;
        float salario;
        float cargaHoraria;
    public:
        virtual void imprimeAtribFunc (){
            cout << "Nome: " << this->nome << "; Matricula: " << this->matricula << "; Salario: " << this->salario << " reais; Carga horaria: " << this->cargaHoraria << " horas."  << endl;
            return;
        }
        virtual void imprime_funcao () = 0;

        string getNome(){
            return this->nome;
        }
        void setNome (string _nome){
            this-> nome = _nome;
        }

        string getMatricula(){
            return this-> matricula;
        }
        void setMatricula(string _matricula){
            this-> matricula = _matricula;
        }
        float getSalario (){
            return this->salario;
        }
        void setSalario (float _salario){
            this-> salario = _salario;
        }
        float getCargaHoraria(){
            return this-> cargaHoraria;
        }
        void setCargaHoraria(float _cargaHoraria){
            this-> cargaHoraria = _cargaHoraria;
        }
};

class Analista: public Funcionarios {
    public:
        void imprimeAtribFunc(){
            cout << "Nome: " << this->getNome() << "; Matricula: " << this->getMatricula() << "; Salario: " << this->getSalario() << " reais; Carga horaria: " << this->getCargaHoraria() << " horas."  << endl;
            return;
        }
        void imprime_funcao(){
            cout << "Funcao: Analista, brother." << endl;
        }
};

class Desenvolvedor: public Funcionarios {
    public:
        void imprimeAtribFunc(){
            cout << "Nome: " << this->getNome() << "; Matricula: " << this->getMatricula() << "; Salario: " << this->getSalario() << " reais; Carga horaria: " << this->getCargaHoraria() << " horas."  << endl;
            return;
        }
        void imprime_funcao(){
            cout << "Funcao: Desenvolverdor, brother." << endl;
        }
};

class Testador: public Funcionarios{
    public:
        void imprimeAtribFunc(){
            cout << "Nome: " << this->getNome() << "; Matricula: " << this->getMatricula() << "; Salario: " << this->getSalario() << " reais; Carga horaria: " << this->getCargaHoraria() << " horas."  << endl;
            return;
        }
        void imprime_funcao(){
            cout << "Funcao: Testador, brother." << endl;
        }
};

int main(){
    Setor<int,Analista>* analista = new Setor<int, Analista>;
    Setor<int,Desenvolvedor>* desenvolvedor = new Setor<int, Desenvolvedor>;
    Setor<int,Testador>* testador = new Setor<int, Testador>;

    string nome;
    string matricula;
    float cargaHoraria;
    float salario;

    vector<Analista*> *asd = new vector<Analista*>;

    int i;
    for (i=0; i<2; i++){

        Analista *anal = new Analista;

        cout << "Analista [" << i << "] nome: "<< endl;
        cin  >> nome;
        cout << "Analista [" << i << "] matricula: "<< endl;
        cin  >> matricula;
        cout << "Analista [" << i << "] salario: "<< endl;
        cin  >> salario;
        cout << "Analista [" << i << "] carga horaria: "<< endl;
        cin  >> cargaHoraria;

        anal->setNome(nome);
        anal->setMatricula(matricula);
        anal->setSalario(salario);
        anal->setCargaHoraria(cargaHoraria);

        analista->addNovosMembros(anal);

    }
    for (i=0; i<2; i++){

        Desenvolvedor *desenv = new Desenvolvedor;

        cout << "Desenvolvedor [" << i << "] nome: "<< endl;
        cin  >> nome;
        cout << "Desenvolvedor [" << i << "] matricula: "<< endl;
        cin  >> matricula;
        cout << "Desenvolvedor [" << i << "] salario: "<< endl;
        cin  >> salario;
        cout << "Desenvolvedor [" << i << "] carga horaria: "<< endl;
        cin  >> cargaHoraria;

        desenv->setNome(nome);
        desenv->setMatricula(matricula);
        desenv->setSalario(salario);
        desenv->setCargaHoraria(cargaHoraria);

        desenvolvedor->addNovosMembros(desenv);

    }
    for (i=0; i<2; i++){

        Testador *testa = new Testador;

        cout << "Testador [" << i << "] nome: "<< endl;
        cin  >> nome;
        cout << "Testador [" << i << "] matricula: "<< endl;
        cin  >> matricula;
        cout << "Testador [" << i << "] salario: "<< endl;
        cin  >> salario;
        cout << "Testador [" << i << "] carga horaria: "<< endl;
        cin  >> cargaHoraria;

        testa->setNome(nome);
        testa->setMatricula(matricula);
        testa->setSalario(salario);
        testa->setCargaHoraria(cargaHoraria);

        testador->addNovosMembros(testa);

    }

    cout << "Lista de membros analistas: " << endl;
    for (i = 0; i<2; i++){
        analista->getMembros()[i]->imprimeAtribFunc();
    }
    cout << "Lista de membros desenvolvedores: " << endl;
    for (i = 0; i<2; i++){
        desenvolvedor->getMembros()[i]->imprimeAtribFunc();
    }
    cout << "Lista de membros testadores: " << endl;
    for (i = 0; i<2; i++){
        testador->getMembros()[i]->imprimeAtribFunc();
    }

    delete(analista);
    delete(desenvolvedor);
    delete(testador);


    return 0;
}
