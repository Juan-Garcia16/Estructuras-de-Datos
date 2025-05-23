#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXN 100000
#define RED 1
#define BLACK 0
#define NILKey "zzzzzzzzzz"
#define MAXS 15

struct nodeRBTree
{
    char key[MAXS];
    int color;
    int position;
    struct nodeRBTree *left;
    struct nodeRBTree *right;
    struct nodeRBTree *p;
};

void InorderTreeWalk(struct nodeRBTree *x)
{
    if (strcmp(x->key, NILKey) != 0)
    {
        InorderTreeWalk(x->left);
        if (x->color == BLACK)
            printf("( %s, %d BLACK ) ", x->key, x->position);
        else
            printf("( %s, %d RED ) ", x->key, x->position);
        InorderTreeWalk(x->right);
    }
}

struct nodeRBTree *TreeSearch(struct nodeRBTree *x, char kName[])
{
    while ((strcmp(x->key, NILKey) != 0) && (strcmp(kName, x->key) != 0))
    {
        if (strcmp(kName, x->key) < 0)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

struct nodeRBTree *TreeMinimum(struct nodeRBTree *x)
{
    while (strcmp(x->left->key, NILKey) != 0)
        x = x->left;
    return x;
}

struct nodeRBTree *TreeMaximum(struct nodeRBTree *x)
{
    while (strcmp(x->right->key, NILKey) != 0)
        x = x->right;
    return x;
}

struct nodeRBTree *TreeSuccessor(struct nodeRBTree *x)
{
    struct nodeRBTree *y;
    if (strcmp(x->right->key, NILKey) != 0)
        return TreeMinimum(x->right);
    y = x->p;
    while ((strcmp(y->key, NILKey) != 0) && (x == y->right))
    {
        x = y;
        y = y->p;
    }
    return y;
}

struct nodeRBTree *TreePredecessor(struct nodeRBTree *x)
{
    struct nodeRBTree *y;
    if (strcmp(x->left->key, NILKey) != 0)
        return TreeMaximum(x->left);
    y = x->p;
    while ((strcmp(y->key, NILKey) != 0) && (x == y->left))
    {
        x = y;
        y = y->p;
    }
    return y;
}

struct nodeRBTree *LeftRotate(struct nodeRBTree *T, struct nodeRBTree *x)
{
    struct nodeRBTree *y;
    y = x->right;
    x->right = y->left;
    y->left->p = x;
    y->p = x->p;
    if (strcmp(x->p->key, NILKey) == 0)
        T = y;
    else
    {
        if (x == x->p->left)
            x->p->left = y;
        else
            x->p->right = y;
    }
    y->left = x;
    x->p = y;
    return T;
}

struct nodeRBTree *RightRotate(struct nodeRBTree *T, struct nodeRBTree *x)
{
    struct nodeRBTree *y;
    y = x->left;
    x->left = y->right;
    y->right->p = x;
    y->p = x->p;
    if (strcmp(x->p->key, NILKey) == 0)
        T = y;
    else
    {
        if (x == x->p->right)
            x->p->right = y;
        else
            x->p->left = y;
    }
    y->right = x;
    x->p = y;
    return T;
}

struct nodeRBTree *AssignNilLeaf()
{
    struct nodeRBTree *w;
    w = (struct nodeRBTree *)malloc(sizeof(struct nodeRBTree));
    w->color = BLACK;
    strcpy(w->key, NILKey);
    w->position = -1;
    w->left = NULL;
    w->right = NULL;
    return w;
}

struct nodeRBTree *RB_InsertFixup(struct nodeRBTree *T, struct nodeRBTree *z)
{
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

struct nodeRBTree *RB_Insert(struct nodeRBTree *T, char kName[], int position)
{
    struct nodeRBTree *x, *y, *z;
    z = (struct nodeRBTree *)malloc(sizeof(struct nodeRBTree));
    z->color = RED;
    strcpy(z->key, kName);
    z->position = position;
    z->left = AssignNilLeaf();
    z->left->p = z;
    z->right = AssignNilLeaf();
    z->right->p = z;

    
    if (strcmp(T->key, NILKey) != 0)
        y = T->p;
    else
        y = T;
    x = T;
    while (strcmp(x->key, NILKey) != 0)
    {
        y = x;
        if (strcmp(z->key, x->key) < 0)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (strcmp(y->key, NILKey) == 0)
        T = z; /* Empty tree . */
    else
    {
        free(x);
        if (strcmp(z->key, y->key) < 0)
            y->left = z;
        else
            y->right = z;
    }
    T = RB_InsertFixup(T, z);
    return T;
}

struct nodeRBTree *RB_DeleteFixup(struct nodeRBTree *T, struct nodeRBTree *x)
{
    struct nodeRBTree *w;
    while ((x != T) && (x->color == BLACK))
    {
        if (x == x->p->left)
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
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    T = RightRotate(T, w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                T = LeftRotate(T, x->p);
                x = T;
            }
        }
        else
        {
            w = x->p->left;
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
                x->p->color = BLACK;
                w->left->color = BLACK;
                T = RightRotate(T, x->p);
                x = T;
            }
        }
    }
    x->color = BLACK;
    return T;
}

struct nodeRBTree *RB_Delete(struct nodeRBTree *T, struct nodeRBTree *z)
{
    struct nodeRBTree *x, *y;
    if ((strcmp(z->left->key, NILKey) == 0) || (strcmp(z->right->key, NILKey) == 0))
        y = z;
    else
        y = TreeSuccessor(z);
    if (strcmp(y->left->key, NILKey) != 0)
        x = y->left;
    else
        x = y->right;
    x->p = y->p;
    if (strcmp(y->p->key, NILKey) == 0)
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
        strcpy(z->key, y->key);
        z->position = y->position;
        /* Copy all information fields from y to z. */
    }
    if (y->color == BLACK)
        T = RB_DeleteFixup(T, x);
    if (y == y->left->p)
        free(y->left);
    if (y == y->right->p)
        free(y->right);
    free(y);
    return T;
}