/*
상수 <-> 변수
상수 지정 - const, 매크로, enum
상수는 대문자만 사용해서 표시

비트논리연산자 : &, | ^ ~
시프트연산자 : >>, <<

파일입출력

*/

#include <stdio.h>

// 매크로
#define PI 3.14159 // memory에 안 올라감 = 주소값 할당 X
#define PRINT_HELLLO printf("Hello")
#define SQUARE(X) ((X) * (X)) // 매개변수 있는 매크로 만들 때, 괄호 사용 안 하면, 식 이상하게 계산된다. 
#define MAX(A,B) (((A)>(B)) ? (A) : (B))
#define FOR(I,S,E) for (int I = S; I <= E; I++)
//#define LOOP while (true) // 무한루프


// enum : 보통 E로 시작, 자료형 없어도 자동으로 int 취급, 값 생략해도 자기가 알아서 번호 순서대로 매겨준다. 중간 수정도 가능
enum EGameState {
    GAMESTATE_MAINMENU,
    GAMESTATE_PLAYING,
    GAMESTATE_PAUSED,
    GAMESTATE_GAMEOVER
}

int main(){
    // const float PI = 3.141592; // memory에 저장됨
    float a = PI;
    printf("pi = %.2f\n", PI);
    //printf("&PI = %d\n", &PI);

    int curState = 0;

    while(true) {
        switch(curState) {
            case GAMESTATE_MAINMENU:
                break;
            
            case GAMESTATE_PLAYING:
                break;
            
            case GAMESTATE_PAUSED:
                break;
            
            case GAMESTATE_GAMEOVER:
                break;           
        }
    }

    PRINT_HELLLO

    int a;
    scanf("%d", a);
    printf("%d\n", SQUARE(a));
    printf("%d\n", SQUARE(a - 1));

    int b = 5, c = 10;
    printf("%d\n", MAX(b,c));

    FOR(i, 1, 10) {
        printf("%d ", i);
    }

    char a = 12, b = 10;
    printf("%d\n", a & b); // and
    printf("%d\n", a | b); // or
    printf("%d\n", a ^ b); // XOR
    printf("%d\n", ~a); //not

    char a = 22;
    printf("%d\n", a << 1);
    printf("%d\n", a >> 1);
    printf("%d\n", a << 3);
    printf("%d\n", a >> 3);
    printf("%d\n", a << 6); // 왼쪽으로 이동할 경우 char형 자료형으로는 표현 가능한 범위가 벗어나서 아얘 새로운 자료형을 C가 자동으로 바꿔서 감
    printf("%d\n", a >> 6); // 오른쪽으로 이동할 경우는 아얘 잘려서 없어짐

}