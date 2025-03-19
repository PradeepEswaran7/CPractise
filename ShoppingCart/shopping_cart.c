#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shopping_cart.h"

// Predefined list of products
Product products[MAX_PRODUCTS] = {
    {1, "Apple", 50.0f},
    {2, "Orange", 100.0f},
    {3, "Mango", 150.0f},
    {4, "Banana", 200.0f}
};

void showProducts() {
    printf("\nAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("ID: %d | Name: %s | Price: %.2f\n", 
               products[i].productId, products[i].productName, products[i].productPrice);
    }
}

void addProductToCart(ShoppingCart *cart) {
    int id, qty;
    printf("\nEnter the Product ID to add to the cart: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTS) {
        printf("Invalid Product ID!\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("Quantity must be greater than 0.\n");
        return;
    }

    // Check if product already exists in cart
    for (int i = 0; i < cart->size; i++) {
        if (cart->items[i].productId == id) {
            cart->items[i].productQty += qty;
            cart->items[i].totalPrice = cart->items[i].productQty * products[id - 1].productPrice;
            printf("Updated quantity for %s in cart.\n", cart->items[i].productName);
            return;
        }
    }

    // Add new item to cart
    cart->items[cart->size].productId = id;
    strcpy(cart->items[cart->size].productName, products[id - 1].productName);
    cart->items[cart->size].productQty = qty;
    cart->items[cart->size].totalPrice = qty * products[id - 1].productPrice;
    cart->size++;

    printf("%s added to cart.\n", products[id - 1].productName);
}

void updateProductInCart(ShoppingCart *cart) {
    if (cart->size == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    int id, qty;
    printf("\nEnter the Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < cart->size; i++) {
        if (cart->items[i].productId == id) {
            printf("Enter new quantity for %s: ", cart->items[i].productName);
            scanf("%d", &qty);

            if (qty <= 0) {
                printf("Quantity must be greater than 0.\n");
                return;
            }

            cart->items[i].productQty = qty;
            cart->items[i].totalPrice = qty * products[id - 1].productPrice;
            printf("Updated %s in cart.\n", cart->items[i].productName);
            return;
        }
    }

    printf("Product not found in cart.\n");
}

void removeProductFromCart(ShoppingCart *cart) {
    if (cart->size == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    int id, index = -1;
    printf("\nEnter the Product ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < cart->size; i++) {
        if (cart->items[i].productId == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found in cart.\n");
        return;
    }

    for (int i = index; i < cart->size - 1; i++) {
        cart->items[i] = cart->items[i + 1];
    }
    cart->size--;

    printf("Product removed from cart.\n");
}

void viewCart(ShoppingCart *cart) {
    if (cart->size == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    float total = 0;
    printf("\nYour Cart:\n");
    for (int i = 0; i < cart->size; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Total Price: %.2f\n", 
               cart->items[i].productId, cart->items[i].productName, cart->items[i].productQty, cart->items[i].totalPrice);
        total += cart->items[i].totalPrice;
    }

    printf("Total Amount: %.2f\n", total);
}
