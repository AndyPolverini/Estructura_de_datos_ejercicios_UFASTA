#include <stdio.h>

int suma(int vector[], int tamaño)
{
    int total = 0;
    for (int i = 0; i < tamaño; i++)
        total += vector[i];
    return total;
}

float promedio(int vector[], int tamaño)
{
    int totalSuma = suma(vector, tamaño);
    return (float)totalSuma / tamaño;
}

int maximoInt(int vector[], int tamaño)
{
    int max = vector[0];
    for (int i = 1; i < tamaño; i++)
    
        if (vector[i] > max)
        
            max = vector[i];
        
    
    return max;
}

void maximoVoid(int vector[], int tamaño, int *resultadoMax)
{
    int max = vector[0];
    for (int i = 1; i < tamaño; i++)
        if (vector[i] > max)
            max = vector[i];
    *resultadoMax = max;
}

int minimoInt(int vector[], int tamaño)
{
    int min = vector[0];
    for (int i = 1; i < tamaño; i++)
        if (vector[i] < min)
            min = vector[i];
    return min;
}

void minimoVoid(int vector[], int tamaño, int *resultadoMin)
{
    int i;
    *resultadoMin = vector[0];
    for (i = 1; i < tamaño; i++)
        if (vector[i] < *resultadoMin)
            *resultadoMin = vector[i];
}

int filtrarMayoresK(int vectorA[], int tamañoA, int vectorB[], int K)
{
    int i, tamañoB = 0;
    for (i = 0; i < tamañoA; i++)
        if (vectorA[i] > K)
        {
            vectorB[tamañoB] = vectorA[i];
            tamañoB++;
        }
    return tamañoB;
}

int main()
{
    int N, A[300], B[300], tamañoB, K, opcion;
    int elMaximo, elMinimo;
    FILE *archivo = fopen("DATOS.TXT", "r");

    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return 1;
    }

    fscanf(archivo, "%d", &N);

    for (int i = 0; i < N; i++)
    {
        fscanf(archivo, "%d", &A[i]);
    }

    fclose(archivo);

    do {
        printf("1. Suma \n");
        printf("2. Promedio\n");
        printf("3. Maximo \n");
        printf("4. Minimo \n");
        printf("5. Generar vector B (Mayores a K)\n");
        printf("6. Salir \n");
        scanf("%d", &opcion);
    
        switch (opcion)
        {
            case 1:
                printf("La suma es: %d\n", suma(A, N));
                break;
            
            case 2:
                printf("El promedio es: %.2f\n", promedio(A, N));
                break;

            case 3:
                printf("Maximo (funcion int): %d\n", maximoInt(A, N));
                maximoVoid(A, N, &elMaximo);
                printf("Maximo (funcion void): %d\n", elMaximo);
                break;
            
            case 4:
                printf("Minimo (funcion int): %d\n", minimoInt(A, N));
                minimoVoid(A, N, &elMinimo);
                printf("Minimo (funcion void): %d\n", elMinimo);
                break;

            case 5:
                printf("Ingrese el valor de K: ");
                scanf("%d", &K);
                tamañoB = filtrarMayoresK(A, N, B, K);
                printf("Elementos del vector B: ");
                for (int i = 0; i < tamañoB; i++)
                {
                    printf("%d ", B[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Saliendo del programa... \n");
                break;

            default:
                break;
        }
    } while(opcion != 6);

    return 0;
}
