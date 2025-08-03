/*
배열 포인터

arr[i] == *(arr + i) == *(ptr + i) == *(i + ptr) == i[ptr]

a[b]를 C언어에서 *(a+b)로 바꿔서 처리


ptr이라고 적었지만 arr이어도 가능 다차원도 가능
1. ptr == &ptr[0]
2. *ptr == ptr[0]
3. ptr + 1 == ptr의 sizeof(*ptr)을 더한 값
ex - 1칸 당 4byte 
ptr : 4
-> 여기에 +1 = ptr + 1 = 8

*/

#include <stdio.h>

int main() {
    // int arr[3] = {1, 2, 3};
    // int *ptr = arr;

    // for(int i = 0; i < 3; i++){
    //     printf("%d ", *(ptr + i));
    // }
    // printf("\n");

    // for(int i = 0; i < 3; i++){
    //     printf("%d ", ptr[i]); // 이 표현 자주 써라
    // }
    // printf("\n");

    // for(int i = 0; i < 3; i++){
    //     printf("%d ", i[ptr]); // 쓰지 마라
    // }
    // printf("\n");

    // 배열의 주소
    int arr[3] = {1, 2, 3};
    printf("arr = %d\n", arr);
    printf("arr + 1 = %d\n", arr + 1);
    printf("&arr = %d\n", &arr);
    printf("&arr + 1 = %d\n", &arr + 1);

    // 배열 자체를 가리키는 포인터
    int arr1[3] = {1, 2, 3};
    int (*ptr_arr)[3]; // 길이 3인 int형 배열을 가리키는 포인터 선언, 배열포인터
    ptr_arr = &arr1; // arr1[0]의 주솟값

    for(int i = 0; i < 3; i++) {
        printf("%d\n", (*ptr_arr)[i]); // 주솟값 + 크기
    }




}