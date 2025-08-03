/*
2차원 배열 & 배열 포인터
*/

#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d\n", sizeof(arr)); // 24
    printf("%d\n", sizeof(arr[0])); // 12
    printf("%d\n", sizeof(arr[0][0])); // 4
    printf("%d\n", &arr); // arr[0][0] 주소값
    printf("%d\n", &arr[0]); // arr[0][0] 주소값
    printf("%d\n", &arr[0][0]); // arr[0][0] 주소값

    // 검증 1. ptr[i] == arr[i]?
    // 검증 2. ptr[i][j] == arr[i][j]?
    // 검증 3. ptr == arr?

    int(*ptr)[3] = arr; // int(*ptr)[3] = &arr[0]; -> 2차원 배열의 한 행을 가리킬 수 있는 배열포인터를 만들어서 2차원 배열을 넣음

    for(int i = 0; i < 2; i++) { // 배열 포인터가 2차원 배열 역할 함
        for(int j = 0; j < 3; j++){
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }


    for(int(*row)[3] =arr; row < arr + 2; row++){
        for(int *col = *row; col < *row + 3; col++){ // col = *row = &(*row)[0]
            printf("%d ", *col);
        }
        printf("\n");
    }



}