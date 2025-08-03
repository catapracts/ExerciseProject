package algo;
import java.util.*;


public class Dynamic_Programming 
{
	
	/*
	동적 계획법(DP: Dynamic programming) 
	- 작은 문제들을 풀면서 그 결과를 저장해 나아가면서 전체 문제를 해결하는 알고리즘
	- 중복 계산을 줄여서 계산 속도를 높일 수 있으며 경우의 수가 많은 경우에도 효율적으로 계산
	- 일반적으로 재귀적으로 구현되며 메모이제이션(Memoization) 기법을 사용하여 중복 계산을 피함
	*재귀(Recursion) =  자기 자신을 호출하는 함수로 반복적으로 호출을 함으로써 원하는 결과를 도출
	**메모이제이션(Memoization) =  ‘중복 계산'을 피하기 위한 기법, 이전에 계산된 결과를 저장하고 다음에 동일한 계산에 필요할 때 저장된 결과를 이용하여 중복 계산을 피함으로써 성능을 향상
	
	
	- 동적 계획법의 구현 단계
	1. 문제를 하위 문제로 쪼갭니다.
	2. 하위 문제를 재귀적으로 해결합니다.
	3. 결과를 저장합니다. (메모이제이션)
	4. 저장된 결과를 이용하여 큰 문제를 해결합니다.(* 해당 단계를 통해서 중복 계산을 피하여서 성능을 높입니다.)
	
	
	- 동적 계획법의 메모이제이션(Memoization) = 이전에 계산한 값을 저장하여 다시 계산하지 않도록 하여 속도를 빠르게 하는 방법
	메모이제이션(Memoization) 구성과정
	1. 입력값에 대한 결과값을 저장할 메모이제이션 테이블을 초기화합니다.
	2. 함수를 호출할 때, 먼저 메모이제이션 테이블에서 해당 입력값의 결과값이 이미 저장되어 있는지 확인합니다.
	3. 저장되어 있으면 해당 결과값을 반환하고, 저장되어 있지 않으면 계산을 수행하고 그 결과를 메모이제이션 테이블에 저장합니다.계산된 결과값을 반환합니다.
	메모이제이션(Memoization) table - 동적 계획법에서 사용되는 저장 공간 / 이전에 계산한 값을 저장해두었다가 나중에 같은 값을 계산할 때 다시 계산하지 않고 이전에 계산한 값을 활용 / 일반적으로는 해시 테이블이나 배열 등을 사용하여 구현

	
	- 동적 계획법을 사용하기 위한 조건
	1. 최적 부분 구조 (Optimal Substructure) : '큰 문제의 최적해'가 '작은 문제의 최적해'를 포함하는 성질 = 작은 문제의 최적해를 구한 후 그것을 이용하여 큰 문제의 최적해를 구할 수 있습니다
	2. 중복 부분 문제 (Overlapping Subproblems) : '동일한 작은 문제를 반복적으로 해결'해야 하는 성질 = 작은 문제를 해결할 때 반복적으로 같은 문제를 해결


	- 동적 계획법 종류
	
	1. 탑다운(Top-Down) 방식 : 재귀적으로 호출하여 문제를 해결 / 재귀 호출을 사용하므로 스택 오버플로(Stack Overflow)문제가 발생 할 수 있다 / 큰 문제를 작은 문제로 나누어 푸는 분할정복(Divide and Conquer) 방식과 비슷합니다. 다만 중복되는 작은 문제들을 한 번만 푸는 것이 특징
	*스택 오버플로(Stack Overflow) :  함수 호출 시 스택 메모리에 할당된 공간을 벗어나게 되는 현상 / 일반적으로 재귀 호출이 지나치게 많이 일어날 때 발생하며, 프로그램이 비정상적으로 종료
	**재귀적으로 수행하는 피보나치 수열 = 탑다운 방식 ? : 피보나치 수열의 경우 앞의 두수를 더해가는 방법으로써 재귀적으로 수행하지만 중복 계산이 발생하여 비 효율적입니다.그러나 탑다운 방식의 경우는 중복되는 작은 문제들을 한번만 풀기에 상대적으로 효율적

	2. 바텀업(Bottom-Up) 방식 : ‘작은 문제’부터 해결하여 ‘큰 문제’까지 해결하는 알고리즘 방식 / 이전에 ‘계산한 부분 문제’의 결과를 저장해두고 나중에 같은 부분 문제가 나타날 때 다시 계산하지 않고 저장된 값을 사용하여 시간을 절약 / 탑 다운 방식과 비교하여 재귀적으로 수행하지 않고 ‘반복문’을 통하여서 문제를 해결해 나아가는 방식
	*탑다운 방식 = 바텀업 방식 ? : X - 해결방식이 다르다 - Top-Down = 재귀, Bottom-Up = 반복문 이용
	
	
	- 동적 계획법 활용 방법
	1. 피보나치의 수열(Fibonacci numbers) = 이전 두 항의 합이 다음 항이 되는 수열 -> 동적 계획법의 메모이제이션 방식을 통해 값을 저장해두는 방식을 이용하자.
	
	2. 최장 공통 수열(Longest Common Subsequence, LCS) = 두 개의 문자열이 주어졌을 때, 두 문자열에서 ‘공통’으로 나타나는 ‘가장 긴 부분 문자열’을 찾는 문제 / 예를 들어, "ABCDGH"와 "AEDFHR"이 주어졌을 때, 이 두 문자열에서 공통으로 나타나는 가장 긴 부분 문자열은 "ADH"
	- ‘최장 공통 수열’과 ‘최장 공통 문자열’을 통하여 비교를 하여 이해
	- 최장 공통 수열 = 두개의 문자열 내에서 ‘서로 다른 위치에 있는 문자들’을 비교하여 가장 긴 길이의 공통 부분 수열을 찾습니다.(* 해당 경우는 연속된 문자열이 아니더라도 포함합니다)
	- 최장 공통 문자열 = 두개의 문자열 내에서 ‘연속적인 부분 문자열’ 중 가장 긴 길이의 공통 부분 문자열을 찾습니다. (* 해당 경우는 연속되는 문자열인 경우 포함됩니다)
	- 동적 계획법의 종류 중 ‘바텀업 방식’을 이용하여서 작은 부분 문자열에 대한 문제를 해결하고 이를 이용하여 큰 부분문자열의 결과를 계산하는 방식으로 사용
	
	*최장 증가 부분 수열(Longest Increasing Subsequence, LIS)
	- 주어진 수열에서 일부 항목을 선택하여 만들 수 있는 부분 수열 중에서, ‘원소의 크기가 증가하는 순서대로 정렬’되어 있는 가장 긴 수열을 찾는 문제
	- 예를 들어, 주어진 수열이 [10, 22, 9, 33, 21, 50, 41, 60, 80]인 경우, 최장 증가 부분 수열은 [10, 22, 33, 50, 60, 80]
	
	*최장 감소 부분 수열(Longest Decreasing Subsequence, LDS)
	- 주어진 수열에서 일부 항목을 선택하여 만들 수 있는 부분 수열 중에서, ‘원소의 크기가 감소하는 순서대로 정렬’되어 있는 가장 긴 수열을 찾는 문제
	- 예를 들어, 주어진 수열이 [80, 60, 50, 41, 33, 22, 21, 10, 9]인 경우, 최장 감소 부분 수열은 [80, 60, 50, 41, 33, 22, 21, 10, 9]
	
	*/
	
