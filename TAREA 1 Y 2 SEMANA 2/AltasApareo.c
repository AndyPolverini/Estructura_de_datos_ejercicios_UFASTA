#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cod[6], des[25];
    int cant;
} RL;

void apareoAlta() {
    FILE *archL, *archA, *arch3;
    RL regL, regA;
    
    archL = fopen("LIBROS.DAT", "rb");
    if (archL != NULL) {
        archA = fopen("ALTAS.DAT", "rb");
        if (archA == NULL) {
            fclose(archL);
            printf("Error al abrir ALTAS.DAT\n"); 
        } else {
            arch3 = fopen("TEMP.DAT", "wb"); 

          
            fread(&regL, sizeof(RL), 1, archL);
            fread(&regA, sizeof(RL), 1, archA);
            
            while (strcmp(regL.cod, "ZZZZ") != 0 || strcmp(regA.cod, "ZZZZ") != 0) {
                if (strcmp(regL.cod, regA.cod) < 0) { 
                    fwrite(&regL, sizeof(RL), 1, arch3); 
                    fread(&regL, sizeof(RL), 1, archL); 
                }
                else if (strcmp(regL.cod, regA.cod) == 0) { 
                    printf("ERROR: El codigo %s ya existe.\n", regA.cod);
                    fread(&regA, sizeof(RL), 1, archA);
                }
                else {
                    fwrite(&regA, sizeof(RL), 1, arch3);
                    fread(&regA, sizeof(RL), 1, archA);
                }
            }
            
            fclose(archA);
            fclose(archL);
            fclose(arch3);
            rename("TEMP.DAT", "LIBROS.DAT"); 
            printf("Proceso de Altas completado con exito.\n");
        }
    } else {
        printf("Error al abrir LIBROS.DAT\n");
    }
}