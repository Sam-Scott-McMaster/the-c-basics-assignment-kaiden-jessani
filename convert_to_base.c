#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void convert_to_base(long num, int base, char* total, int* index) {
    static char list_of_base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (num == 0) {
        return;
    }
    convert_to_base(num / base, base, total, index);
    total[*index] = list_of_base[num % base];
    (*index)++;
}

int sizeArr(long num, int base) {
    int counter = 0;
    while (num > 0) {
        counter++;
        num = num / base;
    }
    return counter;
}
