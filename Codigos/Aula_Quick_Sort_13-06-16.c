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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int V[], int inicio, int fim)
{
    int pivo = V[fim];
    int pIndice = inicio;

    for (int i = inicio; i < fim; i++) {
        if (V[i] <= pivo) {
            if (i != pIndice)
                swap(&V[i], &V[pIndice]);
            pIndice++;
        }
    }

    swap(&V[pIndice], &V[fim]);

    return pIndice;
}

void quickSort(int V[], int inicio, int fim)
{
    if (inicio < fim) {
        int pIndice = particionar(V, inicio, fim);

        quickSort(V, inicio, pIndice - 1);
        quickSort(V, pIndice + 1, fim);
    }
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
    quickSort(V, 0, n - 1);
    printf("ORDENADO: ");
	//printArray(V, n);

    return 0;
}
