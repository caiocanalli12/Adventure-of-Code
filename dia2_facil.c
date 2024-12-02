#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAMANHO 8
#define MINIMO 5

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

        int crescente = 1, decrescente = 1;
        int segura = 1;

        for (int i = 1; i < n; i++) {
            int diff = abs(array[i] - array[i - 1]);

            if (diff < 1 || diff > 3) {
                segura = 0;
                break;
            }

            if (array[i] > array[i - 1]) {
                decrescente = 0;
            } else if (array[i] < array[i - 1]) {
                crescente = 0;
            }
        }

        if (segura && (crescente || decrescente)) {
            total++;
        }

        contador++;
    } while (contador < 1000);

    printf("%d\n", total);

    return 0;
}
