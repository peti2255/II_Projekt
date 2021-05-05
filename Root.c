//
// Created by petee on 4/26/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "Root.h"
root *createroot(double data)
{
    root* node = (root*)malloc(sizeof (root));
    if(!node)
    {
        printf("Sikertelen lefoglalas");
        exit(1);
    }
    node->time = data;
    node->right = NULL;
    node->left = NULL;

    return node;
}
root *insert(root *tree, double data) {
    if(tree == NULL)
    {
        return createroot(data);
    }
    else
    {
        if(tree->time > data)
            tree->left =  insert(tree->left,data);
        else tree->right = insert(tree->right,data);
    }
    return tree;
}

root* readtime(const char *file) {
    FILE *input = fopen(file, "r");
    if (!input) {
        printf("Sikertelen");
        exit(1);

    }
    double a;
    root *root1 = NULL;
    while (fscanf(input, "%lf\n", &a) != EOF)
    {

        root1 = insert(root1,a);
    }
    fclose(input);
    return root1;
}
void inorder(root *tree) {
        if(tree->left)
            inorder(tree->left);
        printf("%.2lf \n", tree->time);
        if(tree->right)
            inorder(tree->right);

}

void destroyroot(root *tree) {
    free(tree->right);
    free(tree->left);
    free(tree);
    printf("Felszabaditva");
}

root *delete(root *tree, int data) {
    if(tree==NULL){
        printf("Nem lehetseges a torles.\n");
        return tree;
    }
    if(tree->time>data){
        tree->left=delete(tree->left,data);
    }
    else if(tree->time<data){
        tree->right=delete(tree->right,data);
    }
    else{
        if(tree->left==NULL){
            struct root* temp=tree->right;
            free(tree);
            return temp;
        }
        else if(tree->right==NULL){
            struct root* temp=tree->left;
            free(tree);
            return temp;
        }
        struct root* temp=minValueNode(tree->right);
        tree->time=temp->time;
        tree->right=delete(tree->right,temp->time);
    }
    return tree;
}
struct root *minValueNode(struct root *pRoot) {
    struct root* current = pRoot;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

int find(root *tree, double data) {
    if (tree == NULL) {
        return 0;
    }
    if (data == tree->time) {
        return 1;
    } else {
        if (data < tree->time)
            find(tree->left, data);
        else find(tree->right, data);
    }

    return -1;
}

double findMinforN(root* root, int N)
{
    if (root->left == NULL && root->right == NULL && root->time < N)
        return -1;
    if ((root->time >= N && root->left == NULL) || (root->time >= N && root->left->time < N))
        return root->time;
    if (root->time <= N)
        return findMinforN(root->right, N);
    else
        return findMinforN(root->left, N);
}


