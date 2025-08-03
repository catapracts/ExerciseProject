/*
포인터 배열 : 포인터 여러 개 / 포인터들의 배열
배열 포인터 : 포인터 1개 / 배열을 가리키는 포인터
*/

#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40;
    int *ptr[4]; // 포인터 배열 선언
    ptr[0] = &a, ptr[1] = &b, ptr[2] = &c, ptr[3] = &d;
    printf("%d, %d, %d, %d ", ptr[0], ptr[1], ptr[2], ptr[3]);
    printf("%d, %d, %d, %d ", *ptr[0], *ptr[1], *ptr[2], *ptr[3]);

    int arr[4] = {1, 2, 3, 4};
    int *ptr1[4];

    for(int i = 0; i < 4; i++){
        ptr1[i] = &arr[i];
    }

    for(int i = 0; i < 4; i++){
        printf("%d ", *ptr1[i]);
    }
    printf("\n");


    char str[] = "Hello"; // 6개 char형 배열
    printf("%s\n", str); // printf("%s\n", &str[0]); -> 0번째 칸을 가리키면 null문자 나올 때까지 순서대로 출력 = %s

    char strings[3][10] = {"Hello", "World", "F-22"};
    char *p_str[3];

    for(int i = 0; i < 3; i++){
        printf("%s\n", &strings[i][0]); // printf("%s\n", strings[i]);
    }

    for(int i = 0; i < 3; i++){
        p_str[i] = &strings[i][0];
    }

    for(int i = 0; i < 3; i++){
        printf("%s\n", p_str[i]);
    }

}