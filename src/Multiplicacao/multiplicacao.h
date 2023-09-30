#ifndef MULTIPLICACAO_H
#define MULTIPLICACAO_H

#include <string.h>

// Função que tranforma inteiro em binario. 
unsigned long long int int_to_bin(unsigned long long int k);

// Função Hash que retorna o indice.
int hash(char* num);

// Função para formatar um número.
void formatarNumero(const char *string_telefone, char *numero_formatado);

#endif 