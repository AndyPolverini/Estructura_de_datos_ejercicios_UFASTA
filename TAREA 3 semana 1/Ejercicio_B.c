#include <stdio.h>
typedef struct {
    char palo;
    short int num;
} Tcarta;

void contarPalos()
{
    FILE *archivo;
    Tcarta carta;

    int oro = 0;
    int copa = 0;
    int espada = 0;
    int basto = 0;

    archivo = fopen("CARTAS.DAT", "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fread(&carta, sizeof(Tcarta), 1, archivo) == 1)
    {
        switch (carta.palo)
        {
            case 1:
                oro++;
                break;

            case 2:
                copa++;
                break;

            case 3:
                espada++;
                break;

            case 4:
                basto++;
                break;
        }
    }

    printf("Oro: %d\n", oro);
    printf("Copa: %d\n", copa);
    printf("Espada: %d\n", espada);
    printf("Basto: %d\n", basto);

    fclose(archivo);
}