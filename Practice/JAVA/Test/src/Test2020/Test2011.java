package Test2020;

/*
Parent는 올려받은 걸 가지고, compute(3)이랑 compute(1)처리
compute(1)은 1 들어왔으니까 return값 1로 끝
compute(3)은 또 compute(2) + compute(0)의 결과값을 가지니까 다시 compute처리하기 위해 Parent 재귀
그리고 compute(2)는 또 compute(1) + compute(-1)의 결과값을 return해야하니 다시 compute처리하기 위해 Parent 재귀 + compute(0)은 또 처리할 필요없이 0
compute(2)는 compute(1) + compute(-1)의 결과값을 return하는데 각각 값이 1, -1이므로 +하면 0된다.
compute(3)은 또 compute(2) + compute(0)의 결과값을 가지니까 compute(2) = 0이고 compute(0)=0이므로 compute(3)도 0
compute(3) = 0, compute(0) = 1로 compute(4)의 return값이 완성되었으니 compute(4)호출한 곳(main)으로 return
*/

class Parent
{
	int compute(int num) //3이랑 1 들어옴
	{
		if(num<=1) return num;
		return compute(num-1) + compute(num-2); //
	}
}

/*
처음에 child에 4들어와서 compute(3)이랑 compute(1)되서 이 둘의 return의 합을 구해서 최종 return한다.
compute(3)이랑 compute(1) 같이 Parent로 올려버림
*/

class Child extends Parent
{
	int compute(int num) // 처음에 4 들어옴
	{
		if(num<=1) return num;
		return compute(num-1) + compute(num-3); //각각에 4 들어가서 3, 1되서 Parent로 올라감
	}
}


public class Test2011 
{

	public static void main(String[] args) 
	{
		int a[] = new int[8];
		int i = 0;
		int n = 10;
		while(n>0) //n>0일 때까지만 반복
		{
			a[i++] = n%2; //a[i]에 n%2값 저장 후 +1 : a[i=0] = 초기값 존재 X -> a[i=1] = 0(10을 2로 나눈 후 나머지) -> a[i=2] = 1(5를 1로 나눈 후 나머지) -> a[i=3] = 0(2를 2로 나눈 후 나머지) -> a[i=4] = 1(1을 2로 나눈 후 나머지)
			n /= 2; //n을 2로 나눈다 : 10 -> 5 -> -> 2 -> 1 -> 0
		}
		// while문 이후 저장된 결과 : 0101000
		
		for(i = 7; i>=0; i--) //거꾸로 출력
		{
			System.out.print(a[i]); // 00001010
		}
		
		System.out.println("\n\n==============================\n");
		
		int array[][] = new int[3][5]; // 2차원 배열(3,5) 선언
		int b = 1; // 이유없는 코드 - 낚시용?
		for(int c = 0; c<3; c++) // 2차원 배열 중 행(3)을 돌면서 반복하기 위해 사용
		{
			for(int d = 0; d<5; d++) // 2차원 배열 중 열(5)을 돌면서 반복하기 위해 사용
			{
				array[c][d] = d * 3 + c + 1; // 각 열에 넣을 값들 계산 
				System.out.println(array[c][d] + " "); // 결과 : [[1,4,7,10,13]] -> [[1,4,7,10,13], [2,5,8,11,14]] -> [[1,4,7,10,13], [2,5,8,11,14], [3,6,9,12,15]]  
			}
			System.out.println();
		}
		
		System.out.println("==============================\n");
		
		Parent obj = new Child(); // Child 객체 생성
		System.out.println(obj.compute(4)); // Child함수에서 처리 시작 / 결과 : 1
		
		

	}

}
