#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function for adding a product to the stock
 int addProduct(int codes[], int quantities[], int numProducts) {
    int code, quantity;
    printf("Enter the code of the product : ");
    scanf("%d", &code);
    printf("Enter the quantity that you want to add : ");
    scanf("%d", &quantity);
    
    // Verifying if the product does already exist in the stock
    for (int i = 0; i < numProducts; i++) {
        if (codes[i] == code) {
            quantities[i] += quantity; // Adding to the existent quantity
            printf("The quantity is added to the stock.\n");
            return numProducts;
        }
    }

    // If the product does not exist, add it to the stock
    codes[numProducts] = code;
    quantities[numProducts] = quantity;
    printf("The product is added to the stock.\n");
    return numProducts + 1;
}

// Function to remove a product from stock
int removeProduct(int codes[], int quantities[], int numProducts) {
    int code, quantity;
    printf("Enter the code of the product : ");
    scanf("%d", &code);
    printf("Enter the quantity that you want to remove : ");
    scanf("%d", &quantity);

    // Verifying if the product exists in the stock
    for (int i = 0; i < numProducts; i++) {
        if (codes[i] == code) {
            // Verifying if the quantity to be removed is valid
            if (quantity > quantities[i]) {
                printf("Error : the quantity to be removed is greater than the quantity that is in the stock.\n");
            }
            else {
                quantities[i] -= quantity;
                printf("Quantity is removed from the stock.\n");
            }
            return numProducts;
        }
    }

    // If the product does not exist, display a message of error
    printf("Error: the product does not exist in the stock.\n");
    return numProducts;
}

// Function for displaying the total stock
void displayStock(int codes[], int quantities[], int numProducts) {
    printf("Total stock :\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product %d - Quantity : %d\n", codes[i], quantities[i]);
    }
}

int main() {
    // Initial stock is empty
    int codes[100]; // Supposing a maximum capacity of 100 products
    int quantities[100];
    int numProducts = 0;

    char choice;
    do {
        // Display the menu
        printf("\nMenu :\n");
        printf("1. Add a product to the stock\n");
        printf("2. Remove a product from the stock\n");
        printf("3. Display the total stock\n");
        printf("4. Exit\n");

        // Asking the user to choose
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Perform the corresponding action
        switch (choice) {
        case '1':
            numProducts = addProduct(codes, quantities, numProducts);
            break;
        case '2':
            numProducts = removeProduct(codes, quantities, numProducts);
            break;
        case '3':
            displayStock(codes, quantities, numProducts);
            break;
        case '4':
            printf("Program completed.\n");
            break;
        default:
            printf("Invalid choice. Try Again.\n");
        }
    } while (choice != '4');

    return 0;
}

