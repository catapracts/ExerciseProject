#include<stdio.h>
int bigNum (int, int); // 함수의 원형 선언

/*
제어문(control flow statements) 
- ~.C = 절차적 프로그램(procedural program) 또는 명령형 프로그램(Imperative program)
- 프로그램의 이러한 순차적인 흐름을 제어 / 종류 :  조건문, 반복문 등
- 중괄호({} = block)사용해서 영역 표시 




조건문(conditional statements)
- 주어진 조건식의 결과에 따라 별도의 명령을 수행하도록 제어하는 명령문
- if / if-else /  if - else if - else / switch
- if : 조건식의 결과 = 참(true) : 주어진 명령문을 실행, 거짓(false) : 아무것도 실행X / 연속으로 사용가능 
- if-else :  조건식의 결과 = 참(true) : if에 주어진 명령문을 실행, 거짓(false) : else에 주어진 명령문을 실행/ 3항 연산자로 간단하게 구현 가능 
- if - else if - else : 조건식의 결과 = 참(true) : if or else-if에 주어진 명령문을 실행, 거짓(false) : else에 주어진 명령문을 실행
- switch
  - if / else 문보다 가독성이 더 좋으며, 컴파일러가 최적화를 쉽게 할 수 있어 속도 또한 빠른 편
  - 주어진 조건 값의 결과에 따라 프로그램이 다른 명령을 수행하도록 하는 조건문
  - 조건 값으로는 int형으로 승격할 수 있는(integer promotion) 값만 사용= if / else 문보다는 사용할 수 있는 상황이 적은 편
  - default 절은 조건 값이 위에 나열된 어떠한 case 절에도 해당하지 않을 때 실행 / 반드시 존재해야 하는 것은 아니며 필요할 때에만 선언

     


반복문(iteration statements)
- 프로그램 내에서 똑같은 명령을 일정 횟수만큼 반복하여 수행하도록 제어하는 명령문
- 가장 많이 사용되는 제어문 중 하나
- while / do-while / for 
- while : 조건식이 참(true)인지를 판단하여, 참이면 내부의 명령문을 실행-> 내부의 명령문을 전부 실행하고 나면, 다시 조건식으로 돌아와 또 한 번 참인지를 판단
*표현식의 검사를 통해 반복해서 실행되는 반복문 = 루프(loop)
- do-while : 먼저 루프를 한 번 실행한 후에 조건식을 검사= 건식의 결과와 상관없이 무조건 한 번은 루프를 실행
- for : 자체적으로 초기식, 조건식, 증감식을 모두 포함하고 있는 반복문 / 초기식, 조건식, 증감식은 각각 생략가능 / 



기타제어문 
- loop 제어 - continue, break 
- continue : 루프 내에서 사용하여 해당 루프의 나머지 부분을 건너뛰고, 바로 다음 조건식의 판단으로 넘김 /  보통 반복문 내에서 특정 조건에 대한 예외 처리를 하고자 할 때 자주 사용
- break : 루프 내에서 사용하여 해당 반복문을 완전히 종료시킨 뒤, 반복문 바로 다음에 위치한 명령문을 실행 /  반복문을 완전히 빠져나가고 싶을 때 사용
- goto : 프로그램의 흐름을 지정된 레이블(label)로 무조건 변경시키는 명령문 / 른 제어문과는 달리 아무런 조건 없이 프로그램의 흐름을 옮김 / 가장 손쉽게 사용할 수 있지만, 반면에 프로그램의 흐름을 매우 복잡하게 만들 수 있음 -> 현재는 디버깅 이외에는 거의 사용X 




함수(Function)
- 하나의 특별한 목적의 작업을 수행하기 위해 독립적으로 설계된 프로그램 코드의 집합
- 종류: 표준 함수, 사용자 정의 함수
- 사용 이유 : 반복적인 프로그래밍을 피할 수 있기 때문 - > 특정 작업을 여러 번 반복해야 할 때는 해당 작업을 수행하는 함수를 작성, 호출, 수행


- 함수 정의
return type 함수이름(매개변수들){함수 Body}
-> return type : 작업을 마치고 반환하는 데이터의 타입
-> 함수 이름 : 함수를 호출하기 위한 이름
-> 매개변수들(parameters) : 함수 호출 시에 전달되는 인수의 값을 저장할 변수들
-> 함수 Body : 명령문의 집합

- 함수의 원형(prototype) 선언
-> C언어 = 단일 패스(one pass) 컴파일 방식 = 차례대로 한 번에 컴파일 = 위치에 따라 작성한 코드가 실행 안 될 수 있다.
-> main() 함수 앞에 미리 선언하면 함수를 어느 위치에서 구현을 하든 상관 없게 된다.  
*다중 패스(multi-pass) 방식 = 컴파일러에 따라 여러 번에 걸쳐 컴파일




변수의 유효범위(variable scope) 
- 변수의 선언 위치에 따라 해당 변수의 유효 범위, 메모리 반환 시기, 초기화 여부, 저장되는 장소 등이 변경
- 범위에 따라 구분 : 지역 변수(local variable), 전역 변수(global variable), 정적 변수(static variable), 레지스터 변수(register variable)
- 지역 변수(local variable) : '블록' 내에서 선언된 변수 / 블록 내에서만 유효하며, 블록이 종료되면 메모리에서 사라짐 /   메모리상의 스택(stack) 영역에 저장 / 초기화하지 않으면 의미 없는 값(쓰레기값)으로 초기화 / (ex)함수의 매개변수
- 전역 변수(global variable) : 함수의 외부에서 선언된 변수 /  프로그램의 어디에서나 접근 / 프로그램이 종료되어야만 메모리에서 사라짐 / 메모리상의 데이터(data) 영역에 저장 / 직접 초기화하지 않아도 0으로 자동 초기화
- 정적 변수(static variable) : static 키워드로 선언한 변수 / 지역 변수와 전역 변수의 특징을 모두 가짐 / 함수 내에서 선언된 정적 변수는 전역 변수처럼 단 한 번만 초기화되며(초기화는 최초 실행 시 단 한번만 수행됨), 프로그램이 종료되어야 메모리상에서 사라짐 +  지역 변수처럼 해당 함수 내에서만 접근  
- 레지스터 변수(register variable) : 지역 변수를 선언할 때 register 키워드를 붙여 선언한 변수 /  CPU의 레지스터(register) 메모리에 저장되어 빠르게 접근 /  레지스터는 매우 작은 크기의 메모리 -> 영역에 변수를 선언하기 힘든 경우多 -> C 컴파일러는 해당 변수를 그냥 지역변수로 선언 




재귀호출(recursive call)
- 함수 내부에서 함수가 자기 자신을 또다시 호출하는 행위
- 재귀 호출은 자기가 자신을 계속해서 호출하므로, 끝없이 반복 -> 함수 내에 재귀 호출을 중단하도록 조건이 변경될 명령문을 반드시 포함
- 재귀 호출은 알고리즘이나 자료 구조론에서는 매우 중요한 개념 중 하나 - 재귀 호출을 사용하면 복잡한 문제도 매우 간단하게 논리적으로 접근하여 표현가능
- 재귀호출의 장점 : 코드의 간결함
- 재귀호출의 단점 : 무한 재귀호출의 위험성, 성능 상의 문제

*의사 코드(pseudo code) = 특정 프로그래밍 언어의 문법에 맞춰 작성된 것이 아닌, 일반적인 언어로 알고리즘을 표현한 코드



Memory구조
- C 프로그램이 운영체제로부터 할당받는 대표적인 메모리 공간
- 코드(code), 데이터(data) 영역, 스택(stack) 영역, 힙(heap) 영역



*/


