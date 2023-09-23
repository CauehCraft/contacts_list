#include "Contato/contato.c"
#include "Sistema/sistema.c"

int decimal_para_binario(int numero_em_decimal);
int contarDigitos(int numero);

int main() {
    ListaContatos* lista = iniciaLista(); // Inicializa a lista de contatos vazia
    char opcao;

    do {
        menu(); // chama o menu
        opcao = le_opcao('1', '5'); // funcao que lê a opcao do usuário de acordo com o menu

        switch (opcao) {
        case '1': // cadastra contato
            printf("OP1\n"); /* code */ 
            break;
        case '2': // exclui contato
            printf("OP2\n"); /* code */
            break;
        case '3': // lista contatos
            printf("OP3\n"); /* code */
            break;
        case '4': // busca contatos
            printf("OP4\n"); /* code */
            break;
        case '5': // SAIR do programa
            printf("OP5\n"); /* code */
            // freeListaContatos();
            printf("\nObrigado por escolher nossos serviços!\n");
            printf("Encerrando o programa...\n");
            break;
        
        default:
            printf("Opcao invalida!\n");
            break;
        }  
    } while (opcao != '5');

    return 0;
}


int decimal_para_binario(int numero_em_decimal) {
      int aux = 1;
      if (numero_em_decimal < 1)
        return 0;
      else if (numero_em_decimal % 2 == 0)
        aux = 0;

      return decimal_para_binario(numero_em_decimal / 2) * 10 + aux;
}

int contarDigitos(int numero) {
    int contador = 0;

    // Lida com o caso especial de número igual a zero
    if (numero == 0) {
        return 1;
    }

    // Se o número for negativo, transforma em positivo
    if (numero < 0) {
        numero = -numero;
    }

    // Loop para contar os dígitos
    while (numero > 0) {
        contador++;
        numero /= 10;
    }

    return contador;
}

