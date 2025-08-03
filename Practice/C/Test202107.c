/*
21.07 실기
*/
#include<stdio.h>

main() 
{
	int ary[3]; // 빈 배열 선언
	int s = 0; // 변수 1개 선언
	*(ary+0) = 1; // ary배열의 첫 번째 주소의 값에 1 할당, ary[0]=1
	ary[1] = *(ary + 0) + 2; // ary배열의 두 번째 주소의 값에 ary배열의 첫 번째 주소의 값(1) + 2 = 3
	ary[2] = *ary + 3; // ary배열의 세 번째 주소의 값에 ary배열의 첫 번째 주소의 값(1) + 3 = 4
	for(int i = 0; i<3; i++) // 0~2까지 반복
	{
		s = s + ary[i]; //누적 합 : 0 + 1 + 3 + 4 = 8
	}
	printf("%d\n",s); //결과 : 8 



	int res = mp(2, 10);
	printf("%d\n", res); // 결과 : 1024 
}

int mp(int base, int exp) // base = 2, exp = 10
{
	int res = 1; // res = 1
	for(int i = 0; i < exp; i++) // i = 반복 횟수 = 연산 결과에 영향을 안 미침 그냥 몇 번째 계산인지 알리는 것 
	{
		res *= base; 
		// 1*2 -> 2*2 -> 4*2 -> 8*2 -> 16*2 -> 32*2 -> 64*2 -> 128*2 -> 256*2 -> 512*2
	}
	return res; //최종 결과인 512*2=1024 반환 
}
