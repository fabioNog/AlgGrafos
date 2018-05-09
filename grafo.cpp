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
    // basta retornar o tamanho da l    ista que é a quantidade de vizinhos
    return L[v].getTamanho();
}

bool grafo::ehVizinho(Dado v1, Dado v2) {
    noh* aux = L[v1].getPrimeiro();
    
    while(aux != NULL){
        if(L[v1].getDado(aux) == v2){
            return true;
        }
        aux = L[v1].getProximo(aux);
        if(aux == NULL){
            cout << "NAO ENCONTRADO" << endl;
        }
    }

}
//	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
//		return true;
//	return false;
//}


int main() {
    // criando um grafo de 4 vértices
    grafo grafo(4);

    // adicionando as arestas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 3);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(3, 1);
    grafo.adicionarAresta(3, 2);

    // mostrando os graus de saída
    cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
    cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

    // verifica se existe vizinhos
    if (grafo.ehVizinho(0, 1))
        cout << "\n\n1 eh vizinho de 0\n";
    else
        cout << "\n\n1 NAO eh vizinho de 0\n";

    if (grafo.ehVizinho(0, 2))
        cout << "2 eh vizinho de 0\n";
    else
        cout << "2 NAO eh vizinho de 0\n";

    return 0;
}