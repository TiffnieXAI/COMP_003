#include <stdio.h>
#include <stdlib.h>
int main() {
    int size = 3;
    int array[size];
    int *p = array;
    *p = 0;
    p++;

    while (*p != 0) {
        printf("Enter Value: ");
        scanf("%d", p);
        p--;
    }
    p++;

    while (size > 0) {
        printf("%d\t", *p);
        p--;
        size--;
    }

}
