#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
#include "PILHA_ARRANJO.h"

//-----------------------------------------------------------------------
Escolhas enterChoice(TPilha& lista) {
    system("cls");
    Imprime(lista);

    int menuChoice;
        cout << "\nMenu:" << endl
        << "1-Empilha\n"
        << "2-Desempilha\n"
        << "3-Imprime\n"
        << "4-Fim do programa\n"
        << "Opção: ";
        cin >> menuChoice;
    return (Escolhas) menuChoice;
}

void setDados(TInfo& item){
    cout << "\nInforme o Código: ";
    cin >> item.Chave;
}
void setPosicao(int& pos){
    cout << "\nInforme a Posição: ";
    cin >> pos;
}

int main() {
    setlocale (LC_ALL,"portuguese");
    TInfo item;
    int p;
    TPilha l;
    Cria(l);
    Imprime(l);
    Escolhas opcao;
    while ((opcao = enterChoice(l)) != FIM) {
        switch (opcao) {
            case EMPILHA:
                setDados(item);
                Empilha(l, item);
                break;
            case DESEMPILHA:
                Desempilha(l);
                break;
            case IMPRIME:
                Imprime(l);
                break;
            default:
                cerr << "Opção incorreta\n";
                break;
            }
        }
    return 0;
}