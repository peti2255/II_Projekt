#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <aclui.h>
#include "Company.h"
#include "Lancolt_lista.h"

int main() {

    srand(time(0));
    Company* company = create();
    readCompanyFromFile(company,"Company.txt");
    Node* newNode = NULL;
    newNode =  readTrack("track.txt");
    struct root* bst = NULL;
    bst = readtime("be.txt");
    int option;
    bool repeat = true;
    while (repeat) {
        printf("0.Kilepes\n"
               "1.Company adatainak kiiratasa\n"
               "2.Idopontok sorrendje\n"
               "3.Kamionok\n"
               "4.Uj kamionos hozzaadas\n"
               "5.Erkezhet-e a megadott idopontba kamion\n"
               "6.Idopont kereses \n");
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
                traverse(newNode);
                break;
            case 4:
            {
                Track * track = creat();
                double n1;
                printf("Ceg neve: ");
                scanf("%s",track->nameCompany);
                printf("Szallitott termek: ");
                scanf("%s",track->product);
                printf("Ossz suly: ");
                scanf("%lf",&track->crowd);
                printf("Idopont: ");
                scanf("%lf",&n1);
                track->time = n1;
                inserte(&newNode,track,numberoftrack);
                insert(bst,n1);
            }
                break;
            case 5:
            {
                double n;
                printf("Ido megadasa: ");
                scanf("%lf",&n);
                if(findMinforN(bst,n) <= 0 && (n-findMinforN(bst,n) < 20))
                {
                    printf("Kamion erkezes megtiltva!\n");
                }
                else{

                    printf("Kamion erkezhet \n");
                }
            }
                break;
            case 6:
            {
                double elem;
                printf("Ido megadasa: ");
                scanf("%lf",&elem);
                if(find(bst,elem) == 1)
                printf("Letezo idopont\n");
                else
                    printf("Idopont nem talalhato\n ");
            }

                break;
            default:
                printf("Helytelen opcio. Probald ujra! ");
                break;
        }
        printf("\n\n---------------------\n\n");
    }
//    destroyCompany(company);
//    destroyroot(bst);
//    destroy((Track *) newNode);

    return 0;
}
