#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista *novaLista = criaLista(7);

    inserirElementoFinalLista(novaLista, 1);
    inserirElementoFinalLista(novaLista, 5);
    inserirElementoFinalLista(novaLista, 24);
    inserirElementoFinalLista(novaLista, 0);
    inserirElementoFinalLista(novaLista, 6);
    inserirElementoFinalLista(novaLista, 9);

    inserirElementoInicioLista(novaLista, 2);

    removeElementoLista(novaLista, 24);
    inserirElementoFinalLista(novaLista, 15);
    
    imprimirLista(novaLista);
    printf("\nQuantidade de elementos: %d\n", quantidadeLista(novaLista));

    liberarLista(novaLista);

    return 0;
}