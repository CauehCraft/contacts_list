#include "Contato/contato.c"
#include "Sistema/sistema.c"


int main() {
    Contato *lista[MAX_CONTATOS];
    Contato *contatoBuscado = NULL;
    char opcao;
    char nome[TAM_NOME];

    // Inicializar a lista com NULLs
    for (int i = 0; i < MAX_CONTATOS; i++) {
        lista[i] = NULL;
    }

    importarContatos(lista); // importando os contados armazenados

    do {
        menu();                     // chama o menu
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
                apagarContato(lista, hash(contatoBuscado->telefone), nome);
                printf("Contato excluido com sucesso!\n");
            }
            else {
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
            }
            else {
                printf("\nContato não encontrado!\n");
            }
            break;
        case '5': // SAIR do programa
            exportarContatos(lista); // salva os contatos em arquivo antes de fechar o programa
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

