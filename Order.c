#include "libraryC.h"

void edit_order()
{
	int option, productID;
	printf("\tPlease choose your option\n");
	printf("\t1 : Remove product from cart\n");
	printf("\t2 : Add product to cart\n");
	printf("\tEnter your option : ");
	scanf("%d", &option);
	printf("\tPlease enter your product ID which you want to edit : ");
	scanf("%d", &productID);
	if(option == 1)
	{
		removeFromCart(productID);
	} else if(option == 2)
	{
		int quantity_add;
		printf("\tEnter quantity you want to add : ");
		scanf("%d", &quantity_add);
		addToCart(productID, quantity_add);
	} else 
	{
		printf("\tYour option is invalid!\n");
		edit_order();
	}
}

void create_order()
{
	int check;
	printf("\tThese are all the products you have purchased\n");
	displayCart();
	printf("\tPlease check your order again!\n");
	printf("\tPlease choose your option\n");
	printf("\t1 : Edit your order\n");
	printf("\t2 : Cancel your order\n");
	printf("\t3 : Pay for your order\n");
	printf ("\tEnter your option : ");
	scanf("%d", &check);
	if(check == 1)
	{
		edit_order();
		create_order();
	} else if(check == 2)
	{
		system("cls");
		check_order = 0;
	} else if(check == 3)
	{
		printf("\tPayment processed successfully for user: %s\n", t_name);
		system("pause"); 
	}
}
