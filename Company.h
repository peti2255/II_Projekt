//
// Created by Dell on 2021. 04. 22..
//

#ifndef MAIN_C_COMPANY_H
#define MAIN_C_COMPANY_H

#include "Track.h"
#include "Root.h"

typedef struct {
   struct root root;
    char* name;
    char* location;
    int postcode;
    int maxtrack;
    int Numberofworker;
    char* region;
}Company;
Company* create();
void *readCompanyFromFile(Company *company,const char *file);
//void destroy(Company* company);
void print(Company* company);
void postCodeGenerator(Company* company);
#endif //MAIN_C_COMPANY_H
