#include<stdio.h>

struct jsu //구조체 형태 선언 
{
	char nae[12]; // 구조체 element 1 
	int os, db, hab, hhab; // 구조체 element 2, element 3, element 4, element 5
};

int main()
{
	struct jsu st[3] = // 구조체 3개 생성 
	{
		{"데이터1", 95, 88}, {"데이터2", 84, 91}, {"데이터3", 86, 75}
	};
	
	struct jsu* p; // 구조체의 위치를 가리키는 포인터 변수 p선언 
	p = &st[0]; // p에 구조체 st의 0번째 element의 주소값을 할당 
	(p + 1)->hab = (p+1)->os + (p + 2)->db; // 구조체의 두 번째 element의 hab = 구조체의 두 번째 element의 os(84) + 구조체의 세 번째 element의 db(75) : 84 + 75 = 159
	// 구조체의 두 번째 element의 hhab = 구조체의 두 번째 element의 hab(159) + 구조체의 첫 번째 element의 os(95) + 구조체의 첫 번째 element의 db(88) : 159 + 95 + 88 = 342
	(p + 1)->hhab = (p+1)->hab + p->os + p->db;
	printf("%d\n", (p+1)->hab + (p+1)->hhab); // 구조체의 두 번째 element의 hab + 구조체의 두 번째 element의 hhab : 159 + 342 = 501
	
	int* array[3]; // 배열의 크기(길이)가 3인 빈 배열 선언 
	int a = 12, b = 24, c = 36; // int형 변수 3개 선언 
	array[0] = &a; // 배열의 0번째 자리에 a의 주소값을 넣기 / array[0] = a의 주소값 
	array[1] = &b; // 배열의 1번째 자리에 b의 주소값을 넣기 / array[1] = b의 주소값 
	array[2] = &c; // 배열의 2번째 자리에 c의 주소값을 넣기 / array[2] = c의 주소값 
	printf("%d", *array[1] + **array + 1); // array의 두번째 주소의 값(b = 24) + array의 첫 번째 주소의 값(a = 12) + 1 = 24 + 12 + 1 = 37 
}
