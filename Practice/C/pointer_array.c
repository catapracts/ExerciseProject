/*
*데이터의 주소값 = 해당 데이터가 저장된 메모리의 시작 주소 / C언어 - 주소값 = 1byte 메모리 공간으로 나누어 표현
(ex)int형 데이터 = 4byte / int형 데이터의 주소값 = 시작 주소 1byte

* *기호 = 사용하는 위치에 따라 다양한 용도 / 곱셈 연산,  포인터의 선언, 메모리에 접근 등에 사용 

* 워드(word) = CPU가 한 번에 처리할 수 있는 데이터의 크기 / 32bit sys : 1word = 4byte, 64bit sys : 1word = 8byte


Pointer
- 메모리의 주소값을 저장하는 변수
- 연산자 : 주소(번지) 연산자(&), 참조 연산자(*)
 - 주소(번지) 연산자(&) : 변수의 이름 앞에 사용 / 해당 변수의 주소값을 반환
 - 참조 연산자(*) : 포인터의 이름이나 주소 앞에 사용 / 포인터에 가리키는 주소에 저장된 값을 반환
- 선언 형식 : 타입* 포인터이름;
- 선언 + 초기화 : 타입* 포인터이름 = &변수이름; or 타입* 포인터이름 = 주소값;
- 포인터를 선언한 후 참조 연산자(*)를 사용하기 전에 포인터는 반드시 먼저 초기화되어야한다 -> 그렇지 않으면 의도하지 않은 메모리의 값을 변경하게 되기 때문
- 포인터의 타입은 참조 연산자를 통해 값을 참조할 때, 참조할 메모리의 크기를 알려주는 역할
 

Pointer 연산
- 제한된 연산만 가능
- 규칙 존재
1. +, *, / = 의미X 
2. - =  두 포인터 사이의 상대적 거리 => 빼기 연산하면, 메모리 크기가 줄어드는게 아니라 두 메모리 사이의 거리가 데이터 타입의 크기만큼 늘어나는 것 = 멀어지는 것 
3. 정수 +, - : O, 실수 연산 X 
4. 대입, 비교 가능


Argument transfer
- argument = 함수를 호출시, 함수에 필요한 데이터를 전달할 때 사용 
- 종류: call by value, call by reference
call by value : 인수로 전달되는 변수가 가지고 있는 값을 함수 내의 매개변수에 복사하는 방식 / 이렇게 복사된 값으로 초기화된 매개변수는 인수로 전달된 변수와는 완전히 별개의 변수 / 함수 내에서의 매개변수 조작은 인수로 전달되는 변수에 아무런 영향을 미치지 않습니다.
call by reference : 인수로 변수의 값을 전달하는 것이 아닌, 해당 변수의 주소값을 전달 / 함수의 매개변수에 인수로 전달된 변수의 원래 주소값을 저장 / 인수로 전달된 변수의 값을 함수 내에서 변경할 수 있게 됩니다.


Various pointer
- pointer of pointer / void pointer / function pointer / null pointer
null pointer : 0이나 NULL을 대입하여 초기화한 pointer / 아무것도 가리키지 않는 pointer
pointer of pointer : 2중 pointer / 포인터 변수를 가리키는 포인터 / 참조 연산자(*)를 두 번 사용
void pointer : 대상이 되는 데이터의 타입을 명시하지 않은 포인터 / 변수, 함수, 포인터 등 어떠한 값도 가리킬 수 있지만, 포인터 연산이나 메모리 참조와 같은 작업은 할 수 없습니다 = 주소값을 저장하는 것 이외에는 아무것도 할 수 없는 포인터 / 사용할 때마다 명시적 타입 변환을 하고 난 뒤에 사용
function pointer : 함수의 시작 주소를 가리키는 포인터 상수 / 함수 포인터의 포인터 타입은 함수의 반환값과 매개변수에 의해 결정 = 함수의 원형을 알아야만 해당 함수에 맞는 함수 포인터를 만들 수 있습니다.
*프로그램에서 정의된 함수는 프로그램이 실행될 때 모두 메인 메모리로 올라감 ->  함수의 이름은 메모리에 올라간 함수의 시작 주소를 가리키는 포인터 상수(constant pointer)가 됨 
원형 - void func (int, int); -> 함수 포인터 - void (*ptr_func) (int, int);
**함수 포인터 사용시 연산자의 우선순위 때문에 반드시 *ptr_func 부분을 괄호(())로 둘러싸기


Pointer와 Array의 관계
- C언어에서는 배열의 이름을 포인터처럼 사용할 수 있을 뿐만 아니라, 포인터를 배열의 이름처럼 사용
- 포인터 상수(constant pointer) = 포인터 변수가 가리키고 있는 주소 값을 변경할 수 없는 포인터 = Array
- 상수 포인터(pointer to constant) = 상수를 가르키는 포인터
- 배열의 크기를 계산할 때에는 배열의 이름과 포인터 사이에 차이가 발생
배열의 이름을 이용한 크기 계산 -> 배열의 크기가 int형 배열 요소 3개의 크기인 12바이트로 제대로 출력
포인터를 이용한 크기 계산 ->  배열의 크기가 아닌 포인터 변수 자체의 크기가 출력되는 차이
*배열에 관계된 연산을 할 때는 언제나 배열의 크기를 넘어서는 접근을 하지 않도록 주의 -> 포인터 연산을 이용하여 계산하다가 배열의 크기를 넘어서는 접근을 하는 경우, C 컴파일러는 어떠한 오류도 발생X = 언제나 배열의 크기에도 주의


Pointer Array & Array Pointer
- Pointer Array : 배열 요소로 포인터 변수를 가지는 배열 = 포인터 변수를 저장할 수 있는 배열
- Array Pointer : 배열을 가리킬 수 있는 포인터 / 2차원 이상의 배열에서만 의미 / 포인터를 배열처럼 사용하기 위해서 배열 포인터를 정의하여 사용
- 구분 : 괄호의 유무 

2차원 배열의 배열 이름으로 포인터 연산을 하면 배열의 행 단위로 이동 = (arr+1)은  arr[1]과 같은 곳을 가리킴 / 포인터 연산 시 증가하는 값이 행의 길이(= 부분 배열의 크기 = sizeof(arr[0]) / sizeof(타입))에 따라 차이 / 



*main함수
- 원형 : void(또는 int) main(int argc, char *argv[]); 
- 프로그램이 실행되면 제일 먼저 자동으로 호출되는 함수
첫 번째 인수 = int형 변수 argc / main() 함수에 인수로 전달되는 문자열의 개수를 명시
두 번째 인수 = char형 포인터 배열 argv = main() 함수에 인수로 전달된 각각의 문자열이 저장된 배열

*/



