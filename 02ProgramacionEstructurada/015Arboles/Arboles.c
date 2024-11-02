#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

// Función para crear un nuevo nodo
struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recorrido en orden (In-Order Traversal)
void traverseInOrder(struct Node *root)
{
    if (root != NULL)
    {
        traverseInOrder(root->left);
        printf("%d ", root->value);
        traverseInOrder(root->right);
    }
}

// Insertar un nodo en el árbol binario
struct Node *insert(struct Node *node, int value)
{
    // Si el árbol está vacío, devuelve un nuevo nodo
    if (node == NULL)
    {
        return newNode(value);
    }

    // De otro modo, recorre el árbol
    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

// Función para imprimir el árbol con ramas simuladas
void printTree(struct Node *root, int space)
{
    int i;
    if (root == NULL)
        return;

    // Incrementar la distancia entre niveles
    space += 5;

    // Imprimir el subárbol derecho primero
    printTree(root->right, space);

    // Imprimir el nodo actual después de los espacios adecuados
    printf("\n");
    for (i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    // Imprimir el subárbol izquierdo
    printTree(root->left, space);
}

int main()
{
    struct Node *root = NULL;

    // Insertar nodos en el árbol
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);

    // Recorrer el árbol en orden
    printf("Recorrido InOrder del árbol binario: ");
    traverseInOrder(root);

    // Imprimir el árbol con ramas simuladas
    printf("\n\nRepresentación gráfica del árbol binario:\n");
    printTree(root, 0);

    return 0;
}