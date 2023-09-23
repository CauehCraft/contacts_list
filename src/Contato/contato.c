#include "contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 100
#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_TELEFONE 16

// Estrutura do tipo Contato
struct contato {
    char nome[100];
    char email[100];
    char telefone[16];
};

// Definição da estrutura do Contato
struct listacontatos {
    Contato info;
    int key;
    struct listacontatos* next;
} ;

// Inicializa a Lista de Contatos
ListaContatos* iniciaLista(void) {
    return NULL;
}

// Função para criar um novo contato
ListaContatos* criarContato(const char* nome, const char* email, const char* telefone) {
    ListaContatos* novoContato = (ListaContatos*)malloc(sizeof(ListaContatos));
    if (novoContato == NULL) {
        printf("Erro ao alocar memória para o novo contato.\n");
        exit(1);
    }
    strcpy(novoContato->info.nome, nome);
    strcpy(novoContato->info.email, email);
    strcpy(novoContato->info.telefone, telefone);
    novoContato->next = NULL;
    return novoContato;
}

// Função para inserir um novo contato no início da lista
void inserirContato(ListaContatos** lista, const char* nome, const char* email, const char* telefone) {
    ListaContatos* novoContato = criarContato(nome, email, telefone);
    novoContato->next = *lista;
    *lista = novoContato;
}

// Função para buscar um contato na lista pelo nome
ListaContatos* buscarContato(ListaContatos* lista, const char* nome) {
    ListaContatos* atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->info.nome, nome) == 0) {
            return atual;
        }
        atual = atual->next;
    }
    return NULL; // Contato não encontrado
}

// Função para remover um contato da lista pelo nome
void removerContato(ListaContatos** lista, const char* nome) {
    ListaContatos* atual = *lista;
    ListaContatos* anterior = NULL;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL) {
        printf("Contato com o nome '%s' não encontrado na lista.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *lista = atual->next;
    } else {
        anterior->next = atual->next;
    }

    free(atual);
}

// Função para imprimir a lista de contatos
void imprimirListaContatos(ListaContatos* lista) {
    ListaContatos* atual = lista;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->info.nome);
        printf("Email: %s\n", atual->info.email);
        printf("Telefone: %s\n", atual->info.telefone);
        printf("-----------------------\n");
        atual = atual->next;
    }
}

// Função importar contatos de um arquivo
ListaContatos* importarContatos(ListaContatos *c_list){
    FILE *arquivo_origem;
    ListaContatos *new_list = c_list;
    char linha[TAM_LINHA], nome[TAM_NOME], email[TAM_EMAIL], telefone[TAM_TELEFONE];

    // lendo arquivo com as informacoes dos contatos salvos em arquivo
    arquivo_origem = fopen("../dados/contatos.txt", "r");
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fseek(arquivo_origem, 0, SEEK_END); // posiciona o cursor no final do arquivo
    if (ftell(arquivo_origem) == 0) { // verifica a posição atual do cursor
        printf("Arquivo de contatos está vazio.\n");
        return NULL;
    }else{
        rewind(arquivo_origem); // recoloca o cursor no inicio do arquivo
    }

    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) { 
        sscanf(linha, " %[^;];%[^;];%[^;];", nome, email, telefone);
        inserirContato(&new_list, nome, email, telefone);    
    }

    fclose(arquivo_origem); // fecha o arquivo
    return new_list;
}