#include <ctype.h> 
#include <math.h> 
#include <stdio.h> 
#include <string.h>
#include <malloc.h> 
#include <time.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <windows.h>
char t_name[100], t_email[100];
char t_password1[100], t_password2[100];
char t_mobile[100], tmp[10];
int t_age, i, j;
FILE *file;
float amount;
int check = 1, check_order = 1;
typedef struct Product{
int id;
char name[50];
int quantityInStock;
float price; 
} Product;

typedef struct Order{
int id;
char customer_name[30];
char phone[20];
char payment_method[20];
char payment_status[20];
Product products[100];
int quanity; 
float totalPrice;
} Order;

typedef struct CartItem {
  Product product;
  int quantity;
} CartItem;

CartItem cart[10];
int itemCount = 0;

Product products[50];
int productCount = 0;

void addProduct() {
    Product product;
    int i; 
    printf("Enter Product ID: ");
    scanf("%d", &product.id);
    fflush(stdin);
    printf("Enter Product Name : ");
    gets(product.name);
    printf("Enter Price: ");
    scanf("%f", &product.price);
    printf("Enter Quantity In Stock: ");
    scanf("%d", &product.quantityInStock);

    for ( i = 0; i < productCount; i++) {
        if (products[i].id == product.id) {
            printf("Product already exists\n");
            return;
        }
    }

    if (productCount < 50) {
        products[productCount] = product;
        productCount++;
        printf("Product added!\n");
    } else {
        printf("Product list is full!\n");
    }
    return;
}
void displayProducts(){
	int i; 
    if (productCount == 0) {
        printf("\n\n\t\t\t\t\t**********NO PRODUCTS TO DISPLAY**********\n");
        check = 0;
        return;
    }
    printf("\tProduct list:\n");
    for (i = 0; i < productCount; i++) {
    printf("\tID: %d\n", products[i].id );
    printf("\tProduct Name: %s\n", products[i].name);
    printf("\tPrice: %.2f\n", products[i].price);
    printf("\tQuantity in Stock: %d\n", products[i].quantityInStock);
}
}
void editProduct(int productId) {

    int found = 0;
    int i;
    for ( i = 0; i < productCount; i++) {
        if (products[i].id == productId) {
            printf("\tEnter new product name: ");
            gets(products[i].name);
            printf("\tEnter new product price: ");
            scanf("%f", &products[i].price);
            fflush(stdin);
            printf("\tEnter new quantity in stock: ");
            scanf("%d", &products[i].quantityInStock);
            found = 1;
            printf("\tProduct information updated!\n");
            break;
        }
    }

    if (!found) {
        printf("\tProduct not found!\n");
    }
    return;
}
void deleteProduct(int productId) {
    int found = 0;
    int i, j;
    for ( i = 0; i < productCount; i++) {
        if (products[i].id == productId) {
            for ( j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("\tProduct deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\tProduct not found!\n");
    }
    return;
}

void addToCart(int productId, int quantity) {
    int found = 0;
    int i, j;
    for ( i = 0; i < productCount; i++) {
        if (products[i].id == productId) {
            if (products[i].quantityInStock >= quantity) {
                int foundCartItem = 0;
                for ( j = 0; j < itemCount; j++) {
                    if (cart[j].product.id == productId) {
                        cart[j].quantity += quantity;
                        foundCartItem = 1;
                        break;
                    }
                }
                if (!foundCartItem && itemCount < 10) {
                    cart[itemCount].product = products[i];
                    cart[itemCount].quantity = quantity;
                    itemCount++;
                }
                products[i].quantityInStock -= quantity;
                found = 1;
                printf("\tProduct added to cart!\n");
                printf("\tID: %d\n", products[i].id);
                printf("\tProduct Name: %s\n", products[i].name);
                printf("\tPrice: %.2f\n", products[i].price);
                printf("\tQuantity: %d\n", quantity);
                printf("\tTotal Price for this item: %.2f\n", products[i].price * quantity);
                
            }else {
                printf("\tQuantity of product is insufficient!\n");
                return;
            }
            break;
        }
    }

    if (!found) {
        printf("\tProduct not found!\n");
        return;
    }
    return;
}
float calculateTotalPrice() {
	int i; 
    float total = 0;
    for ( i = 0; i < itemCount; i++) {
        total += cart[i].product.price * cart[i].quantity;
    }
    return total;
}

void displayCart() {
	int i;
	if (itemCount == 0) {
    printf("\tYour cart is empty!\n");
    return;
    }
    for ( i = 0; i < itemCount; i++) {
    printf("\tYour cart:\n");
    printf("\tID: %d\n", cart[i].product.id);
    printf("\tProduct Name: %s\n", cart[i].product.name);
    printf("\tPrice: %.2f\n", cart[i].product.price);
    printf("\tQuantity: %d\n", cart[i].quantity);
    printf("\tTotal Price for this item: %.2f\n", cart[i].product.price * cart[i].quantity);
}
    printf("\tTotal Price: %.2f\n", calculateTotalPrice());
return;
}
void removeFromCart(int productId) {
    int found = 0;
    int i, j;
    for ( i = 0; i < itemCount; i++) {
        if (cart[i].product.id == productId) {
            for ( j = i; j < itemCount - 1; j++) {
                cart[j] = cart[j + 1];
            }
            itemCount--;
            printf("\tProduct removed from cart!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\tProduct not found in cart!\n");
    }
    return;
}
void saveProducts() {
	int i;
    file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for ( i = 0; i < productCount; i++) {
        fprintf(file, "%d,%s,%.2f,%d\n", products[i].id, products[i].name, products[i].price, products[i].quantityInStock);
    }
    fclose(file);
}
void saveCartToFile() {
	int i;
    file = fopen("cart.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for ( i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%d,%d\n", cart[i].product.id, cart[i].quantity, cart[i].product.quantityInStock);
    }
    fclose(file);
}
void loadProductsFromFile() {
    file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("No saved products!\n");
        return;
    }
    
    char line[100];
    int i; 
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d", &products[productCount].id, products[productCount].name, &products[productCount].price, &products[productCount].quantityInStock);
         for ( i = 0; i < productCount; i++) {
        if (products[i].id == products[productCount].id) {
            productCount--;
            break;
        }
    }
        productCount++;
    }
    fclose(file);
}
void loadCartFromFile() {
    file = fopen("cart.txt", "r");
    if (file == NULL) {
        printf("No saved cart items!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%d,%d", &cart[itemCount].product.id, &cart[itemCount].quantity, &cart[itemCount].product.quantityInStock);
        itemCount++;
    }

    fclose(file);
}
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
bool check_name()
{
	for(i=0; t_name[i] != '\0'; i++)
	{
		if((!((t_name[i] >= 'a' && t_name[i] <= 'z') || (t_name[i] >= 'A' && t_name[i] <= 'Z'))) && (t_name[i] != ' '))
		{
			printf("\tPlease enter your name again\n");
			return false;
		}
	}
	return true;
}
bool check_email()
{
	int atIndex = -1, dotIndex = -1;
    int len = strlen(t_email);
    if(len < 15)
    {
    	printf("\tPlease enter your email again\n");
    	return false;
	}
    for (i = 0; i < len; i++) {
        if (t_email[i] == '@') {
            atIndex = i;
            break;
        }
    }
    for (i = atIndex; i < len; i++) {
        if (t_email[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    if (atIndex < 1 || dotIndex < atIndex + 2 || dotIndex == len - 1) {
    	printf("\tPlease enter your email again\n");
        return false;
    }
    return true;
}
 
int check_password() {
    int length = strlen(t_password1);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    if (length < 8) {
    	printf("\tPassword too short\n");
        return false;
    }
    for (i = 0; i < length; i++) {
        char c = t_password1[i];
        if (isupper(c)) {
            hasUpper = 1;
        } else if (islower(c)) {
            hasLower = 1;
        } else if (isdigit(c)) {
            hasDigit = 1;
        } else if (ispunct(c) || c == ' ') {
            hasSpecial = 1;
        }
    }
    if(strcmp(t_password1, t_password2) != 0)
    {
    	printf("\tYour password and confirm password are different\n");
    	return false;
	}
	else if( !(hasUpper && hasLower && hasDigit && hasSpecial))
	{
		printf("\tYour password is not valid\n");
		return 0;
	} else return hasUpper && hasLower && hasDigit && hasSpecial;
}

bool check_phone_and_age()
{
	if(t_mobile[0] != '0' || strlen(t_mobile) < 10 || strlen(t_mobile) > 10)
	{
		printf("\tPLease enter your phone number again\n");
		return false;
	}
	for(i=1; t_mobile[i] != '\0'; i++)
	{
		if(!(t_mobile[i] >= 48 && t_mobile[i] <= 57))
		{
			printf("\tPLease enter your phone number again\n");
			return false;
		}
	}
	if(t_age < 18)
	{
		printf("\tYou don't have to be old enough to use this app\n");
		return false;
	}
	return true;
}


void login()
{
	char tmp_password[100];
	char tmp_email[100];
	int check_status = 0;
	system("cls");
	printf("\t\t\t\t\t**********WELCOME TO LOG IN**********\n");
	printf("\tPlease enter your email : ");
	scanf("%s", tmp_email);
	printf("\n");
	printf("\tPlease enter your password : ");
	scanf("%s", tmp_password);
	if(t_email == "" || t_password1 =="")
	{
		printf("\tPLease sign up\n");
		system("pause");
		sigup();
		check_status = 1;
	}
	if(strcmp(t_email, tmp_email) != 0)
	{
		printf("\tError with your email\n");
		system("pause");
		login();
		check_status = 1;
	}
	if(strcmp(t_password1, tmp_password) != 0)
	{
		printf("\tError with your password\n");
		system("pause");
		login();
		check_status = 1;
	}
	if(check_status)
	{
		printf("\t\t\t\t\t**********YOUR ARE SUCCESSFULLY LOGGED IN**********\n");
		system("pause");
		FILE *file_loggin;
		file_loggin = fopen("thongtindangnhap.txt", "a");
		fprintf(file_loggin, "%s\n", t_email);
		fprintf(file_loggin, "%s\n", t_password1);
		fclose(file_loggin);
	}
}

void signup()
{
	system("cls");
	fflush(stdin);
	printf("\t\t\t\t\t**********WELCOME TO SIGN UP**********\n");
	printf("\tPlease enter your name : ");
	gets(t_name);
	printf("\n");
	printf("\tPlease enter your email : ");
	gets(t_email);
	printf("\n");
	printf("\tPlease enter your password : ");
	gets(t_password1);
	printf("\n");
	printf("\tConfirm password : ");
	gets(t_password2);
	printf("\n");
	printf("\tPlease enter your phone number : ");
	scanf("%s", t_mobile);
	printf("\n");
	printf("\tPlease enter your age : ");
	scanf("%d", &t_age);
	check_name(); 
	check_email(); 
	check_password(); 
	check_phone_and_age();
	if(check_name() && check_email() && check_password() && check_phone_and_age())
	{
		file = fopen("thongtinuser.txt", "a");
		fprintf(file, "%s\n", t_name);
		fprintf(file, "%s\n", t_email);
		fprintf(file, "%s\n",t_password1);
		fprintf(file, "%s\n", t_mobile);
		fprintf(file, "%d\n", t_age);
		fclose(file);
		login();
	}
}
void SaveandLoadData(int action){
	switch(action) {
		case 0:
			loadCartFromFile();
			loadProductsFromFile();
			break;
		case 1:
			saveProducts();
			saveCartToFile();
			break;
	}
}

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
