#include<stdio.h>

/*

K = p
O = p+1
R = p+2
E = p+3
A = p+4
\0 = p+5 : KOREA = String이므로 맨 뒤에 null값 존재, 출력할 때는 안 나타남 

printf("%s\n", p); : p위치에서부터 끝까지 문자열 출력 
printf("%s\n", p+3); : p+3위치에서부터 끝까지 문자열 출력 
printf("%c\n", *p); : p가 가리키는 곳의 문자 출력 
printf("%c\n", *(p+3)); : p+3이 가리키는 곳의 문자 출력 
printf("%c\n", *p+2); : p가 가리키는 곳의 문자에 +2한 값 출력 = M by ASCII code 
*/

main()
{
	char* p = "KOREA";
	printf("%s\n", p); //KOREA
	printf("%s\n", p+3); //EA
	printf("%c\n", *p); //K
	printf("%c\n", *(p+3)); //E
	printf("%c\n", *p+2); //M
}
