#include <stdio.h>
#include <string.h>

#include "fila_contigua.h"

void teste_enfileirar_1m_contigua() {
    Fila* f = fila_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 1000000; i++) fila_inserir_contigua(f, newElement);
    Fila* queue = fila_clone_contigua(f);
    for (int i = 0; i < 1000000; i++) fila_remover_contigua(f, &oldElement);

    fila_destruir_contigua(&f);
    fila_destruir_contigua(&queue);
}

void teste_enfileirar_5m_contigua() {
    Fila* f = fila_criar_contigua();
    TipoElemento newElement = {name : "Testerson"};
    TipoElemento oldElement;

    for (int i = 0; i < 5000000; i++) fila_inserir_contigua(f, newElement);
    Fila* queue = fila_clone_contigua(f);
    for (int i = 0; i < 5000000; i++) fila_remover_contigua(f, &oldElement);

    fila_destruir_contigua(&f);
    fila_destruir_contigua(&queue);
}
int main() {
    teste_enfileirar_5m_contigua();
    return 0;
}
