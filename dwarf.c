#include <stdio.h>

// Function Prototypes
void dwarf(int n);        
void dwarfAAP(int *n);   
void dwarfPAA(int *p);   

int main() {
    // Array initialization
    int x[5] = {1, 2, 3, 4, 5};
    
    printf("\nArray:\n");
    // Passing array elements as values
    for (int i = 0; i < 5; i++) {
        dwarf(x[i]);
    }

    printf("\n\nArray as Pointers:\n");
    // Passing array elements as pointers
    for (int i = 0; i < 5; i++) {
        dwarfAAP(x + i);
    }

    int *p = x; // Pointer pointing to the array
    printf("\n\nPointers as Array:\n");
    // Passing pointer arithmetic reference to function
    for (int i = 0; i < 5; i++) {
        dwarfPAA(p + i);
    }
}

// Function to check if a number is dwarf (passed by value)
void dwarf(int n) {
    int sumOfFact = 0;

    for (int i = 1; i < n; i++) {
        if (n == 1) {
            printf("%d is dwarf\n", n);
            return;
        }
        else if (n % i == 0) { // Finding proper divisors
            sumOfFact += i;
        }
    }

    // Checking the dwarf number condition
    if (sumOfFact > (n / 2)) {
        printf("\n%d is dwarf\n", n);
    } else {
        printf("\n%d not dwarf\n", n);
    }
}

// Function to check if a number is dwarf (array element passed as pointer)
void dwarfAAP(int *n) {
    int sumOfFact = 0;
    
    for (int i = 1; i < *n; i++) {
        if (*n == 1) {
            printf("%d is dwarf\n", *n);
            return;
        }
        else if (*n % i == 0) { // Finding proper divisors
            sumOfFact += i;
        }
    }

    // Checking the dwarf number condition
    if (sumOfFact > (*n / 2)) {
        printf("\n%d is dwarf\n", *n);
    } else {
        printf("\n%d not dwarf\n", *n);
    }
}

// Function to check if a number is dwarf (pointer used as array reference)
void dwarfPAA(int *p) {
    int sumOfFact = 0;
    
    for (int i = 1; i < *p; i++) {
        if (*p == 1) {
            printf("%d is dwarf\n", *p);
            return;
        }
        else if (*p % i == 0) { // Finding proper divisors
            sumOfFact += i;
        }
    }

    // Checking the dwarf number condition
    if (sumOfFact > (*p / 2)) {
        printf("\n%d is dwarf\n", *p);
    } else {
        printf("\n%d not dwarf\n", *p);
    }
}
