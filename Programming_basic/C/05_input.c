/*

& = pointer

scanf = 숫자 구분 되어 있는 거 인식함

*/

#include <stdio.h>

int main(){
    // int a, b;

    // scanf("%d%d", &a, &b);

    // int plus = a + b;
    // int minus = a - b;
    // int product = a * b;
    // int divide = a / b;

    // printf("%d + %d = %d\n", a, b, plus);
    // printf("%d - %d = %d\n", a, b, minus);
    // printf("%d * %d = %d\n", a, b, product);
    // printf("%d / %d = %d\n", a, b, divide);

    // float c, d;
    // scanf("%f%f", &c, &d);

    // float plus1 = c + d;
    // float minus1 = c - d;
    // float product1 = c * d;
    // float divide1 = c / d;

    // printf("%f + %f = %f\n", c, d, plus1);
    // printf("%f - %f = %f\n", c, d, minus1);
    // printf("%f * %f = %f\n", c, d, product1);
    // printf("%f / %f = %f\n", c, d, divide1);

    double e, f;
    scanf("%lf%lf", &e, &f);

    printf("%lf + %lf = %lf\n", e, f, e+f);
    printf("%lf - %lf = %lf\n", e, f, e-f);
    printf("%lf * %lf = %lf\n", e, f, e*f);
    printf("%lf / %lf = %lf\n", e, f, e/f);
}