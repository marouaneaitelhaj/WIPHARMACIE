#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Product {
    char name[100];
    float price;
    int quantite;
    int codeOfProduct;
};
void sortstructbynum(int n, struct Product prod[n]) {
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
void sortstructbyaz(int n, struct Product prod[n]) {
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
void search(struct Product prod[5], int userChoice){
    int numberOfProduct = 5;
    for(int i = 0; i < numberOfProduct; i++){
        if(prod[i].codeOfProduct == userChoice){
            printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
        }
    }
}
void buyProduct(struct Product prod[5]){
    int m, p;
    printf("WRITE THE MUMBER OF THE PRODUCT\n");
    scanf("%d", &p);
    system("cls");
    printf("HOW MUCH %s YOU WANT TO BUY ", prod[p - 1].name);
    scanf("%d", &m);
    prod[p - 1].quantite -= m;
}
void notification(struct Product prod[5]){
    int numberOfProduct;
    for (int i = 0; i < numberOfProduct; i++){
        if(prod[i].quantite <= 3){
            printf("****YOU MUST ADD SOME%s****\n", prod[i].name);
        }
    }
}
void addquantite(struct Product prod[5]){
    int i, q;
    printf("WRITE THE NUMBER OF DRUGS YOU WANT TO ADD\n");
    scanf("%d", &i);
    printf("HOW MUCH YOU WANT TO ADD %s \n", prod[i - 1].name);
    scanf("%d", &q);
    prod[i - 1].quantite += q;
}
int main() {
    int oldnumberOfProduct = 5;
    int start = oldnumberOfProduct;
    ///////////////////////////////////////////////
    struct Product prod[oldnumberOfProduct];
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
        printf("===>  NAME\t\t\tPRICE\t\tQUANTITE\tCODE\n");
    for (int i = 0; i < oldnumberOfProduct; i++) {
        printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
    }
    printf("\n11==> BUY PRODUCT\t");
    printf("22==> ADD NEW PRODUCT\t");
    printf("33==> ADD QUANTITE\t");
    printf("44==> SORT\t");
    printf("55==> SEARCH\t\t");
    int userChoice;
    scanf("%d", & userChoice);
    switch (userChoice) {
        //////////////////////////////////////////////////////////////////////
    case 55:
        printf("WRITE THE CODE OF THE PRODUCT WHAT ARE YOU LOKING FOR\n");
        scanf("%d", &userChoice);
        search(prod, userChoice);
    //goto test;
    break;
    case 33:
        addquantite(prod);
        goto test;
    break;
    case 11:
        buyProduct(prod);
        notification(prod);
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
        system("cls");
        printf("HOW MANY PRODUCT YOU WANT TO ADD\n");
        int yy;
        scanf("%d", &yy);
        oldnumberOfProduct += yy;
        for (int i = start; i < oldnumberOfProduct; i++) {
            printf("Name of product :\n");
            scanf("%s", prod[i].name);
            printf("Price of product :\n");
            scanf("%f", & prod[i].price);
            printf("Quantite of product :\n");
            scanf("%d", & prod[i].quantite);
            printf("Code of product :\n");
            scanf("%d", & prod[i].codeOfProduct);
        };
        start += oldnumberOfProduct;
                printf("\nnumberOfProduct %d\n", oldnumberOfProduct);
        goto test;
        break;
    }
    return 0;
}
