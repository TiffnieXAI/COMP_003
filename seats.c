#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 4

// Step 1: Template for Seat Struct
typedef struct {
    int row;
    char col;
    int taken;
} Seat;

// Step 2: Initialize the 2D seat array
void initializeSeats(Seat plane[ROWS][COLS]) {
    char columns[COLS] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            plane[i][j].row = i + 1;
            plane[i][j].col = columns[j];
            plane[i][j].taken = 0;
        }
    }
}

// Step 3: Display the seating pattern
void displaySeats(Seat plane[ROWS][COLS]) {
    printf("\nCurrent Seating Arrangement:\n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (plane[i][j].taken)
                printf("X  ");
            else
                printf("%c  ", plane[i][j].col);
        }
        printf("\n");
    }
}

// Step 4: Assign seats to passengers
void assignSeats(Seat plane[ROWS][COLS]) {
    char seatInput[4];
    int row, col, filled = 0;

    while (filled < ROWS * COLS) {
        printf("\nEnter seat (e.g. 1A), or 0 to exit: ");
        scanf("%s", seatInput);

        if (seatInput[0] == '0') {
            printf("Exiting seat assignment.\n");
            break;
        }

        if (strlen(seatInput) < 2 || strlen(seatInput) > 3) {
            printf("Invalid input format. Try again.\n");
            continue;
        }

        if (strlen(seatInput) == 2) {
            row = seatInput[0] - '0';
        } else {
            row = (seatInput[0] - '0') * 10 + (seatInput[1] - '0');
        }

        char colLetter = toupper(seatInput[strlen(seatInput) - 1]);

        if (row < 1 || row > ROWS || colLetter < 'A' || colLetter > 'D') {
            printf("Invalid seat! Rows are 1-5 and columns A-D.\n");
            continue;
        }

        col = colLetter - 'A';

        if (plane[row - 1][col].taken) {
            printf("Seat %d%c is already taken. Choose another.\n", row, colLetter);
            continue;
        }

        plane[row - 1][col].taken = 1;
        filled++;

        printf("Seat %d%c successfully assigned.\n", row, colLetter);
        displaySeats(plane);
    }

    if (filled == ROWS * COLS)
        printf("\nAll seats are now filled!\n");
}

// Step 5: Main function
int main() {
    Seat plane[ROWS][COLS];
    initializeSeats(plane);
    displaySeats(plane);
    assignSeats(plane);
    return 0;
}

