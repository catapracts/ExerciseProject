#include<stdio.h>

int chkover(int w, int h, int j, int i)
{
	if(i >= 0 && i < w && j >= 0 && j < h) return 1;
	return 0;
}

int main(void)
{
	int field[4][4] = {{0, 1, 0, 1}, {0, 0, 0, 1}, {1, 1, 1, 0}, {0, 1, 1, 1}};
	int mines[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	int w = 4, h = 4;
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			if(field[y][x] == 0) continue;
			for(int j = y - 1; j <= y+1; j++)
			{
				for(int i = x - 1; i <= x + 1; i++)
				{
					if(chkover(w, h, j, i) == 1)
					{
						mines[j][i] += 1;
					}
				}
			}
		}
	}
	
	int s, el = 0;
	for(int i = 6; i <= 30; i++)
	{
		s = 0;
		
		for(int j = 1; j <= i / 2; j++)
		{
			if(i % j == 0)
			{
				s = s + j;	
			}
		}
		
		if(s == i)
		{
			el++;	
		}
	}
	
	printf("%d\n", el);
	
	
}
