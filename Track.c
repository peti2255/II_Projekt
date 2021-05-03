//
// Created by Dell on 2021. 04. 22..
//

#include "Track.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Lancolt_lista.h"

Track *creat() {
    int n = 30;

    Track* track = (Track*)calloc(n,sizeof(Track));
    if(!track)
    {
        printf("Sikertelen helyfoglalas");
        exit(1);
    }
    track->nameCompany = (char *)malloc(20* sizeof (char));
    if(!track->nameCompany)
    {
        printf("Hibas helyfoglalas");
        exit(1);
    }
    track->product = (char *)malloc(20 * sizeof (char));
    track->id = 0;
    track->crowd = 0.0;

    return track;
}

void destroytrack(Track* track) {
    free(track->nameCompany);
    free(track->product);
    free(track);
    printf("Felszabaditva");
}



int IDgenerator(Track *track) {
    track->id = rand()%100;
}

void printTrack(Track *track) {
    printf("Name: %s\n",track->product);
    printf("ID: %i\n", track->id);
    printf("Company: %s\n",track->nameCompany);

}


