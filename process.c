#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
El promedio de X = 42835.484121
El promedio de Y = 39737.736855
El promedio de Z = 0.000067

Desviacion estandar de X = 243.098209
Desviacion estandar de Y = 243.074250
Desviacion estandar de Z = 0.011045

*/

int main(int argc, char const *argv[]) {
  double const prom_x = 42835.484121, prom_y = 39737.736855, prom_z = 0.000067;
  int i=3, total=0;
  double pv=0, promx=0, promy=0, promz=0;
  char buffer[15];
  FILE *archivo;
  archivo = fopen("real.txt","r");
	if (archivo == NULL){
		printf("\nError de apertura del archivo. \n\n");
  }else{
	    printf("\nEl contenido del archivo de prueba es \n\n");
      while (feof(archivo) == 0){
        buffer[0] = '\0';
       	fscanf(archivo, "%s", buffer);
        if(buffer[0] != '\0'){
          pv = atof(buffer);
          total += 1;
          if(i == 3){
            //printf("X = %f \n", pv);
            i--;
            promx += pow(pv-prom_x, 2);
          }else if(i == 2){
            //printf("Y = %f \n", pv);
            i--;
            promy += pow(pv-prom_y, 2);
          }else if(i == 1){
            //printf("Z = %f \n", pv);
            i=3;
            promz += pow(pv-prom_z, 2);
          }
        }
	    }
      total /= 3;
      printf("El valor de Z = %f\n", promz);
      printf("Desviacion estandar de X = %f\n", sqrt(promx/(total-1)));
      printf("Desviacion estandar de Y = %f\n", sqrt(promy/(total-1)));
      printf("Desviacion estandar de Z = %f\n", sqrt(promz/(total-1)));
      printf("Total = %i\n", total);
   }
  fclose(archivo);
	return 0;
}
