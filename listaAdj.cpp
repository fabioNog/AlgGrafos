#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "listaAdj.hpp"

using namespace std;


noh::noh(Dado d){
    dado = d;
    proximo = NULL;
}


lista::lista(){
    primeiro = NULL;
    ultimo = NULL;
    tamanho = 0;
}

lista::~lista(){
    noh* aux = primeiro;
    noh* temp;
    while(aux != NULL){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    
    ultimo = NULL;
    primeiro = NULL;
}

inline bool lista::vazia(){
     if(primeiro = NULL){
        return true;
    }
}

void lista::insere(Dado d){
    noh* novo = new noh(d);
    
    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;       
    }

    ultimo->proximo = novo;
    ultimo = novo;
    tamanho++;
}

void lista::imprime(){
    noh* aux = primeiro;
    int i = 0;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    while(aux != NULL){
        cout << (i+1) << " valor: " << aux->dado << endl;
        aux = aux->proximo;
        i++;
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}


//Retorna o ponteiro para o primeiro elemento da lista
noh* lista::getPrimeiro(){
    return this->primeiro;
}

//Retorna o dado do noh da lista;

Dado lista::getDado(noh* aux){
    return aux->dado;
}

noh* lista::getProximo(noh* aux){
    return aux->proximo;
}

noh* lista::getNo(noh* no){
    return no;
}

int lista::getTamanho(){
    return this->tamanho;
}