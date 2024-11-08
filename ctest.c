#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "convert_to_base.h"

int main(int argc, char *argv[]) {
    long n;
    int base = 16; // Default base
    int min = 0, max = 0;
    bool isNegative = false;
    char sum[65]; // Assuming a maximum size for the sum array

    if (argc == 1) {
        while (1) {
            if (scanf("%ld", &n) == EOF) {
                break; // End the loop if EOF is reached
            }
            if (scanf("%ld", &n) != 1) {
                // Handle non-long-int input
                fprintf(stderr, "Error: Non-long-int token encountered.\n");
                // Clear the input buffer
                while (getchar() != '\n'); // Clear the invalid input
                continue; // Prompt for input again
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
    } else if (argc == 3) {
        base = atoi(argv[2]);
        if (base < 2 || base > 36) {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH] \n\t 1<BASE<37 \n\t START and FINISH are long integers. \n");
            return 1;
        }
        while (1) {
            if (scanf("%ld", &n) == EOF) {
                break; // End the loop if EOF is reached
            }
            if (scanf("%ld", &n) != 1) {
                // Handle non-long-int input
                fprintf(stderr, "Error: Non-long-int token encountered.\n");
                return 1;
                // Clear the input buffer
                while (getchar() != '\n'); // Clear the invalid input
                continue; // Prompt for input again
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
    } else if (argc == 4 && strcmp(argv[2], "-r") == 0) {
        min = atoi(argv[3]);
        max = atoi(argv[4]);
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
                i = i - i - i;
            } else {
                printf("%s\n", sum);
            }
            isNegative = false;
        }
    } else if (argc == 6) {
        base = atoi(argv[2]);
        min = atoi(argv[4]);
        max = atoi(argv[5]);
        if (base < 2 || base > 36) {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH] \n\t 1<BASE<37 \n\t START and FINISH are long integers. \n");
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
                i = i - i - i;
            } else {
                printf("%s\n", sum);
            }
            isNegative = false;
        }
    } else if (argc == 4) {
        // Handle other cases if needed
    } else {
        fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH] \n\t 1<BASE<37 \n\t START and FINISH are long integers. \n");
        return 1;
    }

    return 0;
}
