#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

No* criar_lista_circular() {
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca == NULL) {
        printf("Erro ao alocar memória para a lista circular.\n");
        exit(EXIT_FAILURE);
    }
    cabeca->proximo = cabeca; // Aponta para ele mesmo para indicar uma lista vazia
    return cabeca;
}

void inserir_no(No* H, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = valor;
    novo_no->proximo = H->proximo;
    H->proximo = novo_no;
}

void imprimir_lista(No* H) {
    if (H->proximo == H) {
        printf("Lista circular vazia.\n");
        return;
    }
    No* atual = H->proximo;
    do {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    } while (atual != H->proximo);
    printf("\n");
}

void remover_no(No* H, char valor) {
    No* atual = H;
    while (atual->proximo != H) {
        if (atual->proximo->valor == valor) {
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
            return;
        }
        atual = atual->proximo;
    }
    printf("Valor '%c' não encontrado na lista circular.\n", valor);
}

void liberar_lista(No* H) {
    No* atual = H->proximo;
    while (atual != H) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(H);
}
