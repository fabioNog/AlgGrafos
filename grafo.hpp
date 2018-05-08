#include <iostream>
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "listaAdj.hpp";


class grafo{
private:
    int vertice;
    int aresta;
    lista L;
    
public:
    grafo(int vertice,int aresta);
    void insere();
};


#endif /* GRAFO_HPP */

