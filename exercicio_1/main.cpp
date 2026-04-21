#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
#include "LISTA_ARRANJO.h"


//-----------------------------------------------------------------------
Escolhas enterChoice(TLista& lista) {
     system("cls");
/*
    cout << "\n=== LISTA DE ACIDENTES ===" << endl;
    cout << "Total de registros: " << lista.tamanho << endl;
    cout << "IDs: ";
    Imprime(lista);
*/
    int menuChoice;
        cout << "\nMenu:" << endl
        << "1 - Insere no Início\n"
        << "2 - Insere na Posição\n"
        << "3 - Insere no Final\n"
        << "4 - Insere Ordenado\n"
        << "5 - Remove do Início\n"
        << "6 - Remove do Final\n"
        << "7 - Pesquisa e Remove\n"
        << "8 - Pesquisa por ID\n"
        << "9 - Pesquisa por Cidade\n"
        << "10 - Imprime Detalhes (ID)\n"
        << "11 - Imprime Todos\n"
        << "0 - Fim do programa\n"
        << "Opção: ";
        cin >> menuChoice;
    return (Escolhas) menuChoice;
}

void setDados(TInfo& item){
    cout << "\nInforme o Código: ";
    cin >> item.ID;
    cin.ignore();
    cout << "Informe a Rodovia: ";
    getline(cin, item.Rodovia);
    cout << "Informe a Cidade: ";
    getline(cin, item.Cidade);
    cout << "Informe a Data: ";
    getline(cin, item.Data);
    cout << "Informe o Dia da Semana: ";
    getline(cin, item.DiaSemana);
    cout << "Informe a Hora: ";
    getline(cin, item.Hora);
    cout << "Informe o Tipo de Acidente: ";
    getline(cin, item.TipoAcidente);
    cout << "Informe o Número de Feridos: ";
    cin >> item.Feridos;
    cout << "Informe o Número de Mortos: ";
    cin >> item.Mortos;
    cin.ignore();
    cout << "Informe a Descrição: ";
    getline(cin, item.Descricao);
}
void setPosicao(int& pos){
    cout << "\nInforme a Posição: ";
    cin >> pos;
}

int main() {
    setlocale (LC_ALL,"portuguese");
    TInfo item;
    int p;
    string cidade;
    TLista l;
    Cria(l);
    CarregaArquivo(l, "acidentes.txt");
    int opcao;
    while (true) {
        opcao = enterChoice(l);
        if (opcao == 0) break;
        
        switch (opcao) {
            case 1:
                setDados(item);
                InsereInicio(l,item);
                break;
            case 2:
                setDados(item);
                setPosicao(p);
                InserePosicao(l, p, item);
                break;
            case 3:
                setDados(item);
                InsereFinal(l, item);
                break;
            case 4:
                setDados(item);
                InsereOrdenado(l, item);
                break;
            case 5:
                RemoveInicio(l);
                break;
            case 6:
                RemoveFinal(l);
                break;
            case 7:
                cout << "Informe a chave a remover: ";
                cin >> p;
                PesquisaRemove(l, p);
                break;
            case 8:
                cout << "Informe o ID a pesquisar: ";
                cin >> p;
                if (PesquisaPorID(l, p) != -1) {
                    cout << "ID encontrado: " << p << endl;
                } else {
                    cout << "ID não encontrado." << endl;
                }
                break;
            case 9:
                cin.ignore();
                cout << "Informe a Cidade a pesquisar: ";
                getline(cin, cidade);
                cout << "\n=== ACIDENTES EM " << cidade << " ===" << endl;
                ImprimeAcidentesPorCidade(l, cidade);
                break;
            case 10:
                cout << "Informe o ID para imprimir detalhes: ";
                cin >> p;
                ImprimeAcidentes(l, p);
                break;
            case 11:
                cout << "\n=== TODOS OS ACIDENTES ===" << endl;
                for (int i = 0; i < l.tamanho; i++) {
                    ImprimeAcidentes(l, l.itens[i].ID);
                    cout << "---" << endl;
                }
                break;
            default:
                cerr << "Opção incorreta\n";
                break;
            }
        cout << "\nPressione ENTER para continuar...";
        cin.ignore();
        cin.get();
        }
    return 0;
}