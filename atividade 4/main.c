#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = lista_criar();

    lista_inserir_inicio(&lista, 'A');
    lista_inserir_inicio(&lista, 'B');
    lista_inserir_inicio(&lista, 'C');
    lista_inserir_inicio(&lista, 'D');

    printf("Lista: ");
    lista_imprimir(lista);

    char valor_busca = 'C';
    printf("Verificar existência de '%c': %d\n", valor_busca, lista_verificar_existencia(lista, valor_busca));

    valor_busca = 'A';
    printf("Número de ocorrências de '%c': %d\n", valor_busca, lista_verificar_ocorrencias(lista, valor_busca));

    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    int posicao_insercao = 2;
    lista_inserir_no_i(lista, posicao_insercao);

    printf("Lista após inserção na posição %d: ", posicao_insercao);
    lista_imprimir(lista);

    int posicao_remocao = 2;
    lista_remover_no_i(lista, posicao_remocao);

    printf("Lista após remoção na posição %d: ", posicao_remocao);
    lista_imprimir(lista);

    valor_busca = 'B';
    lista_remover_no(&lista, valor_busca);
    printf("Lista após remoção de todos os '%c': ", valor_busca);
    lista_imprimir(lista);

    lista_destruir(&lista);

    return 0;
}
