//----FILA IMPLEMENTADA POR MEIO DE ARRANJO----
typedef struct NodoFila *Apontador;

typedef struct  {
    int Chave;
    /*outros componentes*/
} TInfo;

struct NodoFila{
    TInfo Item;
    struct NodoFila *Proximo;
};

typedef struct {
    struct NodoFila *Primeiro;
    struct NodoFila *Ultimo;
} TFila;

//---------------------------------------------
void QInit (TFila& Fila) {
    Fila.Primeiro = (Apontador) malloc(sizeof(struct NodoFila));
    Fila.Ultimo = Fila.Primeiro;
    Fila.Primeiro->Proximo = NULL;
}
//---------------------------------------------
bool QisEmpty (TFila Fila) {
    return Fila.Primeiro==Fila.Ultimo?true:false;
}
//---------------------------------------------
void enQueue (TFila& Fila, TInfo Item) {
    Apontador p = (Apontador) malloc(sizeof(struct NodoFila));
    p->Item = Item;
    p->Proximo = NULL;
    Fila.Ultimo->Proximo = p;
    Fila.Ultimo = p;
}
//---------------------------------------------
 void deQueue (TFila& Fila) {
  if (QisEmpty(Fila))
	   cout << "Erro : A Fila está vazia.\n" << endl;
  else {
    Apontador p = Fila.Primeiro->Proximo;
    Fila.Primeiro->Proximo = p->Proximo;
    if (Fila.Primeiro->Proximo == NULL)
       Fila.Ultimo = Fila.Primeiro;
       free(p);
	}
}
//---------------------------------------------
 void Print(TFila Fila) {
    cout << "Itens na Fila: " << endl;
    if (QisEmpty(Fila))
        cout << "Fila está vazia." << endl;
    else {
        Apontador aux;
        aux = Fila.Primeiro->Proximo;
        while (aux != NULL)
        {
            cout << aux->Item.Chave << " ";
            aux = aux->Proximo;
        }
        cout << endl;
    }
}
//---------------------------------------------
