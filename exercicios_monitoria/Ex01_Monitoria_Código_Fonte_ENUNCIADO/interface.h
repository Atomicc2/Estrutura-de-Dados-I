#ifndef INTERFACE_H
#define INTERFACE_H

#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

void exibirMenu()
{
    cout << "\n==========================================" << endl;
    cout << "          GERENCIADOR DE KERNEL K-OS      " << endl;
    cout << "==========================================" << endl;
    cout << "1. Criar Novo Processo (Inserção Ordenada)" << endl;
    cout << "2. Finalizar Processo (Matar por PID)" << endl;
    cout << "3. Listar Processos (Prioridade: Alta -> Baixa)" << endl;
    cout << "4. Listar Processos (Prioridade: Baixa -> Alta)" << endl;
    cout << "5. Reescalonar Processo (Mudar Prioridade)" << endl;
    cout << "0. Encerrar Sistema" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Escolha uma operação: ";
}

int lerPID()
{
    int pid;
    while (true)
    {
        cout << "Digite o PID (apenas números inteiros): ";
        if (cin >> pid && pid >= 0)
        {
            return pid; // Entrada válida
        }
        else
        {
            cout << "[ERRO] Entrada inválida! Por favor, digite um número inteiro positivo." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void lerNome(char nome[], int tamanhoMaximo) {
    while (true) {
        cout << "Nome do Processo: ";
        cin >> ws;
        cin.getline(nome, tamanhoMaximo);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[ERRO] Nome muito grande! Limite de " << (tamanhoMaximo - 1) << " caracteres." << endl;
            continue;
        }

        bool possuiCaractereNaoEspaco = false;
        for (int i = 0; nome[i] != '\0'; i++) {
            if (!isspace(static_cast<unsigned char>(nome[i]))) {
                possuiCaractereNaoEspaco = true;
                break;
            }
        }

        if (nome[0] != '\0' && possuiCaractereNaoEspaco) {
            return;
        } else {
            cout << "[ERRO] O nome não pode ser vazio ou conter apenas espaços!" << endl;
        }
    }
}

int lerPrioridade() {
    int prio;
    while (true) {
        cout << "Prioridade (0 a 10): ";
        if (cin >> prio && prio >= 0 && prio <= 10) {
            return prio;
        } else {
            cout << "[ERRO] Prioridade inválida! Digite um número entre 0 e 10." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

void mostrarMensagemErro()
{
    cout << "\n[!] Opção inválida. Tente novamente." << endl;
}

void pausar()
{
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

#endif