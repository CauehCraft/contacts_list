/* TAD: Contato */

#ifndef  CONTATO_H
#define  CONTATO_H

// Struct do tipo Contao
typedef struct contato Contato;

// Struct para o nó da lista
typedef struct listacontatos ListaContatos;

// Inicializa a Lista de Contatos
ListaContatos* iniciaLista(void);

// Função para criar um novo contato
ListaContatos* criarContato(const char* nome, const char* email, const char* telefone);

// Função para inserir um novo contato no início da lista
void inserirContato(ListaContatos** lista, const char* nome, const char* email, const char* telefone);

// Função para buscar um contato na lista pelo nome
ListaContatos* buscarContato(ListaContatos* lista, const char* nome);

// Função para remover um contato da lista pelo nome
void removerContato(ListaContatos** lista, const char* nome);

// Função para imprimir a lista de contatos
void imprimirListaContatos(ListaContatos* lista);

// Função importar contatos de um arquivo
ListaContatos* importarContatos(ListaContatos *c_list);

// Função exportar contatos para arquivo
void exportarContatos(ListaContatos* c_list);

// Função que troca os valores de dois nós
void swapNodes(ListaContatos *c_list_1, ListaContatos *c_list_2);

// Função que ordena a lista em ordem alfabetica
void lst_ordena(ListaContatos *c_list);

#endif