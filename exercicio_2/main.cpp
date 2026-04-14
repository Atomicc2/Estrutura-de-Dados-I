#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
#include "LISTA_APONTADOR.h"
enum Escolhas
{
    CRIA,
    INSEREINICIO,
    INSEREPOSICAO,
    INSEREFINAL,
    REMOVEINICIO,
    REMOVEFINAL,
    PESQUISAREMOVE,
    IMPRIME,
    FIM
};
//-----------------------------------------------------------------------
Escolhas enterChoice(TLista &lista)
{
    system("cls");
    Imprime(lista);
    int menuChoice;
    cout << "\nMenu:" << endl
         << "1-Insere no Inicio\n"
         << "2-Insere na Posicao\n"
         << "3-Insere no Final\n"
         << "4-Remove do Inicio\n"
         << "5-Remove do Final\n"
         << "6-Pesquisa e Remove\n"
         << "7-Imprime\n"
         << "8-Fim do programa\n"
         << "Opcao: ";
    cin >> menuChoice;
    return (Escolhas)menuChoice;
}
void setDados(TInfo &item)
{
    cout << "\nInforme o C´odigo: ";
    cin >> item.Chave;
}
void setPosicao(int &pos)
{
    cout << "\nInforme a Posi¸c~ao: ";
    cin >> pos;
}
int main()
{
    setlocale(LC_ALL, "portuguese");
    TInfo item;
    int p;
    TLista l;
    Cria(l);
    Imprime(l);
    Escolhas opcao;
    while ((opcao = enterChoice(l)) != FIM)
    {
        switch (opcao)
        {
        case INSEREINICIO:
            setDados(item);
            InsereInicio(l, item);
            break;
        case INSEREPOSICAO:
            setDados(item);
            setPosicao(p);
            InserePosicao(l, p, item);
            break;
        case INSEREFINAL:
            setDados(item);
            InsereFinal(l, item);
            break;
        case REMOVEINICIO:
            RemoveInicio(l);
            break;
        case REMOVEFINAL:
            RemoveFinal(l);
            break;
        case PESQUISAREMOVE:
            setDados(item);
            PesquisaRemove(l, item);
            break;
        case IMPRIME:
            Imprime(l);
            break;
        default:
            cerr << "Op¸c~ao incorreta\n";
            break;
        }
    }
    return 0;
}