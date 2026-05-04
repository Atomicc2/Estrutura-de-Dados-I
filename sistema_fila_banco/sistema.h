//----FILA IMPLEMENTADA POR MEIO DE APONTADOR----
typedef struct NodoFila *Apontador;
#include <string>

#define TAMANHO_MAX 20

typedef struct  {
    int Senha;
    string Nome;
} TInfo;

struct NodoFila{
    TInfo Item;
    struct NodoFila *Proximo;
};

typedef struct {
    struct NodoFila *Primeiro;
    struct NodoFila *Ultimo;
    int Tamanho;
} TFila;

//---------------------------------------------
void QInit (TFila& Fila) {
    Fila.Primeiro = (Apontador) malloc(sizeof(struct NodoFila));
    Fila.Ultimo = Fila.Primeiro;
    Fila.Primeiro->Proximo = NULL;
    Fila.Tamanho = 0;
}
//---------------------------------------------
bool QisEmpty (TFila Fila) {
    return Fila.Primeiro==Fila.Ultimo?true:false;
}
//---------------------------------------------
bool QisFull (TFila Fila) {
    return Fila.Tamanho >= TAMANHO_MAX;
}
//---------------------------------------------
int QgetTamanho (TFila Fila) {
    return Fila.Tamanho;
}
//---------------------------------------------
void enQueue (TFila& Fila, TInfo Item) {
    if (!QisFull(Fila)) {
        Apontador p = (Apontador) malloc(sizeof(struct NodoFila));
        p->Item = Item;
        p->Proximo = NULL;
        Fila.Ultimo->Proximo = p;
        Fila.Ultimo = p;
        Fila.Tamanho++;
    }
}
//---------------------------------------------
TInfo deQueue (TFila& Fila) {
    TInfo item;
    item.Senha = -1; // Valor inválido para indicar erro
    item.Nome = "";
    
    if (!QisEmpty(Fila)) {
        Apontador p = Fila.Primeiro->Proximo;
        if (p != NULL) {
            item = p->Item;
            Fila.Primeiro->Proximo = p->Proximo;
            if (Fila.Primeiro->Proximo == NULL)
                Fila.Ultimo = Fila.Primeiro;
            Fila.Tamanho--;
            free(p);
        }
    }
    return item;
}
//---------------------------------------------
void Print(TFila Fila) {
    if (QisEmpty(Fila))
        cout << "A fila está vazia." << endl;
    else {
        Apontador aux;
        aux = Fila.Primeiro->Proximo;
        while (aux != NULL) {
            cout << "  [Senha: " << aux->Item.Senha << "] " << aux->Item.Nome << endl;
            aux = aux->Proximo;
        }
    }
}
//---------------------------------------------