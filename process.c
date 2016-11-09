#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  FILE *archivo;
  archivo = fopen("test.txt","r");
	if (archivo == NULL){
		printf("\nError de apertura del archivo. \n\n");
  }else{
	    printf("\nEl contenido del archivo de prueba es \n\n");
      int i=3;
      double pv=0;
      char buffer[15];
      while (feof(archivo) == 0){
        buffer[0] = '\0';
       	fscanf(archivo, "%s", buffer);
        if(buffer[0] != '\0'){
          pv = atof(buffer);
          if(i == 3){
            printf("X = %f \n", pv);
            i--;
          }else if(i == 2){
            printf("Y = %f \n", pv);
            i--;
          }else if(i == 1){
            printf("Z = %f \n", pv);
            i=3;
          }
        }
	    }
   }
  fclose(archivo);
	return 0;
}
