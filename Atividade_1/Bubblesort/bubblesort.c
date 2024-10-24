#include <stdio.h>

// Função para ordenar um array usando Bubble Sort
void bubbleSort(int arr[], int n) {
    // Loop externo para passar por todos os elementos
    for (int i = 0; i < n - 1; i++) {
        // Loop interno para comparar e trocar elementos adjacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo, troca de posição
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; // Armazena o valor temporariamente
                arr[j] = arr[j + 1]; // Troca os valores
                arr[j + 1] = temp; // Completa a troca
            }
        }
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
    // Array a ser ordenado
    int arr[] = {10, 8, 6, 4, 2, 9, 7, 5, 4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    // Chama a função de ordenação
    bubbleSort(arr, n);

    // Exibe o resultado
    printf("Array ordenado com Bubble Sort: ");
    printArray(arr, n);

    return 0;
}
// Made by Marcos Vinicius CC4N