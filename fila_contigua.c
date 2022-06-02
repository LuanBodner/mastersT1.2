#include "fila_contigua.h"

#include "string.h"

#define TAM_INICIAL 5

/**************************************
 * DADOS
 **************************************/

/**************************************
 * FUNÇÕES AUXILIARES
 **************************************/

bool fila_ehValida_contigua(Fila* f) { return (f != NULL ? true : false); }

void realoca_contigua(Fila* f, int novoTamanho) {
    TipoElemento* vetorAuxiliar =
        (TipoElemento*)calloc(novoTamanho, sizeof(TipoElemento));
    int i;
    int pos = f->inicio;

    for (i = 0; i < f->qtdeElementos; i++) {
        vetorAuxiliar[i] = f->vetor[pos];
        pos = (pos + 1) % f->tamVetor;
    }
    free(f->vetor);
    f->vetor = vetorAuxiliar;
    f->inicio = 0;
    f->fim = f->qtdeElementos;
    f->tamVetor = novoTamanho;
}

void verifica_aumenta_contigua(Fila* f) {
    if (f->qtdeElementos ==
        f->tamVetor -
            1) {  // precisamos deixar 1 posicao vazia entre o fim e o inicio
        realoca_contigua(f, f->tamVetor * 2);
    }
}

void verifica_diminui_contigua(Fila* f) {
    if (f->qtdeElementos <= f->tamVetor / 4 && f->tamVetor > TAM_INICIAL) {
        realoca_contigua(f, f->tamVetor / 2);
    }
}

int fila_tamVetor_contigua(Fila* f) { return f->tamVetor; }

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila* fila_criar_contigua() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->vetor = (TipoElemento*)calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir_contigua(Fila** enderecoFila) {
    if (enderecoFila == NULL) return;
    if (!fila_ehValida_contigua(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

void fila_imprimir_contigua(Fila* f) {
    printf("Queue: \n[");

    for (int i = 0; i < f->qtdeElementos; i++) {
        if (i < f->qtdeElementos - 1)
            printf("%s, ", f->vetor[i].name);
        else
            printf("%s]\n", f->vetor[i].name);
    }
}

Fila* fila_clone_contigua(Fila* f) {
    Fila* queue = fila_criar_contigua();
    realoca_contigua(queue, f->qtdeElementos);
    for (int i = 0; i < f->qtdeElementos; i++) queue->vetor[i] = f->vetor[i];
    queue->tamVetor = f->tamVetor;
    queue->qtdeElementos = f->qtdeElementos;
    queue->inicio = f->inicio;

    return queue;
}

bool fila_inserir_contigua(Fila* f, TipoElemento elemento) {
    if (!fila_ehValida_contigua(f)) return false;

    verifica_aumenta_contigua(f);
    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tamVetor;
    f->qtdeElementos++;

    return true;
}

bool fila_remover_contigua(Fila* f,
                           TipoElemento* saida) {  // estratégia do scanf
    if (!fila_ehValida_contigua(f)) return false;
    if (fila_vazia_contigua(f)) return false;

    TipoElemento elemento = f->vetor[f->inicio];
    f->inicio = (f->inicio + 1) % f->tamVetor;
    *saida = elemento;
    f->qtdeElementos--;
    verifica_diminui_contigua(f);

    return true;
}

bool fila_primeiro_contigua(Fila* f,
                            TipoElemento* saida) {  // estratégia do scanf
    if (!fila_ehValida_contigua(f)) return false;
    if (fila_vazia_contigua(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia_contigua(Fila* f) {
    if (!fila_ehValida_contigua(f)) return true;

    return (f->qtdeElementos == 0 ? true : false);
}

int fila_tamanho_contigua(Fila* f) {
    if (!fila_ehValida_contigua(f)) return 0;

    return f->qtdeElementos;
}
