#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <sys/time.h>
#include "ordenacao.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opt, sub_opt, *vetor, tamanho, resposta,i, j;
    struct timeval Tempo_antes, Tempo_depois;
    double deltaT;

    while(1){ //menu principal
        system("cls");
        printf("\t\t\t\t\t*************************************\n");
        printf("\t\t\t\t\t****** Algoritmos de Ordenação ******\n");
        printf("\t\t\t\t\t*************************************\n\n\n");

        printf("Escolha um algoritmo: \n\n");
        printf("[1] BeadSort\n");
        printf("[2] BubbleSort\n");
        printf("[3] CountingSort\n");
        printf("[4] HeapSort\n");
        printf("[5] InsertionSort\n");
        printf("[6] MergeSort\n");
        printf("[7] QuickSort\n");
        printf("[8] RadixSort\n");
        printf("[9] SelectionSort\n");
        printf("[10] ShellSort\n");
        printf("[11] TimSort\n");
        printf("[0] Sair do programa\n\n> ");
            scanf("%d", &opt);

        if(opt == 0) {
            system("cls");
            printf("Sair ? (1 - Sim / 2 - Não)\n> ");
            scanf("%d", &resposta);
            if(resposta == 1){
                exit(1);
            }else {
                continue;
            }
        }

        //verificar se opt é válido
        if(opt < 0 || opt > 11) {
            system("cls");
            printf("\nOpção inválida!\n\n");
            system("pause");
            continue;
        }

        system ("cls");
        printf("\nEscolha a quantidade de elementos: \n\n");
        printf("[1] 1.000\n");
        printf("[2] 5.000\n");
        printf("[3] 10.000\n");
        printf("[4] 20.000\n");
        printf("[5] 50.000\n");
        printf("[6] 100.000\n\n> ");
            scanf("%d", &sub_opt);

        switch(sub_opt) {
        case 1:
            tamanho = 1000;
            break;
        case 2:
            tamanho = 5000;
            break;

        case 3:
            tamanho = 10000;
            break;

        case 4:
            tamanho = 20000;
            break;

        case 5:
            tamanho = 50000;
            break;

        case 6:
            tamanho = 100000;
            break;

        default:
            system("cls");
            printf("\nOpção inválida!\n\n");
            system("pause");
            continue;
        }

        switch(opt){
        case 1:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                beadSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução BeadSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 2:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                bubbleSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução BubbleSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 3:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                countingSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução CountingSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 4:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                heapSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução HeapSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 5:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                int beg = 0;
                insertionSort(vetor, beg, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução InsertionSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 6:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                mergeSort(vetor, 0, tamanho-1);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução MergeSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 7:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                quickSort(vetor, 0, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução QuickSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 8:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                radixSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução RadixSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 9:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                selectionSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução SelectionSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 10:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                shellSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução ShellSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        case 11:
            system("cls");
            printf("Calculando tempo de execução...\n");

            for(j=0 ; j<10 ; ++j){
                deltaT = 0;
                gettimeofday(&Tempo_antes, NULL);
                vetor = geraNumerosAleatorios(tamanho);

                timSort(vetor, tamanho);

                gettimeofday(&Tempo_depois, NULL);
                deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) - (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
                printf("\nTempo de execução TimSort com %d elementos: %f segundos\n", tamanho, deltaT);

                free(vetor);
            }
            printf("\n");
            system("pause");
            break;

        }
    }
    return 0;
}


