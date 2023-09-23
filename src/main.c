#include <stdio.h>
#include <stdlib.h>
#include "Contato/contato.c"

int decimal_para_binario(int numero_em_decimal);
int contarDigitos(int numero);

int main() {
    ListaContatos* lista = iniciaLista(); // Inicializa a lista de contatos vazia

    inserirContato(&lista, "João", "joao@example.com", "123456789");
    inserirContato(&lista, "Maria", "maria@example.com", "987654321");
    inserirContato(&lista, "Julia", "julia@example.com", "7777777777");
    inserirContato(&lista, "Ana Silva", "ana.silva@email.com", "1234567890");

    printf("\033[31m");
    printf("Lista de Contatos:\n");
    printf("\033[0m");
    imprimirListaContatos(lista);
    
    exportarContatos(lista);

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

