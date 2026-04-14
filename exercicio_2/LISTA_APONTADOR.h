#pragma once

typedef struct NodoLista *Apontador;
typedef struct
{
    int Chave;
    /*outros componentes*/
} TInfo;
struct NodoLista
{
    TInfo Item;
    struct NodoLista *Proximo;
};
typedef struct
{
    struct NodoLista *Primeiro;
    struct NodoLista *Ultimo;
} TLista;

void Cria(TLista &Lista);
bool Vazia(TLista Lista);
void InsereInicio(TLista &Lista, TInfo Item);
void InserePosicao(TLista &Lista, int pos, TInfo Item);
void InsereFinal(TLista &Lista, TInfo Item);
void RemoveInicio(TLista &Lista);
void RemoveFinal(TLista &Lista);
void PesquisaRemove(TLista &Lista, TInfo Item);
void Imprime(TLista Lista);
