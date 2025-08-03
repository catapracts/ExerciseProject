#include <stdio.h>

int main(){
    
    // 1. 두 숫자를 입력받아 숫자들의 합을 출력하는 프로그램
    // int a, b;
    // scanf("%d%d", &a, &b);
    // printf("%d + %d = %d\n", a, b, a+b);

    // 2. 체중(kg, real)과 키(m, real)를 입력 받아서 체질량 지수 구하기, BMI = 체중/키^2
    // float weight, height;
    // printf("height(m) : ");
    // scanf("%f", &height);
    // printf("weight(kg) : ");
    // scanf("%f", &weight);
    // float bmi = weight / (height*height);
    // printf("BMI : %f\n", bmi);

    // 3. 알파벳 입력 받아서 그 다음 알파벳 출력
    char a;
    printf("input character : ");
    scanf("%c", &a);
    char b = a+1;
    printf("next characte : %c\n", b);

}