#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cli.h"

float add_nums(float a, float b) { return a + b; }
float sub_nums(float a, float b) { return a - b; }
float mul_nums(float a, float b) { return a * b; }
float div_nums(float a, float b) { return a / b; }
float round_num(float a) { 
    float rounded_num = roundf(a * 10) / 10; 
    return rounded_num; 
}

float max_num(float a, float b) {
    if (a == b) {
        printf("%.2f = %.2f\n", a, b);
        exit(EXIT_SUCCESS);
    }
    return (a > b) ? a : b;
}

float min_num(float a, float b) {
    if (a == b) {
        printf("%.2f = %.2f\n", a, b);
        exit(EXIT_SUCCESS);
    }
    return (a < b) ? a : b;
}

int mod_nums(float a, float b) {
    if (a != (int)a || b != (int)b) {
        printf("Error: Modulo only supports integers. You gave: %.2f and %.2f\n", a, b);
        exit(EXIT_FAILURE);
    }
    if ((int)b == 0) {
        printf("Error: modulo by 0\n");
        exit(EXIT_FAILURE);
    }
    return (int)a % (int)b;
}

float square_root(float a) {
    if (a < 0) {
        printf("Error: Can't sqrt negative numbers\n");
        exit(EXIT_FAILURE);
    }
    return sqrtf(a);
}

float log_of(float a) {
    if (a <= 0) {
        printf("Error: log input must be > 0\n");
        exit(EXIT_FAILURE);
    }
    return logf(a);
}

float pow_nums(float a, float b) {
    if (a < 0 || b < 0) {
        printf("Invalid input: pow() doesn't accept negative numbers\n");
        exit(EXIT_FAILURE);
    }
    printf("%.2f^%.2f = %.2f", a, b, a);
    for (int i = 1; i < b; i++) printf(" * %.2f", a);
    printf(" = %.2f\n", pow(a, b));
    return pow(a, b);
}

int factorial_of(float a) {
    if ((int)a < 0) {
        printf("Negatives don't have factorials\n");
        exit(EXIT_FAILURE);
    }

    int n = (int)a;
    if (n == 0 || n == 1) {
        printf("%d! = 1\n", n);
        return 1;
    }

    int result = 1;
    printf("%d! = 1", n);
    for (int i = 2; i <= n; i++) {
        printf(" * %d", i);
        result *= i;
    }
    printf(" = %d\n", result);
    return result;
}

void help_info(void) {
    fprintf(stderr, "Usage: ./main <command> <num1> <num2>\n");
    fprintf(stderr, "Commands: add sub mul div pow --fac --log\n");
    fprintf(stderr, "          max min --round --sqrt mod\n");
}

