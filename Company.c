//
// Created by Dell on 2021. 04. 22..
//

#include <malloc.h>
#include <stdio.h>
#include "Company.h"

Company *create() {
    Company * company=(Company*)malloc(sizeof (Company));
    if(!company){
        printf("Sikertelen helyfoglalas");
        exit(1);
    }
    company->name=(char*)malloc(20);
    company->location=(char*)malloc(20);
    return company;
}
void destroy(Company* company){
    free(company->name);
    free(company->location);
    free(company);
    printf("Felszabaditva");
}
void print(Company*company){

}

