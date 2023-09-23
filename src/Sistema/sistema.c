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
    printf("--------- MENU ---------\n");
    printf("1. Criar Contato\n");
    printf("2. Excluir Contato\n");
    printf("3. Listar Contatos\n");
    printf("4. Buscar Contato\n");
    printf("5. Sair\n");
}