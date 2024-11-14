#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Node *createStack();
Queue *createQueue();
int estaVisitado(int listaVisitados[10], int numero);
int isEmpty(Queue *q);
int isEmptyPila(Node *top);
void push(Node **top, int data);
int pop(Node **top);
int peek(Node *top);
void printStack(Node *stack);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int front(Queue *q);
int *bfs(int grafo[5][5]);
int *dfs(int grafo[5][5]);
void impGrafoMatriz(int grafo[5][5]);
void impGrafoLista(int grafo[5][5]);

int main()
{
    int grafo[5][5] = {
        /*0*/ {0, 1, 0, 1, 1},
        /*1*/ {1, 0, 1, 1, 0},
        /*2*/ {0, 1, 0, 1, 0},
        /*3*/ {1, 1, 1, 0, 0},
        /*4*/ {1, 0, 0, 0, 0}
    };

    printf("Matriz de adyacencia:\n");
    impGrafoMatriz(grafo);
    printf("\n\n");
    printf("Lista de adyacencia:\n");
    impGrafoLista(grafo);

    int *recorridoBFS;
    int *recorridoDFS;

    recorridoBFS = bfs(grafo);

    printf("Recorrido BFS: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", recorridoBFS[i]);
    }

    recorridoDFS = dfs(grafo);

    printf("\nRecorrido DFS: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", recorridoDFS[i]);
    }

    return 0;
}

Node *createStack()
{
    return NULL;
}

// Inicializar una cola vacia
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Verificar si la cola esta vacia
int isEmpty(Queue *q)
{
    return q->front == NULL;
}

int isEmptyPila(Node *top)
{
    return top == NULL;
}

// Insertar un elemento en la pila (push)
void push(Node **top, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Eliminar un elemento de la pila (pop)
int pop(Node **top)
{
    if (isEmptyPila(*top))
    {
        printf("Pila vacia\n");
        return -1;
    }
    Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Ver el valor en el tope (peek)
int peek(Node *top)
{
    if (isEmptyPila(top))
    {
        printf("Pila vacia\n");
        return -1;
    }
    return top->data;
}

// Funcion para imprimir todos los elementos de la pila
void printStack(Node *stack)
{
    if (stack == NULL)
    {
        printf("Pila vacia.\n");
        return;
    }
    Node *current = stack;
    printf("Elementos en la pila: ");
    while (current != NULL)
    {
        printf("| Current:%p Data: %d Next: %p |", current, current->data, current->next);
        current = current->next;
    }
    printf("\n");
}

// Insertar un elemento en la cola (enqueue)
void enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Eliminar un elemento de la cola (dequeue)
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Cola vacia\n");
        return -1;
    }

    Node *temp = q->front;
    int dequeued = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return dequeued;
}

// Ver el valor en el frente (front)
int front(Queue *q)
{
    if (isEmpty(q))
    {
        //printf("Cola vacia\n");
        return -1;
    }
    return q->front->data;
}

int *bfs(int grafo[5][5])
{
    Queue *cola = createQueue();

    int *recorrido = (int *)malloc(5 * sizeof(int));
    if (recorrido == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Handle memory allocation failure
    };

    int visited[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int nodo = 0;
    int i = 0;

    enqueue(cola, nodo);

    do
    {
        for (int i = 0; i < 5; i++)
        {
            int nodoVisitado = estaVisitado(visited, nodo);
            if (grafo[nodo][i] == 1 && nodoVisitado != 1)
            {
                int visitado = estaVisitado(visited, i);

                if (visitado != 1)
                {
                    enqueue(cola, i);
                }
            }
        }

        visited[i] = dequeue(cola);
        i++;
        nodo = front(cola);

    } while (!isEmpty(cola));

    for (int i = 0; i < 6; i++)
    {
        recorrido[i] = visited[i];
    }

    return recorrido;
}

int *dfs(int grafo[5][5])
{
    Node *stack = createStack();
    int visited[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int *recorrido = (int *)malloc(5 * sizeof(int));
    int node = 0;
    int x = 0;

    push(&stack, node);
    visited[0] = node;

    do
    {
        int totalAdyacencias = 0;
        int totalAdyacenciasVisitadas = 0;

        for (int i = 0; i < 5; i++)
        {
            if (grafo[node][i] == 1)
            {
                totalAdyacencias++;
            }

            if (grafo[node][i] == 1 && estaVisitado(visited, i) == 1)
            {
                totalAdyacenciasVisitadas++;
            }
        }

        if (totalAdyacencias == totalAdyacenciasVisitadas)
        {
            node = pop(&stack);
        }

        for (int i = 0; i < 5; i++)
        {
            if (grafo[node][i] == 1 && estaVisitado(visited, i) != 1)
            {
                push(&stack, i);
                x++;
                visited[x] = i;
                node = peek(stack);
                break;
            }
        }

    } while (stack != NULL);

    for (int i = 0; i < 5; i++)
    {
        recorrido[i] = visited[i];
    }

    return recorrido;
}

void impGrafoMatriz(int grafo[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            for (int k = 0; k < 6; k++)
            {
                printf("%d ", k);
            }
        }
        printf("\n");
        printf("%d|", i);
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", grafo[i][j]);
        }
    }
}

void impGrafoLista(int grafo[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d", i);
        for (int j = 0; j < 5; j++)
        {
            if (grafo[i][j] == 1)
            {
                printf(" -> %d", j);
            }
        }
        printf("\n");
    }
}

int estaVisitado(int listaVisitados[10], int numero)
{
    int respuesta = 0;

    for (int j = 0; j < 10; j++)
    {
        if (listaVisitados[j] == numero)
        {
            respuesta = 1;
        }
    }

    return respuesta;
}