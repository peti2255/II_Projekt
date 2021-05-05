//
// Created by petee on 4/30/2021.
//

#include "Lancolt_lista.h"
#include <stdlib.h>
#include <stdio.h>

Node* createe() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));

    if(!newNode) {
        printf("Error while allocating newNode!");
        return NULL;
    }

    newNode->next = NULL;
    return newNode;
}

void inserte(Node** front, Track* data, int index) {
    numberoftrack++;
    Node* newNode = createe();
    newNode->data= data;
    if(front == NULL || index == 0) {
        newNode->next = (struct Node *) *front;
        *front = newNode;
    } else {
        Node* p = *front;
        int i = 1;

        while(p->next != NULL && i < index) {
            p = (Node *) p->next;
            i++;
        }

        newNode->next = p->next;
        p->next = (struct Node *) newNode;
    }
}

int* statistics(Node* front) {
    int* stats = (int*)calloc(listLength(front, 0), sizeof(int));

    if(!stats) {
        printf("Failed to allocate memory for statstics!");
        return NULL;
    }

    for(int i = 0; i < listLength(front, 0); i++) {
        stats[getKthDigit(front, i, 0)]++;
    }

    return stats;
}

int getKthDigit(Node* front, int k, int currPos) {
    if(k == currPos) {
        return (int) front->data;
    }

    return getKthDigit((Node *) front->next, k, currPos + 1);
}

int listLength(Node* front, int size) {
    if(!front) {
        return size;
    }

    listLength((Node *) front->next, size + 1);
}


void destroyss(Node* front) {
    if(front->next)
        destroyss((Node *) front->next);

    free(front);
    front = NULL;
}

Node * readTrack(const char *file) {
    FILE *input = fopen(file, "r");
    if (!input) {
        printf("Sikertelen");
        exit(1);

    }
    int n;
    fscanf(input, "%i\n", &n);
    numberoftrack = n;
    Node* newNode = NULL;
    Track *track = NULL;
    for (int i = 0; i < n; ++i) {
        track = creat();
        IDgenerator(track);
        fscanf(input, "%[^\n]\n", track->nameCompany);
        fscanf(input, "%lf\n", &track->crowd);
        fscanf(input, "%[^\n]\n", track->product);
        fscanf(input, "%lf\n", &track->time);
        inserte(&newNode,track,i);

    }

    fclose(input);
    return newNode;
}


