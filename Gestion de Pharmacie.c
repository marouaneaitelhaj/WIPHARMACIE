#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int sold_quantity, p, sales_times;
int i = 0;
float price_average;
int user_choice_menu;
int userChoice;
int start = 5;
void red()
{
	printf("\033[1;31m");
}

struct Product
{
	char name[100];
	float price;
	int quantity;
	int codeOfProduct;
};
struct sales
{
	char name[100];
	char time[100];
	float priceTTC;
};
int lenth = 5;
struct Product prod[50];
struct sales chat[50];
void pressKey()
{
	printf("\n\nPress any key to continue...\n");
	getch();
}

void sort_struct_by_price(int n)
{
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

void sort_secend_struct_by_price(int n)
{
	int i, j;
	struct sales temp;
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

void sort_struct_by_name(int n)
{
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

void search_by_code(struct Product prod[], int userChoice, int lenth)
{
	for (int i = 0; i < lenth; i++)
	{
		if (prod[i].codeOfProduct == userChoice)
		{
			printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantity, prod[i].codeOfProduct);
		}
	}
}

void search_by_quantity(struct Product prod[], int userChoice, int lenth)
{
	for (int i = 0; i < lenth; i++)
	{
		if (prod[i].quantity == userChoice)
		{
			printf("%d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantity, prod[i].codeOfProduct);
		}
	}
}

void delete_product()
{
	int userChoice;
	int j;
	printf("WRITE THE CODE OF THE PRODUCT : \n");
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

void display()
{
	printf("\n\n\n                ===>  NAME\t\t\tPRICE\t\tquantity\tCODE\n");
	for (int i = 0; i < lenth; i++)
	{
		printf("                %d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantity, prod[i].codeOfProduct);
	}
}

void buy_Product()
{
	buy: system("cls");
	display();
	printf("\nWRITE THE NUMBER OF THE PRODUCT IN THE LIST\n");
	scanf("%d", &p);
	printf("HOW MUCH %s YOU WANT TO BUY ", prod[p - 1].name);
	scanf("%d", &sold_quantity);
	if (prod[p - 1].quantity > sold_quantity)
	{
		prod[p - 1].quantity -= sold_quantity;
		sales_times++;
		time_t rawtime;
		struct tm * info;
		time(&rawtime);
		info = localtime(&rawtime);
		for (i; i < sales_times; i++)
		{
			strcpy(chat[i].name, prod[p - 1].name);
			chat[i].priceTTC = (float) prod[p - 1].price * sold_quantity;
			strcpy(chat[i].time, asctime(info));
		}
	}
	else
	{
		printf("YOU DONT HAVE ENOUGH quantity\n\n");
		pressKey();
		goto buy;
	}
}

void less_than_3_notification()
{
	for (int i = 0; i < lenth; i++)
	{
		if (prod[i].quantity <= 3)
		{
			printf("****YOU MUST ADD SOME ==>%s ****\n", prod[i].name);
		}
	}
}

void less_than_3_button()
{
	for (int i = 0; i < lenth; i++)
	{
		if (prod[i].quantity <= 3)
		{
			printf("PRODUCTS WHOSE QUANTITY IS LESS THAN 3 : \n");
			printf("                %d==>  %s\t\t%0.2f\t\t%d\t\t%d\n", i + 1, prod[i].name, prod[i].price, prod[i].quantity, prod[i].codeOfProduct);
		}
	}
}

void add_quantity(int userChoice)
{
	int i, q;
	for (int i = 0; i < lenth; i++)
	{
		if (prod[i].codeOfProduct == userChoice)
		{
			printf("HOW MUCH %s YOU WANT TO ADD \n", prod[i].name);
			scanf("%d", &q);
			prod[i].quantity += q;
		}
	}
}

void add_product()
{
	printf("1=> ADD ONE PRODUCT\n2=> ADD A GROUP OF PRODUCTS\n");
	int numberOfaddingproduct;
	scanf("%d", &numberOfaddingproduct);
	switch (numberOfaddingproduct)
	{
		case 1:
			lenth++;
			for (start; start < lenth; start++)
			{
				printf("Name of product :\n");
				scanf("%s", prod[start].name);
				printf("Price of product :\n");
				scanf("%f", &prod[start].price);
				printf("quantity of product :\n");
				scanf("%d", &prod[start].quantity);
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
				printf("quantity of product :\n");
				scanf("%d", &prod[start].quantity);
				printf("Code of product :\n");
				scanf("%d", &prod[start].codeOfProduct);
			};
			system("cls");
			break;

	}
}

void max_price_sold()
{
	printf("THE MAX OF THE PRICES OF THE PRODUCTS SOLD ON THE CURRENT DAY : \n\n");
	sort_secend_struct_by_price(sales_times);
	printf("==>  %s\t\t%0.2f $\n", chat[sales_times - 1].name, chat[sales_times - 1].priceTTC);
}

void min_price_sold()
{
	printf("THE MIN OF THE PRICES OF THE PRODUCTS SOLD ON THE CURRENT DAY : \n");
	sort_secend_struct_by_price(sales_times);
	printf("==>  %s\t\t%0.2f $\n", chat[0].name, chat[0].priceTTC);
}

int main()
{
	int start = lenth;
	///////////////////////////////////////////////
	prod[0].codeOfProduct = 73440;
	strcpy(prod[0].name, "Probuphine");
	prod[0].price = 19.99;
	prod[0].quantity = 10;
	///////////////////////////////////////////////
	prod[1].codeOfProduct = 38621;
	strcpy(prod[1].name, "Loratadine");
	prod[1].price = 14.99;
	prod[1].quantity = 10;
	///////////////////////////////////////////////
	prod[2].codeOfProduct = 46323;
	strcpy(prod[2].name, "Cephalexin");
	prod[2].price = 9.99;
	prod[2].quantity = 10;
	///////////////////////////////////////////////
	prod[3].codeOfProduct = 23495;
	strcpy(prod[3].name, "Amlodipine");
	prod[3].price = 24.99;
	prod[3].quantity = 10;
	///////////////////////////////////////////////
	prod[4].codeOfProduct = 44342;
	strcpy(prod[4].name, "Metoprolol");
	prod[4].price = 25.99;
	prod[4].quantity = 10;
	start:
    printf("\n\n\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t\t\t\t\t*        GESTION DE PHARMACIE         *\n");
    printf("\t\t\t\t\t\t* * * * * * * * M E N U * * * * * * * *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          1=>SHOW LIST               *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          2=>BUY PRODUCT             *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          3=>ADD NEW PRODUCT         *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          4=>ADD QUANTITY            *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          5=>SORT                    *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          6=>SEARCH                  *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          7=>DELETE                  *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          8=>SALES HISTORY           *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          9=>MAX PRICE SOLD          *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          10=>MIN PRICE SOLD         *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t\t*          11=>LESS THAN 3            *\n");
	printf("\t\t\t\t\t\t*                                     *\n");
	printf("\t\t\t\t\t        * * * * * * * * * * * * * * * * * * **\n");
	scanf("%d", &user_choice_menu);
	switch (user_choice_menu)
	{
		case 1:
			system("cls");
			display();
			pressKey();
			system("cls");
			goto start;
			break;
		case 3:
			system("cls");
			add_product();
			less_than_3_notification();
			goto start;
			break;
		case 2:
			buy_Product();
			system("cls");
			less_than_3_notification();
			goto start;
			break;
		case 4:
			system("cls");
			display();
			printf("\nCODE OF PRODUCT : ");
			scanf("%d", &userChoice);
			add_quantity(userChoice);
			system("cls");
			goto start;
			break;
		case 5:
			sort:
				system("cls");
			printf("\n1==> SORT BY PRICE\n2==> SORT BY NAME\n");
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
				default:
					system("cls");
					goto sort;
			}

			goto start;
			break;
		case 7:
			system("cls");
			display();
			delete_product();
			system("cls");
			goto start;
			break;
		case 6:
			system("cls");
			display();
			printf("\n1=>BY quantity\n2=>BY CODE\n");
			scanf("%d", &userChoice);
			switch (userChoice)
			{
				case 1:
					printf("WRITE THE quantity OF THE PRODUCT\n");
					scanf("%d", &userChoice);
					search_by_quantity(prod, userChoice, lenth);
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
			if (sales_times > 0)
			{
				for (i = 0; i < sales_times; i++)
				{
					printf("********************************\n");
					printf("NAME OF PRODUCT : %s\n", chat[i].name);
					printf("PRICE TTC  : %0.2f $\n", chat[i].priceTTC *0.15 + chat[i].priceTTC);
					printf("TIME : %s", chat[i].time);
				}

				printf("********************************\n");

				for (i = 0; i < sales_times; i++)
				{
					price_average += chat[i].priceTTC;
				}

				printf("TOTAL : %0.2f $\n", (float) price_average);
				printf("PRICE AVERAGE : %0.2f $\n", (float) price_average / sales_times);
				pressKey();
				system("cls");
				goto start;
			}
			else
			{
				printf("NOTHING FOUND\n");
				pressKey();
				system("cls");
				goto start;
			}

			break;
		case 9:
			if (sales_times > 0)
			{
				system("cls");
				max_price_sold();
				pressKey();
				system("cls");
				goto start;
			}
			else
			{
				printf("NOTHING FOUND\n");
				pressKey();
				system("cls");
				goto start;
			}

			break;
		case 10:
			if (sales_times > 0)
			{
				system("cls");
				min_price_sold();
				pressKey();
				system("cls");
				goto start;
			}
			else
			{
				printf("NOTHING FOUND\n");
				pressKey();
				system("cls");
				goto start;
			}

			break;
		case 11:
			less_than_3_button();
			pressKey();
			system("cls");
			goto start;
			break;
		default:
			system("cls");
			goto start;
	}

	return 0;
}
