#include <iostream>

#include "grafo.hpp"
#include <string>

using namespace std;

grafo::grafo(Dado V) {
    this->V = V; // atribui o número de vértices
    this->L = new lista[V];
    this->tamVetor = 0;
}

void grafo::adicionarAresta(Dado v1, Dado v2) {
    // adiciona vértice v2 à lista de vértices adjacentes de v   
    L[v1].insere(v2);
    this->tamVetor++;
}

void grafo::guardaV1(Dado d) {

    Dado* V = new Dado[this->tamVetor];
    for (int i = 0; i<this->tamVetor; i++) {
        V[i] = d;
        if (i == this->tamVetor) {
            for (int j = 0; j < this->tamVetor; i++) {
                cout << V[i] << endl;
            }
        }

    }

}

void grafo::imprimeListaV1(lista* L) {

}

int grafo::obterGrauDeSaida(int v) {
    // basta retornar o tamanho da lista que é a quantidade de vizinhos
    return L[v].getTamanho();
}

//

bool grafo::ehVizinho(Dado v1, Dado v2) {
    noh* aux = L[v1].getPrimeiro();

    while (aux != NULL) {
        if (L[v1].getDado(aux) == v2) {
            return true;
        }
        aux = L[v1].getProximo(aux);
        if (aux == NULL) {
            cout << "NAO ENCONTRADO" << endl;
        }
    }
}

void grafo::imprimeListas() {
    cout << "chegue aqui" << endl;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //A IDEIA AQUI EH FAZER UM LAÇO EM TODOS OS VERTICES ANDANDO NA LISTA EM CADA ITERAÇÃO
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for (Dado i = 0; i < this->V; i++) {


        //   Obtenho o ponteiro primeiro da lista do L[i]
        noh* aux = L[i].getPrimeiro();

        cout << "L[" << i << "] -> ";

        while (aux != L[i].getUltimo()) {
            cout << L[i].getDado(aux);
            aux = L[i].getProximo(aux);
            if (aux == L[i].getUltimo()) {
                cout << L[i].getDado(aux);
            }
        }

    }

}

//Retorna a todos os vertices do Arquivo inclusive os repetidos;

Dado grafo::getV() {
    return this->V;
}

Dado grafo::getTamVetor() {
    return this->tamVetor;
}


