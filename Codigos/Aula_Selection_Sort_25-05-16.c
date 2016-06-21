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

void swap (int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort (int v[], int n){
	int i, j, m;
	for (i = 0; i < n-1; i++){
		m =i;
		for (j = i +1; j < n; j++)
			if (v[j] < v[m])
				m = j;
		swap (&v[i], &v[m]);
	}	
		
	
}

int main (){
	int n = 100000;
    int *v = (int *) malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        v[i] = rand() % 1001 + (-500);
	
	
	printf("ORIGINAL: ");
    //printArray(v, n);
    selectionSort(v, n);
    printf("ORDENADO: ");
    //printArray(v, n);
	
	return 0;
}
