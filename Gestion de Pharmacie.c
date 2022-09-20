#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int m, p, numofachat;
int i = 0;
float bsr;
struct Product {
    char name[100];
    float price;
    int quantite;
    int codeOfProduct;
};
struct achat {
    char name[100];
    char time[100];
    float priceTTC;
};
int oldnumberOfProduct = 5;
struct Product prod[50];
struct achat chat[50];
void sortstructbynum(int n, struct Product prod[]) {
    int i, j;
    struct Product temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < (n - 1 - i); j++) {
            if (prod[j].price > prod[j + 1].price) {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }
}
void sortstructbyaz(int n, struct Product prod[]) {
    int i, j;
    struct Product temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < (n - 1 - i); j++) {
            if (strcasecmp(prod[j].name, prod[j + 1].name) > 0) {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }
}
void search(struct Product prod[], int userChoice, int oldnumberOfProduct){
    for(int i = 0; i < oldnumberOfProduct; i++){
        if(prod[i].codeOfProduct == userChoice){
            printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
        }
    }
}
void deleteproduct();
void buyProduct(){
    printf("WRITE THE MUMBER OF THE PRODUCT\n");
    scanf("%d", &p);
    printf("HOW MUCH %s YOU WANT TO BUY ", prod[p - 1].name);
    scanf("%d", &m);
    prod[p - 1].quantite -= m;
    numofachat++;
    time_t rawtime;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );
    for(i; i < numofachat; i++){
    strcpy(chat[i].name, prod[p - 1].name);
    chat[i].priceTTC = (float) prod[p - 1].price * m;
    strcpy(chat[i].time, asctime(info));
    }
}
void notification(struct Product prod[], int oldnumberOfProduct){
    for (int i = 0; i < oldnumberOfProduct; i++){
        if(prod[i].quantite <= 3){
            printf("****YOU MUST ADD SOME %s****\n", prod[i].name);
        }
    }
}
void addquantite(struct Product prod[]){
    int i, q;
    printf("WRITE THE NUMBER OF DRUGS YOU WANT TO ADD\n");
    scanf("%d", &i);
    printf("HOW MUCH YOU WANT TO ADD %s \n", prod[i - 1].name);
    scanf("%d", &q);
    prod[i - 1].quantite += q;
}
int main() {
    int start = oldnumberOfProduct;
    ///////////////////////////////////////////////
    prod[0].codeOfProduct = 73440;
    strcpy(prod[0].name, "Probuphine");
    prod[0].price = 19.99;
    prod[0].quantite = 10;
    ///////////////////////////////////////////////
    prod[1].codeOfProduct = 38621;
    strcpy(prod[1].name, "Loratadine");
    prod[1].price = 14.99;
    prod[1].quantite = 10;
    ///////////////////////////////////////////////
    prod[2].codeOfProduct = 46323;
    strcpy(prod[2].name, "Cephalexin");
    prod[2].price = 9.99;
    prod[2].quantite = 10;
    ///////////////////////////////////////////////
    prod[3].codeOfProduct = 23495;
    strcpy(prod[3].name, "Amlodipine");
    prod[3].price = 24.99;
    prod[3].quantite = 10;
    ///////////////////////////////////////////////
    prod[4].codeOfProduct = 44342;
    strcpy(prod[4].name, "Metoprolol");
    prod[4].price = 25.99;
    prod[4].quantite = 10;
    test:
        printf("\n\n\n||===>  NAME\t\t\tPRICE\t\tQUANTITE\tCODE\n");
    for (int i = 0; i < oldnumberOfProduct; i++) {
        printf("||%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
    }
    printf("\n11==> BUY PRODUCT\t");
    printf("22==> ADD NEW PRODUCT\t");
    printf("33==> ADD QUANTITE\t");
    printf("44==> SORT\t");
    printf("55==> SEARCH\t\t");
    printf("66==> DELETE\t\t");
    printf("77==> Analytics\t\t");
    int userChoice;
    scanf("%d", & userChoice);
    switch (userChoice) {
        //////////////////////////////////////////////////////////////////////
    case 55:
        printf("WRITE THE CODE OF THE PRODUCT WHAT ARE YOU LOKING FOR\n");
        scanf("%d", &userChoice);
        search(prod, userChoice, oldnumberOfProduct);
        goto test;
    break;
    case 33:
        addquantite(prod);
        system("cls");
        goto test;
    break;
    case 11:
        buyProduct();
        system("cls");
        notification(prod, oldnumberOfProduct);
        goto test;
    break;
    case 44:
        system("cls");
        printf("\n1==> SORT BY NUMBER\n2==> SORT BY A-Z\n");
        scanf("%d", &userChoice);
        switch (userChoice) {
        case 1:
            system("cls");
            sortstructbynum(oldnumberOfProduct, prod);
            goto test;
            break;
        case 2:
            system("cls");
            sortstructbyaz(oldnumberOfProduct, prod);
            goto test;
            break;
        }
        break;
        /////////////////////////////////////////////////////////////////////////////////
    case 22:

        printf("HOW MANY PRODUCT YOU WANT TO ADD\n");
        int numberOfaddingproduct;
        scanf("%d", &numberOfaddingproduct);
        oldnumberOfProduct += numberOfaddingproduct;
        for (start; start < oldnumberOfProduct; start++) {
            printf("Name of product :\n");
            scanf("%s", prod[start].name);
            printf("Price of product :\n");
            scanf("%f", & prod[start].price);
            printf("Quantite of product :\n");
            scanf("%d", & prod[start].quantite);
            printf("Code of product :\n");
            scanf("%d", & prod[start].codeOfProduct);
        };
        system("cls");
        goto test;
        break;
    case 66:
        deleteproduct();
        system("cls");
        goto test;
        break;
    case 77:
        for(i = 0; i < numofachat; i++){
        printf("NAME OF PRODUCT : %s\n", chat[i].name);
        printf("INCOM  : %0.2f\n", chat[i].priceTTC * 0.15);
        printf("TIME : %s", chat[i].time);
        }
        for(i = 0; i < numofachat; i++){
        bsr += chat[i].priceTTC;
        }

        printf("BSR : %f", (float) bsr / numofachat);
        goto test;
        break;
    }
    return 0;
}
void deleteproduct(){
    int userChoice;
    int j;
    printf("WRITE THE CODE OF THE PRODUCT WHAT ARE YOU delete az FOR\n");
    scanf("%d", &userChoice);
    for(int i = 0; i < oldnumberOfProduct; i++){
        if(prod[i].codeOfProduct == userChoice){
            for(j=i; j<oldnumberOfProduct-1; j++){
                    prod[j]=prod[j+1];
                }
                oldnumberOfProduct--;
        }
    }
}
