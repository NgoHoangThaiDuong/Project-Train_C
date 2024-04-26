#include "libraryC.h"

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


