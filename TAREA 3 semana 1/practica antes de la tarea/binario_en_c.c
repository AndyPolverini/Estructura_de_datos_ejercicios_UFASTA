#include <stdio.h>
int main()
{
    FILE *archivoBin;

    archivoBin = fopen("archivoBin", "wb");
    if(archivoBin == NULL)
    {
        printf("\n>> error al abrir el archivo >>> saliendo...\n");
        return 1;
    }
    
else 
{
    printf("\n>> el archivo se abrio correctamente en modo escritura binaria (wb) <<<\n");

}

short numero_leido;

for(int i = 0; i < 5 ; i++)
{
    printf("\ningrese un numero: \n");
    scanf("%hi", &numero_leido);
    fwrite( &numero_leido,sizeof(short),1,archivoBin);

}





}
