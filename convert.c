#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "convert_to_base.h"

// Function to print the help message
void print_help() {
    printf("Usage: convert [-b BASE] [-r START FINISH]\n\n");
    printf("Options:\n");
    printf("  -b BASE          Specify the base for conversion (default is 16). Valid range is 2 to 36.\n");
    printf("  -r START FINISH  Convert numbers in the range from START to FINISH (inclusive).\n\n");
    printf("Description:\n");
    printf("  This program converts numbers to a specified base. If no arguments are provided, it reads numbers from standard input and converts them to the default base (16). If a base is specified with the `-b` option, it converts numbers to that base. The `-r` option allows converting a range of numbers from START to FINISH.\n\n");
    printf("Examples:\n");
    printf("  convert\n");
    printf("    Reads numbers from standard input and converts them to base 16.\n\n");
    printf("  convert -b 10\n");
    printf("    Reads numbers from standard input and converts them to base 10.\n\n");
    printf("  convert -r 1 10\n");
    printf("    Converts numbers from 1 to 10 to base 16.\n\n");
    printf("  convert -b 2 -r 1 10\n");
    printf("    Converts numbers from 1 to 10 to base 2.\n");
}

int main(int argc, char *argv[]) {
    long n;
    int base = 16; // Default base
    int min = 0, max = 0;
    bool isNegative = false;
    char sum[65]; // Assuming a maximum size for the sum array

    // Check if the user requested help
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    // Check if the user specified a base
    if (argc == 3) {
        base = atoi(argv[2]);
        if (base < 2 || base > 36) {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
            fprintf(stderr, "\t1 < BASE < 37\n");
            fprintf(stderr, "\tSTART and FINISH are long integers\n");
            return 1;
        }
    }

    // If no arguments or only base is specified, read numbers from standard input
    if (argc == 1 || argc == 3) {
        while (1) {
            if (scanf("%ld", &n) == EOF) {
                break; // End the loop if EOF is reached
            }
            if (n < 0) {
                isNegative = true;
                n = labs(n);
            }
            int index = 0;
            if (n == 0) {
                strcpy(sum, "0");
            } else {
                convert_to_base(n, base, sum, &index);
                sum[index] = '\0';
            }
            if (isNegative) {
                printf("-%s\n", sum);
            } else {
                printf("%s\n", sum);
            }
            isNegative = false;
        }
    } else if (argc == 4) {
        fflush(stdout);
        if (strcmp(argv[1], "-r") == 0) {
            min = atoi(argv[2]);
            max = atoi(argv[3]);
            for (long i = min; i <= max; i++) {
                if (i < 0) {
                    isNegative = true;
                    i = labs(i);
                }
                int index = 0;
                if (i == 0) {
                    strcpy(sum, "0");
                } else {
                    convert_to_base(i, base, sum, &index);
                    sum[index] = '\0';
                }
                if (isNegative) {
                    printf("-%s\n", sum);
                } else {
                    printf("%s\n", sum);
                }
                isNegative = false;
            }
        } else {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
            fprintf(stderr, "\t1 < BASE < 37\n");
            fprintf(stderr, "\tSTART and FINISH are long integers\n");
            return 1;
        }
    } else if (argc == 6) {
        base = atoi(argv[2]);
        min = atoi(argv[4]);
        max = atoi(argv[5]);
        if (base < 2 || base > 36) {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
            fprintf(stderr, "\t1 < BASE < 37\n");
            fprintf(stderr, "\tSTART and FINISH are long integers\n");
            return 1;
        }
        for (long i = min; i <= max; i++) {
            if (i < 0) {
                isNegative = true;
                i = labs(i);
            }
            int index = 0;
            if (i == 0) {
                strcpy(sum, "0");
            } else {
                convert_to_base(i, base, sum, &index);
                sum[index] = '\0';
            }
            if (isNegative) {
                printf("-%s\n", sum);
            } else {
                printf("%s\n", sum);
            }
            isNegative = false;
        }
    } else {
        fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
        fprintf(stderr, "\t1 < BASE < 37\n");
        fprintf(stderr, "\tSTART and FINISH are long integers\n");
        return 1;
    }

    return 0;
}
