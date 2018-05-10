#include <iostream>
#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <string>

#include "listaAdj.hpp"

class grafo {
private:
    Dado V; // número de vértices

    Dado vertice;
    Dado aresta;
    lista* L;
    Dado tamVetor;
    

public:
    
    grafo(Dado V);
    void adicionarAresta(Dado v1, Dado v2); // adiciona uma aresta no grafo
    int obterGrauDeSaida(Dado v);
    bool ehVizinho(Dado v1, Dado v2);
    void imprimeListas();
    Dado getV();
    Dado getTamVetor();
    void guardaV1(Dado d);
    void imprimeListaV1(lista* L);
};


#endif /* GRAFO_HPP */

