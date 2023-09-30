#include "Contato/contato.c"
#include "Sistema/sistema.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    Contato* lista[MAX_CONTATOS];

    // Inicializar a lista com NULLs
    for (int i = 0; i < MAX_CONTATOS; i++) {
        lista[i] = NULL;
    }

    // Adicionar alguns contatos (exemplo)
    lista[0] = (Contato*)malloc(sizeof(Contato));
    strcpy(lista[0]->nome, "Joao");
    strcpy(lista[0]->email, "joao@example.com");
    strcpy(lista[0]->telefone, "123456789");

    lista[1] = (Contato*)malloc(sizeof(Contato));
    strcpy(lista[1]->nome, "Maria");
    strcpy(lista[1]->email, "maria@example.com");
    strcpy(lista[1]->telefone, "987654321");

    lista[2] = (Contato*)malloc(sizeof(Contato));
    strcpy(lista[2]->nome, "Adenor Melo");
    strcpy(lista[2]->email, "adenor@example.com");
    strcpy(lista[2]->telefone, "987654321");

    // Imprimir a lista antes de apagar
    printf("Lista antes de apagar:\n");
    imprimirListaContatos(lista);

    // Apagar o contato no índice 1 (Maria)
    apagarContato(lista, 1);

    // Imprimir a lista depois de apagar
    printf("\nLista depois de apagar:\n");
    imprimirListaContatos(lista);

    // Liberar a memória alocada para a lista
    liberarMemoriaListaContatos(lista);

    return 0;
}
