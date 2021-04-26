#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <aclui.h>
#include "Company.h"
#include "Track.h"
#include "Root.h"

int main() {

    srand(time(0));
    Company* company = create();
    readCompanyFromFile(company,"Company.txt");
    struct root* bst = NULL;
    bst = readtime("be.txt");
    int option;
    bool repeat = true;
    while (repeat) {
        printf("0.Kilepes\n"
               "1.Company adatainak kiiratasa\n"
               "2.Kamionik kiiratas\n"
               "3.\n"
               "4.\n"
               "5.\n"
               "6.\n"
               "7.\n"
               "8.\n");


        printf("Valassz opciot: ");
        scanf("%i", &option);
        switch (option) {
            case 0:
                printf("Kilepes...");
                repeat = false;
                break;
            case 1:
                print(company);
                break;
            case 2:
                inorder(bst);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Helytelen opcio. Probald ujra! ");
                break;
        }
    }

    return 0;
}
