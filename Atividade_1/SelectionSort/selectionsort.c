#include <stdio.h>

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
    int arr[] = {10, 8, 6, 4, 2, 9, 7, 5, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Array ordenado com Selection Sort: ");
    printArray(arr, n);

    return 0;
}
// Made by Marcos Vinicius CC4N