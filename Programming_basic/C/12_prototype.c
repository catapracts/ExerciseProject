/*
prototype - 함수 틀만 만들고 내용은 안 만드는것
일반적으로 main 밑에 있으면 프로그램 동작 안함
그러나 prototype으로 미리 선언하고 그 내용을 다른 곳에 두면
한 함수안에 여러 함수 사용이 가능
= 함수 선언 순서 신경 안 서도 됨 / 어떤 함수들이 있는지 한 번에 파악 가능 = 코드 간결


*/

#include <stdio.h>

// prototype 함수
void walk(int distance);
void walk(int angle);
void drawSquare();


int main(){
    drawSquare();

}

// 로봇수학 - 걷기
void walk(int distance){
    printf("%d 걷기\n", distance);
}

// 로봇수학 - 회전
void walk(int angle){
    printf("%d 회전", angle);
}

// 사각형 이동
void drawSquare(){
    for(int i = 0; i <=4 ; i++){
        walk(10);
        rotate(90);
    }
}