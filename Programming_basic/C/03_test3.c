#include <stdio.h>

int main() {
    /*
    1. 100이하의 정수를 입력 받아 첫 줄에 짝수번째 숫자들을 출력하고, 다음 줄에 홀수번째 숫자들을 순서데로 출력하는 프로그램
    (ex)
    input : 7
    3 1 4 1 5 9 2

    output
    1 1 9
    3 4 5 2
    */

    // int a, b;
    // int arr[] = {};
    
    // printf("100이하 정수 입력 : ");
    // scanf("%d ", &a);

    // for(int i = 0; i < a; i++){
    //     scanf("%d ", &b);
    //     arr[i] = b;
    // }

    // for(int i = 0; i < sizeof(arr[i]); i++){
    //     if(arr[i] % 2 == 0) ;
    //     else if(arr[i] % 3 == 0) ;
    // }

    int n;
    int arr[105];
    
    printf("100이하 정수 입력 : ");
    scanf("%d ", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < n; i += 2){
        printf("%d ", arr[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i += 2){
        printf("%d ", arr[i]);
    }
    printf("\n");

    /*
    2. 코드 보고 예상되는 값 적기
    */
   int a = 10;
   int b = 20;
   int *ptr;
   ptr = &a;
   *ptr = 30;
   ptr = &b;
   *ptr = 10;

   printf("%d\n", a); // 30
   printf("%d\n", b); // 10
   printf("%d\n", *ptr); // 10

   /*
   3. 코드 보고 예상되는 값 적기
   */
  int arr1[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  printf("%d\n", arr1); // arr1[0]의 주솟값
  for(int i = 3; i < 7; i++){ // 1, 5, 9, 2
    printf("%d %d\n", arr1 + i, *(arr1 + i)); // arr1[3]의 주솟값 3, arr1[4]의 주솟값 11, arr1[5]의 주솟값 14, arr1[6]의 주솟값 5 
  }

  /*
  4. 10X10 이하의 정수형 이차원 배열을 입력받아 그 배열의 각 행의 요소의 합을 출력하는 프로그램
  ex
  input
  3 4
  4 2 6 3
  7 9 3 4
  5 1 2 1

  output
  15
  23
  9
  */
//   int a, b;
//   int arr2[100][100];
//   scanf("%d %d", &a, &b);

//   for(int i = 0; i < a; i++){
//     for(int j = 0; j < b; j++){
//         scanf("%d ", &arr2[i][j]);
//     }
//   }

//   int sum[100];
//   for(int i = 0; i < a; i++){
//     for(int j = 0; j < b; j++){
//         sum[i] += arr2[i][j];
//     }
//     printf("\n");
//   }

//   for(int i = 0; i < sizeof(sum); i++){
//     printf("%d\n", &sum[i]);
//   }

  int n, m;
  int arr2[12][12];
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        scanf("%d ", &arr2[i][j]);
    }
  }

  for(int i = 0; i < a; i++){
    int sum = 0;
    for(int j = 0; j < b; j++){
        sum += arr2[i][j];
    }
    printf("%d\n", sum);
  }


}