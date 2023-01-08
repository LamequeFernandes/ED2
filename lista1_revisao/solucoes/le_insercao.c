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

// void imprime (celula *le) {
//     while (le->prox != NULL) {
//         printf("%d -> ", le->prox->dado);
        
//         le = le->prox;
        
//         if (le->prox == NULL)
//             printf("NULL");
//     }
// }

// void imprime_rec (celula *le) {
//     if (le->prox == NULL) printf ("NULL");

//     if (le->prox != NULL) {
//         printf("%d -> ", le->prox->dado);
//         imprime_rec(le->prox);
//     }
// }

// int main () {

//     celula *le = malloc(sizeof(celula));
//     insere_inicio(le, 1);
//     insere_inicio(le, 2);
//     insere_inicio(le, 3);
//     insere_inicio(le, 4);

//     insere_antes(le, 10, 2);
//     insere_antes(le, 17, 19);

//     imprime(le);
//     printf("\n");
//     imprime_rec(le);

//     return 0;
// }