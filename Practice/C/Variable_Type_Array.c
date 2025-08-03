#include<stdio.h>


/*
선행처리(Preprocess) 
- 실행파일을 생성하는 과정에서 source파일내에 존재하는 선행처리지시문을 처리하는 작업
- compile하기 전 preprocessor에 의해 먼저 처리 = compiler가 compile하기 전에 source 재구성 역할
- #으로 시작 / ;X / 중간에 c언어 code 섞는 거 불가능 / 자기가 위치한 곳 기준부터 끝까지 영향
- 선행처리 지시자(preprocessing directives) : #include, #define, #line, #error, #pragma, #undef, #if, #ifdef, #ifndef, #elif, #else, #endif
- #include : 외부에 선언된 함수나 상수등을 사용하기 위해서 헤더 파일을 현재 파일에 포함할 때, 사용
표시방식 2가지 :  " #include<stdio.h> or #include"myStdio.h" 
<> : C언어 제공 표준 Header File, "" : User가 직접 작성한 Header File -> 일종의 기준 
- #define : 함수나 상수를 단순화해주는 macro정의시 사용 -> code 가독성 증가 
표시방식 : #define 이름(식별자) 값(대체리스트) -> 이렇게 치환하는 과정 = macro 확장 - 중첩 사용 가능, 빈값(공백) 사용 가능 
(ex)#define a 5; 


변수(variable)
- data를 저장하기 위해, Program에 의해 이름을 할당받은 Memory Space + 값 변경 가능 
- Memory Space받으면  Memory Address도 같이 가진다. 
- type : 정수(short, int, long), 실수(float, double), 문자(char), boolean, pointer, struct
- unsigned/signed 정수, 문자형 / long double -> 할당되는 memory 크기 & data표현 범위 다르다. 
- 생성 규칙 : 숫자로 시작X, 이름 사이 공백X, 미리간 정해진 keyword사용X(ex-int), 대소문자 구분(ex - int i랑 int I랑 서로 다른 변수 취급)
- 선언 : 자료형 변수이름; / 선언과 동시에 초기화 :  자료형 변수이름 = 값; / 대입 : 변수이름 = 값;
- 이렇게 선언도 가능 : 자료형 변수이름1, 변수이름 2; / 자료형 변수이름1=값, 변수이름2 = 값2;(자료형이 같을 때 가능)
*자료형 = Data type = type 
**Memory Space : data 저장 공간 
***Memory Address : Memory Space에서의 위치
****Memory length : variable이 차지하는 memory의 크기


상수(constant)
-  data를 저장하기 위해, Program에 의해 이름을 할당받은 Memory Space + 값 변경 불가능
- 표현 방식으로 구분 : Literal, Symbolic 
- Literal : 정수, 실수, 문자 type 존재 but 저장된 memory space가리키는 이름이 없음
(ex)123(정수형), 1.1(실수형), 'a'(문자형)
- Symbolic :  memory space가리키는 이름이 있음 / 반드시 선언+초기화 / const or macro이용
(ex) const int MAX=10; #define MAX 10;


형변환(type conversion)
- 다른 type끼리는 연산이 불가능하므로, 같은 type으로 만드는 작업
- 표현범위 小 ->  표현범위 大 (이상X) /  표현범위大 ->  표현범위小 (이상O - data손실 발생)
- 방식 2가지 : implicit(자동), explicit(강제)
*환t사용 시 C compiler의 기준 : char → short → int → long → float → double → long double 
explicit - type cast연산자 이용/ (변환하려고 하는 type)


연산자(Operator)
- Program의 산술식 or 연산식 표현/처리하는 기호
- 산술(+,-,*,/,%), 대입(=,+=,-=,*=,/=,%=), 증감(++,--), 비교(<,>,==,!=,>=,<=), 논리(&&,||,!), 비트(&,|,^,~,<<,>>), 기타(3연산자, pointer(&(주소),*(참조)), sizeof,)
- 우선순위 존재


배열(Array)
- 같은 type의 변수들로 이루어진 유한집합 / 같은 type data 많이 다뤄야할 경우 가장 자주 사용하는 기본 자료구조 /  N차원 배열 가능 
- 배열의 값 = element(요소), 배열의 값을 가리키는 숫자 = index(0부터 시작)
- 배열의 길이 = 항상 상수, C의 Compiler는 Array의 길이 신경 안 쓴다. 
- 선언 : DataType 배열이름[배열길이]; / 선언+초기화 : DataType 배열이름[배열길이] = {element1, element2, ...}; / 길이 없이 선언+초기화 : DataType 배열이름[] = {element1, element2, ...};
- 배열이 차지하는 메모리 크기 확인 방법 : 배열의 길이*sizeof(type) 
- 배열의 길이 확인하는 방법  = sizeof(배열 이름) / sizeof(배열 이름[0])
*/


