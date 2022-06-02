#ifndef _FILA_H_CONTIGUA_
#define _FILA_H_CONTIGUA_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _element {
    int id;
    char name[255];
    float salary;
    int status;
    char address[255];
} TipoElemento;
/**************************************
 * DADOS
 **************************************/
typedef struct _fila {
    TipoElemento* vetor;
    int tamVetor;
    int inicio;
    int fim;
    int qtdeElementos;
} Fila;

/**************************************
 * PROTÓTIPOS
 **************************************/
Fila* fila_criar_contigua();
void fila_destruir_contigua(Fila** enderecoFila);
bool fila_inserir_contigua(Fila* f, TipoElemento elemento);
bool fila_remover_contigua(Fila* f,
                           TipoElemento* saida);  // estratégia do scanf
bool fila_primeiro_contigua(Fila* f,
                            TipoElemento* saida);  // estratégia do scanf
bool fila_vazia_contigua(Fila* f);
int fila_tamanho_contigua(Fila* f);

void fila_imprimir_contigua(Fila* f);
Fila* fila_clone_contigua(Fila* f);
bool fila_inserirTodos_contigua(Fila* f, TipoElemento* vetor, int tamVetor);

#endif
