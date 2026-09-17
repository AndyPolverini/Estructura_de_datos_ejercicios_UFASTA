#include <stdio.h>

// EJERCICIO A 
void A(int a, int b, int *s, int *p)
{
    *s = a + b;
    *p = a * b;
}

int main(void)
{
    int suma;
    int producto;
    A(4, 8, &suma, &producto);
    printf("la suma es %d\n", suma);
    printf("el producto es %d\n", producto);

    return 0;
}