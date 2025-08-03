/*
sizeof(x) : x의 크기 확인 / x = 자료형, 변수이름

실수를 정수형 변수에 담는 것 불가능
정수를 실수형 변수에 담는 것 가능

형변환 : 자료형을 다른 자료형으로 바꾸기
(형변환할 자료형)변수이름


int / int = int
float(double) / int = float(double)
float(double) / float(double) = float(double)

int + int = int
int + float(double) = float(double)
float(double) + float(double) = float(double)
*/

#include <stdio.h>

int main(){
    printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));
    int a; char b; float c; double d;
    printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));
    int e = 3.14; double f = 10;
    printf("%d %f\n", a, b); // a = 3, b = 10.000000
    int g = -3.14; double h = 10;
    printf("%d %f\n", g, h); // a = -3, b = 10.000000

    int math = 90, korean = 95, english = 96;
    int sum = math + korean + english;
    double avg = sum / 3;
    printf("%f\n", avg); //93.666667

    // 1. sum : int -> double
    // 2. (double)sum / 3;

}