#include<stdio.h>
void local(int);  
void local1(int*);
double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
double calculator(double , double, double (*func)(double, double));

void local(int num)
{
	num += 10;
}

void local1(int* num)
{
	*num += 10;
}  



int main(void)
{
	int x = 7;        // 변수의 선언
	int *ptr1 = &x;    // 포인터의 선언
	int *ptr2 = &ptr1; // 포인터의 참조
	
	int num = 1234;
	double num1 = 3.14;  
	int* ptr_num = &num;
	double* ptr_num1 = &num1;
	
	
	printf("pointer size = %d\n", sizeof(ptr1)); //결과 : 8(포인터 변수의 크기 : 8byte)
	printf("pointer size = %d\n", sizeof(ptr_num)); //결과 : 8(포인터 변수의 크기 : 8byte)
	printf("pointer size = %d\n", sizeof(ptr_num1)); //결과 : 8(포인터 변수의 크기 : 8byte)
	printf("ptr_num -> address_value = %#x\n", ptr_num); //결과 : 0x62fdf4(num의 주소값)
	printf("ptr_num -> data_value = %d\n", *ptr_num); //결과 : 1234(num의 value)
	printf("ptr_num1 -> address_value = %#x\n", ptr_num1); //결과 : 0x62fdf4(num1의 주소값)
	printf("ptr_num1 -> data_value = %f\n", *ptr_num1); //결과 : 3.140000(num1의 value)

	printf("\n====================================\n\n");

	char* ptr_char = 0;
	int* ptr_int = NULL;
	double* ptr_double = 0x00;  

	printf("ptr_char -> address value = %#x\n", ptr_char); // 결과 : 0 = pointer에 저장된 초기 주소값 = 0 
	printf("ptr_char+1 -> address value = %#x\n", ++ptr_char); // 결과 : 1(0x1) = pointer의 주소값은 자료형의 크기만큼 증가 
	
	printf("\n====================================\n\n");
	
	printf("ptr_int -> address value = %#x\n", ptr_int); // 결과 : 0 = pointer에 저장된 초기 주소값 = 0
	printf("ptr_int+1 -> address value = %#x\n", ++ptr_int); // 결과 : 4(0x4) = pointer의 주소값은 자료형의 크기만큼 증가
	
	printf("\n====================================\n\n");
	
	printf("ptr_double -> address value = %#x\n", ptr_double); // 결과 : 0 = pointer에 저장된 초기 주소값 = 0
	printf("ptr_double+1 -> address value = %#x\n", ++ptr_double); // 결과 : 8(0x8) = pointer의 주소값은 자료형의 크기만큼 증가	
		
	printf("\n====================================\n\n");
	
	int num2 = 10;
	int num3 = 20;
	int *ptr_num2 = &num2;
	int *ptr_num3 = &num3;  

	if (ptr_num2 != ptr_num3) // 포인터끼리의 비교 연산
	{
	    printf("ptr_num2 -> data_value = %d\n", *ptr_num2);
	    printf("ptr_num3 -> data_value = %d\n", *ptr_num3);
    	printf("ptr_num2 != ptr_num3\n\n");
	    ptr_num3 = ptr_num2; // 포인터끼리의 대입 연산
	}
	
	printf("ptr_num2 -> data_value = %d\n", *ptr_num2);
	printf("ptr_num3 -> data_value = %d\n", *ptr_num3);

	if (ptr_num2 == ptr_num3) // 포인터끼리의 비교 연산
	{
	    printf("ptr_num2 == ptr_num3\n\n");
	}
	
	printf("\n====================================\n\n");
	
	int var = 10;
    printf("initial value of var = %d\n", var);  

    local(var);
    printf("value of var after local() func. = %d\n", var);

	printf("\n====================================\n\n");
	
	int var1 = 10;
    printf("initial value of var1 = %d\n", var1);

    local1(&var1);
    printf("value of var1 after local1() func. = %d\n\n", var1);
    
    printf("\n====================================\n\n");
    
	int num4 = 10;              // 변수 선언
	int* ptr_num4 = &num4;       // 포인터 선언
	int** ptr_num5 = &ptr_num4; // 포인터의 포인터 선언  

	printf("num4 = %d\n", num4); // 결과 : 10 = num4에 저장된 값 
	printf("ptr_num4 -> data_value = %d\n", *ptr_num4); // 결과 : 10 = ptr_num4가 갖고 있는 주소값이 num4고, 그 num4에 저장된 값 
	printf("ptr_num5 -> data_value = %d\n", **ptr_num5); // 결과 : 10 = ptr_num5가 갖고 있는 주소값이 ptr_num4고, ptr_num4가 갖고 있는 주소값이 num4고, 그 num4에 저장된 값 

	printf("\n====================================\n\n");
	
	int num5 = 10;         // 변수 선언
	void* ptr_num6 = &num5; // void 포인터 선언  
 
	printf("num5 = %d\n", num5); // 결과 : 10 = num5에 저장된 값
	printf("ptr_num6 -> data_value = %d\n", *(int*)ptr_num6); // 결과 : 10 = int pointer type으로 명시적 타입 변환을 거친 void pointer에 num5의 주소값이 저장되어 있고, 그 num5에 저장된 값

	*(int*)ptr_num6 = 20;  // void 포인터를 통한 메모리 접근  
	printf("ptr_num6 -> data_value = %d\n", *(int*)ptr_num6); // 결과 : 20 = int pointer type으로 명시적 타입 변환을 거친 void pointer에 num5의 주소값이 저장되어 있고, 그 num5에 저장된 값

	printf("\n====================================\n\n");	
	
	double (*calc)(double, double) = NULL; // 함수 포인터 선언
	double result = 0;  
	double num7 = 3, num8 = 5;
	char oper = '*';  

	switch(oper)
	{
	    case '+':
	        calc = add;
	        break;

    	case '-':
	        calc = sub;
	        break;

    	case '*':
	        calc = mul;
	        break;

    	case '/':
	        calc = div;
	        break;

    	default:
	        puts(" only +, -, *, /");
	}  

	result = calculator(num7, num8, calc);
	printf("result = %lf\n", result);
	
	printf("\n====================================\n\n");
	
	int array[3] = {10, 20, 30}; // 배열 선언
	int* ptr_array = array;        // 포인터에 배열의 이름을 대입  

	printf("array[0] : %d, array[1] : %d, array[2] : %d\n", array[0], array[1], array[2]); //결과 : 10 20 30 
	printf("ptr_array[0] : %d, ptr_array[1] : %d, ptr_array[2] : %d\n", ptr_array[0], ptr_array[1], ptr_array[2]); //결과 : 10 20 30 - pointer로 배열 출력
	printf("*(array+0) : %d, *(array+1) : %d, *(array+2) : %d\n\n", *(array+0), *(array+1), *(array+2)); //결과 : 10 20 30 - 배열 이름으로 pointer 연산 / array+0 = array의 시작 주소, array+2 = array의2nd element, *(array+2) = array[2]위치의 값 = 30
	printf("get array size using by array name : %d\n", sizeof(array)); //결과 : 12 = int크기*3 = 12byte 
	printf("get array size using by pointer : %d\n\n", sizeof(ptr_array)); //결과 : 8 = pointer의 크기 = 8byte
	
	printf("\n====================================\n\n");
	
	int i, array_length;
	int num9 = 10, num10 = 20, num11 = 30;
	int* array1[3] = {&num9, &num10, &num11}; // int형 포인터 배열 선언 - array1에 num9,10,11의 address value를 저장 

	array_length = sizeof(array1)/sizeof(array1[0]); // 24/8 = 3 = 배열의 길이(크기)
	printf("%d\n", sizeof(array1)); //24 : pointer의 크기는 개당 8byte이므로 3개가 들어갔으니 8*3 = 24 
	printf("%d\n", sizeof(array1[0])); //8 : pointer의 크기는 개당 8byte
	printf("%#x\n", array1[0]); //0x62fd3c -> num9의 address value -> num9의 data value 
	printf("%#x\n", array1[1]); //0x62fd38 -> num10의 address value -> num9의 data value 
	printf("%#x\n", array1[2]); //0x62fd34 -> num11의 address value -> num9의 data value 
	

	for (i = 0; i < array_length; i++) //배열 전체를 돌아본다. 
	{
	    printf("%d\n", *array1[i]); // 결과 : 10, 20, 30
	}
	
	printf("\n====================================\n\n");
	
	int arr[2][3] =             // 배열의 선언
	{
	    {10, 20, 30},
	    {40, 50, 60}
	};

	int (*pArr)[3] = arr;       // 배열 포인터의 선언  

	printf("%d\n", arr[1][1]);  // 배열 이름으로 참조
	printf("%d\n", pArr[1][1]); // 배열 포인터로 참조	
	
	
	
	
	
}

double add(double num01, double num02)
{
	return num01 + num02;
}

double sub(double num01, double num02)
{
	return num01 - num02;
}

double mul(double num01, double num02)
{
	return num01 * num02;
}

double div(double num01, double num02)
{
	return num01 / num02;
}

double calculator(double num01, double num02, double (*func)(double, double))
{
	return func(num01, num02);
}

