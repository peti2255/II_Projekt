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
    root *root1 = NULL; printf("nem megy");
    while (fscanf(input, "%lf\n", &a) != EOF)
    {

        root1 = insert(root1,a);
    }
    fclose(input);
    return root1;
}
void inorder(root *tree) {

    {
        if(tree->left)
            inorder(tree->left);
        printf("%.2lf \n", tree->time);
        if(tree->right)
            inorder(tree->right);
    }

}


