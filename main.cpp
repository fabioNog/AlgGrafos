//Bibliotecas do C++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//Bibliotecas criadas por mim
#include "listaAdj.hpp"
#include "matrizAdj.hpp"
#include "grafo.hpp"

using namespace std;

int main() {

    string s;
    cout << "Digite o valor do arquivo" << endl;
    cin >> s;

    //++++++++++++++++++++++++++++++++++++++++++++    
    //    DECLARANDO  VARIAVEIS 
    //++++++++++++++++++++++++++++++++++++++++++++      
    ifstream arquivo(s);
    string dados;

    lista* LArq;
    lista* LVert1;
    LArq = new lista();
    LVert1 = new lista();

    Dado* vet;

    Dado cont = 0;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //    Primeiro Verifica-se se o arquivo foi aberto corretamente 
    //    Se sim então ele entrara no while
    //    DENTRO DO WHILE INSIREI TODAS AS STRINGS DO ARQUIVO EM UMA LISTA ENCADEADA
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    if (arquivo) {
        // Dentro deste while eu pegarei cada string do arquivo e armazenarei em uma lista
        while (arquivo >> dados) {
            if (dados == "DIRECTED") {
                continue;
            }
            string s = dados;
            int i = stoi(s);
            LArq->insere(i);
            cont++;
        }
        arquivo.close();
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    // *   ALOCANDO TODOS AS STRINGS PARES EM UMA VETOR SECUNDARIO 
    // *   AO QUAL GERARA UMA LISTA DE AO QUAL SEU TAMANHO É A METADE DA LISTA QUE A GEROU
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    noh* atual1 = LArq->getPrimeiro();

    while (atual1 != LArq->getUltimo()) {
        LVert1->insere(LArq->getDado(atual1));
        atual1 = LArq->getProximo(LArq->getProximo(atual1));
        if (atual1 == NULL) {
            atual1 = LArq->getUltimo();
        }
    }


    noh* atual2 = LVert1->getPrimeiro();
    vet = new Dado[LVert1->getTamanho()];
    for (Dado i = 0; i < LVert1->getTamanho(); i++) {
        if ((atual2 != NULL) and (atual2 != LVert1->getUltimo())) {
            vet[i] = LVert1->getDado(atual2);
            atual2 = LVert1->getProximo(atual2);
        }

    }

    for (int i = 0; i < cont; i++) {
        cout << vet[i] << endl;

    }




    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //  *  Imprimeiri a lista com vertices apenas que pertecem ao primeiro vertice adicionado no grafo
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //    cout << "Imprimeiri a lista com vertices apenas que pertecem ao primeiro vertice adicionado no grafo" << endl;
    //    LVert1->imprime();



    //++++++++++++++++++++++++++++++++++++++++++++    
    //    INSERE UMA LISTA EM UM VETOR 
    //++++++++++++++++++++++++++++++++++++++++++++

    //
    //    //++++++++++++++++++++++++++++++++++++++++++++    
    //    //    IMPRIME VETOR 
    //    //++++++++++++++++++++++++++++++++++++++++++++
    //    Dado Metade = LVert1->getTamanho();
    //    cout << "Imprime o vetor " << endl;
    //    for (int i = 0; i < Metade; i++) {
    //        cout << vet[i] << endl;
    //    }
    //
    //
    //    Dado i, j, k;
    //
    //    Dado* Repetidos;
    //    Repetidos = new Dado[Metade];
    //
    //    for (i = 0; i < Metade; i++) {
    //        Repetidos[i] = -2;
    //    }
    //
    //    Dado* Repeticoes;
    //    Repeticoes = new Dado[Metade];
    //
    //    for (i = 0; i < cont; i++) {
    //        Repeticoes[i] = 1;
    //    }
    //
    //    for (i = 0; i < cont; i++) {
    //        //        printf("Digite o a[%d] = ", i);
    //        //        scanf("%d", &Lidos[i]);
    //
    //        for (j = 0; j <= i; j++) {
    //            if (vet[i] == Repetidos[j]) {
    //                Repeticoes[j]++;
    //                break;
    //            } else if (Repetidos[j] == -2) {
    //                Repetidos[i] = vet[i];
    //            }
    //        }
    //    }
    //
    //    if (vet[i] < 0 || i >= cont - 1) {
    //        for (k = 0; k < i; k++) {
    //            if ((Repeticoes[k] != 1) and (Repetidos[k] != -2)) {
    //                cout << "O numero " << Repetidos[k] << " apareceu " << Repeticoes[k] << "vezes.\n";
    //            }
    //
    //        }
    //    }
    //
    //
    //    grafo* F = new grafo(cont);



    //    //        ADICIONANDO NA LISTA DE ADJENCIA DO GRAFO;
    //    int i = 0;
    //    cout << "Cheguei fora do while" << endl;
    //    while (i < cont) {
    //        cout << "Cheguei fora do while" << endl;
    //        F->adicionarAresta(vet[i], vet[i + 1]);
    //        i = i + 2;
    //        cout << "Cheguei aqui 2" << endl;
    //
    //    }


    //    F->imprimeListas();

    return 0;
}