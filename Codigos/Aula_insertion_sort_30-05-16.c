#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void insertionSort(int v[], int n){
	for (int i =1; i < n; i++){
		int j = i;
		while ((v[j] < v[j - 1]) && (j > 0)){
			int temp = v[j];
			v[j] = v[j-1];
			v[j-1] = temp;
			j--;
			}
		}
	}

void printArray(int v[], int n)
{
    int i;
    printf("[ ");
    for (i = 0; i < n; i++) {
        printf("%6d", v[i]);
    }
    printf(" ]\n");
}

int main(){
	
	int n = 100000;
    int *v = (int *) malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        v[i] = rand() % 1001 + (-500);
	
	printf("ORIGINAL: ");
    //printArray(v, n);
    insertionSort(v, n);
    printf("ORDENADO: ");
	//printArray(v, n);	
	
	return 0;
	}
