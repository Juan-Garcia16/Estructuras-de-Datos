#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node {
    int key;             // Campo que almacena el valor del nodo
    struct node *next;   // Puntero que apunta al siguiente nodo en la lista
};

struct node *push(struct node *top, int element){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->key = element;
    newNode->next = top;
    top = newNode;

    return top;
}

int pop(struct node **top){
    struct node *currentNode;
    int element;

    currentNode = *top;
    element = currentNode->key;
    *top = currentNode->next;
    free(currentNode);

    return element;
}

int stackEmpty(struct node *top){
    return top == NULL?TRUE:FALSE;
}

void printStack(struct node *top){
    struct node *current = top;

    while(current != NULL) // Mientras no lleguemos al final de la lista
    {
        printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }
    printf("NULL\n"); // Indicamos el final de la lista

}

int main(){
    struct node *top = NULL;
    int operation, element;

    while(scanf("%d", &operation) != EOF)
    {
        if(operation == 1) //push
        {
            scanf ("%d", &element);
            top = push(top, element);
            printStack(top);
        }
        else
        {
            if (operation == 2) //pop
            {
                if(!stackEmpty(top))
                {
                    element  = pop(&top);
                    printf("Elemento: %d\n", element);
                    printStack(top);
                }
                else
                    printf("The stack is empty\n");
            }   
            else
                printf("Bad use.\n 1.Push\n 2.Pop\n");
            
        }
        
    }

    return 0;
}