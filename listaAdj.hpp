

#ifndef LISTAADJ_HPP
#define LISTAADJ_HPP

typedef int Dado;
class noh{
    friend class lista;
private:
    Dado dado;
    noh* proximo;
public:
    noh(Dado d);
};

class lista{
    
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
public:
    lista();
   ~lista();
   
   
   inline bool vazia();
   void insere(Dado d);
   void imprime();
    
};




#endif /* LISTAADJ_HPP */
