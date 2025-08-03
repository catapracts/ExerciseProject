/*
제어문 - if, while, for

중첩 if, {} code style

switch
goto -> 코드 복잡해질 수 있어서 잘 안 씀

*/

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("n is even\n");
    }
    else {
        printf("n is odd\n");
    }

    if(n % 2){
        printf("n is odd\n");
    }
    else {
        printf("n is even\n");
    }

    if(1){ // 1(True) = 무조건 실행됨, 0(False) = 무조건 실행 안됨
        printf("***\n");
    }
    else {
        printf("$$$\n");
    }

    if(n > 0){
        printf("n is positive\n");
    }
    else if(n == 0){
        printf("n is zero\n");
    }
    else {
        printf("n is naegative\n");
    }

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(a > b){
        if(a > c) printf("%d\n", a);
        
        else printf("%d\n", c);
    } else if(b > c) printf("%d\n", b);
    else printf("%d\n", c);

    int choice;
    makeChoice:
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("새 게임\n");
            break; // switch문에서 빠져나감, 없으면 그냥 차례대로 switch 끝날 때까지 계속 내려감
        case 2:
            printf("불러오기\n");
            break;
        case 3:
            printf("크레딧\n");
            break;
        case 4:
            printf("설정\n");
            break;
        case 5:
            printf("게임 종료\n");
            break;
        default:
            printf("다시 입력\n");
            goto makeChoice;
            break;
    }

    int i = 1;
    repeat:
    if(i<10){
        i++;
        goto repeat;
    }


}