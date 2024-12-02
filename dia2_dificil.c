#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO 8
#define MINIMO 5

int verificar_segura(int array[], int n);

int verificar_segura_removendo_um(int array[], int n) {
    for (int i = 0; i < n; i++) {

        int temp[TAMANHO];
        int j = 0;
        for (int k = 0; k < n; k++) {
            if (k != i) {
                temp[j++] = array[k];
            }
        }

        if (verificar_segura(temp, n - 1)) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int contador = 0;
    int array[TAMANHO];
    int n;
    int total = 0;

    do {
        n = 0;

        char linha[256];
        fgets(linha, sizeof(linha), stdin);

        char *token = strtok(linha, " ");
        while (token != NULL && n < TAMANHO) {
            array[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        if (n < MINIMO) {
            contador++;
            continue;
        }

        if (verificar_segura(array, n)) {
            total++;
        }

        else if (verificar_segura_removendo_um(array, n)) {
            total++;
        }

        contador++;
    } while (contador < 1000);

    printf("%d\n", total);

    return 0;
}

int verificar_segura(int array[], int n) {
    int crescente = 1, decrescente = 1;

    for (int i = 1; i < n; i++) {
        int diff = abs(array[i] - array[i - 1]);

        if (diff < 1 || diff > 3) {
            return 0;
        }

        if (array[i] > array[i - 1]) {
            decrescente = 0;
        } else if (array[i] < array[i - 1]) {
            crescente = 0;
        }
    }

    return crescente || decrescente;
}