	// 메모이제이션(Memoization)예시 - 피보나치 수열
	private static Map<Integer, Integer> memo = new HashMap<>();

	public static int fibonacci(int n) 
	{
		if (n <= 1) 
		{
	      return n;
	    }

	    if (memo.containsKey(n)) 
	    {
	      return memo.get(n);
	    }

	    int result = fibonacci(n - 1) + fibonacci(n - 2);
	    memo.put(n, result);
	    return result;
	}
	
	
	// 피보나치 수열을 구하기 위한 계산법 : 탑다운 방식 - 계산이 될때 다음 호출이 되면 동일한 값이 호출이 되어 중복 계산이 발생 / 중복 계산은 예를 들어 n = 4일 경우 calcRecursiveFibonacci(3) + calcRecursiveFibonacci(2)
	public static int calcRecursiveFibonacci(int n) 
	{
	    if (n <= 1) 
	    {
	        return n;
	    }
	    
	    else 
	    {
	        return calcRecursiveFibonacci(n - 1) + calcRecursiveFibonacci(n - 2);
	    }
	}
	
	
	// 피보나치 수열을 구하기 위한 계산법 : 바텀업 방식 - 이전에 계산한 내용을 저장해두고 나중에 같은 내용이 발생할때 다시 계산하지 않고 저장된 값을 사용하여 시간을 절약하는 방법
	//1. memo[0]과 memo[1]은 초기값으로 설정합니다. 2. i가 2부터 n까지 반복문을 통해 memo[i] = memo[i-1] + memo[i-2]로 값을 계산하고 저장합니다.(메모이제이션) 3. 이를 통해서 n번째 항의 값을 반환합니다.
	public static int fibonacci_bottom(int n) 
	{
	    if (n <= 1) 
	    {
	        return n;
	    }
	    
	    int[] memo = new int[n+1];
	    
	    memo[0] = 0;
	    
	    memo[1] = 1;
	    
	    for (int i = 2; i <= n; i++) 
	    {
	        memo[i] = memo[i-1] + memo[i-2];
	    }
	    
	    return memo[n];
	}	
	
	
	
	

