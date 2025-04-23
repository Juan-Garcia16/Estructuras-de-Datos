#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct nodeTree{
    int key;
    struct nodeTree *p;
    struct nodeTree *left;
    struct nodeTree *right;
};

//devuelve el puntero a la raiz del arbol
struct nodeTree *TreeInsert(struct nodeTree *T, int k){
    struct nodeTree *z, *x, *y;
    z = (struct nodeTree *)malloc(sizeof(struct nodeTree));

    z->key = k;
    z->left = NULL;
    z->right = NULL;

    y = NULL;
    x = T;

    while (x != NULL)
    {
        y = x;
        if (z->key <  x->key)
            x = x->left;
        else
            x = x->right;   
    }

    z->p = y;
    if (y == NULL)
        T = z;
    else
    {
        if (z->key < y->key)
            y->left = z;
        else   
            y->right = z;
    }

    return T;
}

struct nodeTree *TreeMinimum(struct nodeTree *x){
    while (x->left != NULL)
        x = x->left;

    return x;
}

struct nodeTree *TreeSuccessor(struct nodeTree *x){
    struct nodeTree *y;

    if (x->right != NULL)
        return TreeMinimum(x->right);

    y = x->p;

    while ((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->p;
    }
    
    return y;
}

struct nodeTree *TreeDelete(struct nodeTree *T, struct nodeTree *z){
    struct nodeTree *x, *y;

    if ((z->left == NULL) || (z->right == NULL))
        y = z;
    else
        y = TreeSuccessor(z);

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->p = y->p;

    if (y->p == NULL)
        T = x;
    else
    {
        if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
    }

    if (y != z)
    {
        z->key = y->key;
        //Copy all information fields from y to z
    }

    free(y);

    return T;
}

void InOrderTreeWalk(struct nodeTree *x){
    if (x != NULL)
    {
        InOrderTreeWalk(x->left);
        printf("%d ", x->key);
        InOrderTreeWalk(x->right);
    }
}


struct nodeTree *TreeSearch(struct nodeTree *x, int k){
    while ((x != NULL) && (k != x->key))
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}


int main(){
    int n, element, idElement;
    long long int result;
    struct nodeTree *T = NULL, *z;

    while (scanf("%d", &n) && (n > 0))
    {
        for (idElement = 1; idElement <= n; idElement++)
        {
            scanf("%d", &element);
            T = TreeInsert(T, element);
        }

        result = 0;
        for (idElement = 1; idElement < n; idElement++)
        {
            z = TreeMinimum(T);
            element = z->key;
            T = TreeDelete(T, z);

            z = TreeMinimum(T);
            element += z->key;
            T = TreeDelete(T, z);
            result += element;
            T = TreeInsert(T, element); //element es la suma de los dos elemento smas pequenos en este momento
        }

        printf("%lld\n", result);
        free(T);
        T = NULL;
    }

    return 0;
}