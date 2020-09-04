#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ordenacao.h"

int geraNumerosAleatorios(int quantidade){
    int *vetor,i;

    srand(time(NULL));
    vetor = (int *) malloc(quantidade*sizeof(int));
    for (int i=0; i < quantidade; i++){
        vetor[i] = (rand() % 5000);
    }
return vetor;
}

void radixSort(int *vetor, int tamanho) {

    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);

}

double countingSort(int *vetor, int tamanho){
    int i, j, k;
    int valores[tamanho];

    for(i=0; i<tamanho; i++){
        valores[i] = 0;
    }

    for(i=0; i<tamanho; i++){
        valores[vetor[i]]++;
    }

    for(i=0, j=0; j<tamanho; j++){
        for(k=valores[j]; k>0; k--){
            vetor[i] = j;
            i++;
        }
    }
}

//Função do QuickSort
int dividePartes(int *vetor, int ini, int fim) {
    int esq, dir, pivo, aux;

    esq = ini;
    dir = fim;
    pivo = vetor[ini];

    while(esq < dir) {
        while(esq <= fim && vetor[esq] <= pivo) {
            esq++;
        }
        while(dir >= 0 && vetor[dir] > pivo) {
            dir--;
        }

        if(esq < dir) {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[ini] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void quickSort(int *vetor, int ini, int fim){
    int pivo;

    if(ini < fim) {
        pivo = dividePartes(vetor, ini, fim);
        quickSort(vetor, ini, pivo - 1);
        quickSort(vetor, pivo + 1, fim);
    }
}

// Função secundaria do heapsort
void CriandoHeap(int *vetor, int ini, int fim){
    int filho = 2*ini + 1, aux = vetor[ini], i;

    while(filho <= fim){

        if(filho < fim){
            if(vetor[filho] < vetor[filho + 1]){
                filho += 1;
            }
        }

        if(vetor[filho] > aux){
            vetor[ini] = vetor[filho];
            ini = filho;
            filho = ini*2 + 1;
        }else{
            filho = fim + 1;
        }

    }

    vetor[ini] = aux;
}

void heapSort(int *vetor, int tamanho){

    int i, aux;

    for(i=(tamanho-1)/2; i>=0; i--){
        CriandoHeap(vetor, i, tamanho-1);
    }

    for(i=(tamanho-1); i>0; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        CriandoHeap(vetor, 0, i-1);
    }
}

void shellSort(int *vetor, int tamanho) {
    int i , j , value;

    int h = 1;
    while(h < tamanho) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < tamanho; i++) {
            value = vetor[i];
            j = i;
            while (j > h-1 && value <= vetor[j - h]) {
                vetor[j] = vetor[j - h];
                j = j - h;
            }
            vetor[j] = value;
        }
        h = h/3;
    }
}

//Finção para Timsort

void inserting(int *a, int beg, int end){
    int temp, i, j;
    for (i = beg + 1; i <= end; i++){
        temp = a[i];
        j = i - 1;
        while (a[j] > temp && j >= beg){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int minimum(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

double timSort(int *a, int n){

    int i,size,beg,mid,end, run=32768;

    for (i = 0; i < n; i+=run)
        inserting(a, i, minimum((i+(run - 1)), (n-1)));
    for (size = run; size < n; size = 2*size){
        for (beg = 0; beg < n; beg += 2*size){
            mid = beg + size - 1;
            end = minimum((beg + 2*size - 1), (n-1));

            merge(a, beg, mid, end);
        }
    }
    }

void insertionSort(int *vetor, int beg, int end){
        int temp, i, j;
        for (i = beg + 1; i <= end; i++)
        {
            temp = vetor[i];
            j = i - 1;
            while (vetor[j] > temp && j >= beg)
            {
                vetor[j+1] = vetor[j];
                j--;
            }
            vetor[j+1] = temp;
        }
    }

void merge(int *vetor, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = vetor[l + i];
	for (j = 0; j < n2; j++)
		R[j] = vetor[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			vetor[k] = L[i];
			i++;
		}
		else{
			vetor[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		vetor[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		vetor[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int *vetor, int l, int r){
    if (l < r){
		int m = l+(r-l)/2;

		mergeSort(vetor, l, m);
		mergeSort(vetor, m+1, r);

		merge(vetor, l, m, r);
	}
}

void beadSort(int *vetor, int tamanho){
	int i, j, max, sum;
	unsigned char *beads;
#	define BEAD(i, j) beads[i * max + j]

	for (i = 1, max = vetor[0]; i < tamanho; i++)
		if (vetor[i] > max) max = vetor[i];
	beads = calloc(1, max * tamanho);

	for (i = 0; i < tamanho; i++)
		for (j = 0; j < vetor[i]; j++)
			BEAD(i, j) = 1;
	for (j = 0; j < max; j++){
		for (sum = i = 0; i < tamanho; i++){
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		for (i = tamanho - sum; i < tamanho; i++)
            BEAD(i, j) = 1;
	}
	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		vetor[i] = j;
	}
	free(beads);
}

void bubbleSort(int *vetor, int tamanho){

    int i, continua, aux, fim = tamanho;
    do {
        continua =0;
        for(i=0;i<fim-1;i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = i;
            }
    }
    fim--;
    }while(continua != 0);
}

void selectionSort(int *vetor, int tamanho){
    int i, j, menor, troca ;
        for(i=0;i<tamanho-1;i++){
            menor  = i;
            for(j=i+1;j<tamanho;j++){
                if(vetor[j] < vetor[menor]){
                    menor = j;
                }
            }
          if(i != menor){
             troca = vetor[i];
             vetor[i] = vetor[menor];
             vetor[menor] = troca;
          }
    }
}

