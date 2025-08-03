#include <stdio.h>

int main(){
    int a = 10;
    int *ptr_a = &a;
    printf("ptr_a의 값 : %d\n", ptr_a); // 주소값
    printf("ptr_a + 1의 값 : %d\n", ptr_a + 1); // 주소값

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("arr의 값 : %d\n", arr); // arr[0]의 주소
    for(int  i = 0; i < 10; i++){
        printf("&arr[%d] = %d\n", i, &arr[i]); // arr[i] = i번째 주소값
        printf("arr + %d = %d\n", i, arr + i); // arr[i] = i+1번째 주소값
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]); // 배열 값들 출력
    }
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", *(arr + i)); // 배열 값들 출력
    }
    printf("\n");

    for(int *ptr = arr; ptr < arr + 10; ptr++){
        printf("%d ", *ptr); // 배열 값들 출력
    }
    printf("\n");

    

}