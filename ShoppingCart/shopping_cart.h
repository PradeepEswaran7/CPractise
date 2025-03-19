#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#define MAX_PRODUCTS 4
#define MAX_CART_ITEMS 10

// Product structure
typedef struct {
    int productId;
    char productName[20];
    float productPrice;
} Product;

// ShoppingCartItem structure
typedef struct {
    int productId;
    char productName[20];
    int productQty;
    float totalPrice;
} ShoppingCartItem;

// ShoppingCart structure
typedef struct {
    ShoppingCartItem items[MAX_CART_ITEMS];
    int size;
} ShoppingCart;

// Function prototypes
void showProducts();
void addProductToCart(ShoppingCart *cart);
void updateProductInCart(ShoppingCart *cart);
void removeProductFromCart(ShoppingCart *cart);
void viewCart(ShoppingCart *cart);

#endif // SHOPPING_CART_H
