#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
    int key;
    struct node *next;
};

struct node *InsertElementInCircularLinkedList(struct node *tail, int element){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof (struct node)); 
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

struct node *DeleteFirstNodeOfCircularLinkedList(struct node *tail){
    struct node *firstNode;
    
    if (tail == NULL)
        printf("The circular linked list is empty.\n");

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
            free(firstNode);
        }
    }
    
    return tail;
}

void PrintCircularLinkedList(struct node *tail){
    struct node *current;
    
    if (tail == NULL)
        printf("NULL\n");
    
    else
    {
        current = tail->next;
        
        while(current != tail)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }
        
        printf("%d -> ...\n",current->key);
    }
}

int solver(int n, int k){
    struct node *tail = NULL;
    int i, j, result;

    //se crea lista circular desde 1 hasta n, tail queda en el ultimo
    for (i = 1; i <= n; i++)
        tail = InsertElementInCircularLinkedList(tail, i); 

    //eliminar el tail->next de la logica
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < k; j++)
            tail = tail->next;
            
        tail = DeleteFirstNodeOfCircularLinkedList(tail);
    }

    result = tail->key;
    free(tail);
    return result;
}

int main(){    
    int n, k;
    
    while( scanf("%d %d", &n, &k) && n > 0)
        printf("%d\n", solver(n, k));
    
    return 0;
}
