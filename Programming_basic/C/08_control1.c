/*
제어문 - 반복문 : while, for
반복문의 조건에 맞지 않아도 무조건 1번은 실행시키기 : do-while
무한반복

for
- 일정하게 증감하는 함수 필요시
- 배열의 모든 element에 순차적으로 접근하고 싶을 때
- 특정 횟수만큼 작업 반복

break - loop 1개 빠져나오기
continue - 
중첩for문(매우 중요)

*/

#include <stdio.h>

int main(){
    // int i = 1;
    // while(i <= 10){
    //     printf("%d\n", i);
    //     i++;
    // }

    // int j = 1;
    // do {
    //     printf("%d\n", j);
    //     j++;
    // } while(j <= 10);

    // int k = 1;
    // while (1){
    //     printf("%d", k);
    // };

    // int l;
    // do {
    //     printf("0 입력\n");
    //     scanf("%d", &l);
    // } while(l != 0);
    // printf("0 입력됨\n");

    // int m;
    // scanf("%d", &m);
    // int n = 0; int p = 1;
    // while(n <= m){
    //     printf("2^%d = %d\n", n, p);
    //     n++;
    //     p*=2;
    // }




    for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);      
    }

    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i *= 2){
        printf("%d\n", i);
    }

    int m;
    scanf("%d",&m);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    printf("sum = %d\n", sum);

    int j;
    scanf("%d", &j);
    for(int i = 1; i<=n; i++){
        printf("*");
    }

    // for(int i = 1; ; i++){
    //     printf("%d", i);
    // } 무한loop

    int k;
    scanf("%d",&k);
    for(int i = 0, j = 1; i <= k; i++, j*=2){
        printf("2^%d = %d\n", i, j);
    }

    int l;
    scanf("%d",&l);
    int sum1 = 0;
    for(int i = 0; i <= l; sum1 += i, i++);
    printf("%d\n", sum1);

    for(int i = 1; ; i++){
        int j;
        scanf("%d", &j);
        if(j == 0) break;
        else printf("%d번째 : %d\n", i, j);
    }

    int m;
    scanf("%d",&m);
    int sum2 = 0;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0){
            continue; // 아래 코드로 안 나가고 i++로 감 = loop 다 안 돌고 건너뜀 -> 굳이 써야할 이유가?
        }
        sum += i;
    }
    printf("%d\n", sum2);

    // 중첩for문 - 정사각형 만들기
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("*");
        }
        printf("\n");
    }

    // 중첩for문 - 계단 만들기
    int q;
    scanf("%d",&q);
    for(int i = 1; i <= q; i++){
        for(int j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
}