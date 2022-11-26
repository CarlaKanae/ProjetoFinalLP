#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include <string.h>

struct Conta
{
    int numero;
    char cliente[51];
    int especial;
    float saldo;
};

void inicializar(p_conta pConta[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        pConta[i] = NULL;
    }
}

void inserirConta(p_conta pConta[], int posicao)
{
    pConta[posicao] = (p_conta)malloc(sizeof(struct Conta));
    fflush(stdin);
    printf("\tEntre com os dados da Conta: \n\n");
    printf("\tDigite o número da conta: ");
    scanf("%d",&pConta[posicao]->numero);
    fflush(stdin);
    printf("\tDigite o nome do cliente: ");
    gets(pConta[posicao]->cliente);
    //Imprimir em letras maiúsculas
    strupr(pConta[posicao]->cliente);
    fflush(stdin);
    printf("\tDigite (1) para conta especial ou (0) para conta normal: ");
    scanf("%d", &pConta[posicao]->especial);
    //Saldo zerado por ser cadastro da conta
    pConta[posicao]->saldo = 0;
    printf("\n\n");
    printf("\tConta cadastrada com sucesso!!! \n\n\n");
    system("pause");
}

void listarConta(p_conta pConta[], int tamanho)
{
    //Passa pelo vetor mostrando cada ponteiro e seu membro
    for(int i = 0; i < tamanho; i++)
    {
        imprimirUmaConta(pConta[i]);
    }
}

void alterarConta(p_conta pConta[], int tamanho)
{
    int contaProc = encontrarConta();

    for(int i =0; i<tamanho; i++)
    {
        if(contaProc == pConta[i]->numero)
        {
            imprimirUmaConta(pConta[i]);
            fflush(stdin);
            printf("\tDigite o nome do cliente: ");
            gets(pConta[i]->cliente);
            //Imprimir em letras maiúsculas
            strupr(pConta[i]->cliente);
            printf("\tConta alterada com sucesso!!! \n\n\n");
            system("pause");
            return;
        }
    }
    printf("\tConta não encontrada!\n\n");
    system("pause");
}

void procurarConta(p_conta pConta[], int tamanho)
{
    int contaProc = encontrarConta();

    for(int i =0; i<tamanho; i++)
    {
        if(contaProc == pConta[i]->numero)
        {
            imprimirUmaConta(pConta[i]);
            system("pause");
            return;
        }
    }
    printf("\tConta não encontrada! \n\n");
    system("pause");
}

void imprimirUmaConta(p_conta pConta)
{
    printf("\tNúmero da conta: %d \n", pConta->numero);
    printf("\tCliente: %s \n", pConta->cliente);
    //Imprimir em letras maiúsculas
    strupr(pConta -> cliente);
    printf("\tSaldo: %.2f \n", pConta->saldo);
    printf("\tNível conta: %d \n", pConta->especial);
    printf("\t-------------------- \n");
}

int encontrarConta()
{
    int contaProc;
    printf("\tDigite o número da conta que você procura: ");
    scanf("%d", &contaProc);
    return contaProc;
}

void depositar(p_conta pConta[], int tamanho)
{
    int contaProc = encontrarConta();
    for(int i =0; i<tamanho; i++)
    {
        if (contaProc == pConta[i]->numero)
        {
            imprimirUmaConta(pConta[i]);
            printf("\tDepósito:\n");
            float valor;
            printf("\tDigite o valor a ser depositado: ");
            scanf("%f", &valor);
                if (valor <= 0)
                {
                    printf("\tValor Inválido!\n\n");
                    system("pause");
                    return;
                }
            pConta[i]->saldo += valor;
            printf("\tDepósito realizado com sucesso!\n\n");
            system("pause");
            return;
        }
    }
    printf("\tConta Inexistente!\n\n");
    system("pause");
}

void sacar(p_conta pConta[], int tamanho)
{
    int contaProc = encontrarConta();
    for(int i =0; i<tamanho; i++)
    {
        if (contaProc == pConta[i]->numero)
        {
            imprimirUmaConta(pConta[i]);
            printf("\tSaque:\n");
            float valor;
            printf("\tDigite o valor a ser sacado: ");
            scanf("%f", &valor);
                if (valor > pConta[i]->saldo)
                {
                    printf("Saldo Insuficiente!\n\n");
                    system("pause");
                    return;
                }
            pConta[i]->saldo -= valor;
            printf("\tSaque efetuado com sucesso!\n\n");
            system("pause");
            return;
        }
    }
    printf("\tConta não encontrada!\n\n");
    system("pause");
}

void saldoGeral(p_conta pConta[], int tamanho)
{
    float subtotal = (float)0;
    for(int i = 0; i<tamanho; i++)
    {
        float total = pConta[i]->saldo;
        subtotal += total;
    }
    printf("\n");
    printf("\tValor total em todas as contas R$%.2f \n\n", subtotal);
    system("pause");
}

