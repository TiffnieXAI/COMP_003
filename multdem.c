/*
 * Program Description:
 * This program initializes a 2D array of size 2x3, takes user input for all elements,
 * and searches for a user-specified value within the array. If the value is found,
 * the program prints the index of the first occurrence; otherwise, it notifies the user
 * that the value is not present.
 */

 #include <stdio.h>

 int main() {
     int a = 2; // Number of rows
     int b = 3; // Number of columns
     int X[2][3]; // 2D array declaration
     int found = 0; // Flag to track if the value is found

     printf("Please Input Values.\n");
     // Get input for the 2D array
     for (int i = 0; i < a; i++) {
         for (int j = 0; j < b; j++) {
            printf("X[%d][%d]: ", i, j);
             if (scanf("%d", &X[i][j]) != 1) { // Validate input
                 printf("Invalid Input!\n");
                 return 1;
             }
         }
     }
     // Get the element to search
     int dv;
     printf("Input Desired Value: ");
     if (scanf("%d", &dv) != 1) { // Validate input
         printf("Invalid Input!\n");
         return 1;
     }

     // Search for the desired value in the 2D array
     for (int i = 0; i < a; i++) {
         for (int j = 0; j < b; j++) {
             if (X[i][j] == dv) { // Check if the current element matches the search value
                 printf("Existing Value!\nIndex: X[%d][%d]\n", i, j);
                 found = 1; // Mark as found
                 break; // Exit inner loop once found
             }
         }
     }

     // If value is not found in the array
     if (found == 0) {
         printf("Value Not Found!\n");
     }

     return 0;
 }

