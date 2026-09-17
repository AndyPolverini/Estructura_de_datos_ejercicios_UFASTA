// EJERCICIO B
#include <stdio.h>

long Factorial(int n) {
    long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main () {
    printf("ingrese un numero: ");
    int numero;
    scanf("%d", &numero);
    printf("el factorial de %d es %ld\n", numero, Factorial(numero));
    return 0;



}