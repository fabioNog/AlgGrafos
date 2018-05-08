#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "listaAdj.hpp"
#include "matrizAdj.hpp"

using namespace std;

int main() {
    ifstream arquivo("Arquivo1.txt");
    string dados;
    cout << endl;
    lista* L;
    L = new lista();
    Dado* vet;

    int cont = 0;

    //    Primeiro Verifica-se se o arquivo foi aberto corretamente 
    //    Se sim então ele entrara no while
    if (arquivo) {
        //        Dentro deste while eu pegarei cada string do arquivo e armazenarei em uma lista
        while (arquivo >> dados) {
            if (dados == "DIRECTED") {
                continue;
            }
            string s = dados;
            int i = stoi(s);
            L->insere(i);
            cont++;
        }
        
        
        arquivo.close();

    }
//       Alocarei um vetor de tamanho referente a quantidade(cont) de strings contidas no arquivo  
    vet = new Dado[cont];
    noh* atual = L->getPrimeiro();
    

    for (int i = 0; i < cont; i++) {
        vet[i] = L->getDado(atual);
        atual = L->getProximo(atual);
        cout << vet[i] << endl;
    }

    return 0;
}
//    L->imprime();

