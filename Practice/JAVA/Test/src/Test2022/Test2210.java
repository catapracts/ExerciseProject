package Test2022;

public class Test2210 
{
	static int[] mkarr()
	{
		int[] tmpArr = new int[4];
		for(int i = 0; i < tmpArr.length; i++)
		{
			tmpArr[i] = i;
		}
		return tmpArr;
	}
	
	public static void main(String[] args) 
	{
		int[] arr;
		arr = mkarr();
		for(int i = 0; i < arr.length; i++)
		{
			System.out.print(arr[i]);
		}
		
		System.out.println("\n\n====================\n");
		
		int r = 0;
		for(int i = 1; i < 999; i++)
		{
			if(i % 3 == 0 && i % 2 == 0)
			{
				r = i;
			}
		}
		
		System.out.print(r);
		
		System.out.println("\n\n====================\n");
		
		int result[] = new int[5];
		int arr1[] = {77, 32, 10, 99, 50};
		for(int i = 0; i < 5; i++)
		{
			result[i] = 1;
			for(int j = 0; j < 5; j++)
			{
				if(arr1[i] < arr1[j])
				{
					result[i]++;
				}
			}
		}
		
		for(int k = 0; k < 5; k++)
		{
			System.out.print(result[k]);
		}
	}

}
