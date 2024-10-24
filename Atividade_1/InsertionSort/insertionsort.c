#include <stdio.h>

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
    int arr[] = {10, 8, 6, 4, 2, 9, 7, 5, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Array ordenado com Insertion Sort: ");
    printArray(arr, n);

    return 0;
}
// Made by Marcos Vinicius CC4N