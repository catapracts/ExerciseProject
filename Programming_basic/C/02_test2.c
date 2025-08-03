// 제어문 테스트

#include <stdio.h>

int main(){
    /*
    1. 시험 점수 입력 받아서 그에 따라 출력
    90~100 : A / 80~89 : B / 70~79 : C / 60~69 : D / 50~59 : E / 50미만 : F
    */
//    first:

//    int score;
//    printf("점수 입력 : ");
//    scanf("%d", &score);

//    if(score >= 90 && score <= 100) printf("A\n");
//    else if(score >= 80 && score < 90) printf("B\n");
//    else if(score >= 70 && score < 80) printf("C\n");
//    else if(score >= 60 && score < 70) printf("D\n");
//    else if(score >= 50 && score < 60) printf("E\n");
//    else if(score < 50) printf("F\n");
//    else {
//     printf("다시 입력하세요.\n");
//     goto first;
//    }

//    int score;
//    printf("점수 입력 : ");
//    scanf("%d", &score);
//    if(score > 100 || score < 0) printf("잘못 입력하셨습니다.\n");
//    else {
//     if(score >= 90) printf("A\n");
//     else if(score >= 80) printf("B\n");
//     else if(score >= 70) printf("C\n");
//     else if(score >= 60) printf("D\n");
//     else printf("E\n");
//    }


    /*
    2. 자연수 입력하면 입력한 수의 약수들 출력하고 맨 마지막은 ,으로 끝나게 출력
    12 입력 -> 1, 2, 3, 4, 6, 12, 출력
    */
//    int input;
//    printf("자연수 입력 : ");
//    scanf("%d", &input);

//    for(int i = 1; i <= input; i++){
//     if(input % i == 0){
//         printf("%d, ", i);
//     }
//    }

//    for(int i = 1; i <= input / 2; i++){
//     if(input % i == 0){
//         printf("%d, ", i);
//     }
//    }
//    printf("%d\n", input);


    /*
    3. 3, 6, 9게임
    1의 자릿수가 3, 6, 9면 *을 대신 출력
    1 2 * 4 5 * 7 8 * ... n까지
    */

//    int input;
//    printf("숫자 입력 : ");
//    scanf("%d", &input);

// //    for(int i = 1; i <= input; i++){
// //     if(i % 3 == 0){
// //         printf("* ");
// //         continue;
// //     }
// //     printf("%d ", i);
// //    }

//    for(int i = 1; i <= input; i++){
//     int k = i % 10;
//     if(k == 3 || k == 6 || k == 9){
//         printf("* ");
//     }
//     else printf("%d ", i);
//    }
//    printf("\n");


    /*
    4. 숫자 출력하기
    숫자 1개 입력 - 해당 숫자만큼 줄이랑 숫자 출력
    입력 4
    1
    1 3
    1 3 5
    1 3 5 7
    */
    // printf("숫자 입력 : ");
    // int input;
    // scanf("%d", &input);

    // // for(int i = 1; i <= input; i++){
    // //     for(int j = 1; j <= i; j += 2){
    // //         printf("%d ", j);
    // //     }
    // //     printf("\n");
    // // }

    // for(int i = 1; i <= input; i++){
    //     for(int j = 1; j <= i; j++){
    //         printf("%d ", 2 * j - 1);
    //     }
    //   printf("\n");
    // }

    // for(int i = 1; i <= input; i++){
    //     for(int j = 1; j <= 2 * i - 1; j+=2){
    //         printf("%d ", j);
    //     }
    //   printf("\n");
    // }


    /*
    5. 숫자 출력하기2
    입력 4
    1
    1 2 3
    1 2 3 4 5
    1 2 3 4 5 6 7
    */

    printf("숫자 입력 : ");
    int input;
    scanf("%d", &input);

    for(int i = 1; i <= input; i++){
        for(int j = 1; j <= 2*i-1; j++){
            printf("%d ", j);
        }
      printf("\n");
    }

    for(int i = 1; i <= 2 * input - 1; i += 2){
        for(int j = 1; j <= i; j++){
            printf("%d ", j);
        }
      printf("\n");
    }


}