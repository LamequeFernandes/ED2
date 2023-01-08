#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->prox = le->prox;
    novo->dado = x;

    le->prox = novo;
}

void insere_antes (celula *le, int x, int y) {
    while (le->prox != NULL) {
        if (le->prox->dado == y) {
            celula *novo = malloc(sizeof(celula));
            novo->prox = le->prox;
            novo->dado = x;
            le->prox = novo;

            break;
        }
        le = le->prox;

        if (le->prox == NULL) {
            celula *novo = malloc(sizeof(celula));
            novo->prox = NULL;
            novo->dado = x;

            le->prox = novo;

            break;
        }
    }    
}

void imprime (celula *le) {
    while (le->prox != NULL) {
        printf("%d -> ", le->prox->dado);
        le = le->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le) {
    if (le->prox == NULL) printf ("NULL\n");

    if (le->prox != NULL) {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
}

int remove_depois (celula *p) {
    if (p->prox == NULL) 
        return 0;

    celula *a_remover = p->prox;
    p->prox = a_remover->prox;

    int valor_a_remover = a_remover->dado;
    free(a_remover);

    return valor_a_remover;
}

void remove_elemento (celula *le, int x) {
    while (le->prox != NULL) {
        if (le->prox->dado == x) {
            remove_depois(le);
            break;
        }
        le = le->prox;
    }
}

void remove_todos_elementos (celula *le, int x) {
    celula *no_anterior = malloc(sizeof(celula));

    while (le->prox != NULL) {
        if (le->prox->dado == x) {
            remove_depois(le);
        } else {
            le = le->prox;
        }
    }
}

celula *busca (celula *le, int x) {
    while (le->prox != NULL) {
        if (le->prox->dado == x) {
            return le->prox;
        }
        le = le->prox;
        if (le->dado == x) {
            return le;
        }
    }
    return NULL;
}

celula *busca_rec (celula *le, int x) {
    if (le->dado == x) {
        return le;
    }
    if (le->prox == NULL) {
        return NULL;
    } else
        busca_rec(le->prox, x);
}

int main () {

    celula *le = malloc(sizeof(celula));
    insere_inicio(le, 1);
    insere_inicio(le, 2);
    insere_inicio(le, 3);
    insere_inicio(le, 4);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 7);
    insere_inicio(le, 4);

    insere_antes(le, 10, 2);
    insere_antes(le, 17, 19);

    remove_depois(le);
    remove_elemento(le, 2);
    remove_todos_elementos(le, 7);

    imprime(le);
    printf("\n");
    imprime_rec(le);

    celula *no_buscado = busca(le, 10);
    if (no_buscado != NULL)
        printf("%d\n", no_buscado->dado);
    
    celula *no_buscado_rec = busca(le, 10);
    if (no_buscado_rec != NULL)
        printf("%d\n", no_buscado_rec->dado);

    return 0;
}