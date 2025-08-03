package Test2021;

public class Test2104 
{

	public static void main(String[] args) 
	{
		int j, i;
		for(j = 0, i = 0; i<=5; i++) // 0~5까지 합산한 과정 & 결과 출력
		{
			j+=i;
			System.out.print(i); //print이므로 가로로 출력
			if(i==5)
			{
				System.out.print("=");
				System.out.print(j);
			}
			else
				System.out.print("+");
		}
		
		System.out.println("\n\n========================\n");
		
		int aa[][] = {{45, 50, 75}, {89}}; //2차원 배열 생성
		System.out.println(aa[0].length); //2차원 배열 중 첫 번째 행의 길이
		System.out.println(aa[1].length); //2차원 배열중 두 번째 행의 길이
		System.out.println(aa[0][0]); //2차원 배열 중 1행 1열의 값 = 45
		System.out.println(aa[0][1]); //2차원 배열 중 1행 2열의 값 = 50
		System.out.println(aa[1][0]); //2차원 배열 중 2행 1열의 값 = 89

	}

}
