#include <stdio.h>

typedef struct {
    char palo;
    short int num;
} Tcarta;

void ContarOro()
{
    FILE *arch;
    Tcarta caux;
    int Cantidad_Oro = 0;

    arch = fopen("CARTAS.DAT", "rb");

    if (arch == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }

    while (fread(&caux, sizeof(Tcarta), 1, arch) == 1)
    {
        if (caux.palo == 1)
        {
            Cantidad_Oro++;
        }
    }

    printf("La cantidad de cartas de oro es: %d\n", Cantidad_Oro);

    fclose(arch);
}