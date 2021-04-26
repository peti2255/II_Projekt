//
// Created by petee on 4/26/2021.
//

#ifndef II_PROJEKT_ROOT_H
#define II_PROJEKT_ROOT_H

#include "Track.h"

typedef struct root
{
    double time;
    struct root *left;
    struct root *right;
}root;
root *createroot(double data);
void destroy(root ** tree);
struct root * readtime(const char* file);
root* insert(root *tree, double data);
root* delete(root *tree,int data);
root *find(root *tree,int data);
void inorder(root *tree);
#endif //II_PROJEKT_ROOT_H
