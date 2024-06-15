#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
    int quantidade;
    int tamanho;
    int *elementos;
};

Lista *criaLista(int tamanhoLista)
{
    if (tamanhoLista > 0)
    {
        Lista *novo = (Lista *)malloc(sizeof(Lista));

        if (novo != NULL)
        {
            novo->quantidade = 0;
            novo->tamanho = tamanhoLista;
            novo->elementos = (int *)malloc(sizeof(int) * tamanhoLista);

            return novo;
        }
        else
        {
            printf("Memória insuficiente para criar lista!");
            exit(1);
        }
    }
    else
    {
        printf("Tamanho inválido para criar lista!");
        exit(1);
    }
}

int listaVazia(Lista *l)
{
    if (l == NULL || l->quantidade == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int consultaPosicao(Lista *l, int posicao)
{
    if (l != NULL)
    {
        if (listaVazia(l) == 0)
        {
            if (posicao >= 0 && posicao <= l->quantidade)
            {
                return l->elementos[posicao];
            }
            else
            {
                printf("Índice inválido para consulta!\n");
                return -1;
            }
        }
        else
        {
            printf("Lista vazia para consulta!\n");
            return -1;
        }
    }
    else
    {
        printf("Lista inválida para consulta!\n");
        return -1;
    }
}

void inserirElementoFinalLista(Lista *l, int e)
{
    if (l != NULL && e >= 0)
    {
        if (l->quantidade < l->tamanho)
        {
            l->elementos[l->quantidade] = e;
            l->quantidade++;
        }
        else
        {
            printf("Quantidade passou o limite da lista!\n");
        }
    }
    else
    {
        printf("Lista inválida para inserir elementos!\n");
    }
}

void inserirElementoInicioLista(Lista *l, int e)
{
    if (l != NULL && e >= 0)
    {
        if (l->quantidade < l->tamanho)
        {
            for (int i = l->quantidade; i > 0; i--)
            {
                l->elementos[i] = l->elementos[i - 1];
            }
            
            l->elementos[0] = e;
            l->quantidade++;
        }
        else
        {
            printf("Quantidade passou o limite da lista!\n");
        }
    }
    else
    {
        printf("Lista inválida para inserir elementos!\n");
    }
}

void removeElementoLista(Lista *l, int e)
{
    if (l != NULL && e >= 0)
    {
        int encontrado = 0;

        for (int i = 0; i < l->quantidade; i++)
        {
            if (consultaPosicao(l, i) == e)
            {
                encontrado = 1;
            }

            if (encontrado == 1 && i < l->quantidade - 1)
            {
                l->elementos[i] = l->elementos[i + 1];
            }
        }

        if (encontrado == 1)
        {
            l->quantidade--;
        }
        else
        {
            printf("Elemento não encontrado para remoção!\n");
        }
    }
    else
    {
        printf("Lista inválida para remover elementos!\n");
    }
}

int quantidadeLista(Lista *l)
{
    if (l != NULL)
    {
        return l->quantidade;
    }
    else
    {
        return -1;
    }
}

void imprimirLista(Lista *l)
{
    if (l != NULL)
    {
        for (int i = 0; i < l->quantidade; i++)
        {
            printf("%d\t", consultaPosicao(l, i));
        }

        printf("\n");
    }
    else
    {
        printf("Lista inválida para imprimir!\n");
    }
}

void liberarLista(Lista *l)
{
    if (l != NULL)
    {
        free(l);
    }
    else
    {
        printf("Lista inválida para liberação!\n");
    }
}