#include <stdio.h>

int main()
{
    short numeros[5]; 
    FILE * archivoBin;

    
    archivoBin = fopen("archivoBIN.bin","rb");

    if(archivoBin == NULL)
    {
        printf("\n>> *** Error al abrir el archivo >> Saliendo... ***\n");
        return 1; 
    }
    else
    {
        printf("\n>> *** El archivo se abrio correctamente en modo escritura binaria (wb)*** \n");
    }

     int i = 0;
    
     fread(numeros,sizeof(short),5,archivoBin);

    while(i < 5)
    {
        printf("\n%hi",numeros[i]);
        i++;
    }

    printf("\n>> Cerrando el archivo...\n");
    fclose(archivoBin);

    printf("\n>> *** Fin del programa ***\n");
    return 0;
}