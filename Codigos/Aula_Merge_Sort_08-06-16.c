#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int V[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%6d", V[i]);
    }
    printf(" ]\n");
}

void merge(int E[], int nE, int D[], int nD, int V[])
{
    int i, j, k;

    i = j = k = 0;

    while (i < nE && j < nD) {
        if (E[i] <= D[j]) {
            V[k] = E[i];
            i++;
        } else {
            V[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < nE) {
        V[k] = E[i];
        k++;
        i++;
    }

    while (j < nD) {
        V[k] = D[j];
        k++;
        j++;
    }
}

void mergeSort(int V[], int n)
{
    int i;
    int meio;

    if (n < 2)
        return;

    meio = n / 2;

    int *E = (int *) malloc(meio * sizeof(int));
    int *D = (int *) malloc((n - meio) * sizeof(int));;

    for (i = 0; i < meio; i++)
        E[i] = V[i];

    for (i = meio; i < n; i++)
        D[i - meio] = V[i];

    mergeSort(E, meio);
    mergeSort(D, n - meio);
    merge(E, meio, D, n - meio, V);

    free(E);
    free(D);
}

int main()
{
    int i, n = 100000;
    int *V = (int *) malloc(n * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < n; i++)
        V[i] = rand() % 1001 + (-500);
    printf("ORIGINAL: ");
    //printArray(V, n);
    mergeSort(V, n);
    printf("ORDENADO: ");
    //printArray(V, n);

    return 0;
}
