#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó na árvore
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um elemento na árvore
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Função para pesquisar um elemento na árvore
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// Função para encontrar o nó com o menor valor
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Função para excluir um elemento da árvore
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Caso 1: Nó com zero ou um filho
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Caso 2: Nó com dois filhos
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Função para exibir a árvore (em ordem)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");

    printf("Pesquisa de 40: %s\n", search(root, 40) ? "Encontrado" : "Não encontrado");
    printf("Pesquisa de 25: %s\n", search(root, 25) ? "Encontrado" : "Não encontrado");

    printf("Excluindo 20\n");
    root = deleteNode(root, 20);
    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");

    printf("Excluindo 30\n");
    root = deleteNode(root, 30);
    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");

    printf("Excluindo 50\n");
    root = deleteNode(root, 50);
    printf("Árvore em ordem: ");
    inOrder(root);
    printf("\n");

    return 0;
}
