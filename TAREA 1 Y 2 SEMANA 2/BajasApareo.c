#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
 char cod [6], des[25];
 int cant;
 }RL;
 typedef struct {
 char cod [6];
 }RB;
void apareoBaja(){
 FILE * archL, *archB, *arch3;
 RL regL;
 RB regB;
 archL = fopen("LIBROS.DAT", "rb");
 if (archL != NULL) {
 archB = fopen("BAJAS.DAT", "rb");
 if (archB == NULL)
 fclose(archL);
 else {
 arch3 = fopen("TEMP.DAT", "wb"); //este archivo contendra de modo transitorio los datos

 //lectura adelantada
fread(&regL, sizeof(RL),1, archL);
 fread(&regB, sizeof(RB),1, archB);

 //se analiza que no se alcance el final de los dos archivos
 while (strcmp(regL.cod, "ZZZZ") != 0 || strcmp(regB.cod, "ZZZZ") !=0)
 if (strcmp(regL.cod, regB.cod) < 0){ //es un libro que no se dará de baja
 fwrite(&regL, sizeof(RL),1, arch3); //se guarda en TEMP
 fread(&regL, sizeof(RL),1, archL); //se avanza en DATOS
 }
 else
 if (strcmp(regL.cod, regB.cod) == 0){ //es un libro que se dará de baja
 fread(&regL, sizeof(RL),1, archL); //se avanza en DATOS sin guardar
 fread(&regB, sizeof(RB),1, archB); //se avanza en BAJAS
 }
 else{
 printf("ERROR en dato %s",regB.cod); //es un libro que no existe
 fread(&regB, sizeof(RB),1, archB);
 }
 fclose(archB);
 fclose(archL);
 fclose(arch3);
 rename("TEMP.DAT","LIBROS.DAT"); //renombra archivo nuevo con el nombre original
 }
 }
} 