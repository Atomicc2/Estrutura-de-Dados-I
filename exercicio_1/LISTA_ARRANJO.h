#define Tmax 5

typedef struct {
    int Chave;
} TInfo;

typedef struct {
    TInfo itens[Tmax];
    int tamanho;
} TLista;

enum Escolhas {CRIA, INSEREINICIO, INSEREPOSICAO, INSEREFINAL, REMOVEINICIO,
REMOVEFINAL, PESQUISAREMOVE, IMPRIME, FIM};

void Cria(TLista& Lista);
void InsereInicio(TLista& Lista, TInfo Item);
void InserePosicao(TLista& Lista, int pos, TInfo Item);
void InsereFinal(TLista& Lista, TInfo Item);
void InsereOrdenado(TLista& Lista, TInfo Item);
void RemoveInicio(TLista& Lista);
void RemoveFinal(TLista& Lista);
void PesquisaRemove(TLista& Lista, int Chave);
void Imprime(TLista Lista);
Escolhas enterChoice(TLista& lista);
void setDados(TInfo& item);
void setPosicao(int& pos);