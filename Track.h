//
// Created by Dell on 2021. 04. 22..
//

#ifndef II_PROJEKT_TRACK_H
#define II_PROJEKT_TRACK_H
typedef struct Track{
    char* nameCompany;
    int id;
    double crowd;
    char * product;

    int trackNum;
}Track;

int numberoftrack;

Track* creat();

void destroytrack(Track* track);

int IDgenerator(Track* track);
void printTrack(Track* track);

#endif //II_PROJEKT_TRACK_H