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
    if(!company->name)
    {
        printf("Hibas helyfoglalas");
        exit(1);
    }
    company->location=(char*)malloc(20);
    if(!company->location)
    {
        printf("Hibas helyfoglalas");
        exit(1);
    }
    company->region=(char*)malloc(20);
    if(!company->region)
    {
        printf("Hibas helyfoglalas");
        exit(1);
    }

    return company;
}
void destroy(Company* company){
    free(company->name);
    free(company->location);
    free(company);
    printf("Felszabaditva");
}
void print(Company*company){

        printf("%s\n",company->name);
        printf("%s\n",company->location);
        printf("Munkasok szama%i\n",company->Numberofworker);
        printf("Posta kod %i\n",company->postcode);
        printf("Maximalis kamion befogadas: %i\n",company->maxtrack);
        printf("\n\n");

}

void *readCompanyFromFile(Company *company,const char *file) {
    FILE *input = fopen(file, "r");
    if (!input) {
        printf("Sikertelen");
        exit(1);

    }

        fscanf(input, "%[^\n]\n", company->name);
        fscanf(input, "%[^\n]\n", company->location);
        fscanf(input, "%i\n", &company->maxtrack);
        fscanf(input, "%i\n", &company->Numberofworker);
        fscanf(input, "%[^\n]\n", company->region);
        postCodeGenerator(company);
    fclose(input);
}

void postCodeGenerator(Company *company) {
    company->postcode = rand()%(10000 - 1000 + 1) + 1000;
}

