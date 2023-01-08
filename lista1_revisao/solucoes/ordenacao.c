#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        int valorAtual = vetor[i];
        int j;
        for (j = i-1; j >= 0 && vetor[j] > valorAtual; j--)
            vetor[j+1] = vetor[j];
        vetor[j+1] = valorAtual;
    }
}

int main() {

    int *vetor;
    int n;
    int tamVetor = 1;
    
    vetor = malloc(sizeof(int));

    while(scanf ("%d", &n) != EOF){
        vetor[tamVetor-1] = n;
        tamVetor++;
        vetor = realloc(vetor, tamVetor*sizeof(int));
    }

    tamVetor--;

    insertion_sort(vetor, tamVetor);

    for (int i = 0; i < tamVetor; i++) {
        if (i == tamVetor-1) printf("%d\n", vetor[i]);
        else printf("%d ", vetor[i]);
    }

    return 0;

}