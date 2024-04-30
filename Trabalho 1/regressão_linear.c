#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    float y;
} Ponto;

float calcular_media_x(Ponto* pontos, int num_pontos);
float calcular_media_y(Ponto* pontos, int num_pontos);
float calcular_coeficiente_angular(Ponto* pontos, int num_pontos, float media_x, float media_y);
float calcular_coeficiente_linear(float media_x, float media_y, float coef_angular);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_csv>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int num_pontos = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num_pontos++;
    }

    Ponto *pontos = (Ponto*)malloc(num_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < num_pontos; i++) {
        fscanf(file, "%d,%f", &pontos[i].x, &pontos[i].y);
    }

    fclose(file);

    float media_x = calcular_media_x(pontos, num_pontos);
    float media_y = calcular_media_y(pontos, num_pontos);

    float coef_angular = calcular_coeficiente_angular(pontos, num_pontos, media_x, media_y);
    float coef_linear = calcular_coeficiente_linear(media_x, media_y, coef_angular);

    printf("Equação da regressão linear: y = %.2fx + %.2f\n", coef_angular, coef_linear);

    free(pontos);

    return 0;
}

float calcular_media_x(Ponto* pontos, int num_pontos) {
    float soma = 0;
    for (int i = 0; i < num_pontos; i++) {
        soma += pontos[i].x;
    }
    return soma / num_pontos;
}

float calcular_media_y(Ponto* pontos, int num_pontos) {
    float soma = 0;
    for (int i = 0; i < num_pontos; i++) {
        soma += pontos[i].y;
    }
}