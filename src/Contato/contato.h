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

ListaContatos* importarContatos(ListaContatos *c_list);

#endif