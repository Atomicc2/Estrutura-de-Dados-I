#include <iostream>
#include "PILHA_ARRANJO.h"
using namespace std;

void Cria(TPilha& Lista) {
    Lista.topo = 0;
}

void Imprime(TPilha Lista) {
    for(int i = 0; i < Lista.topo; i++) {
        cout << Lista.itens[i].Chave << " ";
    }
    cout << endl;
}

void Empilha(TPilha& Lista, TInfo Item){
    if(Lista.topo < Tmax) {
        Lista.itens[Lista.topo] = Item;
        Lista.topo++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void Desempilha(TPilha& Lista) {
    if(Lista.topo > 0) {
        Lista.topo--;
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }

}