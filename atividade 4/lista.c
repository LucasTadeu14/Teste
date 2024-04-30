#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    if (cabeca == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        exit(EXIT_FAILURE);
    }
    cabeca->proximo = NULL;
    return cabeca;
}

void lista_inserir_inicio(No** L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = valor;
    novo_no->proximo = *L;
    *L = novo_no;
}

void lista_imprimir(No* L) {
    No* atual = L->proximo;
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo);
    printf("%c ", L->proximo->valor);
}

void lista_inserir_no_i(No* L, int i) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = 'X'; 
    No* atual = L;
    for (int j = 0; j < i && atual->proximo != NULL; j++) {
        atual = atual->proximo;
    }
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i && atual->proximo != NULL; j++) {
        atual = atual->proximo;
    }
    if (atual->proximo == NULL) {
        return; 
    }
    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
}

void lista_remover_no(No** L, char valor_busca) {
    No* atual = *L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
        } else {
            atual = atual->proximo;
        }
    }
}

void lista_destruir(No** L) {
    No* atual = (*L)->proximo;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(*L);
    *L = NULL;
}
