#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
        cout << "Elemento Removido = " << p->Item.ID << endl;
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
    cout << "Elemento Removido = " << p->Item.ID << endl;
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
    while (atual != NULL && atual->Item.ID != Item.ID)
    {
        anterior = atual;
        atual = atual->Proximo;
    }

    if (atual == NULL)
    {
        cout << "Elemento " << Item.ID << " nao encontrado." << endl;
        return;
    }

    anterior->Proximo = atual->Proximo;
    if (atual == Lista.Ultimo)
        Lista.Ultimo = anterior;

    cout << "Elemento Removido = " << atual->Item.ID << endl;
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
            cout << aux->Item.ID << " ";
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
//--------------------------------------------
void CarregaArquivo(TLista &Lista, const string nomeArquivo)
{
    ifstream arquivo(nomeArquivo);
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }
    
    string linha;
    while(getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        TInfo item;
        
        getline(ss, campo, ';');
        item.ID = stoi(campo);
        
        getline(ss, campo, ';');
        item.Cidade = campo;
        
        getline(ss, campo, ';');
        item.Rodovia = campo;
        
        getline(ss, campo, ';');
        item.Data = campo;
        
        getline(ss, campo, ';');
        item.DiaSemana = campo;
        
        getline(ss, campo, ';');
        item.Hora = campo;
        
        getline(ss, campo, ';');
        item.TipoAcidente = campo;
        
        getline(ss, campo, ';');
        item.Feridos = stoi(campo);
        
        getline(ss, campo, ';');
        item.Mortos = stoi(campo);
        
        getline(ss, campo, ';');
        item.Descricao = campo;
        
        InsereFinal(Lista, item);
    }
    arquivo.close();
}
//--------------------------------------------
void ImprimeAcidente(TLista &Lista, int ID)
{
    Apontador aux = Lista.Primeiro->Proximo;
    bool encontrado = false;
    while (aux != NULL)
    {
        if(aux->Item.ID == ID) {
            encontrado = true;
            cout << "ID: " << aux->Item.ID << endl;
            cout << "Cidade: " << aux->Item.Cidade << endl;
            cout << "Rodovia: " << aux->Item.Rodovia << endl;
            cout << "Data: " << aux->Item.Data << endl;
            cout << "Dia da Semana: " << aux->Item.DiaSemana << endl;
            cout << "Hora: " << aux->Item.Hora << endl;
            cout << "Tipo de Acidente: " << aux->Item.TipoAcidente << endl;
            cout << "Feridos: " << aux->Item.Feridos << endl;
            cout << "Mortos: " << aux->Item.Mortos << endl;
            cout << "Descricao: " << aux->Item.Descricao << endl;
            break;
        }
        aux = aux->Proximo;
    }
    if(!encontrado) {
        cout << "Acidente com ID " << ID << " nao encontrado." << endl;
    }
}
//--------------------------------------------
void ImprimePorID(TLista &Lista, int ID)
{
    ImprimeAcidente(Lista, ID);
}
//--------------------------------------------