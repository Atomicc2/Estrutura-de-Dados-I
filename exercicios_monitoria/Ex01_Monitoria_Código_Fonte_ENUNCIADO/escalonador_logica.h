#ifndef ESCALONADOR_LOGICA_H
#define ESCALONADOR_LOGICA_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Processo *Apontador;

struct Processo
{
    int PID;
    char nome[101];
    int prioridade;
    Processo *ant;
    Processo *prox;
};

struct ListaProcessos
{
    Processo *primeiro;
    Processo *ultimo;
};

//------------------------------------------------------------------------
void inicializar(ListaProcessos &lista)
{
    lista.primeiro = (Apontador)malloc(sizeof(struct Processo));
    if (lista.primeiro == NULL)
    {
        cout << "[ERRO] Falha ao inicializar o sistema." << endl;
        return;
    }

    lista.primeiro->PID = -1;
    lista.primeiro->nome[0] = '\0';
    lista.primeiro->prioridade = -1;
    lista.primeiro->prox = NULL;
    lista.primeiro->ant = NULL;

    lista.ultimo = lista.primeiro;
}

//------------------------------------------------------------------------
bool listaVazia(ListaProcessos &lista)
{
    return (lista.primeiro == lista.ultimo) ? true : false;
}

//------------------------------------------------------------------------
bool pidExiste(ListaProcessos lista, int pid)
{
    Apontador pAtual = lista.primeiro->prox;

    while (pAtual != NULL)
    {
        if (pAtual->PID == pid)
        {
            return true;
        }
        pAtual = pAtual->prox;
    }

    return false;
}

//------------------------------------------------------------------------
void criarProcesso(ListaProcessos &lista, int pid, string nome, int prioridade)
{
    // Verificar se PID já existe
    if (pidExiste(lista, pid))
    {
        cout << "\n[ERRO] Processo com PID " << pid << " já existe!" << endl;
        return;
    }

    // Criar novo nó
    Apontador novoProcesso = (Apontador)malloc(sizeof(struct Processo));
    if (novoProcesso == NULL)
    {
        cout << "\n[ERRO] Falha ao alocar memória para novo processo." << endl;
        return;
    }

    novoProcesso->PID = pid;
    strcpy(novoProcesso->nome, nome.c_str());
    novoProcesso->prioridade = prioridade;

    // Encontrar posição correta (ordenado por prioridade decrescente)
    Apontador pAtual = lista.primeiro->prox;
    Apontador pAnterior = lista.primeiro;

    while (pAtual != NULL && pAtual->prioridade > prioridade)
    {
        pAnterior = pAtual;
        pAtual = pAtual->prox;
    }

    // Inserir na posição encontrada
    novoProcesso->prox = pAtual;
    novoProcesso->ant = pAnterior;

    if (pAtual != NULL)
    {
        pAtual->ant = novoProcesso;
    }
    else
    {
        lista.ultimo = novoProcesso;
    }

    pAnterior->prox = novoProcesso;

    cout << "\n[OK] Processo " << nome << " (PID: " << pid << ", Prioridade: " << prioridade << ") criado com sucesso!" << endl;
}

//------------------------------------------------------------------------
void matarProcesso(ListaProcessos &lista, int pid)
{
    Apontador pAtual = lista.primeiro->prox;

    // Buscar o processo com o PID
    while (pAtual != NULL && pAtual->PID != pid)
    {
        pAtual = pAtual->prox;
    }

    // Se não encontrou
    if (pAtual == NULL)
    {
        cout << "\n[ERRO] Processo com PID " << pid << " não encontrado!" << endl;
        return;
    }

    // Remover o processo
    pAtual->ant->prox = pAtual->prox;

    if (pAtual->prox != NULL)
    {
        pAtual->prox->ant = pAtual->ant;
    }
    else
    {
        lista.ultimo = pAtual->ant;
    }

    cout << "\n[OK] Processo " << pAtual->nome << " (PID: " << pid << ") finalizado e removido da memória." << endl;
    free(pAtual);
}

//------------------------------------------------------------------------
void imprimirEstado(ListaProcessos lista, bool reverso)
{
    if (listaVazia(lista))
    {
        cout << "\n[INFO] Nenhum processo em execução." << endl;
        return;
    }

    cout << "\n" << setw(8) << "PID" << setw(25) << "NOME" << setw(15) << "PRIORIDADE" << endl;
    cout << "---------------------------------------------------" << endl;

    if (!reverso)
    {
        // Exibir em ordem normal (alta -> baixa prioridade)
        Apontador pAtual = lista.primeiro->prox;
        while (pAtual != NULL)
        {
            cout << setw(8) << pAtual->PID << setw(25) << pAtual->nome << setw(15) << pAtual->prioridade << endl;
            pAtual = pAtual->prox;
        }
    }
    else
    {
        // Exibir em ordem reversa (baixa -> alta prioridade)
        Apontador pAtual = lista.ultimo;
        while (pAtual != lista.primeiro)
        {
            cout << setw(8) << pAtual->PID << setw(25) << pAtual->nome << setw(15) << pAtual->prioridade << endl;
            pAtual = pAtual->ant;
        }
    }
}

//------------------------------------------------------------------------
void promoverProcesso(ListaProcessos &lista, int pid, int novaPrioridade)
{
    Apontador pAtual = lista.primeiro->prox;

    // Buscar o processo com o PID
    while (pAtual != NULL && pAtual->PID != pid)
    {
        pAtual = pAtual->prox;
    }

    // Se não encontrou
    if (pAtual == NULL)
    {
        cout << "\n[ERRO] Processo com PID " << pid << " não encontrado!" << endl;
        return;
    }

    int prioridadeAntiga = pAtual->prioridade;

    // Se a prioridade é a mesma, não fazer nada
    if (pAtual->prioridade == novaPrioridade)
    {
        cout << "\n[INFO] Processo já possui prioridade " << novaPrioridade << "." << endl;
        return;
    }

    // Remover o processo da lista
    pAtual->ant->prox = pAtual->prox;
    if (pAtual->prox != NULL)
    {
        pAtual->prox->ant = pAtual->ant;
    }
    else
    {
        lista.ultimo = pAtual->ant;
    }

    // Atualizar prioridade
    pAtual->prioridade = novaPrioridade;

    // Encontrar nova posição (ordenado por prioridade decrescente)
    Apontador pAtual2 = lista.primeiro->prox;
    Apontador pAnterior = lista.primeiro;

    while (pAtual2 != NULL && pAtual2->prioridade > novaPrioridade)
    {
        pAnterior = pAtual2;
        pAtual2 = pAtual2->prox;
    }

    // Reinserir na nova posição
    pAtual->prox = pAtual2;
    pAtual->ant = pAnterior;

    if (pAtual2 != NULL)
    {
        pAtual2->ant = pAtual;
    }
    else
    {
        lista.ultimo = pAtual;
    }

    pAnterior->prox = pAtual;

    cout << "\n[OK] Processo (PID: " << pid << ") teve sua prioridade alterada de " << prioridadeAntiga << " para " << novaPrioridade << "." << endl;
}

//------------------------------------------------------------------------
void limparSistema(ListaProcessos &lista)
{
    Apontador pAtual = lista.primeiro;
    Apontador pTemp;

    // Liberar todos os nós (incluindo a sentinela)
    while (pAtual != NULL)
    {
        pTemp = pAtual;
        pAtual = pAtual->prox;
        free(pTemp);
    }

    cout << "\n[SISTEMA] Memória liberada." << endl;
}

#endif