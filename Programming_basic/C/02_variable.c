/*

RAM에 data 저장, 불러오기 등의 행위를 할 때 사용하는 게 변수
int a
-> 그릇 모양 int : 크기 - 4byte(32bits)
-> 그릇 이름 a
변수 만들다 = 선언




*/

#include <stdio.h>

int main(){
    int a;

    a = 3; // a라는 그릇에 3이라는 내용물을 넣다.
    printf("%d\n", a);

    a = 5; // a라는 그릇에 5라는 내용물을 넣다. 기존 3 대신 5가 넣어진다.
    printf("%d\n", a);

    int b = 4;
    printf("%d + %d = %d\n", a, b, a+b);

    int c = a+b;
    printf("%d + %d = %d\n", a, b, c);

    
}