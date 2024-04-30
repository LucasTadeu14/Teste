#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No* proximo;
} No;

No* lista_criar();
void lista_inserir_inicio(No** L, char valor);
void lista_imprimir(No* L);
int lista_verificar_existencia(No* L, char valor_busca);
int lista_verificar_ocorrencias(No* L, char valor_busca);
void lista_imprimir_inversa(No* L);
void lista_inserir_no_i(No* L, int i);
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No** L, char valor_busca);
void lista_destruir(No** L);

#endif
