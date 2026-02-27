#include <stdio.h>

void add(double a, double b, double *result) { *result = a + b; }
void sub(double a, double b, double *result) { *result = a - b; }
void mul(double a, double b, double *result) { *result = a * b; }

void div(double a, double b, double *result) { if (b) *result = a / b; }

int main(void) {
    double a, b;
    char op;
    double result;

    if (scanf("%lf %c %lf", &a, &op, &b) != 3) return 0;

    if (op == '+') {
        add(a, b, &result);
    } else if (op == '-') {
        sub(a,b,&result);
    } else if (op == '*') {
        mul(a, b, &result);
    } else if (op == '/') {
        div(a, b, &result);
        if (!b) { printf("ERROR");return 1;}
    }
    printf("%.10g", result);
    return 0;
}
