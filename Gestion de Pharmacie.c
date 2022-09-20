#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int m, p, number_time_buy;
int i = 0;
float price_average;
int user_choice_menu;
int userChoice;
int start = 5;
struct Product{
    char name[100];
    float price;
    int quantite;
    int codeOfProduct;
};
struct cart{
    char name[100];
    char time[100];
    float priceTTC;
};
int lenth = 5;
struct Product prod[50];
struct cart chat[50];
void pressKey(){
    printf("Press any key to continue...\n");
    getch();
}
void sort_struct_by_price(int n){
    int i, j;
    struct Product temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (prod[j].price > prod[j + 1].price)
            {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }
}
void sort_secend_struct_by_price(int n){
    int i, j;
    struct cart temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (chat[j].priceTTC > chat[j + 1].priceTTC)
            {
                temp = chat[j];
                chat[j] = chat[j + 1];
                chat[j + 1] = temp;
            }
        }
    }
}
void sort_struct_by_name(int n){
    int i, j;
    struct Product temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (strcasecmp(prod[j].name, prod[j + 1].name) > 0)
            {
                temp = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = temp;
            }
        }
    }
}
void search_by_code(struct Product prod[], int userChoice, int lenth){
    for (int i = 0; i < lenth; i++)
    {
        if (prod[i].codeOfProduct == userChoice)
        {
            printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
        }
    }
}
void search_by_quantite(struct Product prod[], int userChoice, int lenth){
    for (int i = 0; i < lenth; i++)
    {
        if (prod[i].quantite == userChoice)
        {
            printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
        }
    }
}
void delete_product(){
    int userChoice;
    int j;
    printf("WRITE THE CODE OF THE PRODUCT\n");
    scanf("%d", &userChoice);
    for (int i = 0; i < lenth; i++)
    {
        if (prod[i].codeOfProduct == userChoice)
        {
            for (j = i; j < lenth - 1; j++)
            {
                prod[j] = prod[j + 1];
            }

            lenth--;
        }
    }
}
void affichage(){
    printf("\n\n\n===>  NAME\t\t\tPRICE\t\tQUANTITE\tCODE\n");
    for (int i = 0; i < lenth; i++)
    {
        printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantite, prod[i].codeOfProduct);
    }
}
void buy_Product(){
    buy:
    system("cls");
            affichage();
    printf("\nWRITE THE MUMBER OF THE PRODUCT IN THE LIST\n");
    scanf("%d", &p);
    printf("HOW MUCH %s YOU WANT TO BUY ", prod[p - 1].name);
    scanf("%d", &m);
    if(prod[p - 1].quantite > m){
    prod[p - 1].quantite -= m;
    number_time_buy++;
    time_t rawtime;
    struct tm * info;
    time(&rawtime);
    info = localtime(&rawtime);
    for (i; i < number_time_buy; i++)
    {
        strcpy(chat[i].name, prod[p - 1].name);
        chat[i].priceTTC = (float) prod[p - 1].price * m;
        strcpy(chat[i].time, asctime(info));
    }
    } else{
        printf("YOU DONT HAVE ENOUGH QUANTITE\n\n");
        pressKey();
        goto buy;
    }
}
void notification(){
    for (int i = 0; i < lenth; i++)
    {
        if (prod[i].quantite <= 3)
        {
            printf("****YOU MUST ADD SOME %s****\n", prod[i].name);
        }
    }
}
void addquantite(int userChoice){
    int i, q;
    for (int i = 0; i < lenth; i++)
    {
        if (prod[i].codeOfProduct == userChoice)
        {
            printf("HOW MUCH YOU WANT TO ADD %s \n", prod[i].name);
            scanf("%d", &q);
            prod[i].quantite += q;
        }
    }
}
void addproduct(){
    printf("1=> ONE PRODUCT\n2=> A LOT OF PRODUCT\n");
    int numberOfaddingproduct;
    scanf("%d", &numberOfaddingproduct);
    switch(numberOfaddingproduct){
        case 1:
            lenth++;
            for (start; start < lenth; start++)
            {
                printf("Name of product :\n");
                scanf("%s", prod[start].name);
                printf("Price of product :\n");
                scanf("%f", &prod[start].price);
                printf("Quantite of product :\n");
                scanf("%d", &prod[start].quantite);
                printf("Code of product :\n");
                scanf("%d", &prod[start].codeOfProduct);
            };
            system("cls");
            break;
            case 2:
    printf("HOW MANY PRODUCT YOU WANT TO ADD\n");
            int numberOfaddingproduct;
            scanf("%d", &numberOfaddingproduct);
            lenth += numberOfaddingproduct;
            for (start; start < lenth; start++)
            {
                printf("Name of product :\n");
                scanf("%s", prod[start].name);
                printf("Price of product :\n");
                scanf("%f", &prod[start].price);
                printf("Quantite of product :\n");
                scanf("%d", &prod[start].quantite);
                printf("Code of product :\n");
                scanf("%d", &prod[start].codeOfProduct);
            };
            system("cls");
            break;

}}
int main()
{
    int start = lenth;
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
    start:
    printf("\n\n\t\t\t\t\t============== MENU ================\n");
    printf("\t\t\t\t\t          1=>SHOW LIST              \n");
    printf("\t\t\t\t\t          2=>BUY PRODUCT            \n");
    printf("\t\t\t\t\t          3=>ADD NEW PRODUCT        \n");
    printf("\t\t\t\t\t          4=>ADD QUANTITE           \n");
    printf("\t\t\t\t\t          5=>SORT                   \n");
    printf("\t\t\t\t\t          6=>SEARCH                 \n");
    printf("\t\t\t\t\t          7=>DELETE                 \n");
    printf("\t\t\t\t\t          8=>ANALYTICS              \n");
    printf("\t\t\t\t\t          9=>MAX PRICE SOLD              \n");
    printf("\t\t\t\t\t          10=>MIN PRICE SOLD              \n");
    printf("\t\t\t\t\t====================================\n");
    scanf("%d", &user_choice_menu);
    switch(user_choice_menu){
    case 1:
        system("cls");
        affichage();
    pressKey();
    system("cls");
    goto start;
        break;
        case 3:
            addproduct();
            notification();
            goto start;
            break;
        case 2:
            buy_Product();
            system("cls");
            notification();
            goto start;
            break;
        case 4:
            system("cls");
            affichage();
    printf("CODE OF PRODUCT");
    scanf("%d", &userChoice);
            addquantite(userChoice);
            system("cls");
            goto start;
            break;
        case 5:
            system("cls");
            printf("\n1==> SORT BY NUMBER\n2==> SORT BY A-Z\n");
            scanf("%d", &userChoice);
            switch (userChoice)
            {
                case 1:
                    system("cls");
                    sort_struct_by_price(lenth);

                    break;
                case 2:
                    system("cls");
                    sort_struct_by_name(lenth);

                    break;
            }
            goto start;
            break;
                case 7:
                    system("cls");
                    affichage();
                    delete_product();
            system("cls");
            goto start;
            break;
                case 6:
                    system("cls");
                    affichage();
                    printf("\n1=>BY QUANTITE\n2=>BY CODE\n");
            scanf("%d", &userChoice);
            switch (userChoice)
            {
                case 1:
                    printf("WRITE THE QUANTITE OF THE PRODUCT\n");
                    scanf("%d", &userChoice);
                    search_by_quantite(prod, userChoice, lenth);
                    break;
                case 2:
                    printf("WRITE THE CODE OF THE PRODUCT\n");
                    scanf("%d", &userChoice);
                    search_by_code(prod, userChoice, lenth);
                    break;
            }
            pressKey();
            system("cls");
    goto start;
                    break;
                case 8:

                        for (i = 0; i < number_time_buy; i++)
            {
                printf("\n********************************\n");
                printf("NAME OF PRODUCT : %s\n", chat[i].name);
                printf("PRICE TTC  : %0.2f $\n", chat[i].priceTTC *0.15 + chat[i].priceTTC);
                printf("TIME : %s", chat[i].time);
            }

            for (i = 0; i < number_time_buy; i++)
            {
                price_average += chat[i].priceTTC;
            }

            printf("PRICE AVERAGE : %0.2f $\n", (float) price_average / number_time_buy);
            printf("********************************\n");
            pressKey();
            system("cls");
            goto start;
             break;
                case 9:
                    if(number_time_buy > 0){
                    system("cls");
                    sort_secend_struct_by_price(number_time_buy);
                    printf("==>  %s\t\t%0.2f\t\t%d\t\t%d\n", chat[number_time_buy - 1].name, chat[number_time_buy - 1].priceTTC);
                    pressKey();
                    system("cls");
                    goto start;
                    } else{
                        printf("NOTHING FOUND\n");
                        pressKey();
                        system("cls");
                    goto start;
                    }
                    break;
                    case 10:
                        if(number_time_buy > 0){
                    system("cls");
                    sort_secend_struct_by_price(number_time_buy);
                    printf("==>  %s\t\t%0.2f\t\t%d\t\t%d\n", chat[0].name, chat[0].priceTTC);
                    pressKey();
                    system("cls");
                    goto start;
                    } else{
                        printf("NOTHING FOUND\n");
                        pressKey();
                        system("cls");
                    goto start;
                    }
                    break;
                    default:
                        system("cls");
                    goto start;
    }
    return 0;
}
