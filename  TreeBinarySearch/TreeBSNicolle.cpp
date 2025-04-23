#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int key;
    struct treeNode *parent;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

void inOrderTreeWalk(struct treeNode *x) {
    if (x != NULL) {
        inOrderTreeWalk(x->leftChild);
        printf("%d ", x->key);
        inOrderTreeWalk(x->rightChild);
    }
}

struct treeNode *recursiveTreeSearch(struct treeNode *x, int k) {
    if (x == NULL || k == x->key)
        return x;

    if (k < x->key)
        return recursiveTreeSearch(x->leftChild, k);
    else
        return recursiveTreeSearch(x->rightChild, k);
}

struct treeNode *treeSearch(struct treeNode *x, int k) {
    while (x != NULL && k != x->key) {
        if (k < x->key)
            x = x->leftChild;
        else
            x = x->rightChild;
    }

    return x;
}

struct treeNode *treeMinimum(struct treeNode *x) {
    while (x->leftChild != NULL)
        x = x->leftChild;

    return x;
}

struct treeNode *treeMaximum(struct treeNode *x) {
    while (x->rightChild != NULL)
        x = x->rightChild;

    return x;
}

struct treeNode *treeSuccessor(struct treeNode *x) {
    if (x->rightChild != NULL)
        return treeMinimum(x->rightChild);

    struct treeNode *next = x->parent;

    while (next != NULL && x == next->rightChild) {
        x = next;
        next = next->parent;
    }

    return next;
}

struct treeNode *treePredecessor(struct treeNode *x) {
    if (x->leftChild != NULL)
        return treeMaximum(x->leftChild);

    struct treeNode *next = x->parent;

    while (next != NULL && x == next->leftChild) {
        x = next;
        next = next->parent;
    }

    return next;
}
