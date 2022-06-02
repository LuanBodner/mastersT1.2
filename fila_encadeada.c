#include "fila_encadeada.h"

#include "string.h"

#define TAM_INICIAL 5

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/

bool fila_ehValida(Fila* f) { return (f != NULL ? true : false); }

No* novoNo(TipoElemento valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila* fila_criar_encadeada() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->qtde = 0;
    return fila;
}

void fila_imprimir_encadeada(Fila* f) {
    printf("Queue \n[");
    No* node = f->inicio;
    while (node != NULL) {
        if (node->prox != NULL)
            printf("%s, ", node->dado.name);
        else
            printf("%s", node->dado.name);
        node = node->prox;
    }
    printf("]\n");
}

Fila* fila_clone_encadeada(Fila* f) {
    Fila* queue = fila_criar_encadeada();
    No* node = f->inicio;
    while (node != NULL) {
        fila_inserir_encadeada(queue, node->dado);
        node = node->prox;
    }

    return queue;
}

void fila_destruir_encadeada(Fila** enderecoFila) {
    if (enderecoFila == NULL) return;
    if (!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    No* aux;
    while (f->inicio != NULL) {
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir_encadeada(Fila* f, TipoElemento elemento) {
    if (!fila_ehValida(f)) return false;

    No* novo = novoNo(elemento);

    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->qtde++;

    return true;
}

bool fila_remover_encadeada(Fila* f,
                            TipoElemento* saida) {  // estratégia do scanf
    if (!fila_ehValida(f)) return false;
    if (fila_vazia_encadeada(f)) return false;

    No* aux = f->inicio;
    f->inicio = f->inicio->prox;
    f->qtde--;
    *saida = aux->dado;
    free(aux);

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    return true;
}

bool fila_primeiro_encadeada(Fila* f,
                             TipoElemento* saida) {  // estratégia do scanf
    if (!fila_ehValida(f)) return false;
    if (fila_vazia_encadeada(f)) return false;

    *saida = f->inicio->dado;
    return true;
}

bool fila_vazia_encadeada(Fila* f) {
    if (!fila_ehValida(f)) return true;

    return (f->qtde == 0 ? true : false);
}

int fila_tamanho_encadeada(Fila* f) {
    if (!fila_ehValida(f)) return 0;

    return f->qtde;
}
