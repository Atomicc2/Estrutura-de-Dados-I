#include <string>

using namespace std;

typedef struct NodoLista *Apontador;
typedef struct
{
    int ID;
    string Cidade;
    string Rodovia;
    string Data;
    string DiaSemana;
    string Hora;
    string TipoAcidente;
    int Feridos;
    int Mortos;
    string Descricao;
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
void CarregaArquivo(TLista &Lista, const string nomeArquivo);
void ImprimeAcidente(TLista &Lista, int ID);
void ImprimePorID(TLista &Lista, int ID);
