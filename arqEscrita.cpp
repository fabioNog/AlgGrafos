#include <iostream>

#include <fstream>

using namespace std;


int main(){
    ofstream arq("meus dados.txt");
    arq << "Escrevendo no arquivo" << endl;
    arq.close();
    return 0;
}
