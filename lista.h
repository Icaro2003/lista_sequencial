#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista *criaLista(int tamanhoLista);
int listaVazia(Lista *l);
int consultaPosicao(Lista *l, int posicao);
void inserirElementoFinalLista(Lista *l, int e);
void inserirElementoInicioLista(Lista *l, int e);
void removeElementoLista(Lista *l, int e);
int quantidadeLista(Lista *l);
void imprimirLista(Lista *l);
void liberarLista(Lista *l);

#endif