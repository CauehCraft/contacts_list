/* TAD: Contato */

#ifndef  CONTATO_H
#define  CONTATO_H

// Struct do tipo Contao
typedef struct contato Contato;

// Função para criar um novo contato
Contato* criarContato(const char* nome, const char* email, const char* telefone);

// Função para buscar um contato na lista pelo nome
Contato* buscarContato(Contato** lista_contatos, const char* nome) ;

// Função para remover um contato da lista pelo nome
void apagarContato(Contato** lista_contatos, int indice, char* nome);

// Função para imprimir um contato específico
void imprimirContato(Contato* contato);

// Função para imprimir a lista de contatos
void imprimirListaContatos(Contato** lista_contatos);

// Liberar a memória alocada para a lista de contatos
void liberarMemoriaListaContatos(Contato** lista_contatos);

// Função importar contatos de um arquivo
void importarContatos(Contato** lista_contatos);

// Função exportar contatos para arquivo
void exportarContatos(Contato** lista_contatos);

#endif