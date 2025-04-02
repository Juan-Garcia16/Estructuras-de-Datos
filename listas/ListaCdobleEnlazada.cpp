#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node{
    int key;
    struct node *prev;
    struct node *next;
};

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


void PrintFromFirstTolast(struct node *tail){
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

void PrintFromlastToFirst(struct node *tail){
    struct node *current, *first;
    
    if (tail == NULL)
        printf("NULL\n");
    
    else
    {
        current = tail;
        first = tail->next;
        while(current != first)
        {
            printf("%d -> ", current->key);
            current = current->prev;
        }
        printf("%d -> ...\n",current->key);
    }
}

int main(){
	
    struct node *tail = NULL;
    int operation, element;
    
    while( scanf("%d",&operation) != EOF){
        if(operation == 1){ //Insert
        
            scanf("%d", &element);
            tail = InsertElementInCircularDoublyLinkedList(tail, element);
            PrintFromFirstTolast(tail);
            PrintFromlastToFirst(tail);
        }
		else{
			
            if (operation== 2){//Delete
            
                tail = DeleteFirstNodeOfCircularDoublyLinkedList(tail);
                PrintFromFirstTolast(tail);
                PrintFromlastToFirst(tail);
            }
            else
            	printf("Bad use.\n 1.Insert\n 2.Delete\n");
        }
    }
    
    return 0;
}