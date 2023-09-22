#include <stdio.h>
#include <stdlib.h>
#include "Contato/contato.c"

int decimal_para_binario(int numero_em_decimal);
int contarDigitos(int numero);

int main() {
    ListaContatos* lista = iniciaLista(); // Inicializa a lista de contatos vazia

    inserirContato(&lista, "João", "joao@example.com", "123456789");
    inserirContato(&lista, "Maria", "maria@example.com", "987654321");

    printf("Lista de Contatos:\n");
    imprimirListaContatos(lista);

    ListaContatos* contatoBuscado = buscarContato(lista, "João");
    if (contatoBuscado != NULL) {
        printf("\nContato encontrado:\n");
        printf("Nome: %s\n", contatoBuscado->info.nome);
        printf("Email: %s\n", contatoBuscado->info.email);
        printf("Telefone: %s\n", contatoBuscado->info.telefone);
    } else {
        printf("\nContato não encontrado.\n");
    }

    removerContato(&lista, "Maria");
    printf("\nLista de Contatos após a remoção de 'Maria':\n");
    imprimirListaContatos(lista);

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

