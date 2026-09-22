#include <stdio.h>
#include <string.h>

typedef struct {
  char cod [6];
  char des[25];
  int cant;
  }R;
  typedef struct {
  char cod [6];
  }R2;

  void crealibros(){
    FILE * arch;
    R reg;
    arch = fopen("LIBROS.DAT", "wb");
    strcpy(reg.cod, "A101");
    strcpy(reg.des, "ZORRO");
    reg.cant= 3;
    fwrite(&reg, sizeof(reg),1, arch);

    strcpy(reg.cod, "A104");
    strcpy(reg.des, "BATMAN");
    reg.cant= 2;
    fwrite(&reg, sizeof(reg),1, arch);

    strcpy(reg.cod, "A201");
    strcpy(reg.des, "SPIDERMAN");
    reg.cant= 4;
    fwrite(&reg, sizeof(reg),1, arch);

    strcpy(reg.cod, "ZZZZ"); ///centinela
    strcpy(reg.des, "");
    reg.cant= 0;
    fwrite(&reg, sizeof(reg),1, arch);
    fclose(arch);

    }
    void crea2(){
    FILE * arch;
    R2 reg;
    arch = fopen("BAJAS.DAT", "wb");
    strcpy(reg.cod, "A102");

    fwrite(&reg, sizeof(R2),1, arch);

    strcpy(reg.cod, "A104");
    fwrite(&reg, sizeof(reg),1, arch);

    strcpy(reg.cod, "A203");
    fwrite(&reg, sizeof(reg),1, arch);

    strcpy(reg.cod, "ZZZZ");  ///centinela
    fwrite(&reg, sizeof(reg),1, arch);
    fclose(arch);

    }
