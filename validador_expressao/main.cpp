#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include "PILHA_APONTADOR.h"
enum Escolhas {FIM, ENTRADA};

//------------------------------------------------------------------------

bool VerificaExpressao(string expressao, TPilha& pilha);

Escolhas enterChoice(TPilha& pilha)
{
    system("cls");
    Imprime(pilha);
    int menuChoice;
    cout << "\nMenu [PILHA - APONTADOR]" << endl
         << "1 - Entrar com uma expressão matemática para verificação\n"
         << "Qualquer outra tecla para sair do programa\n"
         << "Opção: ";
    cin >> menuChoice;
    return (Escolhas) menuChoice;
}


int main()
{
    setlocale (LC_ALL,"portuguese");
    TInfo item;
    TPilha p;
    Cria(p);
    Imprime(p);
    string expressao;

    Escolhas opcao;
    while ((opcao = enterChoice(p)) == ENTRADA)
    {
        switch (opcao)
        {
        case ENTRADA:
            cout << "\nInforme a expressão matemática: ";
            cin >> expressao;
            if(VerificaExpressao(expressao, p))
                cout << "Expressão válida!" << endl;
            else
                cout << "Expressão inválida!" << endl;
            system("pause");
            break;
        }
    }
    return 0;
}

bool VerificaExpressao(string expressao, TPilha& pilha){
    for(char& c :expressao) {
        if(c == '(') {
            TInfo item;
            item.Tipo = PARENTESE;
            Empilha(pilha, item);
        } else if(c == '{') {
            TInfo item;
            item.Tipo = CHAVE;
            Empilha(pilha, item);
        } else if(c == '[') {
            TInfo item;
            item.Tipo = COLCHETE;
            Empilha(pilha, item);
        } else if(c == ')') {
            if(Vazia(pilha) || Topo(pilha).Tipo != PARENTESE)
                return false;
            Desempilha(pilha);
        } else if(c == '}') {
            if(Vazia(pilha) || Topo(pilha).Tipo != CHAVE)
                return false;
            Desempilha(pilha);
        } else if(c == ']') {
            if(Vazia(pilha) || Topo(pilha).Tipo != COLCHETE)
                return false;
            Desempilha(pilha);
        }
    }
    return Vazia(pilha);
}
