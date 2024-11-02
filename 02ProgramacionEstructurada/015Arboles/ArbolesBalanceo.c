// Programa en C para insertar un nodo en un árbol AVL
#include <stdio.h>
#include <stdlib.h>

// Un nodo del árbol AVL
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Función auxiliar para obtener la altura del árbol
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Función auxiliar para obtener el máximo de dos enteros
int max(int a, int b)
{
    if (a > b) return a;
else return b;
}

/* Función auxiliar que asigna un nuevo nodo con la clave dada y
    punteros izquierdo y derecho en NULL. */
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)
        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // el nuevo nodo se añade inicialmente como hoja
    return (node);
}

// Función auxiliar para rotar a la derecha el subárbol con raíz en y
// Ver el diagrama dado arriba.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Realizar la rotación
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    // Devolver nueva raíz
    return x;
}

// Función auxiliar para rotar a la izquierda el subárbol con raíz en x
// Ver el diagrama dado arriba.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Realizar la rotación
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    // Devolver nueva raíz
    return y;
}

// Obtener el factor de equilibrio del nodo N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Función recursiva para insertar una clave en el subárbol con raíz
// en el nodo y devuelve la nueva raíz del subárbol.
struct Node *insert(struct Node *node, int key)
{
    /* 1. Realizar la inserción normal del BST */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // No se permiten claves iguales en el BST
        return node;

    /* 2. Actualizar la altura de este nodo ancestro */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Obtener el factor de equilibrio de este nodo ancestro
          para comprobar si este nodo se volvió
          desequilibrado */
    int balance = getBalance(node);

    // Si este nodo se vuelve desequilibrado, entonces
    // hay 4 casos

    // Caso Izquierda-Izquierda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso Derecha-Derecha
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso Izquierda-Derecha
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso Derecha-Izquierda
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* devolver el puntero al nodo (sin cambios) */
    return node;
}

// Recorrido en orden (In-Order Traversal)
void recorrerEnOrden(struct Node *root)
{
    if (root != NULL)
    {
        recorrerEnOrden(root->left);
        printf("%d ", root->key);
        recorrerEnOrden(root->right);
    }
}

// Función para imprimir el árbol con ramas simuladas
void imprimirArbol(struct Node *root, int espacio)
{
    int i;
    if (root == NULL)
        return;

    // Incrementar la distancia entre niveles
    espacio += 10;

    // Imprimir el subárbol derecho primero
    imprimirArbol(root->right, espacio);

    // Imprimir el nodo actual después de los espacios adecuados
    printf("\n");
    for (i = 5; i < espacio; i++)
        printf(" ");
    printf("h:%d - ", root->height);
    printf("%d\n", root->key);

    // Imprimir el subárbol izquierdo
    imprimirArbol(root->left, espacio);
}

/* Programa principal para probar la función anterior */
int main()
{
    struct Node *root = NULL;

    root = insert(root, 20);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 30);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 40);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 50);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 60);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 70);
    imprimirArbol(root, 0);
    printf("\n-----------------------------------\n");
    root = insert(root, 80);

    // Recorrer el árbol en orden
    printf("\nRecorrido InOrder del árbol binario: ");
    recorrerEnOrden(root);

    // Imprimir el árbol con ramas simuladas
    printf("\n\nRepresentación gráfica del árbol binario:\n");
    imprimirArbol(root, 0);

    return 0;
}