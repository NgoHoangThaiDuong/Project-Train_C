#include "libraryC.h"

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
