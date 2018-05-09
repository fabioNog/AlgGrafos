//Bibliotecas do C++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//Bibliotecas criadas por mim
#include "listaAdj.hpp"
#include "matrizAdj.hpp"
#include "grafo.hpp"

using namespace std;

int main() {
    
    string s;
    cout << "Digite o valor do arquivo" << endl;
    cin >> s;
    ifstream arquivo(s);
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
    }
    for (int i = 0; i < cont; i++) {
        cout << vet[i] << endl;
    }
    
//    Instanciando um grafo
    grafo* F = new grafo(cont);
    
    int i=0;
    while(i < cont){
        F->adicionarAresta(vet[i],vet[i+1]);
        i = i+2;
    }
    
    F->imprimeListas();

    return 0;
}
//    L->imprime();

