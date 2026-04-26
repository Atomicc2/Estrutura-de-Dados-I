#include <locale.h>
#include "interface.h"
#include "escalonador_logica.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ListaProcessos meuEscalonador;
    inicializar(meuEscalonador);

    int opcao, pid, prioridade;
    char nome[101];

    do
    {
        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            pid = lerPID();
            lerNome(nome, 101);
            prioridade = lerPrioridade();
            criarProcesso(meuEscalonador, pid, nome, prioridade);
            pausar();
            break;
        case 2:
            cout << "\n== Informe o PID do processo que deseja finalizar ==" << endl;
            pid = lerPID();
            matarProcesso(meuEscalonador, pid);
            pausar();
            break;
        case 3:
            cout << "\n>>> EXIBINDO FILA: ORDEM DE EXECUÇÃO <<<" << endl;
            imprimirEstado(meuEscalonador, false);
            pausar();
            break;
        case 4:
            cout << "\n>>> EXIBINDO FILA: ORDEM REVERSA (ALT+TAB) <<<" << endl;
            imprimirEstado(meuEscalonador, true);
            pausar();
            break;
        case 5:
            pid = lerPID();
            prioridade = lerPrioridade();
            promoverProcesso(meuEscalonador, pid, prioridade);
            pausar();
            break;
        case 0:
            limparSistema(meuEscalonador);
            cout << "Desligando K-OS... Até logo!" << endl;
            pausar();
            break;
        default:
            mostrarMensagemErro();
            pausar();
        }
    } while (opcao != 0);

    return 0;
}