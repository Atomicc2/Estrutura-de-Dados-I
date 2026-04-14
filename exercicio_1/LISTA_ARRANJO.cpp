#include <iostream>
#include "LISTA_ARRANJO.h"
using namespace std;

void Cria(TLista& Lista) {
    Lista.tamanho = 0;
}

void Imprime(TLista Lista) {
    for(int i = 0; i < Lista.tamanho; i++) {
        cout << Lista.itens[i].Chave << " ";
    }
    cout << endl;
}

void InsereInicio(TLista& Lista, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        for(int i = Lista.tamanho; i > 0; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[0] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void InserePosicao(TLista& Lista, int pos, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        for(int i = Lista.tamanho; i > pos; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[pos] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }   
}

void InsereFinal(TLista& Lista, TInfo Item){
    if(Lista.tamanho < Tmax) {
        Lista.itens[Lista.tamanho] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void InsereOrdenado(TLista& Lista, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        int pos = 0;
        while(pos < Lista.tamanho && Lista.itens[pos].Chave < Item.Chave) {
            pos++;
        }
        for(int i = Lista.tamanho; i > pos; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[pos] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

void RemoveInicio(TLista& Lista) {
    if(Lista.tamanho > 0) {
        for(int i = 0; i < Lista.tamanho -1; i++) {
            Lista.itens[i] = Lista.itens[i+1];
        }
        Lista.tamanho--;
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }
}

void RemoveFinal(TLista& Lista) {
    if(Lista.tamanho > 0) {
        Lista.tamanho--;
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }

}

void PesquisaRemove(TLista& Lista, int Chave) {
    if(Lista.tamanho > 0) {
        for(int i = 0; i < Lista.tamanho; i++) {
            if(Lista.itens[i].Chave == Chave) {
                for(int j = i; j < Lista.tamanho -1; j++) {
                    Lista.itens[j] = Lista.itens[j+1];
                }
                Lista.tamanho--;
            } else {
                cout << "Chave não encontrada." << endl;
            }
        }
    } else {
        cout << "Lista vazia. Não é possível remover." << endl;
    }
}

/* Resposta da primeira quastão

void InsereOrdenado(TLista& Lista, TInfo Item) {
    if(Lista.tamanho < Tmax) {
        int pos = 0;
        while(pos < Lista.tamanho && Lista.itens[pos].Chave < Item.Chave) {
            pos++;
        }
        for(int i = Lista.tamanho; i > pos; i--) {
            Lista.itens[i] = Lista.itens[i-1];
        }
        Lista.itens[pos] = Item;
        Lista.tamanho++;
    } else {
        cout << "Lista cheia. Não é possível inserir." << endl;
    }
}

*/