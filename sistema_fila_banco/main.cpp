#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
using namespace std;
#include "sistema.h"

int senhaGlobal = 1;

//------------------------------------------------------------------------
void exibirMenu() {
    cout << "\n========================================" << endl;
    cout << "  SISTEMA DE ATENDIMENTO - BANCO" << endl;
    cout << "========================================" << endl;
    cout << "[1] - Adicionar cliente a fila" << endl;
    cout << "[2] - Atender cliente" << endl;
    cout << "[3] - Exibir filas de espera" << endl;
    cout << "[4] - Sair" << endl;
    cout << "----------------------------------------" << endl;
}

//------------------------------------------------------------------------
void adicionarCliente(TFila& filaPrioritaria, TFila& filaComum) {
    string nome;
    int idade;
    char opcaoPrioridade;
    
    cout << "\nDigite o nome do cliente: ";
    getline(cin, nome);
    
    cout << "Digite a idade do cliente: ";
    cin >> idade;

    TInfo cliente;
    cliente.Nome = nome;
    cliente.Senha = senhaGlobal++;
    
    bool isPrioritario = false;
    
    if (idade >= 60) {
        isPrioritario = true;
    } else {
        cout << "O cliente e gestante ou possui necessidades especiais? (S/N): ";
        cin >> opcaoPrioridade;
        if (opcaoPrioridade == 'S' || opcaoPrioridade == 's') {
            isPrioritario = true;
        }
    }
    
    if (isPrioritario) {
        if (QisFull(filaPrioritaria)) {
            cout << "\nFila prioritaria cheia! Nao e possivel adicionar mais clientes." << endl;
        } else {
            enQueue(filaPrioritaria, cliente);
            cout << "\nCliente " << nome << " (PRIORITARIO) adicionado a fila com a senha " 
                 << cliente.Senha << "." << endl;
        }
    } else {
        if (QisFull(filaComum)) {
            cout << "\nFila comum cheia! Nao e possivel adicionar mais clientes." << endl;
        } else {
            enQueue(filaComum, cliente);
            cout << "\nCliente " << nome << " (COMUM) adicionado a fila com a senha " 
                 << cliente.Senha << "." << endl;
        }
    }
}

//------------------------------------------------------------------------
void atenderCliente(TFila& filaPrioritaria, TFila& filaComum) {
    static bool atenderPrioritario = true; 
    
    if (QisEmpty(filaPrioritaria) && QisEmpty(filaComum)) {
        cout << "\nNenhum cliente para atender. Ambas as filas estao vazias." << endl;
        return;
    }
    
    if (atenderPrioritario && !QisEmpty(filaPrioritaria)) {
        TInfo cliente = deQueue(filaPrioritaria);
        cout << "\nAtendendo cliente PRIORITARIO: " << cliente.Nome 
             << " com senha " << cliente.Senha << "." << endl;
        atenderPrioritario = false; 
    }
    else if (!QisEmpty(filaComum)) {
        TInfo cliente = deQueue(filaComum);
        cout << "\nAtendendo cliente COMUM: " << cliente.Nome 
             << " com senha " << cliente.Senha << "." << endl;
        atenderPrioritario = true; // Próximo será prioritário
    }
    else if (!QisEmpty(filaPrioritaria)) {
        TInfo cliente = deQueue(filaPrioritaria);
        cout << "\nAtendendo cliente PRIORITARIO: " << cliente.Nome 
             << " com senha " << cliente.Senha << "." << endl;
    }
}

//------------------------------------------------------------------------
void exibirFilas(TFila filaPrioritaria, TFila filaComum) {
    cout << "\n========================================" << endl;
    cout << "  FILAS DE ESPERA" << endl;
    cout << "========================================" << endl;
    
    cout << "\nFILA PRIORITARIA (" << QgetTamanho(filaPrioritaria) << " clientes):" << endl;
    cout << "----------------------------------------" << endl;
    Print(filaPrioritaria);
    
    cout << "\nFILA COMUM (" << QgetTamanho(filaComum) << " clientes):" << endl;
    cout << "----------------------------------------" << endl;
    Print(filaComum);
}

//------------------------------------------------------------------------
int main() {
    setlocale(LC_ALL, "portuguese");
    
    TFila filaPrioritaria, filaComum;
    QInit(filaPrioritaria);
    QInit(filaComum);
    
    int opcao;
    
    while (true) {
        exibirMenu();
        cout << "Opcao: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                adicionarCliente(filaPrioritaria, filaComum);
                break;
            case 2:
                atenderCliente(filaPrioritaria, filaComum);
                break;
            case 3:
                exibirFilas(filaPrioritaria, filaComum);
                break;
            case 4:
                cout << "\nEncerrando o programa..." << endl;
                return 0;
            default:
                cout << "\nOpcao invalida! Tente novamente." << endl;
        }
        
        cout << "\nPressione ENTER para continuar...";
        getchar();
        system("cls");
    }
    
    return 0;
}
