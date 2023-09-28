#ifndef SISTEMA_H
#define SISTEMA_H

// Módulo: funções para tratativas e falhas
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Lê e descarta caracteres encontrados na entrada
void limpa_buffer(void);

// Lê e valida a opção digitada pelo usuário
char le_opcao(char menorValor, char maiorValor);

// Exibe o menu
void menu(void);

// formatação do numero
void formata_numero_telefone(char numero[]);

#endif // SISTEMA_H