int main(void)
{
	int num = 3;  

	if (num < 5)
	{
	    printf("num<5\n\n");
	}

	if (num == 5)
	{
	    printf("num==5\n\n");
	}

	if (num > 5)
	{
	    printf("num>5\n\n");
	}	
	
	printf("======================\n\n");
	
	int num1 = 10;  

	if (num1 < 5)
	{
	    printf("num1<5\n\n");
	}

	else
	{
	    if (num1 == 5)
	    {
	        printf("num1==5\n\n");
	    }
	    
	    else
	    {
	        printf("num1>5\n\n");
	    }
	}
	
	printf("======================\n\n");

	int num2 = 15;  

	if (num2 < 5)
	{
	    printf("num2<5\n\n");
	}

	else if (num2 == 5)
	{
	    printf("num2==5\n\n");
	}

	else
	{
	    printf("num2>5\n\n");
	}	
	
	printf("======================\n\n");
	
	int num3 = 2;  

	switch (num3)
	{
	    case 1:
	        printf("num3 = 1\n");
	        break;
	    case 2:
	        printf("num3 = 2\n");
	        break;
	    case 3:
	        printf("num3 = 3\n");
	        break;
	    case 4:
	        printf("num3 = 4\n");
	        break;
	    case 5:
	        printf("num3 = 5\n");
	        break;
	    default:
        	printf("num3 = 1 ~ 5\n");
	        break;
	}
	
	printf("\n======================\n\n");
	
	char ch = 'a';  

	switch (ch)
	{
	    case 'a':
	    case 'A':
	        printf("ch = 'a' or 'A'\n\n");
	        break;

    	case 'b':
	    case 'B':
	        printf("ch = 'b' or 'B' \n\n");
	        break;

    	case 'c':
	    case 'C':
	        printf("ch = 'c' or 'C' \n\n");
	        break;

	    case 'd':
    	case 'D':
	        printf("ch = 'd' or 'D' \n\n");
	        break;

    	case 'f':
	    case 'F':
	        printf("ch = 'f' or 'F' \n\n");
	        break;

	    default:
	        printf("ch = a, b, c, d, f \n");
	        break;
	}
	
	printf("\n============================================\n\n");
	
	int i = 0;
	int num4 = 5;  

	while (i < num4)
	{
	    printf("%d번째 반복\n", i + 1);
	    i++; // 이 부분을 삭제하면 무한 루프에 빠지게 됨
	}

	printf("result = %d\n", i);
	
	printf("\n============================================\n\n");
	
	int i1 = 0;
	int num5 = 3;  

	do
	{
	    printf("%d 번째 반복\n", i1 + 1);
	    i1++;
	} while (i1 > num5);

	printf("result = %d\n", i1);
	
	printf("\n============================================\n\n");
	
	int i2;
	int num6 = 7;  

	for (i2 = 0; i2 < num6; i2++)
	{
	    printf("%d 번째 반복\n", i2 + 1);
	}

	printf("result = %d\n", i2);
	
	printf("\n============================================\n\n");
	
	int i3;
	int except_num = 3;  

	for (i3 = 1; i3 <= 100; i3++)
	{
	    if (i3 % except_num == 0)
	    {
	        continue;
	    }
    	printf("%d\n", i3);
	}
	
	printf("\n============================================\n\n");
	
	int x, y; 

	for (x = 2; x <= 5; x++)
	{
	    for (y = 1; y <= 9; y++)
	    {
	        printf("%d * %d = %d\n", x, y, x * y);
	        if (x == y)
	        {
	            printf("\n");
	            break;
	        }
	    }
	} 
	
	printf("\n============================================\n\n");

	int bigNum(int num01, int num02) // 함수의 정의
	{
	    if (num01 >= num02)
	    {
	        return num01;
	    }

	    else
    	{
        	return num02;

    	}
	}


    int result;  

    result = bigNum(3, 5); // 함수의 호출
    printf("더 큰수= %d\n", result);
    result = bigNum(3, 1); // 함수의 호출
    printf("더 큰수= %d\n", result);
    result = bigNum(7, 5); // 함수의 호출
    printf("더 큰수= %d\n", result);
    
    printf("\n============================================\n\n");
    
    int sum(int n) 
	{
    	int i;
	    int result = 0;

	    for (i = 1; i <= n; i++)
	    {
	        result += i;
	    }
	
		printf("%d\n\n", result);
	    return result;
	}
	
	int a = 5;
	sum(a);//1+2+3+4+5 = 15
	
	int rSum(int n)
	{
	    if (n == 1)           // n이 1이면, 그냥 1을 반환함.
	    {
          return 1;
	    }

    	return n + rSum(n-1); // n이 1이 아니면, n을 1부터 (n-1)까지의 합과 더한 값을 반환함.
	}
	
	rSum(5); //1+2+3+4+5 = 15
	printf("%d\n\n", rSum(5));

	return 0; 
}
