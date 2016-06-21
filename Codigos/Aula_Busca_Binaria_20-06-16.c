#include <stdio.h>

int BuscaBinaria(int v[], int inicio, int fim, int num) {
    int meio = (inicio + fim) / 2; //Encontra o elemento central do vetor;
    if (num == v[meio]) //Verifica se o elemento central é o buscado e retorna;
        return meio;
    else 
		if (inicio != fim) { //Enquanto tiver mais de um elemento ele executará a recursividade;
			if (num < v[meio])
				return BuscaBinaria(v, inicio, meio -1, num);//Chamada recursiva para verificar a metade esquerda;
			else
				return BuscaBinaria(v, meio +1, fim, num);//Chamada recursiva para verificar a metade direita;
		} else {
			return -1;//Retorna -1 caso o número buscado não tenha no vetor;
    }
}

int main() {
    int v[] = {-100, -90, 20, 0, 10, 40, 100};

    int posicaoB = BuscaBinaria(v, 0, 6, 10);

    if (posicaoB >= 0)
        printf ("Encontrou! Na posição %d", posicaoB);
    else
        puts ("Não encontrou!");

    return 0;
}