	//최장 공통 수열(LCS) 예시
	/*
	1. LCS 함수는 문자열 A, B를 인자로 받습니다. 그리고 A와 B의 길이를 각각 m과 n에 저장합니다. opt 이차원 배열은 A와 B의 부분 문자열 간의 최장 공통 부분 수열 길이를 저장하는 배열입니다.

	2. 이제 이차원 배열 opt을 계산합니다. 이는 먼저 opt의 마지막 행과 열을 0으로 설정하고, opt의 나머지 부분은 아래와 같이 계산됩니다.
	- A와 B의 문자가 같은 경우, opt[i][j]는 opt[i+1][j+1]+1을 대입합니다.
	- A와 B의 문자가 다른 경우, opt[i][j]는 opt[i+1][j]와 opt[i][j+1] 중 더 큰 값입니다.

	3. 마지막으로 최장 공통 부분 수열을 찾습니다. 이를 위해 i와 j를 0으로 초기화하고, A와 B의 문자를 비교합니다. 만약 문자가 같으면, 최장 공통 부분 수열에 추가하고, i와 j를 1씩 증가시킵니다. 만약 문자가 다르면, opt[i+1][j]와 opt[i][j+1] 중 더 큰 값을 가지는 곳으로 이동합니다. 이를 반복하면 최장 공통 부분 수열을 찾을 수 있습니다.
	 */
	public static String LCS(String A, String B) 
	{

	    // 1. 전달 받은 문자열의 길이를 저장합니다. 또한 이를 저장할 이차원 배열을 구성합니다.
	    int m = A.length();
	    int n = B.length();
	    int[][] opt = new int[m + 1][n + 1];

	    // 2. A, B 문자열을 역순으로 순회합니다.
	    for (int i = m - 1; i >= 0; i--) 
	    {
	        for (int j = n - 1; j >= 0; j--) 
	        {
	            // 3. A, B 문자열을 비교합니다.
	            if (A.charAt(i) == B.charAt(j)) 
	            {
	                opt[i][j] = opt[i + 1][j + 1] + 1;
	            } 
	            
	            else 
	            {
	                opt[i][j] = Math.max(opt[i + 1][j], opt[i][j + 1]);
	            }
	        }
	    }

	    for (int i = 0; i < opt.length; i++) 
	    {
	        System.out.println("생성된 2차원 배열 :: " + Arrays.toString(opt[i]));
	    }

	    int i = 0, j = 0;
	    StringBuilder sb = new StringBuilder();

	    // 3. 최장 공통 부분 수열을 찾습니다. : 문자열이 같으면 최장 공통 부분수열에 추가하고 i, j 값을 증가시킵니다.
	    while (i < m && j < n) 
	    {
	        if (A.charAt(i) == B.charAt(j)) 
	        {
	            sb.append(A.charAt(i));
	            i++;
	            j++;
	        } 
	        
	        else if (opt[i + 1][j] >= opt[i][j + 1]) 
	        {
	            i++;
	        } 
	        
	        else 
	        {
	            j++;
	        }
	    }

	    return sb.toString();
	}

	

	public static void main(String[] args) 
	{
        int n = 10;
        System.out.println("Fibonacci(" + n + ") = " + fibonacci(n));
        System.out.println("=====================================");
        int a = 4;
        System.out.println("계단을 오르는 방식 : " + calcRecursiveFibonacci(a + 1)); // 계단을 오르는 방식 : 5
        System.out.println("=====================================");
        int b = 5;
        System.out.println(fibonacci_bottom(b));
        System.out.println("=====================================");
        LCS("banaan", "vbankn");
        System.out.println("=====================================");

	}

}
