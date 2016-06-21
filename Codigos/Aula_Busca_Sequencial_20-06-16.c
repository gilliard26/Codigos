#include <stdio.h>

int BuscaSequencial(int v[], int n, int num) {
    for (int i= 0; i < n; i++)
        if (num == v[i])
            return i;
    return -1;
}

int main() {
    int v[] = {8, -1, 12, 25, 2, -10};
	int posicao = BuscaSequencial(v, 6, 8);
    if (posicao >= 0)
        printf ("Encontrou! Na posição %d", posicao);
    else
        puts ("Não encontrou!");

    return 0;
}
