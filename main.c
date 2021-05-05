#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <aclui.h>
#include "Company.h"
#include "Lancolt_lista.h"
#include "Track.h"
#include "Root.h"

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
   // traversetime(newNode);
    while (repeat) {
        printf("0.Kilepes\n"
               "1.Company adatainak kiiratasa\n"
               "2.Idopontok\n"
               "3.Kamionok\n"
               "4.Ujj kamionos hozzaadas\n"
               "5.Erkezhete a megadott idopontba kamion\n"
               "6.Idopont kereses \n"
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
                traverse(newNode);
                break;
            case 4:
            {
                Track * track = creat();
                printf("Ceg neve: ");
                scanf("%s",track->nameCompany);
                printf("Szalitott termek: ");
                scanf("%s",track->product);
                printf("Ossz suly: ");
                scanf("%lf",&track->crowd);
                inserte(&newNode,track,numberoftrack);
            }
                break;
            case 5:
            {
                int n;
                printf("Ido megadasa: ");
                scanf("%i",&n);
                //timesearcher(bst,n);
                if(findMinforN(bst,n) <= 0)
                {
                    printf("Kamion erkezes megtiltva!\n");
                }
                else
                {
                    if(n-findMinforN(bst,n) < 20)
                        printf("Kamion erkezes megtiltva!\n");
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
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Helytelen opcio. Probald ujra! ");
                break;
        }
        printf("\n\n---------------------\n\n");
    }

    return 0;
}
