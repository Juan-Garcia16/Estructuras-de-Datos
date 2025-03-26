/*Ejercicio 2:
Hacer un programa en Lenguaje C/C++ que permita trabajar con listas ordenadas de forma ascendente, para
lo cual el programa debe tener:

1. Una función que permita insertar un elemento en una lista que está ordenada de forma ascendente, la
lista obviamente debe seguir conteniendo sus elementos en orden ascendente después de la inserción del
elemento. El prototipo de la función tiene que ser el siguiente, recibir como parámetros el puntero a la
cabeza de la lista y el número entero a insertar, y devolver el puntero a la cabeza de la lista.
2. Una función para imprimir el contenido de la lista, para lo cual la función tiene que recibir un puntero
a la cabeza de la lista.
3. Una función que permita borrar la primera ocurrencia de un elemento en una lista que está ordenada de
forma ascendente, la lista obviamente seguirá conteniendo sus elementos en orden ascendente después del
borrado del elemento. El prototipo de la función tiene que ser el siguiente, recibir como parámetros el
puntero a la cabeza de la lista y el número entero a borrar, y devolver el puntero a la cabeza de la lista.
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node
{
    int key;            
    struct node *next;   
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

struct node *insertInAscendentLinkedList(struct node *head,int n){
    struct node *newNode, *current, *previous;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = n;

    if(head == NULL) //caso en el que la lista este vacia
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        if(newNode->key <= head->key)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            previous = head;
            current = head->next;
            while (current != NULL && (n > current->key))// si current queda apuntando a null, significa que el elemento quedaria de ultimo
            {
                previous = current;
                current = current->next;
            }
            
            newNode->next = current;
            previous->next = newNode;
        }
    }

    return head;
}


int main(){
    int n, operation; 
    struct node *head = NULL;

    while(scanf("%d %d", &operation, &n) != EOF)
    {
        if(operation == 1) //insert
        {
            head = insertInAscendentLinkedList(head, n);
            printLinkedList(head);
        }
    }
    return 0; // Fin del programa
}