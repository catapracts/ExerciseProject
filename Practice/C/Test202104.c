#include <stdio.h>

main()
{
	struct insa //구조체 정의 
	{
		char name[10]; //구조체 변수1 
		int age; //구조체 변수2 
	} a[] = {"kim", 28, "Lee", 38, "Park", 42, "Choi", 31}; //구조체 형태로 배열 선언 후 초기화 
	
	struct insa* p; // 구조체를 가리키는 포인터 변수 p선언 
	p = a; // p에 a배열의 시작 위치(a[0]) 저장 
	p++; // p+1 = 시작 위치 + 1 = a[1] 
	printf("%s\n", p -> name); // LEE
	printf("%d\n", p -> age); //38
	
}
