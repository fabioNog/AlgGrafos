#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "listaAdj.hpp"
#include "matrizAdj.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
//    int dado;
//    int Q;
//    cout << "Digite a quantidade de elementos que estarao presentes na lista" << endl;
//    cin >> Q;
//    lista* L = new lista();
//    
//    for(int i=0;i<Q;i++){
//        cout << "Digite o " << (i+1) << " valor a ser inserido nesta lista" << endl;
//        cin >> dado;
//        L->insere(dado);
//    }
//    
//    L->imprime();

//Testandoo a class Matriz
    
    int i,j;
    int linha,coluna;
    
    cout << "Digite a quantidade de linhas da matriz:" << endl;
    cin >> linha;
    cout << "Digite a quantidade de colunas da matriz:" << endl;
    cin >> coluna;
    
    matriz* M = new matriz(linha,coluna);
    M->insere();
    M->imprime();
    
    return 0;
}

