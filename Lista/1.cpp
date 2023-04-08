// Lista PAC - 2018/2 - Eng. Ele.
// Higor David Oliveira - 2018102587
// João Phillipe Hautequestt - 2018102204
// Nara Moraes Marcarini - 2018102176

#include <iostream>

using namespace std;

template<typename tipo>
void ordenaVetor(tipo *v, int tam, bool ordem){
    int i, j;
    tipo aux;
    if (ordem){
        //ordenar crescente
        for (j = 0; j < tam -1; j++){
            for(i = 0; i < tam - 1; i++){
                if( v[i] > v[i + 1]){
                    aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                }
            }
        }
    }

    else{//ordenar decrescente
        for (j = 0; j < tam -1; j++){
            for(i = 0; i < tam - 1; i++){
                if( v[i] < v[i + 1]){
                    aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                }
            }
        }
    }
}

template <typename tipo>
void imprimeVetor(tipo *v, int tam){
    int i;
    for (i=0; i<tam ; i++);
        cout <<  "[" << i << "]: " << v[i] << endl;
    return;
}

template<typename tipo>
tipo* leVetor (int tam){
    int i;
    tipo* VetorGen;
    VetorGen = new tipo[tam];
    for (i = 0; i < tam; i++){
        cout << "Valor na posicao [" << i+1 << "]: ";
        cin >> VetorGen[i];
    }
    return VetorGen;
}

int Menu(){
    int i;
    cout << "Escolha um tipo entre as opcoes abaixo: " << endl
        << "(1) Inteiro" << endl
        << "(2) Real" << endl
        << "(3) Inteiro Longo" << endl
        << "(4) Real Longo" << endl
        << "(5) Caractere" << endl;
    cin >> i;
    return i;
}

int main(){
    int t;
    int i;
    bool ordem;


    i = Menu();
    while (i<1 || i>5){
        cout << "Menu invalido, digite novamente!"<< endl;
        i = Menu();
    }

    cout << "Digite o tamanho do vetor: ";
    cin >> t;
    while (t<0){
    cout << "Tamanho invalido!" << endl;
    cout << "Digite o tamanho do vetor: ";
    cin >> t;
    }
    void *VetorGen;

    switch(i){
        case 1:
            {
                int *VetorGen;
                VetorGen = leVetor<int>(t);

                ordenaVetor<int>(VetorGen, t, 1);
                cout << "Vetor na ordem crescente: " << endl;
                imprimeVetor<int>(VetorGen, t);

                ordenaVetor<int>(VetorGen, t, 0);

                cout << "Vetor na ordem decrescente: " << endl;
                imprimeVetor<int>(VetorGen, t);

                break;
            }
        case 2:
            {
                float *VetorGen;
                VetorGen = leVetor<float>(t);

                ordenaVetor<float>(VetorGen, t, 1);
                cout << "Vetor na ordem crescente: " << endl;
                imprimeVetor<float>(VetorGen, t);

                ordenaVetor<float>(VetorGen, t, 0);

                cout << "Vetor na ordem decrescente: " << endl;
                imprimeVetor<float>(VetorGen, t);
                break;
            }
        case 3:
            {
                long int *VetorGen;
                VetorGen = leVetor<long int>(t);

                ordenaVetor<long int>(VetorGen, t, 1);
                cout << "Vetor na ordem crescente: " << endl;
                imprimeVetor<long int>(VetorGen, t);

                ordenaVetor<long int>(VetorGen, t, 0);

                cout << "Vetor na ordem decrescente: " << endl;
                imprimeVetor<long int>(VetorGen, t);
                break;
            }
        case 4:
            {
                double *VetorGen;
                VetorGen = leVetor<double>(t);

                ordenaVetor<double>(VetorGen, t, 1);
                cout << "Vetor na ordem crescente: " << endl;
                imprimeVetor<double>(VetorGen, t);

                ordenaVetor<double>(VetorGen, t, 0);

                cout << "Vetor na ordem decrescente: " << endl;
                imprimeVetor<double>(VetorGen, t);
                break;
            }
        case 5:
            {
                char *VetorGen;
                VetorGen = leVetor<char>(t);

                ordenaVetor<char>(VetorGen, t, 1);
                cout << "Vetor na ordem crescente: " << endl;
                imprimeVetor<char>(VetorGen, t);

                ordenaVetor<char>(VetorGen, t, 0);

                cout << "Vetor na ordem decrescente: " << endl;
                imprimeVetor<char>(VetorGen, t);
                break;
            }

            default:
            int *VetorGen;
            cout << "Nao ha opcao"<< endl;
            break;
        }

    return 0;
}
