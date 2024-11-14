#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da árvore AVL
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Função para obter a altura de um nó
int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para obter o maior valor entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó na árvore
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // Novo nó é inicialmente uma folha
    return newNode;
}

// Rotação simples à direita
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Rotação simples à esquerda
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para inserir um elemento na árvore AVL
struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Caso Rotação à Direita
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Caso Rotação à Esquerda
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Caso Rotação Esquerda-Direita
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso Rotação Direita-Esquerda
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Função para encontrar o nó com o menor valor (para exclusão)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Função para excluir um elemento da árvore AVL
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // Caso Rotação à Direita
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Caso Rotação à Esquerda
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Caso Rotação Esquerda-Direita
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso Rotação Direita-Esquerda
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

// Função para buscar um elemento na árvore AVL
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

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
