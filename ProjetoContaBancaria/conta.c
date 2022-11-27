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
    //Aloca um espaço na mémoria
    pConta[posicao] = (p_conta)malloc(sizeof(struct Conta));
    fflush(stdin);
    printf("\n");
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
            printf("\n");
            printf("\tDigite o nome do cliente: ");
            gets(pConta[i]->cliente);
            //Imprimir em letras maiúsculas
            strupr(pConta[i]->cliente);
            printf("\n");
            printf("\tConta alterada com sucesso!!! \n\n\n");
            system("pause");
            return;
        }
    }
    printf("\n");
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
    printf("\n");
    printf("\tConta não encontrada! \n\n");
    system("pause");
}

void imprimirUmaConta(p_conta pConta)
{
    printf("\t-------------------- \n");
    printf("\tNúmero da conta: %d \n", pConta->numero);
    printf("\tCliente: %s \n", pConta->cliente);
    //Imprimir em letras maiúsculas
    strupr(pConta->cliente);
    printf("\tSaldo: %.2f \n", pConta->saldo);
    printf("\tNível conta: %d \n", pConta->especial);
    printf("\t-------------------- \n");
    system("pause");
}

int encontrarConta()
{
    int contaProc;
    printf("\n");
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
            printf("\n");
            printf("\tDepósito:\n\n");
            float valor;
            printf("\tDigite o valor a ser depositado: ");
            scanf("%f", &valor);
                if (valor <= 0)
                {
                    printf("\n");
                    printf("\tValor Inválido!\n\n");
                    system("pause");
                    return;
                }
            pConta[i]->saldo += valor;
            printf("\n");
            printf("\tDepósito realizado com sucesso!\n\n");
            system("pause");
            return;
        }
    }
    printf("\n");
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
            printf("\n");
            printf("\tSaque:\n\n");
            float valor;
            printf("\tDigite o valor a ser sacado: ");
            scanf("%f", &valor);
                if (valor > pConta[i]->saldo)
                {
                    printf("\n");
                    printf("\tSaldo Insuficiente!\n\n");
                    system("pause");
                    return;
                }
            pConta[i]->saldo -= valor;
            printf("\n");
            printf("\tSaque efetuado com sucesso!\n\n");
            system("pause");
            return;
        }
    }
    printf("\n");
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
    printf("\n\n");
    printf("\t------------------------------------- \n\n");
    printf("\tValor total em todas as contas R$%.2f \n\n", subtotal);
    printf("\t------------------------------------- \n\n");
    system("pause");
}

