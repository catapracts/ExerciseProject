/*
printf, scanf 보다 속도면에서 유리
getchar, putchar -> 문자 1, 2개 입/출력 받을때 유용
gets, puts -> 문자 여러 개 입/출력 받을때 유용

string으로 입/출력 받기
sscanf / sprintf

난수발생
rand();
seed를 같이 사용, 얘에 따라 난수 발생이 달라짐 -> 보통 현재 시간을 넣는다.
게임 개발에 자주 사용

exit(0);
프로그램 종료
*/

#include <stdio.h>
#include <stdlib.h> // Standard Library
#include <time.h>

int main() {
    char ch;
    ch = getchar();
    putchar(ch);

    char str[100];
    gets_s(str);
    puts(str);

    char str[] = "450";
    int n;
    sscanf(str, "%d", &n);
    printf("%d", n);

    int n = 450;
    char str[100];
    sprintf(str, "%d", n);
    printf("%s\n", str);

    printf("%d\n", time(NULL)); // 1970/01/01 00:00:00로부터 지난 시간을 초 단위 기준으로 출력 2037년까지 사용가능
    srand(time(NULL)); // seed 넣기
    for(int i = 0; i <= 100; i++) {
        printf("%d\n", rand() % 10 + 1); // 1~10 사이 랜덤한 숫자 출력
    }

    int sum = 0;

    for(int i = 0; i < 5; i++){
        int n;
        scanf("%d", &n);
        if(n <= 0){
            printf("INPUT ERROR\n");
            exit(0);
        }
        sum += n;
    }
    printf("%d\n", sum);
}