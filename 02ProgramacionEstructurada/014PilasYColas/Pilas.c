#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Inicializar una pila vacia
Node *createStack()
{
    return NULL;
}

// Verificar si la pila esta vacia
int isEmpty(Node *top)
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
    if (isEmpty(*top))
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
    if (isEmpty(top))
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

int main()
{
    Node *stack = createStack();
    int opcion, valor;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    do
    {
        printf("\n--- Menu de Pila ---\n");
        printf("1. Push (agregar elemento)\n");
        printf("2. Pop (retirar elemento)\n");
        printf("3. Peek (ver elemento en el tope)\n");
        printf("4. Imprimir todos los elementos\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Introduce el valor a agregar: ");
            scanf("%d", &valor);
            push(&stack, valor);
            break;
        case 2:
            valor = pop(&stack);
            if (valor != -1)
            {
                printf("Elemento retirado: %d\n", valor);
            }
            break;
        case 3:
            valor = peek(stack);
            if (valor != -1)
            {
                printf("Elemento en el tope: %d\n", valor);
            }
            break;
        case 4:
            printStack(stack);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida.\n");
            break;
        }
        if (opcion != 4)
        {
            printStack(stack);
        }
    } while (opcion != 5);

    return 0;
}