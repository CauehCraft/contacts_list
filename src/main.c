#include "Contato/contato.c"
#include "Sistema/sistema.c"
#include "Multiplicacao/multiplicacao.c"

void solicitarEInserirContato(Contato **lista);

int main() {
    Contato* lista[MAX_CONTATOS];
    Contato* contatoBuscado = NULL;
    char opcao;
    char nome[TAM_NOME];

    // Inicializar a lista com NULLs
    for (int i = 0; i < MAX_CONTATOS; i++) {
        lista[i] = NULL;
    }
    
    do {
        menu(); // chama o menu
        opcao = le_opcao('1', '5'); // funcao que lê a opcao do usuário de acordo com o menu

        switch (opcao) {
        case '1': // cadastra contato
            solicitarEInserirContato(lista);
            break;
        case '2': // exclui contato
            printf("\nDigite o nome do contato que deseja excluir: ");
            scanf(" %[^\n]", nome);
            contatoBuscado = buscarContato(lista, nome);
                if (contatoBuscado != NULL) {
                    apagarContato(lista, hash(contatoBuscado->telefone));
                    printf("Contato excluido com sucesso!\n");
                } else {
                    printf("\nContato não encontrado!\n");
                }
            break;
        case '3': // lista contatos
            printf("------------LISTA DE CONTATOS------------\n");
            imprimirListaContatos(lista);
            break;
        case '4': // busca contatos
            printf("Digite o nome do contato que deseja buscar: ");
            scanf(" %[^\n]", nome);
            contatoBuscado = buscarContato(lista, nome);
                if (contatoBuscado != NULL) {
                    imprimirContato(contatoBuscado);
                } else {
                    printf("\nContato não encontrado!\n");
                }
            break;
        case '5': // SAIR do programa
            //exportarContatos(lista); // salva os contatos em arquivo antes de fechar o programa
            liberarMemoriaListaContatos(lista);
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
void solicitarEInserirContato(Contato **lista) {
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
    int hash_novo_contato;

    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", nome);

    printf("Digite o email do contato: ");
    scanf(" %[^\n]", email);

    printf("Digite o telefone do contato: ");
    scanf(" %[^\n]", telefone);

    hash_novo_contato = hash(telefone);
    printf("Hash gerado: %d\n", hash_novo_contato);
    if (lista[hash_novo_contato] == NULL) {
        lista[hash_novo_contato] = criarContato(nome, email, telefone);
        printf("Contato adicionado com sucesso!\n\n");
    } else {
        printf("Número já existente!\n");
    }
}

