#include <stdio.h>
#include <string.h>

typedef struct {
  char cod[5];
  int matri, nota;
  }R;

  void creaexamenes(){
    FILE * arch;
    R reg;
    arch = fopen("EXAMENES.DAT", "wb");
    do {
        printf("Ingrese materia, matricula y nota ");
        scanf("%s %d %d", reg.cod, &reg.matri, &reg.nota);
        fwrite(&reg, sizeof(reg),1, arch);
    } while (strcmp(reg.cod, "ZZZZ")); ///centinela
    fclose(arch);
    }
void Corte(){
    FILE * arch;
    R reg;
    char codant[5];
    int cont, suma, total=0;

    arch = fopen("EXAMENES.DAT", "rb");
    printf("\t LISTADO \n");
    printf("MATERIA \t CANT EXAMENES \t PROMEDIO \n");  //titulo del listado fuera del ciclo
    fread(&reg, sizeof(reg),1, arch); //lectura adelantada
    while (strcmp (reg.cod, "ZZZZ" ) != 0 ) {
	strcpy(codant,reg.cod);
  	cont=suma=0;
    	while (strcmp (reg.cod, codant) == 0 ) {
	cont++;
	suma += reg.nota;
	    fread(&reg, sizeof(reg),1, arch);
}
      printf("%s \t \t %d \t \t %3.2f\n", codant, cont, (float)suma/cont); /*escribe porq ha cambiado la materia */
      total += cont;
    }
   printf("TOTAL EXAMENES %d \n", total);
   fclose(arch);
  }

    void muestra(){
    FILE * arch;
    R reg;
    arch = fopen("EXAMENES.DAT", "rb");
    fread(&reg, sizeof(reg),1, arch);
    while (strcmp(reg.cod, "ZZZZ") !=0){
        printf("%s %d %d \n", reg.cod, reg.matri, reg.nota);
        fread(&reg, sizeof(reg),1, arch);
    }
    fclose(arch);
    }
void main(){
  //creaexamenes();
  //muestra();
  Corte();
  }
