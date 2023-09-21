#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimal_para_binario(int numero_decimal);
char *adiciona_zero_a_esquerda();

int main(){
    char * numero_em_binario = decimal_para_binario(230);
    int i, tamanho_string_binario = 0;
    int diferenca;
    /*for (i = 0; i < 11; i++) {
        printf("%d: %s\n", i, decimal_para_binario(i));
        tamanho_string_binario = (int)strlen(decimal_para_binario(i));
    }*/
    printf("Num 230 em binário: %s\n", decimal_para_binario(230));
    tamanho_string_binario = (int)strlen(decimal_para_binario(230));
    if(tamanho_string_binario < 11) {
        diferenca = 11 - tamanho_string_binario;
        numero_em_binario = (char *)realloc(numero_em_binario ,(tamanho_string_binario + 1 + diferenca) * sizeof(char));
    }
    for (i = 0; i < diferenca; i++) {
       strcat(numero_em_binario, "0");
    }

    printf("String reajustada: %s\n", numero_em_binario);
    
        

    return 0;
}


/*decimal_para_binario(int ): transforma um número em base decimal para binário. 
Além disso, retorna esse valor na forma de string. Dessa forma porde-se adicionar os zeros
a esqueda sem perda de valores.
*/ 
char *decimal_para_binario(int numero_decimal) {
    // Calcula o número de bits necessários para representar o número decimal
    int num_bits = 0;
    int temp = numero_decimal;
    while (temp > 0) {
        num_bits++;
        temp /= 2;
    }

    // Lida com o caso especial de 0
    if (numero_decimal == 0) {
        char *binario = (char *)malloc(2 * sizeof(char));
        if (binario) {
            strcpy(binario, "0");
            return binario;
        } else {
            exit(1); // Tratamento de erro na alocação de memória
        }
    }

    // Aloca memória para a string binária (mais um para o caractere nulo)
    char *binario = (char *)malloc((num_bits + 1) * sizeof(char));
    if (!binario) {
        exit(1); // Tratamento de erro na alocação de memória
    }

    // Preenche a string binária começando pelo bit mais significativo
    int indice = num_bits - 1;
    while (numero_decimal > 0) {
        binario[indice] = (numero_decimal % 2) + '0';
        numero_decimal /= 2;
        indice--;
    }
    binario[num_bits] = '\0'; // Adiciona o caractere nulo ao final

    return binario;
}
