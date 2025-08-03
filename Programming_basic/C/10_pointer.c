/*
pointer : 변수의 주소를 저장하는 변수

*/

#include <stdio.h>

int main(){
    int a = 20;
    int *ptr_a;
    ptr_a = &a;
    printf("%d\n", ptr_a); // 주소값 나옴
    printf("a의 값 :  %d\n", a);
    printf("a의 주솟값 :  %d\n", &a);
    printf("ptr_a에 저장된 값 :  %d\n", ptr_a);
    printf("ptr_a가 가리키는 변수의 값 :  %d\n", *ptr_a);

    int b = 10;
    int c = 20;
    int *ptr;
    ptr = &b;
    printf("ptr에 저장된 값 : %d\n", *ptr);
    ptr = &c;
    printf("ptr에 저장된 값 : %d\n", *ptr);

    int d = 10;
    int *ptr_b;
    ptr_b = &d;
    printf("d의 값 : %d\n", d);
    *ptr_b = 20;
    printf("d의 값 : %d\n", d);

    int e = 10;
    int *ptr_c;
    ptr_c = &e;
    int **ptr_ptr;
    ptr_ptr = &ptr_c;
    printf("e = %d\n", e);
    printf("&e = %d\n", &e); // 주소값
    printf("ptr_c = %d\n", ptr_c); // 주소값
    printf("&ptr_c = %d\n", &ptr_c); // 주소값
    printf("ptr_ptr = %d\n", ptr_ptr); // 주소값
    printf("*ptr_ptr = %d\n", *ptr_ptr); // 주소값
    printf("**ptr_ptr = %d\n", **ptr_ptr); // e값

}