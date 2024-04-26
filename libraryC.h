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

void addProduct();
void displayProducts();
void editProduct(int productId);
void deleteProduct(int productId);
void addToCart(int productId, int quantity);
float calculateTotalPrice();
void displayCart();
void removeFromCart(int productId);
void saveProducts();
void saveCartToFile();
void loadProductsFromFile();
void loadCartFromFile();
void edit_order();
void create_order();
bool check_name();
bool check_email();
int check_password();
bool check_phone_and_age();
void login();
void signup();
void SaveandLoadData(int action);
