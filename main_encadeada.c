#include <stdio.h>
#include <string.h>

#include "fila_encadeada.h"

void teste_enfileirar_1m_encadeada() {
    Fila* f = fila_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 1000000; i++) fila_inserir_encadeada(f, newElement);
    Fila* queue = fila_clone_encadeada(f);
    for (int i = 0; i < 1000000; i++) fila_remover_encadeada(f, &oldElement);
    fila_destruir_encadeada(&f);
    fila_destruir_encadeada(&queue);
}

void teste_enfileirar_5m_encadeada() {
    Fila* f = fila_criar_encadeada();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 5000000; i++) fila_inserir_encadeada(f, newElement);
    Fila* queue = fila_clone_encadeada(f);
    for (int i = 0; i < 5000000; i++) fila_remover_encadeada(f, &oldElement);

    fila_destruir_encadeada(&f);
    fila_destruir_encadeada(&queue);
}

int main() {
    teste_enfileirar_5m_encadeada();
    return 0;
}
