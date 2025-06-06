#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define RED 1
#define BLACK 0
#define NILKey -2147483647

struct nodeRBTree{
    int key;
    int color;
    struct nodeRBTree *p;
    struct nodeRBTree *left;
    struct nodeRBTree *right;
};

struct nodeRBTree  *LeftRotate(struct nodeRBTree *T, struct nodeRBTree *x){
    struct nodeRBTree *y;

    y = x->right;
    x->right = y->left;
    y->left->p = x;
    y->p = x->p;
    if (x->p->key == NILKey)
        T = y;
    else
    {
        if(x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
    }
    y->left = x;
    x->p = y;

    return T;
} 

struct nodeRBTree *RightRotate(struct nodeRBTree *T, struct nodeRBTree *x){
    struct nodeRBTree *y;
    
    y = x->left;
    x->left = y->right;
    y->right->p = x;
    y->p = x->p;
    if(x->p->key == NILKey)
        T = y;
    else
    {
        if(x == x->p->right)
            x->p->right = y;
        else
            x->p->left = y;
    }
    y->right = x;
    x->p = y;

    return T;
}

struct nodeRBTree *AssignNilleaf(){
    struct nodeRBTree *w;
    w = (struct nodeRBTree *)malloc(sizeof(struct nodeRBTree));
    w->color = BLACK;
    w->key = NILKey;
    w->left = NULL;
    w->right = NULL;

    return w;
}

struct nodeRBTree *RB_InsertFixup(struct nodeRBTree *T, struct nodeRBTree *z){
    struct nodeRBTree *y;

    while (z->p->color == RED)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    T = LeftRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                T = RightRotate(T, z->p->p);
            }
        }
        else
        {
            y = z->p->p->left;
            if (y->color == RED)
            {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    T = RightRotate(T, z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                T = LeftRotate(T, z->p->p);
            }   
        }
    }
    
    T->color = BLACK;
    return T;
}

//devuelve el puntero a la raiz del arbol
struct nodeRBTree *RB_Insert(struct nodeRBTree *T, int k){
    struct nodeRBTree *z, *x, *y;
    z = (struct nodeRBTree *)malloc(sizeof(struct nodeRBTree));
    z->key = k;
    z->left = AssignNilleaf();
    z->right = AssignNilleaf();
    z->right->p = z;
    if (T->key != NILKey)
        y = T->p;
    else
        y = T;
    x = T;

    while (x->key != NILKey)
    {
        y = x;
        if (z->key <  x->key)
            x = x->left;
        else
            x = x->right;   
    }

    z->p = y;
    if (y->key == NILKey)
        T = z;
    else
    {
        free(x);
        if (z->key < y->key)
            y->left = z;
        else   
            y->right = z;
    }

    return T;
}

struct nodeRBTree *TreeMinimum(struct nodeRBTree *x){
    while (x->left->key != NILKey)
        x = x->left;

    return x;
}

struct nodeRBTree *TreeSuccessor(struct nodeRBTree *x){
    struct nodeRBTree *y;

    if (x->right->key != NILKey)
        return TreeMinimum(x->right);

    y = x->p;
    while ((y->key != NILKey) && (x == y->right))
    {
        x = y;
        y = y->p;
    }
    
    return y;
}

struct nodeRBTree *RB_DeleteFixup(struct nodeRBTree *T, struct nodeRBTree *x){
    struct nodeRBTree *w;

    while ((x != T) && (x->color == BLACK))
    {
        if(x == x->p->left)
        {
            w = x->p->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                T = LeftRotate(T, x->p);
                w = x->p->right;
            }
            if ((w->left->color == BLACK) && (w->right->color == BLACK))
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if(w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    T = RightRotate(T, w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                w->p->color = BLACK;
                w->right->color = BLACK;
                T = LeftRotate(T, x->p);
                x = T;
            }
        }
        else
        {
            w =x->p->left;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->p->color = RED;
                T = RightRotate(T, x->p);
                w = x->p->left;
            }
            if ((w->right->color == BLACK) && (w->left->color == BLACK))
            {
                w->color = RED;
                x = x->p;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    T = LeftRotate(T, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                w->p->color = BLACK;
                w->left->color = BLACK;
                T = RightRotate(T, x->p);
                x = T; 
            }    
        }
    }
    
    x->color = BLACK;
    return T;
}

struct nodeRBTree *RB_Delete(struct nodeRBTree *T, struct nodeRBTree *z){
    struct nodeRBTree *x, *y;

    if ((z->left->key == NILKey) || (z->right->key == NILKey))
        y = z;
    else
        y = TreeSuccessor(z);

    if (y->left->key != NILKey)
        x = y->left;
    else
        x = y->right;

    x->p = y->p;

    if (y->p->key == NILKey)
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

    if(y->color == BLACK)
        T = RB_DeleteFixup(T, x);
    if(y == y->left->p)
        free(y->left);
    if(y == y->right->p)
        free(y->right);

    free(y);
    return T;
}

void InOrderTreeWalk(struct nodeRBTree *x){
    if (x->key != NILKey)
    {
        InOrderTreeWalk(x->left);
        if(x->color == RED)
            printf("(%d, RED) ", x->key);
        else
            printf("(%d, BLACK) ", x->key);
        InOrderTreeWalk(x->right);
    }
}


struct nodeRBTree *TreeSearch(struct nodeRBTree *x, int k){
    while ((x->key != NILKey) && (k != x->key))
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

int main(){
    int operation, element;
    struct nodeRBTree *T = AssignNilleaf(), *z;

    while(scanf("%d %d", &operation, &element))
    {
        if (operation == 1)
        {
            T = RB_Insert(T, element);
            InOrderTreeWalk(T);
            printf("\n");
            printf("Root[T]: (%d, ", T->key);
            if(T->color == RED)
                printf("RED)\n");
            else
                printf("BLACK)\n");
        }
        else
        {
            if (operation == 2)
            {
                z = TreeSearch(T, element);
                if (z->key == NILKey)
                {
                    printf("The % is not in RB-Tree. \n", element);
                    InOrderTreeWalk(T);
                    printf("\n");
                    if(T->key == NILKey)
                        printf("Root[T]: (NILKey), ");
                    else
                        printf("Root[T]: (%d, ", T->key);
                    if(T->color == RED)
                        printf("RED)\n");
                    else
                        printf("BLACK)\n");
                }
                else
                {
                    T = RB_Delete(T, z);
                    InOrderTreeWalk(T);
                    printf("\n");
                    if(T->key  == NILKey)
                        printf("Root[T]: (NILKey, ");
                    else
                        printf("Root[T]: (%d, ", T->key);
                    if(T->color == RED)
                        printf("RED)\n");
                    else   
                        printf("BLACK)\n");
                }
            }
            else
                printf("BLACK)\n");
        }
    }

    return 0;
}