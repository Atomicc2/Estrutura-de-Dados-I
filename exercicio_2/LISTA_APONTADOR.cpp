#include <iostream>
#include "LISTA_APONTADOR.h"

using namespace std;

//--------------------------------------------
void Cria(TLista &Lista)
{
    Lista.Primeiro = new NodoLista;
    Lista.Ultimo = Lista.Primeiro;
    Lista.Primeiro->Proximo = NULL;
}
//--------------------------------------------
bool Vazia(TLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}
//--------------------------------------------
void InsereInicio(TLista &Lista, TInfo Item)
{
    Apontador p = new NodoLista;
    p->Item = Item;
    p->Proximo = Lista.Primeiro->Proximo;
    Lista.Primeiro->Proximo = p;
    if (p->Proximo == NULL)
        Lista.Ultimo = p;
}
//--------------------------------------------
void InsereFinal(TLista &Lista, TInfo Item)
{
    Apontador p = new NodoLista;
    p->Item = Item;
    p->Proximo = NULL;
    Lista.Ultimo->Proximo = p;
    Lista.Ultimo = p;
}
//--------------------------------------------
void InserePosicao(TLista &Lista, int pos, TInfo Item)
{
    if (pos <= 1 || Vazia(Lista))
    {
        InsereInicio(Lista, Item);
        return;
    }

    Apontador anterior = Lista.Primeiro;
    int i = 1;
    while (anterior->Proximo != NULL && i < pos)
    {
        anterior = anterior->Proximo;
        i++;
    }

    Apontador p = new NodoLista;
    p->Item = Item;
    p->Proximo = anterior->Proximo;
    anterior->Proximo = p;
    if (p->Proximo == NULL)
        Lista.Ultimo = p;
}
//--------------------------------------------
void RemoveInicio(TLista &Lista)
{
    if (Vazia(Lista))
    {
        cout << "Erro : A lista esta vazia." << endl;
    }
    else
    {
        Apontador p = Lista.Primeiro->Proximo;
        cout << "Elemento Removido = " << p->Item.Chave << endl;
        Lista.Primeiro->Proximo = p->Proximo;
        if (Lista.Primeiro->Proximo == NULL)
            Lista.Ultimo = Lista.Primeiro;
        delete p;
    }
}
//--------------------------------------------
void RemoveFinal(TLista &Lista)
{
    if (Vazia(Lista))
    {
        cout << "Erro : A lista esta vazia." << endl;
        return;
    }

    Apontador anterior = Lista.Primeiro;
    while (anterior->Proximo != Lista.Ultimo)
    {
        anterior = anterior->Proximo;
    }

    Apontador p = Lista.Ultimo;
    cout << "Elemento Removido = " << p->Item.Chave << endl;
    anterior->Proximo = NULL;
    Lista.Ultimo = anterior;
    delete p;
}
//--------------------------------------------
void PesquisaRemove(TLista &Lista, TInfo Item)
{
    if (Vazia(Lista))
    {
        cout << "Erro : A lista esta vazia." << endl;
        return;
    }

    Apontador anterior = Lista.Primeiro;
    Apontador atual = anterior->Proximo;
    while (atual != NULL && atual->Item.Chave != Item.Chave)
    {
        anterior = atual;
        atual = atual->Proximo;
    }

    if (atual == NULL)
    {
        cout << "Elemento " << Item.Chave << " nao encontrado." << endl;
        return;
    }

    anterior->Proximo = atual->Proximo;
    if (atual == Lista.Ultimo)
        Lista.Ultimo = anterior;

    cout << "Elemento Removido = " << atual->Item.Chave << endl;
    delete atual;
}
//--------------------------------------------
void Imprime(TLista Lista)
{
    cout << "Itens na LISTA: " << endl;
    if (Vazia(Lista))
    {
        cout << "Lista esta vazia." << endl;
    }
    else
    {
        Apontador aux = Lista.Primeiro->Proximo;
        while (aux != NULL)
        {
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
//--------------------------------------------