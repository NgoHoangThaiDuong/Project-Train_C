#include <ctype.h> 
#include <math.h> 
#include <stdio.h> 
#include <string.h>
#include <malloc.h> 
#include <time.h> 
#include <stdlib.h> 
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
    printf("Enter Product Name : ");
    scanf("%s", product.name);
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
        printf("No products to display!\n");
        return;
    }
	for (i = 0; i < productCount; i++) {
    printf("Product list:\n");
    printf("ID: %d\n", products[i].id );
    printf("Product Name: %s\n", products[i].name);
    printf("Price: %.2f\n", products[i].price);
    printf("Quantity in Stock: %d\n", products[i].quantityInStock);
}
}
void editProduct(int productId) {
    int found = 0;
    int i;
    for ( i = 0; i < productCount; i++) {
        if (products[i].id == productId) {
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product price:: ");
            scanf("%f", &products[i].price);
            printf("Enter new quantity in stock: ");
            scanf("%d", &products[i].quantityInStock);
            found = 1;
            printf("Product information updated!\n");
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
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
            printf("Product deleted!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
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
                printf("Product added to cart!\n");
            }else {
                printf("Quantity of product is insufficient!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Product not found!\n");
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
    printf("Your cart is empty!\n");
    return;
    }
    for ( i = 0; i < itemCount; i++) {
    printf("Your cart:\n");
    printf("ID: %d\n", cart[i].product.id);
    printf("Product Name: %s\n", cart[i].product.name);
    printf("Price: %.2f\n", cart[i].product.price);
    printf("Quantity: %d\n", cart[i].quantity);
    printf("Total Price: %.2f\n", calculateTotalPrice());
    return;
}
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
            printf("Product removed from cart!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found in cart!\n");
    }
    return;
}




