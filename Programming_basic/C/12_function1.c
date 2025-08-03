/*
call by value
call by reference
gopa - 7913
*/

#include <stdio.h>


// call by value
void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

// call by reference1
void swap1(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// call by reference2
void swap2(int &a, int &b) {
    int tmp = &a;
    a = b;
    b = tmp;
}



int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);
    int c, d;
    scanf("%d %d", &c, &d);
    swap1(&c, &d);
    printf("c = %d, d = %d\n", c, d);
    int e, f;
    scanf("%d %d", &e, &f);
    swap2(e, f);
    printf("e = %d, f = %d\n", e, f);

}