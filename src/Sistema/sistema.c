#include "sistema.h"

void limpa_buffer(void) {
    int valorLido;
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

char le_opcao(char menorValor, char maiorValor) {
    char op;
    char entrada[100];
    char text[50];
    while (1) {
        printf("Digite sua opcao: ");
        scanf(" %[^\n]", entrada);
        op = entrada[0];
        if (op >= menorValor && op <= maiorValor && strlen(entrada) == 1) {
            limpa_buffer();
            break;
        }
        else {
            sprintf(text, "Opcao invalida. A opcao deve estar entre %c e %c.\n", menorValor, maiorValor);
            limpa_buffer();
        }
    }
    return op;
}

void menu(void) {
    printf("\n--------- MENU ---------\n");
    printf("1. Criar Contato\n");
    printf("2. Excluir Contato\n");
    printf("3. Listar Contatos\n");
    printf("4. Buscar Contato\n");
    printf("5. Sair\n");
}

// Função para solicitar detalhes do contato ao usuário e inseri-lo na lista
void solicitarEInserirContato(Contato **lista) {
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
    int hash_novo_contato;
    char numero_formatado[TAM_TELEFONE];

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nome);

    printf("Digite o email: ");
    scanf(" %[^\n]", email);

    printf("Digite o telefone: ");
    scanf(" %[^\n]", telefone);
    
    formatarNumero(telefone, numero_formatado);
    hash_novo_contato = hash(numero_formatado);
    
    printf("Hash gerado: %d\n", hash_novo_contato);
    int tentativa = 0;
    int posicao = hash_novo_contato;
    
    while (lista[posicao] != NULL && tentativa < MAX_CONTATOS) {
        tentativa++;
        printf("Colisão no índice %d\n", posicao == 0 ? hash_novo_contato : posicao);
        posicao = (hash_novo_contato + tentativa * tentativa) % MAX_CONTATOS;
        printf("Tentativa %d, nova posição: %d\n", tentativa, posicao);
    }
    
    if (lista[posicao] == NULL) {
        lista[posicao] = criarContato(nome, email, telefone);
        printf("Contato adicionado com sucesso!\n\n");
    }
    else {
        printf("Número já existente!\n");
    }
}