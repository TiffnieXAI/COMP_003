#include <stdio.h>

typedef struct {
    int value;
    char suit;
} Poker;

// STEP 1: Score the hand
void scoreHand(int valueCount[], Poker hand[], int size) {
    int onepair = 0, threeKind = 0, fourKind = 0;
    int isFlush = 1;
    char firstSuit = hand[0].suit;

    // STEP 2: Check if all suits are the same, for suits
    for (int i = 1; i < size; i++) {
        if (hand[i].suit != firstSuit) {
            isFlush = 0;
            break;
        }
    }

    // STEP 3: Count pairs, three-of-a-kind, four-of-a-kind, for values to
    for (int i = 1; i <= 13; i++) {
        if (valueCount[i] == 2) onepair++;
        else if (valueCount[i] == 3) threeKind++;
        else if (valueCount[i] == 4) fourKind++;
    }

    // STEP 4: Output hand category
    if (fourKind) printf("Four of a Kind\n");
    else if (threeKind && onepair) printf("Full House\n");
    else if (isFlush) printf("Flush\n");
    else if (threeKind) printf("Three of a Kind\n");
    else if (onepair == 2) printf("Two Pairs\n");
    else if (onepair == 1) printf("One Pair\n");
    else printf("Nothing\n");
}

int main() {
    // STEP A: Sample handz
    Poker Hand[5] = {
        {1, 'H'}, {1, 'H'}, {1, 'D'}, {4, 'D'}, {5, 'D'}
    };

    // STEP B: Count values
    int valueCount[14] = {0};
    for (int i = 0; i < 5; i++)
        valueCount[Hand[i].value]++;

    // STEP C: Analyze hand
    scoreHand(valueCount, Hand, 5);

    return 0;
}
