#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// STEP 1: Define structure for a shoe record
typedef struct {
    int styleNumber;
    int stockPerSize[12];
    float price;
} Shoe;

#define MAX_SHOES 100
Shoe inventory[MAX_SHOES];
int shoeCount = 0;

// STEP 2: Function to find shoe index by style number
int findShoe(int styleNumber) {
    for (int i = 0; i < shoeCount; i++) {
        if (inventory[i].styleNumber == styleNumber)
            return i;
    }
    return -1; // Not found
}

// STEP 3: Function to display all shoe records
void displayAllRecords() {
    if (shoeCount == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n%-12s%-10s%-15s\n", "Style No.", "Price", "Stock (Size 3-14)");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < shoeCount; i++) {
        printf("%-12d%-10.2f", inventory[i].styleNumber, inventory[i].price);
        for (int j = 0; j < 12; j++) {
            printf("%2d ", inventory[i].stockPerSize[j]);
        }
        printf("\n");
    }
}
//STEP 4: Main loop for user menu
int main() {
    int choice, InErr;

    while (1) {
        printf("\n========================\n");
        printf("   SHOE STORE INVENTORY\n");
        printf("========================\n");
        printf("1. Enter New Record\n");
        printf("2. Display Record\n");
        printf("3. Change Price\n");
        printf("4. Change Stock on Hand\n");
        printf("5. Display All Records\n");
        printf("6. Exit Program\n");

        while (1) {
            printf("Enter your choice: ");
            InErr = scanf("%d", &choice); // Input validation
            while (getchar() != '\n'); // Clear Input Buffer
            if (InErr == 1 && choice >= 1 && choice <= 6)
                break;
            printf("Invalid input! Please enter 1 to 6 only.\n");
        }

        if (choice == 1) {
            if (shoeCount >= MAX_SHOES) {
                printf("Inventory full!\n");
                continue;
            }

            while (1) {
                printf("Enter Style Number (0–50): ");
                InErr = scanf("%d", &inventory[shoeCount].styleNumber);
                while (getchar() != '\n');
                if (InErr == 1 && inventory[shoeCount].styleNumber >= 0 && inventory[shoeCount].styleNumber <= 50)
                    break;
                printf("Invalid style number! Try again.\n");
            }

            while (1) {
                printf("Enter Price: ");
                InErr = scanf("%f", &inventory[shoeCount].price);
                while (getchar() != '\n');
                if (InErr == 1)
                    break;
                printf("Invalid price! Try again.\n");
            }

            for (int i = 0; i < 12; i++) {
                while (1) {
                    printf("Enter stock for size %d: ", i + 3);
                    InErr = scanf("%d", &inventory[shoeCount].stockPerSize[i]);
                    while (getchar() != '\n');
                    if (InErr == 1 && inventory[shoeCount].stockPerSize[i] >= 0)
                        break;
                    printf("Invalid stock! Try again.\n");
                }
            }

            shoeCount++;
            printf("Record added successfully!\n");

        } else if (choice == 2) {
            int style;
            printf("Enter style number to display: ");
            scanf("%d", &style);
            int idx = findShoe(style);
            if (idx == -1) {
                printf("Style number not found.\n");
                continue;
            }
            printf("\nStyle: %d\n", inventory[idx].styleNumber);
            printf("Price: %.2f\n", inventory[idx].price);
            for (int i = 0; i < 12; i++) {
                printf("Size %d: %d pairs\n", i + 3, inventory[idx].stockPerSize[i]);
            }

        } else if (choice == 3) {
            int style;
            printf("Enter style number to update price: ");
            scanf("%d", &style);
            int idx = findShoe(style);
            if (idx == -1) {
                printf("Style number not found.\n");
                continue;
            }
            float newPrice;
            while (1) {
                printf("Enter new price: ");
                InErr = scanf("%f", &newPrice);
                while (getchar() != '\n');
                if (InErr == 1 && newPrice >= 0) {
                    inventory[idx].price = newPrice;
                    printf("Price updated.\n");
                    break;
                }
                printf("Invalid price! Try again.\n");
            }

        } else if (choice == 4) {
            int style;
            printf("Enter style number to update stock: ");
            scanf("%d", &style);
            int idx = findShoe(style);
            if (idx == -1) {
                printf("Style number not found.\n");
                continue;
            }

            while (1) {
                int sizeToUpdate;
                printf("Enter shoe size to update stock (3–14), or 0 to stop: ");
                InErr = scanf("%d", &sizeToUpdate);
                while (getchar() != '\n');
                if (InErr == 1 && sizeToUpdate == 0) {
                    break;
                }
                if (InErr != 1 || sizeToUpdate < 3 || sizeToUpdate > 14) {
                    printf("Invalid size! Enter between 3 and 14 or 0 to finish.\n");
                    continue;
                }

                int newStock;
                while (1) {
                    printf("Enter new stock for size %d: ", sizeToUpdate);
                    InErr = scanf("%d", &newStock);
                    while (getchar() != '\n');
                    if (InErr == 1 && newStock >= 0) {
                        inventory[idx].stockPerSize[sizeToUpdate - 3] = newStock;
                        printf("Stock updated for size %d.\n", sizeToUpdate);
                        break;
                    }
                    printf("Invalid input! Try again.\n");
                }
            }

        } else if (choice == 5) {
            displayAllRecords();

        } else if (choice == 6) {
            char confirm;
            while (1) {
                printf("Are you sure you want to exit? (Y/N): ");
                scanf(" %c", &confirm);
                while (getchar() != '\n');
                if (confirm == 'Y' || confirm == 'y') {
                    printf("Exiting program.\n");
                    return 0;
                } else if (confirm == 'N' || confirm == 'n') {
                    printf("Returning to menu...\n");
                    break;
                } else {
                    printf("Invalid input. Enter Y or N.\n");
                }
            }
        }
    }
    return 0;
}
