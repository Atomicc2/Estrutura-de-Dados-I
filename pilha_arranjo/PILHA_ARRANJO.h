#define Tmax 10

typedef struct {
    int Chave;
} TInfo;

typedef struct {
    TInfo itens[Tmax];
    int topo;
} TPilha;

enum Escolhas {CRIA, EMPILHA, DESEMPILHA, IMPRIME, FIM};

void Cria(TPilha& Lista);
void Empilha(TPilha& Lista, TInfo Item);
void Desempilha(TPilha& Lista);
void Imprime(TPilha Lista);
Escolhas enterChoice(TPilha& lista);
void setDados(TInfo& item);
void setPosicao(int& pos);