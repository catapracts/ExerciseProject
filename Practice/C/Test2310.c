#include<stdio.h>

int f(int n)
{
	if(n<=1)
	{
		return 1;
	}
	
	else
	{
		return n*f(n-1);
	}
}

int isPerfectNum(int num)
{
	int sum = 0;
	for(int i = 1; i < num; i++)
	{
		if(num % i == 0)
		{
			sum+=i;
		}
	}
	
	if(num==sum)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

struct insa
{
	char name[10];
	int age;
	struct insa* impl_a;
	struct insa* impl_b;
};

main()
{
	struct insa p1 = {"Kim", 28, NULL, NULL};
	struct insa p2 = {"Lee", 36, NULL, NULL};
	struct insa p3 = {"Park", 41, NULL, NULL};
	p1.impl_a = &p2;
	p2.impl_b = &p3;
	printf("%s\n", p1.impl_a->name);
	printf("%d", p2.impl_b->age);
	
	printf("\n==============================\n");
	
	char* p = "KOREA";
	printf("1. %s\n", p);
	printf("2. %s\n", p+1);
	printf("3. %c\n", *p);
	printf("4. %c\n", *(p+3));
	printf("5. %c\n", *p+4);
	
	printf("==============================\n");
	
	printf("%d", f(7));
	
	printf("\n==============================\n");
	
	int r = 0;
	for(int i = 1; i <= 100; i++)
	{
		if(isPerfectNum(i))
		{
			r += i;
		}
	}
	printf("%d", r);
}
