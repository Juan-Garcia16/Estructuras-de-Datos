#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node
{
    int key;            
    struct node *next;   
};

struct node *makeLinkedList(int n)
{
    struct node *head = NULL, *newNode;
    while (n >= 1) // Mientras n sea mayor o igual a 1
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = n;   // Se asigna el valor actual de n al campo 'key' del nodo
        newNode->next = head; // El nuevo nodo apunta al nodo actual de la cabeza
        head = newNode;     // La cabeza de la lista ahora es el nuevo nodo
        n--;                // Se decrementa n para continuar con el siguiente número
    }

    return head;
};

void printLinkedList(struct node *head){
    struct node *current = head;

    while(current != NULL) // Mientras no lleguemos al final de la lista
    {
        printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }
    printf("NULL\n"); // Indicamos el final de la lista

}

struct node *deleteLinkedList(struct node *head){
    struct node *current;

    while (head != NULL) // Mientras la cabeza no sea NULL
    {
        current = head;      // Guardamos la referencia al nodo actual
        head = head->next;   // Avanzamos la cabeza al siguiente nodo
        free(current);       // Liberamos la memoria del nodo actual
    }

    return head;
}


int main(){
    int n = 100; 
    struct node *head;

    head = makeLinkedList(n);
    printLinkedList(head);
    head = deleteLinkedList(head);
    printLinkedList(head);
    
    return 0; // Fin del programa
}