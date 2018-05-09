#include <iostream>

#include "grafo.hpp"

using namespace std;

grafo::grafo(Dado V) {
    this->V = V; // atribui o número de vértices
    this->L = new lista[V];
}

void grafo::adicionarAresta(Dado v1, Dado v2) {
    // adiciona vértice v2 à lista de vértices adjacentes de v   
    L[v1].insere(v2);
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

void grafo::imprimeListas(){
    
    for(int i=0;i<this->V;i++){
        noh* aux = L[i].getPrimeiro();        
        cout << "L["<< i << "]"<< L[i].getDado(aux) << endl;
        aux = L[i].getProximo(aux);
    }
}



