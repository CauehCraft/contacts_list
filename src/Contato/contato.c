#include "contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 100
#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_TELEFONE 16
#define MAX_CONTATOS 32

// Estrutura do tipo Contato
struct contato {
    char nome[100];
    char email[100];
    char telefone[16];
};

// Função para criar um novo contato
Contato* criarContato(const char* nome, const char* email, const char* telefone) {
    Contato *novo_contato = (Contato*)malloc(sizeof(Contato));
    strcpy(novo_contato->nome, nome);
    strcpy(novo_contato->email, email);
    strcpy(novo_contato->telefone, telefone);

    return novo_contato;
}

// Função para buscar um contato na lista pelo nome
Contato* buscarContato(Contato** lista_contatos, const char* nome) {
    int i;
    
    for (int i = 0; i < MAX_CONTATOS; i++) {
        if (lista_contatos[i] != NULL)
            if (strcmp(lista_contatos[i]->nome, nome) == 0)
                return lista_contatos[i];
    }
    
    return NULL; // Contato não encontrado
}

// Função para remover um contato da lista
void apagarContato(Contato** lista_contatos, int indice) {
    if (lista_contatos[indice] != NULL) {
        free(lista_contatos[indice]);
        lista_contatos[indice] = NULL;
    }
}

// Função para imprimir um contato específico
void imprimirContato(Contato* contato) {
    printf("\n-----------------------\n");
    printf("Nome: %s\n", contato->nome);
    printf("Email: %s\n", contato->email);
    printf("Telefone: %s\n", contato->telefone);
    printf("-----------------------\n");
}

// Função para imprimir a lista de contatos
void imprimirListaContatos(Contato** lista_contatos) {
    if (lista_contatos == NULL) {
        printf("A lista de contatos é nula.\n");
        return;
    }

    for (int i = 0; i < MAX_CONTATOS; i++) {
        if (lista_contatos[i] != NULL) {
            imprimirContato(lista_contatos[i]);
        }
    }
}

// Liberar a memória alocada para a lista de contatos
void liberarMemoriaListaContatos(Contato** lista_contatos) {
    for (int i = 0; i < MAX_CONTATOS; i++)
        if (lista_contatos[i] != NULL)
            apagarContato(lista_contatos, i);  
}