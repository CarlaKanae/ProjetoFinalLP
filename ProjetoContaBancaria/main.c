#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include <locale.h>
#define TAM 100

int main()
{
    setlocale(LC_ALL,"Portuguese");
    p_conta vConta[TAM];
    inicializar(vConta, TAM);

    int p = 0; //Posição do Vetor, controlada por p
    int opcao = 0;

    do
    {
        system("cls"); //Limpa a tela
        printf("\n\n");
        printf("\tMenu Principal - Conta Bancária \n");
        printf("\t--------------------------------\n");
        printf("\t1 - Inserir. \n");
        printf("\t2 - Alterar. \n");
        printf("\t3 - Procurar. \n");
        printf("\t4 - Listar. \n");
        printf("\t5 - Depositar. \n");
        printf("\t6 - Sacar. \n");
        printf("\t7 - Imprimir. \n");
        printf("\t8 - Saldo Geral. \n");
        printf("\t0 - Sair. \n");
        printf("\t--------------------------------\n");
        printf("\tDigite uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao)
        {
            case 1:
                system("cls");
                inserirConta(vConta, p);
                p++;
                break;
            case 2:
                system("cls");
                alterarConta(vConta, p);
                break;
            case 3:
                system("cls");
                procurarConta(vConta, p);
                break;
            case 4:
                system("cls");
                listarConta(vConta, p);
                system("pause");
                break;
            case 5:
                system("cls");
                depositar(vConta, p);
                break;
            case 6:
                system("cls");
                sacar(vConta, p);
                break;
            case 7:
                system("cls");
                procurarConta(vConta,p);
                system("pause");
                break;
            case 8:
                system("cls");
                saldoGeral(vConta, p);
                break;
            case 0:
                system("cls");
                 printf("\t Fim do Programa!! \n");
                break;
            default:
                system("cls");
                printf("Opção Inválida! \n");
        }
    }
    while(opcao != 0);

return 0;
}
