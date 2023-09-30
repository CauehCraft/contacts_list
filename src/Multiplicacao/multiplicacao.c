#include "multiplicacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int int_to_bin(unsigned long long int k){
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k/2)));
}

int hash(char* num){
    int soma = 0;
    char* binchar = (char*) malloc(32*sizeof(char));
    for(int i = 0; i<strlen(num); i++){
        soma+= (num[i]-'0');
    }
    
    long long int q = soma*soma;
    long long int numbin = int_to_bin(q);
    // printf("S e Q: %d %lli\t", soma, q);

    int ii=0;
    sprintf(binchar, "%lli", numbin);
    // printf("Original: %s\t", binchar);
    while(strlen(binchar)>5){
        if(ii%2==0){
            binchar[strlen(binchar)-1] = '\0';
        } else {
            //binchar* = binchar+1;
            sprintf(binchar, "%s", binchar+1);
        }
        ii++;
    }
    int hashr = (binchar[0]-'0')*16 + (binchar[1]-'0')*8 + (binchar[2]-'0')*4 + (binchar[3]-'0')*2 + (binchar[4]-'0');

    return hashr;
}

void formatarNumero(const char *string_telefone, char *numero_formatado) {
    int comprimento = strlen(string_telefone);
    int numero_encontrado = 0;

    if (string_telefone == NULL || numero_formatado == NULL || comprimento <= 0) {
        // Tratamento de erro, se necessário
        return;
    }

    for (int i = 0; i < comprimento; i++) {
        // Verifica se o caractere atual é um número
        if (string_telefone[i] >= '0' && string_telefone[i] <= '9') {
            numero_formatado[numero_encontrado++] = string_telefone[i];
        }
    }
    numero_formatado[numero_encontrado]='\0'; 
}

