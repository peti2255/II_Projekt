//
// Created by Dell on 2021. 04. 22..
//

#ifndef MAIN_C_COMPANY_H
#define MAIN_C_COMPANY_H
typedef struct Company{
    char* name;
    char* location;
    int postcode;
    int maxtrack;
    int Numberofworker;
}Company;
Company* create();
void destroy(Company* company);
void print(Company* company);
#endif //MAIN_C_COMPANY_H
