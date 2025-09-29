#include <stdio.h>

void callByValue(int x) {
    x += 10;
    printf("x=%d\n", x);
}

void callByReference(int *x) {
    *x += 10;
    printf("x=%d\n", *x);
}

int main() {
    int a = 20, b = 30;
    printf("a = %d\n", a);
    callByValue(a);
    printf("a=%d\n",a);
    printf("\nb=%d\n",b);
    callByReference(&b);
    printf("b=%d\n",b);
    return 0;
}