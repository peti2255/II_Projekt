//
// Created by petee on 4/30/2021.
//

#ifndef II_PROJEKT_LANCOLT_LISTA_H
#define II_PROJEKT_LANCOLT_LISTA_H

#include <stdbool.h>
#include "Track.h"

typedef struct {
    struct Track* data;
    struct Node* next;
} Node;

Node* createe();

void inserte(Node** front, Track* data, int index);
void traverse(Node* front);
void destroyss(Node* front);
int* statistics(Node* front);
int getKthDigit(Node* front, int k, int currPos);
int listLength(Node* front, int size);
Node * readTrack(const char *file);
#endif //II_PROJEKT_LANCOLT_LISTA_H
