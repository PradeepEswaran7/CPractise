#include <stdio.h>
#include <stdlib.h>
#include "shopping_cart.h"

int main() {
    ShoppingCart cart;
    cart.size = 0;

    int choice;

    while (1) {
        printf("\nWelcome to Pradeep Shopping Market\n");
        printf("1. List of Products\n");
        printf("2. Add Product to Cart\n");
        printf("3. Update Product in Cart\n");
        printf("4. Remove Product from Cart\n");
        printf("5. View Cart\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showProducts();
                break;
            case 2:
                addProductToCart(&cart);
                break;
            case 3:
                updateProductInCart(&cart);
                break;
            case 4:
                removeProductFromCart(&cart);
                break;
            case 5:
                viewCart(&cart);
                break;
            case 6:
                printf("Thank you for shopping! Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
