//
// Created by Dell on 2021. 04. 22..
//

#include "Track.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    track->firstname = (char *)malloc(20 * sizeof (char));
    track->lastname = (char *)malloc(20 * sizeof (char));
    track->id = 0;
    track->crowd = 0.0;

    return track;
}

//void destroy(Track* track) {
//    free(track->nameCompany);
//    free(track->lastname);
//    free(track->firstname);
//    free(track);
//}

Track * readTrack(const char *file) {
    FILE *input = fopen(file, "r");
    if (!input) {
        printf("Sikertelen");
        exit(1);

    }
    int n;
    fscanf(input, "%i\n", &n);
    Track* track = (Track *)calloc(n,sizeof(Track));
   numberoftrack = n;
    for (int i = 0; i < n; ++i) {
        track[i] = *creat();
        IDgenerator(&track[i]);
        fscanf(input, "%[^\n]\n", track[i].firstname);
        fscanf(input, "%[^\n]\n", track[i].lastname);
        fscanf(input, "%[^\n]\n", track[i].nameCompany);
       //fscanf(input, "%i\n", &track[i].gender);
        fscanf(input, "%i\n", &track[i].trackNum);
    }
    fclose(input);
    return track;
}

int IDgenerator(Track *track) {
    track->id = rand()%100;
}

void printTrack(Track *track) {
    printf("Name: %s %s\n", track->firstname, track->lastname);
    printf("ID: %i\n", track->id);
    printf("Company: %s\n",track->nameCompany);

}


