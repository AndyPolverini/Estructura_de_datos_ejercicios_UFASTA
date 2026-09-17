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

void EstaCarta(Tcarta, int *);

int main()
{
    int esta;
    Tcarta c;

    printf("Ingrese una carta, palo y numero: ");
    scanf("%c %hd", &(c.palo), &(c.num));

    EstaCarta(c, &esta);

    if (esta)
        printf("La carta ingresada esta en el archivo\n");
    else
        printf("La carta ingresada no esta en el archivo\n");

    ContarOro();
    contarPalos();

    return 0;
}

void EstaCarta(Tcarta c, int *esta)
{
    FILE *arch;
    Tcarta caux;

    *esta = 0;

    arch = fopen("CARTAS.DAT", "rb");

    if (arch != NULL)
    {
        fread(&caux, sizeof(Tcarta), 1, arch);

        while (!feof(arch) && !(*esta))
        {
            if (caux.palo == c.palo && caux.num == c.num)
                *esta = 1;
            else
                fread(&caux, sizeof(Tcarta), 1, arch);
        }

        fclose(arch);
    }
}