#ifndef SISTEMA_H
#define SISTEMA_H

// Módulo: funções para tratativas e falhas
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// definindo Contato para evitar erros de tipo desconhecido
typedef struct contato Contato;

// Lê e descarta caracteres encontrados na entrada
void limpa_buffer(void);

// Lê e valida a opção digitada pelo usuário
char le_opcao(char menorValor, char maiorValor);

// Exibe o menu
void menu(void);

// Função para solicitar detalhes do contato ao usuário e inseri-lo na lista
void solicitarEInserirContato(Contato **lista);

#endif // SISTEMA_H