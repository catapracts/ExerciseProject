#include<stdio.h>
#define MAX_SIZE 10
int isWhat[MAX_SIZE];

int point = -1;
int isEmpty()
{
	if(point==-1) return 1;
	return 0;
}

int isFull()
{
	if(point==10) return 1;
	return 0;
}

void into(int num)
{
	if(isFull()==1) printf("Full");
	else isWhat[++point] = num;
}

int take()
{
	if(isEmpty()==1) printf("Empty");
	else return isWhat[point--];
	return 0;
}

char n[30];

char* getname()
{
	printf("이름 입력:");
	gets(n);
	return n; 
} 

main()
{
	int n[] = {5, 4, 3, 2, 1};
	for(int i = 0; i < 5; i++)
	{
		// n[i%5] : n[0%5] = n[0], n[1%5] = n[1] / n[(i+1)%5] : n[(0+1)%5] = n[1], n[(1+1)%5] = n[2] ...
		printf("%d", n[(i+1)%5]); // 결과 : 43215 
	}
	
	printf("\n======================================\n");
	
	int m = 4620;
	int a = m/1000; // 4620/1000 = 4.62 -> 4 = 1000원의 개수 : 4개 
	int b = m%1000/500; // 4620%1000 = 620 -> 620/500 = 1.24 = 500원의 개수 : 1개 
	int c = m%500/100; // 4620%500 = 120 -> 120/100 = 1.2 = 100원의 개수 : 1개 
	int d = m%100/10; // 4620%100 = 20 -> 20/10 = 2 = 10원의 개수 : 2개 
	printf("1000원의 개수 : %d\n", a);
	printf("500원의 개수 : %d\n", b);
	printf("100원의 개수 : %d\n", c);
	printf("10원의 개수 : %d\n", d);
	
	printf("======================================\n");
	/*
	char* n1 = getname();
	char* n2 = getname();
	char* n3 = getname();
	printf("%s\n", n1);
	printf("%s\n", n2);
	printf("%s\n", n3);
	*/
	printf("\n======================================\n");
	
	int e[] = { 73, 95, 82 };
	int sum = 0;
	
	for(int j = 0; j < 3; j++)
	{
		sum += e[j];
	}
	
	switch(sum/30)
	{
		case 10:
		case 9: printf("A");
		case 8: printf("B");
		case 7:
		case 6: printf("C");
		default: printf("D");
	}
	
	printf("\n======================================\n");
	
	int f = 0;
	for(int i = 1; i <=2023; i++)
	{
		if(i%4==0)
		{
			f++;
		}
	}
	printf("%d", f); // 결과 : 505 (i = 0부터 시작할 경우 506)
	
	printf("\n======================================\n");
	
	into(5); into(2);
	while((!isEmpty))
	{
		printf("%d", take());
		into(4); into(1); printf("%d", take());
		into(3); printf("%d", take()); printf("%d", take());
		into(6); printf("%d", take()); printf("%d", take());
	}
	
	printf("\n======================================\n");
	
	int E[] = {64, 25, 12, 22, 11};
	int g = sizeof(E) / sizeof(E[0]);
	int i = 0;
	do
	{
		int j = i+1;
		do
		{
			if(E[i]>E[j])
			{
				int tmp = E[i];
				E[i] = E[j];
				E[j] = tmp;
			}
			j++;
		}while(j<g);
		i++;
	}while(i<g-1);
	for(int i = 0; i <= 4; i++)
	{
		printf("%d\t", E[i]);
	}
}
