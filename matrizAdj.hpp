#ifndef MATRIZADJ_HPP
#define MATRIZADJ_HPP
#include <iostream>
using namespace std;

class matriz{
private:
    int linha,coluna;    
    int** mat;
public:
    
    matriz(int linha,int coluna);
    void insere();
    int getLinha();
    int getColuna();
    int getValor();
    void setLinha(int linha);
    void setColuna(int coluna);
    void setValor(int valor);
    void imprime();
    
};

#endif /* MATRIZADJ_HPP */

