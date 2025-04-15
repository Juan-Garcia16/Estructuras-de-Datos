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

struct node *InsertInAscendentLinkedList(struct node *head,int n){
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

struct node *DeleteElementOfAscendentLinkedList(struct node *head, int element){
    struct node *previous, *current;
    if (head == NULL)
        printf("The linked list is empty.\n");
    else
    {
        if (element < head->key)
            printf("The %d is not in linked list\n", element);
        else
        {
            if (element == head->key)
            {
                current = head;
                head = head->next;
                free(current);
            }
            else
            {
                current = head->next;
                previous = head;

                while ((current != NULL) && (element > current->key))
                {
                    previous = current;
                    current = current->next;
                }
                if (current == NULL)
                    printf("The %d is not in linked list\n", element);
                else
                {
                    if (element == current->key)
                    {
                        previous->next = current->next;
                        free(current);
                    }
                    else
                        printf("The %d is not in linked list\n", element);
                }    
            }
        }
    }
    return head;   
}



int main(){
    int element, operation; 
    struct node *head = NULL;
    while(scanf("%d %d", &operation, &element) != EOF)
    {
        if(operation == 1) //insert
        {
            head = InsertInAscendentLinkedList(head, element);
            printLinkedList(head);
        }
        else
        {
            if (operation == 2) //Delete
            {
                head = DeleteElementOfAscendentLinkedList(head, element);
                printLinkedList(head);
            }
            else
                printf("Bad use \n 1.Insert\n 2.Delete\n")
;            
        }
    }
    return 0; // Fin del programa
}