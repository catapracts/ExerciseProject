//22.05½Ç±â 

#include<stdio.h>

int func(int a)
{
	if(a<=1) return 1;
	return a * func(a-1);
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", func(a));
	
	int number = 1234;
	int div = 10, result = 0;
	
	while(number != 0)
	{
		result = result * div;
		result = result + number % div;
		number = number /= div;
	}
	
	printf("%d\n", result);
	
	int number1 = 13195;
	int max_div = 0;
	for(int i = 2; i<number; i++)
	{
		if(isPrime(i) == 1 && number % i == 0) max_div = i;
	}
	
	printf("%d\n", max_div);
}

int isPrime(int number)
{
	for(int i = 2; i<number; i++)
	{
		if(number % i == 0) return 0;
	}
	
	return 1;
}
