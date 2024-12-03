#include <stdlib.h>
#include <stdio.h>

int main (void) {
    int numero;
    int soma = 0;
    int contador = 0;

    do {
        scanf("%d", &numero);
        soma += numero;
        contador++;
    } while (contador < 734);

    printf("%d", soma);

    return 0;
}