#include <iostream>
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "listaAdj.hpp"

class grafo {
private:
    Dado V; // número de vértices

    Dado vertice;
    Dado aresta;
    lista* L;

public:
    grafo(Dado V);
    void adicionarAresta(Dado v1, Dado v2); // adiciona uma aresta no grafo
    int obterGrauDeSaida(Dado v);
    bool ehVizinho(Dado v1, Dado v2);
    void imprimeListas();
};


#endif /* GRAFO_HPP */

