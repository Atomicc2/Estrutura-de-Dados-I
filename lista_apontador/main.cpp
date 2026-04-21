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
    PESQUISAPORID,
    IMPRIME,
    FIM
};
//-----------------------------------------------------------------------
Escolhas enterChoice(TLista &lista)
{
    system("cls");
    int menuChoice;
    cout << "\nMenu:" << endl
         << "1 - Insere no Inicio\n"
         << "2 - Insere na Posicao\n"
         << "3 - Insere no Final\n"
         << "4 - Remove do Inicio\n"
         << "5 - Remove do Final\n"
         << "6 - Pesquisa e Remove\n"
         << "7 - Pesquisa por ID\n"
         << "8 - Imprime\n"
         << "0 - Fim do programa\n"
         << "Opcao: ";
    cin >> menuChoice;
    return (Escolhas)menuChoice;
}
void setDados(TInfo &item)
{
    cout << "\nInforme o ID: ";
    cin >> item.ID;
    cin.ignore();
    cout << "Informe a Cidade: ";
    getline(cin, item.Cidade);
    cout << "Informe a Rodovia: ";
    getline(cin, item.Rodovia);
    cout << "Informe a Data: ";
    getline(cin, item.Data);
    cout << "Informe o Dia da Semana: ";
    getline(cin, item.DiaSemana);
    cout << "Informe a Hora: ";
    getline(cin, item.Hora);
    cout << "Informe o Tipo de Acidente: ";
    getline(cin, item.TipoAcidente);
    cout << "Informe o Numero de Feridos: ";
    cin >> item.Feridos;
    cout << "Informe o Numero de Mortos: ";
    cin >> item.Mortos;
    cin.ignore();
    cout << "Informe a Descricao: ";
    getline(cin, item.Descricao);
}
void setPosicao(int &pos)
{
    cout << "\nInforme a Posicao: ";
    cin >> pos;
}
int main()
{
    setlocale(LC_ALL, "portuguese");
    TInfo item;
    int p;
    TLista l;
    Cria(l);
    CarregaArquivo(l, "acidentes.txt");
    int opcao;
    while (true)
    {
        opcao = enterChoice(l);
        if (opcao == FIM)
            break;
        
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
        case PESQUISAPORID:
            cout << "Informe o ID a pesquisar: ";
            cin >> p;
            ImprimePorID(l, p);
            break;
        case IMPRIME:
            Imprime(l);
            break;
        default:
            cerr << "Opcao incorreta\n";
            break;
        }
        cout << "\nPressione ENTER para continuar...";
        cin.ignore();
        cin.get();
    }
    return 0;
}