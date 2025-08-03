/*
Operator

산술연산자 - 수학연산 : +, -, *, %, = / +=, -=, *=, /=, %= / ++, --
비교연산자 - 크기비교 : <, >, <=, >=, ==, !=
boolean : 진리값 저장용 변수 1byte
논리연산자 - 2개의 명제 연산 / and, or, not : &&, ||, !

*/

#include <stdio.h>

int main(){
    // 산술연산자
    int a = 5;
    printf("a는 원래 %d\n", a);
    a = a + 3;
    printf("a = %d\n", a);
    a += 6;
    printf("a = %d\n", a);
    a -= 8;
    printf("a = %d\n", a);
    a *= 3;
    printf("a = %d\n", a);
    a &= 7;
    printf("a = %d\n", a);
    a++; // 선 대입 후 증가
    printf("a = %d\n", a);
    a--; // 선 대입 후 감소
    printf("a = %d\n", a);
    ++a; // 선 증가 후 대입
    printf("a = %d\n", a);
    --a; // 선 감소 후 대입
    printf("a = %d\n", a);

    // 비교연산자
    int b, c;
    scanf("%d%d", &a, &b);
    
    int d = b > c;
    int e = b < c;
    int f = b == c;
    printf("%d\n", d);
    printf("%d\n", e);
    printf("%d\n", f);

    // 논리연산자
    int g;
    scanf("%d", &g);
    bool h = g >=1 && g<= 10;
    bool i = g == 3 || g == 7;
    bool j = !g;
    printf("%d\n", h);
    printf("%d\n", i);
    printf("%d\n", j);


}