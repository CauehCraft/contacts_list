#include <stdio.h>
#include <stdlib.h>

void decimal_para_binario(int numero_decimal);

int main(){
  int i;
  for (i = 0; i < 11; i++) {
    printf("%d: ", i);
    decimal_para_binario(i);
    printf("\n");
  }
  
  return 0;
}

void decimal_para_binario(int numero_decimal) {
      int aux = 0;
      if (numero_decimal < 1) {
        printf("0");
        return 0;
      }else if (numero_decimal % 2 == 0) {
        aux = 0;
      } else {
        aux = 1;
      }
      decimal_para_binario(numero_decimal / 2);
      printf("%d", aux);
}

