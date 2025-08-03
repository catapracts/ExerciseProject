/*
typedef = type definition : 형정의
ex) unsigned short int -> 쓰기 펴하게 usi로 바꾸는 행위
사용방법 : typedef int Int32; -> int 대신 Int32써도 됨
-> 제대로 형변환 됐는지 확인하려면 까다롭지만 간단하게 sizeof서서 확인해볼 수 있다.

Struct
typedef struct {int x, y} Pair;
Pair p;
p.x = 3;
p.y = 4;

구조체는 주로 main 밖 전역변수로도 사용 가능하다.

*/
#include <stdio.h>

typedef struct {int x, y;} Point; // struct Point {int x, y;}; -> 이렇게 선언해도 된다.

int main(){
    typedef int Pair[2];
    Pair point = {3,4}; // int point[2] = {3,4}; // (x,y)좌표
    printf("%d, %d", point[0], point[1]);

    typedef char *String;
    String *name = "F-22"; // char *name = "F-22";
    printf("name : %s\n", name);
   
    Point p; // 8byte
    p.x = 3;
    p.y = 4;
    printf("(%d, %d)\n", p.x, p.y);
    printf("%d", sizeof(p));

}