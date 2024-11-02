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
        printf("Cola vacia\n");
        return -1;
    }
    return q->front->data;
}

// Función para imprimir todos los elementos de la cola
void printQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("Cola vacia.\n");
        return;
    }
    Node *current = q->front;
    printf("Elementos en la cola: ");
    while (current != NULL)
    {
        printf("| Current:%p Data: %d Next: %p |", current, current->data, current->next);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Queue *q = createQueue();
    int opcion, valor;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    do
    {
        printf("\n--- Menu de Cola ---\n");
        printf("1. Enqueue (agregar elemento)\n");
        printf("2. Dequeue (retirar elemento)\n");
        printf("3. Front (ver elemento en el frente)\n");
        printf("4. Imprimir todos los elementos\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Introduce el valor a agregar: ");
            scanf("%d", &valor);
            enqueue(q, valor);
            break;
        case 2:
            valor = dequeue(q);
            if (valor != -1)
            {
                printf("Elemento retirado: %d\n", valor);
            }
            break;
        case 3:
            valor = front(q);
            if (valor != -1)
            {
                printf("Elemento en el frente: %d\n", valor);
            }
            break;
        case 4:
            printQueue(q);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no valida.\n");
            break;
        }
        if (opcion != 4)
        {
            printQueue(q);
        }

    } while (opcion != 5);

    return 0;
}