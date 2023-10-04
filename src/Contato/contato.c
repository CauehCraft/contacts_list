#include "contato.h"
#include "../Multiplicacao/multiplicacao.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 100
#define TAM_NOME 100
#define TAM_EMAIL 100
#define TAM_TELEFONE 20
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
    for (int i = 0; i < MAX_CONTATOS; i++) {
        if (lista_contatos[i] != NULL)
            if (strcmp(lista_contatos[i]->nome, nome) == 0)
                return lista_contatos[i];
    }
    
    return NULL; // Contato não encontrado
}

// Função para remover um contato da lista
void apagarContato(Contato** lista_contatos, int hash, char* nome) {
    int indice;
    for(int i = 0; i<MAX_CONTATOS; i++){
        if (lista_contatos[indice] != NULL && strcmp(lista_contatos[indice]->nome, nome) == 0) {
            free(lista_contatos[indice]);
            lista_contatos[indice] = NULL;
            break;
        }
        indice = hash + i*i;
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
            apagarContato(lista_contatos, i, lista_contatos[i]->nome);  
}


// Função importar contatos de um arquivo
void importarContatos(Contato** lista_contatos){
    FILE *arquivo_origem;
    int hash_numero;
    char numero_formatado[TAM_TELEFONE];
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
        return;
    }else{
        rewind(arquivo_origem); // recoloca o cursor no inicio do arquivo
    }

    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) { 
        sscanf(linha, " %[^;];%[^;];%[^;];", nome, email, telefone);
        formatarNumero(telefone, numero_formatado);
        hash_numero = hash(numero_formatado);

        int tentativa = 0;
        int posicao = hash_numero;

        while (lista_contatos[posicao] != NULL && tentativa < MAX_CONTATOS) {
            tentativa++;
            //printf("Colisão no índice %d\n", posicao == 0 ? hash_numero : posicao);
            posicao = (hash_numero + tentativa * tentativa) % MAX_CONTATOS;
            //printf("Tentativa %d, nova posição: %d\n", tentativa, posicao);
        }

        if (lista_contatos[posicao] == NULL) {
            lista_contatos[posicao] = criarContato(nome, email, telefone);
            //printf("Contato adicionado com sucesso!\n\n");
        }
        else {
            printf("Erro ao importar contatos!\n");
        }  
    }

    fclose(arquivo_origem); // fecha o arquivo
}

// Função exportar contatos para arquivo
void exportarContatos(Contato** lista_contatos) {
    FILE *arquivo;
    arquivo = fopen("../dados/contatos.txt", "w"); // Abre o arquivo para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
   
    for (int i = 0; i < MAX_CONTATOS; i++) {
        if (lista_contatos[i] != NULL) {
            fprintf(arquivo, "%s;", lista_contatos[i]->nome); // nome
            fprintf(arquivo, "%s;", lista_contatos[i]->email); // e-mail
            fprintf(arquivo, "%s;\n", lista_contatos[i]->telefone); // telefone
        }
    }
    
    fclose(arquivo); // Fecha o arquivo
    printf("Arquivo atualizado com sucesso!\n");
}