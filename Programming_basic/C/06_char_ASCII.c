/*
char = 1byte int
character = 문자(반각문자 - 알파벳, 숫자, 기호)

ASCII : 문자-숫자 표 / 제어문자, 숫자, 기호 등이 존재

*/

#include <stdio.h>

int main(){
    // char a = 67;
    // printf("%d\n", a);
    // printf("%c\n", a); // C
    // printf("%d\n",'C'); // 67

    // char b;
    // scanf("%c", &b);
    // printf("input : %c\n", b);

    char c;
    printf("input Character : ");
    scanf("%c", &c);
    printf("%c of ASCII : %d\n", c,c);

    int d;
    printf("input number : ");
    scanf("%d", &d);
    printf("%d of ASCII : %c\n", d,d);

}