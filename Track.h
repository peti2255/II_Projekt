//
// Created by Dell on 2021. 04. 22..
//

#ifndef II_PROJEKT_TRACK_H
#define II_PROJEKT_TRACK_H
typedef struct {
    char* nameCompany;
    int id;
    double crowd;
    char* name;
}Track;

Track * creat();

void destroy(Track* track);

#endif //II_PROJEKT_TRACK_H