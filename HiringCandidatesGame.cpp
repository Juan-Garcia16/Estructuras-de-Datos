#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura de un nodo para lista circular doblemente enlazada
struct node{
    int key;
    struct node *prev;
    struct node *next;
};

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


struct node *InsertElementInCircularDoublyLinkedList(struct node *tail, int element){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof (struct node)); 
    newNode->key = element;
    
    if (tail == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    
    else
    {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next->prev = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *DeleteFirstNodeOfCircularDoublyLinkedList(struct node *tail){
    struct node *firstNode;
    
    if (tail == NULL)
        printf("The circular doubly linked list is empty.\n");

    else
    {
        if(tail == tail->next)
        {
            free(tail);
            tail = NULL;
        }
        else
        {
            firstNode = tail->next;
            tail->next = firstNode->next;
            firstNode->next->prev = tail;
            free(firstNode);
        }
    }
    return tail;
}

void printLinkedList(struct node *head){
    struct node *current = head;

    while(current != NULL) // Mientras no lleguemos al final de la lista
    {
        printf("%d ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }
    printf("\n"); // Indicamos el final de la lista
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
    int n, r, c, i, indexR, indexC;
    struct node *tail = NULL, *s1, *s2, *head = NULL;

    while(scanf("%d %d %d", &n, &r, &c) != EOF)
    {
        for (i = 1; i <= n; i++)
            tail = InsertElementInCircularDoublyLinkedList(tail, i);

        s1 = tail->next;
        s2 = tail;

        while (n > 2)
        {
            for (indexR = 1; indexR < r; indexR++)
                s1 = s1->next;

            for (indexC = 1; indexC < c; indexC++)
                s2 = s2->prev;
            
            if ((s1->next == s2) && (s2->prev == s1)) // nodos seguidos, con s1 atras de s2
            {
                s2 = s2->prev->prev;   
                tail = s2;
                s1 = s1->next->next;
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
                n -= 2;
            }
            else if (s1 == s2) // mismo nodo
            {
                head = InsertInAscendentLinkedList(head, s1->key);
                s2 = s2->prev;
                s1 = s1->next;
                tail = s2;
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
                n--;
            }
            else
            {
                s2 = s2->prev;
                tail = s2;
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);

                tail = s1->prev;
                s1 = s1->next;
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
                
                n -= 2;
            }

            tail = s1; // para facilitar la eliminacion de la lista circular
        }

        while (tail != NULL)
        {
            head = InsertInAscendentLinkedList(head, tail->next->key);
            tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
        }

        printLinkedList(head);
        head = deleteLinkedList(head);

    }
    return 0;
}
