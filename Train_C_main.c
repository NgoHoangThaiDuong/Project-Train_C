#include "libraryC.h"




int main() {
	SaveandLoadData(0);
	printf("\n\n\n\n\n\t\t\t\t**********WELCOME TO THIS PAGE**********\n");
	int client;
	printf("\tWHO ARE YOU ?\n");
	printf("\t1 : CLIENT\n");
	printf("\t2 : SALER\n");
	printf("\tENTER YOUR CHOICE : ");
	scanf("%d", &client);
	if(client == 1)
	{
		while(1)
		{
			system("cls");
			printf("\n\n\n\t\t\t\t\t**********WELCOME TO THIS PAGE**********\n");
			int client_choice;
			printf("\t1 : SIGN UP \n");
		    printf("\t2 : LOG IN \n");
		    printf("\t3 : EXIT\n");
		    printf("\tPLease enter your choice : ");
		    scanf("%d", &client_choice);
		    fflush(stdin);
		    if(client_choice == 1)
		    {
			    signup();
		    } else if (client_choice == 2)
		    {
			    login();
		    } else if(client_choice == 3)
		    {
			    printf("\t\t\t\t\t**********THANK YOU FOR VISITTING**********\n");
			    return 0;
		    } else 
		    {
		    	printf("\t\t\t\t\t**********YOU CHOOSED INVALID OPTION**********\n");
		    	return 0;
			}
			system("cls");
			displayProducts();
			if(!check) 
			{
				
				printf("\n\t\t\t\t\t**********YOU WILL RETURN TO THE HOMEPAGE**********\n");
				check = 1;
				system("pause");
				system("cls");
				fflush(stdin);
				main();
			}
			printf("\tENTER THE PRODUCTS YOU WANT TO BUY : ");
			int product_number;
			scanf("%d", &product_number);
			system("cls");
			displayProducts();
			for(i=0; i<product_number; i++)
			{
				int Product_ID, quantity_of_product;
				printf("\tPLEASE CHOOSE ID ITEM WHICH YOU LIKE : ");
				scanf("%d", &Product_ID);
				printf("\tPLEASE CHOOSE THE QUANTITY OF ITEM : ");
				scanf("%d", &quantity_of_product);
				addToCart(Product_ID, quantity_of_product);
				SaveandLoadData(1);
			}
			system("cls");
			create_order();
			if(!check_order)
			{
				printf("\t\t\t\t\t**********THANK YOU FOR VISITTING**********\n");
				system("pause");
				system("cls");
				main();
			}
		}
	} else if (client == 2)
	{
		system("cls");
		fflush(stdin);
		while(1)
		{
			int saler_choice;
		    int saler_product;
		    printf("\tPlease choose your option\n");
		    printf("\t1 : ADD PRODUCTS\n");
		    printf("\t2 : EDIT PRODUCTS\n");
		    printf("\t3 : DELETE PRODUCTS\n");
		    printf("\t4 : DISPLAY PRODUCTS\n");
		    printf("\tENTER YOUR CHOICE : ");
		    scanf("%d", &saler_choice);
		    if(saler_choice == 1)
		    {
			    printf("\tENTER THE PRODUCT NUMBER YOU WANT TO ADD : ");
			    int number;
			    scanf("%d", &number);
			    system("cls");
			    fflush(stdin);
			    for(i=0; i<number; i++)
			    {
				   addProduct();
				   SaveandLoadData(1);
			    }
		    } else if(saler_choice == 2)
		    {
		    	displayProducts();
			    printf("\tENTER THE PRODUCT NUMBER YOU WANT TO EDIT : ");
			    int number;
			    scanf("%d", &number);
			    system("cls");
			    fflush(stdin);
			    for(i=0; i<number; i++)
			    {
				    printf("\tCHOOSE ID TO EDIT : ");
			        scanf("%d", &saler_product);
			        fflush(stdin);
			        editProduct(saler_product);
			        SaveandLoadData(1);
			    }
		    } else if (saler_choice == 3)
		    {
		    	displayProducts();
			    printf("\tENTER THE PRODUCT NUMBER YOU WANT TO DELETE : ");
			    int number;
			    scanf("%d", &number);
			    system("cls");
			    fflush(stdin);
			    for(i=0; i<number; i++)
			    {
				    printf("\tCHOOSE ID ITEM TO DELETE : ");
			        scanf("%d", &saler_product);
			        fflush(stdin);
			        deleteProduct(saler_product);
			        SaveandLoadData(1);
			    }
		    } else if(saler_choice == 4)
	    	{
			    system("cls");
			    fflush(stdin);
			    displayProducts();
			    SaveandLoadData(1);
	    	} else 
	    	{
			    printf("\tYOU CHOOSED INVALID OPTION");
			    return 0;
		    }
	    	printf("\t\t\t\t\t**********THANK YOU FOR VISITTING**********\n");
	    	system("pause");
	    	system("cls");
	    	fflush(stdin);
	    	main();
	   	}
	} else 
	{
		printf("\t\t\t\t\t**********THANK YOU FOR VISITTING**********\n");
	}
	SaveandLoadData(1);
}
