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

// Função para inserir um elemento na árvore BST
struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    return root;
}

// Funções de caminhamento para BST
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Função principal para testar a árvore BST
int main() {
    struct Node* rootBST = NULL;
    rootBST = insertBST(rootBST, 50);
    insertBST(rootBST, 30);
    insertBST(rootBST, 20);
    insertBST(rootBST, 40);
    insertBST(rootBST, 70);
    insertBST(rootBST, 60);
    insertBST(rootBST, 80);

    printf("Caminhamento Pré-Ordem (BST): ");
    preOrder(rootBST);
    printf("\n");

    printf("Caminhamento Em Ordem (BST): ");
    inOrder(rootBST);
    printf("\n");

    printf("Caminhamento Pós-Ordem (BST): ");
    postOrder(rootBST);
    printf("\n");

    return 0;
}
