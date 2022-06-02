#ifndef _FILA_H_ENCADEADA_
#define _FILA_H_ENCADEADA_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
    int id;
    char name[255];
    float salary;
    int status;
    char address[255];
} TipoElemento;

/**************************************
 * DADOS
 **************************************/
typedef struct no {
    TipoElemento dado;
    struct no* prox;
} No;

typedef struct _fila {
    No* inicio;
    No* fim;
    int qtde;
} Fila;
/**************************************
 * PROTÓTIPOS
 **************************************/
Fila* fila_criar_encadeada();
void fila_destruir_encadeada(Fila** enderecoFila);
bool fila_inserir_encadeada(Fila* f, TipoElemento elemento);
bool fila_remover_encadeada(Fila* f,
                            TipoElemento* saida);  // estratégia do scanf
bool fila_primeiro_encadeada(Fila* f,
                             TipoElemento* saida);  // estratégia do scanf
bool fila_vazia_encadeada(Fila* f);
int fila_tamanho_encadeada(Fila* f);

void fila_imprimir_encadeada(Fila* f);
Fila* fila_clone_encadeada(Fila* f);
bool fila_inserirTodos_encadeada(Fila* f, TipoElemento* vetor, int tamVetor);

#endif
