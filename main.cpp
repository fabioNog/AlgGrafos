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

    //++++++++++++++++++++++++++++++++++++++++++++    
    //    DECLARANDO  VARIAVEIS 
    //++++++++++++++++++++++++++++++++++++++++++++      
    ifstream arquivo(s);
    string dados;

    lista* LArq;
    lista* LVert1;
    LArq = new lista();
    LVert1 = new lista();

    Dado* vet;

    int cont = 0;

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //    Primeiro Verifica-se se o arquivo foi aberto corretamente 
    //    Se sim então ele entrara no while
    //    DENTRO DO WHILE INSIREI TODAS AS STRINGS DO ARQUIVO EM UMA LISTA ENCADEADA
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    if (arquivo) {
        // Dentro deste while eu pegarei cada string do arquivo e armazenarei em uma lista
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

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //    ALOCANDO TODOS AS STRINGS PARES EM UMA LISTA SECUNDARIA 
    //    AO QUAL GERARA UMA LISTA DE AO QUAL SEU TAMANHO É A METADE DA LISTA QUE A GEROU
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    noh* atual1 = LArq->getPrimeiro();

    while (atual1 != LArq->getUltimo()) {
        LVert1->insere(LArq->getDado(atual1));
        atual1 = LArq->getProximo(LArq->getProximo(atual1));
        if (atual1 == NULL) {
            atual1 = LArq->getUltimo();
        }
    }

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++    
    //    FAZENDO A COMPARAÇÃO DE QUANTAS VEZES UM ELEMENTO APARECE NA LISTA
    //    AO QUAL GERARA UMA LISTA DE AO QUAL SEU TAMANHO É A METADE DA LISTA QUE A GEROU
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    noh* atual1 = LVert1->getPrimeiro();
    noh* aux1;
    int cont1 = 0;
    lista* ListaTamanho;
    ListaTamanho = new lista();
    while (atual1 != NULL) {
        aux1 = LVert1->getProximo(atual1);
        while (aux1 != NULL) {
            if (LVert1->getDado(atual1) == LVert1->getDado(aux1)) {
                cont1++;
                aux1 = LVert1->getProximo(aux1);
            }
        }
        ListaTamanho->insere(cont1);
        atual1 = LVert1->getProximo(atual1);
    }

    ListaTamanho->imprime();




    //++++++++++++++++++++++++++++++++++++++++++++    
    //    INSERE UMA LISTA EM UM VETOR 
    //++++++++++++++++++++++++++++++++++++++++++++
    //vet = new Dado[cont];
    //    for (int i = 0; i < cont; i++) {
    //        cout << "Cheguei aqui" << endl;
    //        vet[i] = LArq->getDado(atual1);
    //        atual1 = LArq->getProximo(atual1);
    //    }
    //++++++++++++++++++++++++++++++++++++++++++++    
    //    INSERE UMA LISTA EM UM VETOR 
    //++++++++++++++++++++++++++++++++++++++++++++ 



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