#include <stdio.h>

int main() {
    /*STEP 1:
    - Initialize size to 100 since magiging dynamic yung array (unsure kung gaano kadami yung input), temporary lang si 100 para di aksayado sa memory
    - Yung variable 'count' will keep track of the no. of elements na malalagay sa array then yun yung gagamiting actual size later
    */
    int size = 100, count = 0;

    /* STEP 2:
    - Initialize an array para *p gets to actually point at something in the memory
    - Also, para kapag nag p++ or p-- tayo, it can point on a memory na pwedeng malagyan ng value, di yung occupied na
    */
    int array[size];
    int *p = array;

    while (1) {
        printf("Enter Value: ");
        scanf("%d", p);
        count++; //Ito na yung tracking of the actual size
        if (*p == 0)
            break;
        p++;
    }

    count-- //exclude si zero sa printing ng elements
    p--;

    while (count > 0) {
        printf("%d\t", *p);
        p--;
        count--;
    }

    return 0;
}
