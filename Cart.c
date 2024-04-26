#include "libraryC.h"

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
