/*
문제1
정수 하나를 매개변수로 받아서, 그 수가 짝수이면 0, 홀수이면 1을 반환하는 함수 작성
*/
#include <stdio.h>

// int parity(int n) {
//     int a;
//     if(n%2 == 0) {
//         a = 0;
//         return a;
//     }
//     else if(n%2 == 1) {
//         a = 1;
//         return a;
//     } 
//     else {
//       printf("not odd or even");
//     }
// }

int parity(int n) {
    if(n%2 == 0) {
        return 0;
    }
    else {
      return 1;
    }
}

int parity1(int n) {
    if(n%2 == 0) {
        return 0;
    }
    return 1;
}

int parity2(int n) {
    return (n % 2 + 2) % 2;
}

int main() {
    printf("%d\n", parity(5));
    printf("%d\n", parity(-3));
    printf("%d\n", parity(6));
}

/*
2. 프로그램 실행 결과
#include <stdio.h>

int useCnt[5] = {0}

void useItem(int);

int main(){
    useItem(4);
    useItem(2);
    useItem(1);
    useItem(4);
    useItem(0);

    for(int i = 0; i < 5; i++){
        printf("슬롯%d의 아이템을 %d번 사용했습니다.\n", i. useCnt[i]);
    }
}

void useItem(int itemNum){
    useCnt[itemNum]++;
}

결과
슬롯0의 아이템을 1번 사용했습니다.
슬롯1의 아이템을 1번 사용했습니다.
슬롯2의 아이템을 1번 사용했습니다.
슬롯3의 아이템을 0번 사용했습니다.
슬롯4의 아이템을 2번 사용했습니다.

*/

/*
3. 프로그램 실행 결과
#include <stdio.h>

void rec(int n) {
    if(n == 0) return;
    printf("%d", n);
    rec(n-1);
    printf("%d", n);
}

int main(){
    rec(5);
}


결과
543212345
답)5432112345
*/


/*
4. 문자열을 매개변수로 받아 그 문자열에서 공백을 제거하여 출력하는 함수 작성
#include <stdio.h>

void print_noSpace(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != '')
            printf("%c", str[i]);
    }
}

int main(){
    print_noSpace("Hello, World!\n");
    print_noSpace("My name is F-22\n");
}


*/
