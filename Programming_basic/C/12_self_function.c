/*
재귀함수
recursion
자기자신이 무한반복
return = 함수 종료
!계산
n! = n * (n-1)!
*/


#include <stdio.h>

void recursion(int a) {
    if(a > 5) return;
    printf("a = %d\n", a);
    recursion(a + 1);
}

int factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n-1);
}

int main(){
    rec(1);
    printf("%d\n", factorial(5));
}