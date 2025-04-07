#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node {
    int key;
    int maximum;
    int minimum;
    struct node *next;
};

struct node *push(struct node *top, int element){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    newNode->next = top;

    if (top == NULL)
    {
        newNode->maximum = element;
        newNode->minimum = element;    
    }
    else
    {
        if (element > top->maximum)
            newNode->maximum = element;
        else
            newNode->maximum = top->maximum;
        
        if (element < top->minimum)
            newNode->minimum = element;
        else
            newNode->minimum = top->minimum;
    }
    
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
    return top == NULL ? TRUE : FALSE;
}

void printStack(struct node *top){
    struct node *current = top;
    while(current != NULL) {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
}