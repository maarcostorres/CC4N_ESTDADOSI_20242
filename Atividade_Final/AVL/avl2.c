#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore AVL
struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

// Função para obter a altura de um nó
int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para obter o maior valor entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó na árvore AVL
struct AVLNode* createAVLNode(int data) {
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Novo nó é inicialmente uma folha
    return newNode;
}

// Rotação simples à direita
struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Rotação simples à esquerda
struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para inserir um elemento na árvore AVL
struct AVLNode* insertAVL(struct AVLNode* node, int data) {
    if (node == NULL)
        return createAVLNode(data);

    if (data < node->data) {
        node->left = insertAVL(node->left, data);
    } else if (data > node->data) {
        node->right = insertAVL(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Funções de caminhamento para AVL
void preOrderAVL(struct AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderAVL(root->left);
        preOrderAVL(root->right);
    }
}

void inOrderAVL(struct AVLNode* root) {
    if (root != NULL) {
        inOrderAVL(root->left);
        printf("%d ", root->data);
        inOrderAVL(root->right);
    }
}

void postOrderAVL(struct AVLNode* root) {
    if (root != NULL) {
        postOrderAVL(root->left);
        postOrderAVL(root->right);
        printf("%d ", root->data);
    }
}

// Função principal para testar a árvore AVL
int main() {
    struct AVLNode* rootAVL = NULL;
    rootAVL = insertAVL(rootAVL, 50);
    insertAVL(rootAVL, 30);
    insertAVL(rootAVL, 20);
    insertAVL(rootAVL, 40);
    insertAVL(rootAVL, 70);
    insertAVL(rootAVL, 60);
    insertAVL(rootAVL, 80);

    printf("Caminhamento Pré-Ordem (AVL): ");
    preOrderAVL(rootAVL);
    printf("\n");

    printf("Caminhamento Em Ordem (AVL): ");
    inOrderAVL(rootAVL);
    printf("\n");

    printf("Caminhamento Pós-Ordem (AVL): ");
    postOrderAVL(rootAVL);
    printf("\n");

    return 0;
}
