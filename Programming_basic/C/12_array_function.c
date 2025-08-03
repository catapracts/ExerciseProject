/*
배열을 매개변수로 사용하기
call-by-value : 값만 전달
call-by-reference : 참조만 전달
int arr[4] = int *arr과 같은 의미
arr = &arr[0]과 같은 값
arr[i] *= 2 = *(arr+i)와 같은 값
arr 0번째에 있는 값부터 차례대로 *2gofk

*/

// int arr[4] = { 1, 2, 3, 4 };

// void printArr() {
//     for(int i = 0; i < 4; i++){
//         printf("%d ", arr[i]);
//     }    
// }


void printArr(int arr[4]) { // 얘는 call-by-reference임
    for(int i = 0; i < 4; i++){
        arr[i] *= 2; // 이 함수가 call-by-value라면 1,2,3,4 call-by-reference면 모든원소에 2씩 곱해져서 나올 것
        printf("%d ", arr[i]);
    } 
}

/*
2차원 배열을 매개변수로 쓸 경우 배열 포인터 사용
&arr[0] = 0번째 열의 주소지

*/

void printArr1(int (*arr)[3]) {
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


#include <stdio.h>

int main() {
    int arr[4] = { 1, 2, 3, 4 };

    printArr(arr);

    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }

    int arr1[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    printArr1(arr1);
}