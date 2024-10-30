#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando Selection Sort
void selectionSort(int arr[], int n) {
    // Loop para mover o limite do array não ordenado
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume que o elemento atual é o menor
        // Loop para encontrar o menor elemento no array não ordenado
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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

    // Ordena o array usando Selection Sort
    selectionSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado com Selection Sort: ");
    printArray(arr, n);

    return 0;
}
// Made by Marcos Vinicius CC4N
