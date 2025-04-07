#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Definición de la estructura de un nodo
struct node {
    int key;             // Almacena el valor del nodo
    struct node *next;   // Puntero que apunta al siguiente nodo en la pila
};

struct node *enqueue(struct node *tail, int element){ // Agrega un elemento a la cola (encolar)
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->key = element;
    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

int dequeue(struct node **tail){ // Elimina un elemento de la cola (desencolar), el primer elemento de la cola, doble puntero para modificar el puntero original
    struct node *firstNode;
    int element;

    if (*tail == (*tail)->next) //si la cola solo tiene un solo nodo, no se deben quitar los parentesis, obliga que primero se aplique lo del parentesis
    {
        element = (*tail)->key;
        free(*tail);
        *tail = NULL;
    }
    else
    {
        firstNode = (*tail)->next;
        element = firstNode->key;
        (*tail)->next = firstNode->next;
        free(firstNode);
    }

    return element;
}

int queueEmpty(struct node *tail){
    return tail == NULL ? TRUE : FALSE; // Retorna 1 si la cola está vacía, 0 en caso contrario
}

void printQueue(struct node *tail){
    struct node *currentNode;
    if (tail == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        currentNode = tail->next; // Comenzamos desde el primer nodo
        while (currentNode != tail)
        {
            printf("%d -> ", currentNode->key); // Imprimimos el valor del nodo actual
            currentNode = currentNode->next;        // Avanzamos al siguiente nodo
        }
        printf("%d -> \n", tail->key);
    }
}

int main(){
    struct node *tail = NULL; // Inicializamos la cola como vacía
    int operation, element; // Variables para la operación y el elemento a insertar/eliminar

    while (scanf("%d", &operation) != EOF)
    {
        if (operation == 1) // Operación de enqueue, encolar un elemento (insertar)
        {
            scanf("%d", &element); // Leer el elemento a insertar
            tail = enqueue(tail, element); // Insertar el elemento en la cola
            printQueue(tail); // Imprimir el estado actual de la cola
        }
        else if (operation == 2) // Operación de dequeue, eliminar el primer elemento de la cola
        {
            if(!queueEmpty(tail))// Verificamos si la cola no está vacía
            {
                element = dequeue(&tail); // Eliminar el primer elemento
                printf("Element: %d\n", element); // Imprimir el elemento eliminado
                printQueue(tail); // Imprimir el estado actual de la cola
            }
            else
            {
                printf("The queue is empty\n"); // Mensaje si la cola está vacía
            }
        }
        else
        {
            printf("Bad use.\n 1.Enqueue\n 2.Dequeue\n"); // Mensaje de error para operaciones inválidas   
        }
    }
    return 0;
}
