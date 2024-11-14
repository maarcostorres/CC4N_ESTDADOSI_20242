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
struct AVLNode* createNode(int data) {
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

// Função de inserção na árvore AVL
struct AVLNode* insert(struct AVLNode* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Caso de rotação à direita
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Caso de rotação à esquerda
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Caso de rotação esquerda-direita
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso de rotação direita-esquerda
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Função para pesquisar um elemento na árvore AVL
struct AVLNode* search(struct AVLNode* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Função para encontrar o nó com o menor valor (usado para exclusão)
struct AVLNode* minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Função para excluir um elemento da árvore AVL
struct AVLNode* deleteNode(struct AVLNode* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct AVLNode* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Caso de rotação à direita
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Caso de rotação à esquerda
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Caso de rotação esquerda-direita
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso de rotação direita-esquerda
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Função para exibir a árvore em ordem (in-order)
void inOrder(struct AVLNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Função principal para testar a árvore AVL
int main() {
    struct AVLNode* root = NULL;

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
