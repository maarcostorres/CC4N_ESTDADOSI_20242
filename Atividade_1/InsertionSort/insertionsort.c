#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando Insertion Sort
void insertionSort(int arr[], int n) {
    // Loop para percorrer o array a partir do segundo elemento
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Armazena o valor do elemento atual
        int j = i - 1;

        // Move os elementos do array que são maiores que a chave
        // para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--; // Move para o próximo elemento à esquerda
        }
        // Coloca a chave na posição correta
        arr[j + 1] = key;
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Array com 50 valores inteiros aleatórios
    int arr[50];
    for (int i = 0; i < 50; i++) {
        arr[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);

    // Ordena o array usando Insertion Sort
    insertionSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado com Insertion Sort: ");
    printArray(arr, n);

    return 0;
}
// Made by Marcos Vinicius CC4N
