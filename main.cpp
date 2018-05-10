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
    lista* LArq;
    lista* LVert1;
    LArq = new lista();
    LVert1 = new lista();
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
            LArq->insere(i);
            cont++;
        }
        arquivo.close();
    }
    
    //       Alocarei um vetor de tamanho referente a quantidade(cont) de strings contidas no arquivo  
    vet = new Dado[cont];
    noh* atual = LArq->getPrimeiro();

    while (atual != LArq->getUltimo()) {
        LVert1->insere(LArq->getDado(atual));
        atual = LArq->getProximo(LArq->getProximo(atual));
        if(atual == NULL){
            atual = LArq->getUltimo();
        }
    }

    LVert1->imprime();



    //++++++++++++++++++++++++++++++++++++++++++++    
    //    INSERE UMA LISTA EM UM VETOR 
    //++++++++++++++++++++++++++++++++++++++++++++        
    for (int i = 0; i < cont; i++) {
        cout << "Cheguei aqui" << endl;
        vet[i] = LArq->getDado(atual);
        atual = LArq->getProximo(atual);
    }



    //    for (int i = 0; i < cont; i++) {
    //        cout << vet[i];
    //    }
    //    
    //    cout << cont/2 << endl; 
    //    
    //    
    ////    Instanciando um grafo
    //    grafo* F = new grafo(cont);
    //    
    //    
    //    
    //    
    //    int* vetGuarda;
    //    vetGuarda = new int[cont/2];
    //    int j=0;
    //    for(int i=0;i<cont;i++){
    //        vetGuarda[j] = vet[i];
    //        j++;
    //        i = i+2;
    //    }
    //    for(int i=0;i<j;i++){
    //        cout << vetGuarda[i];
    //    }


    //    ADICIONANDO NA LISTA DE ADJENCIA DO GRAFO;
    //    int i=0;
    //    while(i < cont){
    //        F->adicionarAresta(vet[i],vet[i+1]);
    //        F->guardaV1(vet[i]);
    //        i = i+2;
    //        if(i == cont){
    //            i =  i - 2;
    //            cout << "O valor do i antes de adicionar na aresta eh: " << i << endl;
    //            F->adicionarAresta(vet[i],vet[i+1]);
    //            F->guardaV1(vet[i]);
    //            i = i + 2;
    //            cout << "O valor do i depois de add na aresta agora eh: " << i << endl;
    //        }
    //    }


    //    F->imprimeListas();

    return 0;
}