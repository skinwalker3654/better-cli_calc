#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "cli.h"

int main(int argc, char **argv) {
    float num1, num2;

    if(argc == 2 && strcmp(argv[1], help_comand) == 0) {
        help_info();
        return EXIT_SUCCESS;
    }

    if(argc < 3) {
        printf("Error: Invalid arguments passed.\n");
        printf("run './main --help' for more details\n");
        return EXIT_FAILURE;
    }

    char *end1;
    num1 = strtof(argv[2], &end1);
    if(*end1 || errno == ERANGE) {
        fprintf(stderr, "Error: Invalid argument, it must be a number\n");
        return EXIT_FAILURE;
    }

    if(argc == 3) {
        if(strcmp(argv[1], factorial) == 0) {
            factorial_of(num1);
            return EXIT_SUCCESS;
        }
        if(strcmp(argv[1], log_num) == 0) {
            printf("The log of %.2f is %.2f\n", num1, log_of(num1));
            return EXIT_SUCCESS;
        }
        if(strcmp(argv[1], sqrt_num) == 0) {
            printf("The square root of %.2f is %.2f\n", num1, square_root(num1));
            return EXIT_SUCCESS;
        }
        if(strcmp(argv[1], round_nums) == 0) {
            printf("%f rounded is %.2f\n", num1, round_num(num1));
            return EXIT_SUCCESS;
        }

        fprintf(stderr, "Error: This command requires a second number\n");
        fprintf(stderr, "run './main --help' for more ditails\n");

        return EXIT_FAILURE;
    }

    if(argc != 4) {
        fprintf(stderr, "Error: Invalid number of arguments for this command.\n");
        fprintf(stderr, "run './main --help' for more details\n");
        return EXIT_FAILURE;
    }

    char *end2;
    num2 = strtof(argv[3], &end2);
    if(*end2 || errno == ERANGE) {
        fprintf(stderr, "Error: Invalid argument, it must be a number\n");
        return EXIT_FAILURE;
    }

    if(strcmp(argv[1], addition) == 0) {
        printf("%.2f + %.2f = %.2f\n", num1, num2, add_nums(num1, num2));
    } else if(strcmp(argv[1], subtraction) == 0) {
        printf("%.2f - %.2f = %.2f\n", num1, num2, sub_nums(num1, num2));
    } else if(strcmp(argv[1], multiplication) == 0) {
        printf("%.2f * %.2f = %.2f\n", num1, num2, mul_nums(num1, num2));
    } else if(strcmp(argv[1], division) == 0) {
        if(num2 == 0) {
            printf("Error: division by 0!\n");
            return EXIT_FAILURE;
        }
        printf("%.2f / %.2f = %.2f\n", num1, num2, div_nums(num1, num2));
    } else if(strcmp(argv[1], power_numbers) == 0) {
        pow_nums(num1, num2);
    } else if(strcmp(argv[1], max_nums) == 0) {
        printf("%.2f > %.2f\n", max_num(num1, num2), (num1 > num2) ? num2 : num1);
    } else if(strcmp(argv[1], min_nums) == 0) {
        printf("%.2f < %.2f\n", min_num(num1, num2), (num1 > num2) ? num1 : num2);
    } else if(strcmp(argv[1], modulo) == 0) {
        printf("%.2f %% %.2f = %d\n", num1, num2, mod_nums(num1, num2));
    } else {
        fprintf(stderr, "Error: Invalid command\n");
        fprintf(stderr, "run './main --help' for more ditails\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

