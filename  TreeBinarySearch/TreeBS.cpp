#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int key;
    struct treeNode *parent;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};

void inOrderTreeWalk(struct treeNode *root) {
    if (root != NULL) {
        inOrderTreeWalk(root->leftChild);
        printf("%d ", root->key);
        inOrderTreeWalk(root->rightChild);
    }
}

struct treeNode *recursiveTreeSearch(struct treeNode *root, int k) {
    if (root == NULL || k == root->key)
        return root;

    if (k < root->key)
        return recursiveTreeSearch(root->leftChild, k);
    else
        return recursiveTreeSearch(root->rightChild, k);
}

struct treeNode *treeSearch(struct treeNode *root, int k) {
    while (root != NULL && k != root->key) {
        if (k < root->key)
            root = root->leftChild;
        else
            root = root->rightChild;
    }

    return root;
}

struct treeNode *treeMinimum(struct treeNode *root) {
    while (root->leftChild != NULL)
        root = root->leftChild;

    return root;
}

struct treeNode *treeMaximum(struct treeNode *root) {
    while (root->rightChild != NULL)
        root = root->rightChild;

    return root;
}

struct treeNode *treeSuccessor(struct treeNode *root) {
    if (root->rightChild != NULL)
        return treeMinimum(root->rightChild);

    struct treeNode *next = root->parent;

    while (next != NULL && root == next->rightChild) {
        root = next;
        next = next->parent;
    }

    return next;
}

struct treeNode *treePredecessor(struct treeNode *root) {
    if (root->leftChild != NULL)
        return treeMaximum(root->leftChild);

    struct treeNode *next = root->parent;

    while (next != NULL && root == next->leftChild) {
        root = next;
        next = next->parent;
    }

    return next;
}
