#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[20];
    int priority;
} vaccine;

int main(){
    vaccine person, dates[5];
    char name[21];
    int priority;

    for (int i = 0; i < 5; i++)
    {
        scanf("%20s", name);
        scanf("%d", &dates[i].priority);
        strcpy(dates[i].name, name);
    }

    for (int i = 0; i < 5; i++)
    {
        
        printf("%s", dates[i].name);
        printf("%d", dates[i].priority);
    }
    
    return 0;
}