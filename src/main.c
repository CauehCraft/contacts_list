#include "Contato/contato.c"
#include "Sistema/sistema.c"

ListaContatos* solicitarEInserirContato(ListaContatos *lista);
int decimal_para_binario(int numero_em_decimal);
int contarDigitos(int numero);

int main() {
    ListaContatos* lista = iniciaLista(); // Inicializa a lista de contatos vazia
    char opcao;
    char nome[TAM_NOME];

    lista = importarContatos(lista);

    do {
        menu(); // chama o menu
        opcao = le_opcao('1', '5'); // funcao que lê a opcao do usuário de acordo com o menu

        switch (opcao) {
        case '1': // cadastra contato
            lista = solicitarEInserirContato(lista);
            printf("Contato adicionado com sucesso!\n\n");
            break;
        case '2': // exclui contato
            printf("Digite o nome do contato que deseja excluir: ");
            scanf(" %[^\n]", nome);
            removerContato(&lista, nome);
            break;
        case '3': // lista contatos
            imprimirListaContatos(lista);
            break;
        case '4': // busca contatos
            printf("Digite o nome do contato que deseja buscar: ");
            scanf(" %[^\n]", nome);
                ListaContatos* contatoBuscado = buscarContato(lista, nome);
                if (contatoBuscado != NULL) {
                    printf("\nContato encontrado:\n");
                    printf("Nome: %s\n", contatoBuscado->info.nome);
                    printf("Email: %s\n", contatoBuscado->info.email);
                    printf("Telefone: %s\n", contatoBuscado->info.telefone);
                } else {
                    printf("\nContato não encontrado.\n");
                }
            break;
        case '5': // SAIR do programa
            exportarContatos(lista); // salva os contatos em arquivo antes de fechar o programa
            lst_libera(lista);
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }  
    } while (opcao != '5');

    return 0;
}

// Função para solicitar detalhes do contato ao usuário e inseri-lo na lista
ListaContatos* solicitarEInserirContato(ListaContatos *lista) {
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nome);

    printf("Digite o email do contato: ");
    scanf(" %[^\n]", email);

    printf("Digite o telefone do contato: ");
    scanf(" %[^\n]", telefone);

    return inserirContato(lista, nome, email, telefone); 
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

