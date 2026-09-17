#include <ctype.h>
#include <stdio.h>

void Mayuscula (char frase[])
{
for (int i = 0; frase[i] != '\0'; i++)
    {
        if (i == 0 || frase[i - 1] == ' ')
        {
            frase[i] = toupper(frase[i]);
        }
        
    }    
}


int main() 
{
    char frase[];

    printf("Escribir una palabra o frase ");
    fgets(frase, sizeof(frase), stdin);

    Mayuscula(frase);

    printf("%s\n", frase);


    return 0;

}
