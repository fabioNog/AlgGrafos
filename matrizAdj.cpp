#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "matrizAdj.hpp"
using namespace std;

matriz::matriz(int linha, int coluna) {
    this->linha = linha;
    this->coluna = coluna;
    mat = new int*[linha];
    for (int i = 0; i < linha; i++) {
        mat[i] = new int[coluna];
    }
}

void matriz::insere() {
    int valor;
    cout << "Chego aqui no insere" << endl;
    for (int i = 0; i < this->getLinha(); i++) {
        for (int j = 0; j < this->getColuna(); j++) {
            cout << "Digite um valor a ser inserido na matriz: " << endl;
            cin >> valor;
            mat[i][j] = valor;
        }
    }
}

void matriz::imprime() {
    for (int i = 0; i < this->getLinha(); i++) {
        for (int j = 0; j < this->getColuna(); j++) {
            cout << "linha " << i << " coluna " << j << " esta o valor: " << mat[i][j] << endl;
        }
    }
}

int matriz::getLinha() {
    return this->linha;
}

int matriz::getColuna() {
    return this->coluna;
}