int main(void)
{
 short a1; //크기 : 2byte 
 unsigned short a2; //크기 : 2byte
 int a3; //크기 : 4byte
 unsigned int a4; //크기 : 4byte
 long a5; //크기 : 4byte
 unsigned long a6; //크기 : 4byte
 
 float a7; //크기 : 4byte, 유효자릿수 : 소수 6번째 자리까지 
 double a8; //크기 : 8byte, 유효자릿수 : 소수 15번째 자리까지 
 long double a9; //크기 : 8byte
 
 char a10; //크기 : 1byte
 unsigned char a11; //크기 : 2byte
 
 //값을 ASCII code로 저장 
 char a12 = 'a';
 printf("a11 = %c\n", a12); //결과 : a12 = a
 printf("a11 = %d\n", a12); //결과 : a12 = 97
 
 printf("========================================\n");
 
 //implicit 
 char b = 150;
 int b1 = 1.11;
 double b2 = 3;
 printf("b = %d\n", b); //결과 : b = -106 -> 표현 범위를 벗어나서 발생한 오류 = 데이터 손실 발생 
 printf("b1 = %d\n", b1); //결과 : b1 = 1 -> 표현 범위를 벗어나서 발생한 오류 = 데이터 손실 발생 
 printf("b2 = %f\n", b2); //결과 : b2 = 3.000000 -> 표현 범위 안에 존재 = 데이터 손실 발생X
 
 double b3 = 5+1.1;
 double b4 = 5.0f+1.1;
 printf("b3 = %f\n", b3); //결과 : b3 = 6.100000 -> int랑 double 연산 시 int->double로 자동 형변환 
 printf("b4 = %f\n", b4); //결과 : b4 = 6.100000 -> float이랑 double 연산 시 float->double로 자동 형변환
 
 
 //explicit 
 int b5 = 1;
 int b6 = 2;
 double b7 = b5/b6;
 double b8 = (double)b5/b6;
 printf("b7 = %f\n", b7); //결과 : b7 = 0.000000 -> type 일치 
 printf("b8 = %f\n", b8); //결과 : b8 = 0.500000 -> type 일치X
 
 printf("========================================\n");
 
 //+,-,*,/,%
 int c = 10;
 int c1 = 3;
 printf("+ : %d\n", c+c1); // 결과 : + : 13
 printf("- : %d\n", c-c1); // 결과 : - :7
 printf("* : %d\n", c*c1); // 결과 : * :30
 printf("/ : %d\n", c/c1); // 결과 : / :3
 printf("나머지 : %d\n", c%c1); // 결과 : 나머지 :1
 
 printf("========================================\n");
 
 //+=,-=,*=,/=,%=
 int c2 = 10;
 int c3 = 10;
 printf("+= : %d\n", c2+=c3); // 결과 : += : 20
 printf("-= : %d\n", c2-=c3); // 결과 : -= : 10
 printf("*= : %d\n", c2*=c3); // 결과 : *= : 100
 printf("/= : %d\n", c2/=c3); // 결과 : /= : 10
 printf("나머지 : %d\n", c2%=c3); // 결과 : 나머지 : 0
 
 printf("========================================\n");
 
 
 //++,--
 int c4 = 10;
 printf("C4++ : %d\n", c4++); // 결과 : C4++ : 10 -> 처음 C(=10) 출력 후 +1 : 현재 C = 11
 printf("++C4 : %d\n", ++c4); // 결과 : ++C4 : 12 -> 처음 +1 후 C(=12) 출력: 현재 C = 12
 printf("C4-- : %d\n", c4--); // 결과 : C4-- : 12 -> 처음 C(=12) 출력 후 -1 : 현재 C = 11
 printf("--C4 : %d\n", --c4); // 결과 : --C4 : 10 -> 처음 -1 후 C(=10) 출력: 현재 C = 10
 int c5 = 11, c6 = c5-- + 10 + --c;
 printf("C6 : %d\n", c6); // 결과 : C6 : 30 -> 연산 순서 : 앞에 +(11+10 = 21) -> c5--(11->10) -> --c5(10->9) -> 뒤에 +(21+9=30) -> =(30)
 
 printf("========================================\n");
 
 //<, >, <=, >=, !=, ==
 int c7 =5, c8 = 4;
 printf(">결과 : %d\n", c6>c7); // >결과 : 1(True)
 printf(">=결과 : %d\n", c6>=c7); // >결과 : 1
 printf("<결과 : %d\n", c6<c7); // >결과 : 0(False)
 printf("<=결과 : %d\n", c6<=c7); // >결과 : 0
 printf("!=결과 : %d\n", c6!=c7); // >결과 : 1
 printf("==결과 : %d\n", c6==c7); // >결과 : 0
 
 printf("========================================\n");
 
 //&&, ||, !
 int c9 = 8, c10 = 9, c11, c12, c13;
 c11 = (c9>0)&&(c10<5);
 c12 = (c9>0)||(c10<5);
 c13 = !c9;
 printf("&&결과 : %d\n", c11); // &&결과 : 0  
 printf("||결과 : %d\n", c12); // &&결과 : 1
 printf("!결과 : %d\n", c13); // &&결과 : 0
 
 printf("========================================\n");
 
 // &, |, ^, ~, <<, >>
 int c14 = 1, c15 = 2;
 printf("&결과 : %d\n", c14&c15); // &결과 : 0 -> AND연산: C14(1=01) & C15(2=10) -> 결과 : 0(00), 둘다 1이어야 1 아니면 전부 0 
 printf("|결과 : %d\n", c14|c15); // |결과 : 3 -> OR연산: C14(1=01) & C15(2=10) -> 결과 : 3(11), 둘다 0이어야 0 아니면 전부 1
 printf("^결과 : %d\n", c14^c15); // ^결과 : 3 -> XOR연산: C14(1=01) & C15(2=10) -> 결과 : 3(11), 둘이 다르면  1 같으면 0
 printf("~결과 : %d\n", ~c14); // ~결과 : -2 -> NOT연산: C14(1=0001) -> 결과 : -2(110) , 맨 앞은 부호비트(0 : +, 1:-)로 사용하기도 한다. 
 printf("~결과 : %d\n", ~c15); // ~결과 : -3 -> NOT연산: C15(2=0010) -> 결과 : -3(111)
 printf(">>결과 : %d\n", c14>>1); // >>결과 : 0 -> >>연산 : C14(1=001) -> 결과 : 0(000)
 printf("<<결과 : %d\n", c14<<1); // <<결과 : 2 -> <<연산 : C14(1=001) -> 결과 : 2(010)
 printf(">>결과 : %d\n", c15>>1); // >>결과 : 1 -> >>연산 : C15(2=010) -> 결과 : 1(001)
 printf("<<결과 : %d\n", c15<<1); // >>결과 : 4 -> <<연산 : C15(2=010) -> 결과 : 4(100)
 
 printf("========================================\n");
 
 //기타 연산자 : 3항, sizeof 
 int c16 = 6, c17 = 4, c18;
 c18 = (c16>c17) ? c16 : c17;
 printf("더 큰수 : %d\n", c18); // 더 큰수 : 6
 printf("c16크기 : %d\n", sizeof(c16)); // c16크기 : 4(int형이므로 크기가 4byte)
 printf("c17크기 : %d\n", sizeof(c17)); // c17크기 : 4
 
 printf("========================================\n");
 
 //배열
 int d, d1=0, d2[3];
 d2[0] = 1; d2[1] = 2; d2[2] = 3;
 
 for(d=0;d<3;d++)
 {
 	d1 += d2[d];
 }
 
 printf("합 : %d, 평균 : %f\n\n", d1, (double)d1/3); // 결과 : 합 : 6, 평균 : 2.000000
 
 int d3, d4=0;
 int d5[3] = {90,90,90};
 
 for(d3=0;d3<3;d3++)
 {
 	d4 += d5[d3];
 }
 
 printf("합 : %d, 평균 : %f\n\n", d4, (double)d4/3); // 결과 : 합 : 270, 평균 : 90.000000
 
 int d6 = sizeof(d5)/sizeof(d5[0]);
 printf("d5배열의 길이 : %d\n", d6); // 결과 : d5배열의 길이 : 3
 
 int d7[] = {5,6,7};
}
