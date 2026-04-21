#define Tmax 1000
#include <string>
using namespace std;

typedef struct {
    int ID;
    string Rodovia;
    string Cidade;
    string Data;
    string DiaSemana;
    string Hora;
    string TipoAcidente;
    int Feridos;
    int Mortos;
    string Descricao;
} TInfo;

typedef struct {
    TInfo itens[Tmax];
    int tamanho;
} TLista;

enum Escolhas {CRIA, INSEREINICIO, INSEREPOSICAO, INSEREFINAL, REMOVEINICIO,
REMOVEFINAL, PESQUISAREMOVE, IMPRIME, FIM};

void CarregaArquivo(TLista& Lista, const string nomeArquivo);
int PesquisaPorID(TLista& Lista, int ID);
void ImprimeAcidentes(TLista& Lista, int ID);
void ImprimeAcidentesPorCidade(TLista& Lista, string Cidade);
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