//
// Created by Dell on 2021. 04. 22..
//

#include "Track.h"
#include <stdio.h>
#include <stdlib.h>

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
    track->name = (char *)malloc(20 * sizeof (char));
    track->id = 0;
    track->crowd = 0.0;

    return track;
}

void destroy(Track* track) {
    free(track->nameCompany);
    free(track->name);
    free(track);
}
