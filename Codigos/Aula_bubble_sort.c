#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int V[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%6d", V[i]);
    }
    printf(" ]\n");
}


void bubbleSort(int v[], int n){
	for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
	}

int main()
{

    int n = 100000;
    int *v = (int *) malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        v[i] = rand() % 1001 + (-500);
    
   printf("Original: ");
   //printArray(v, n);
   bubbleSort(v, n);
   printf("Ordenado: ");
   //printArray(v, n);
   
   return 0;
}
