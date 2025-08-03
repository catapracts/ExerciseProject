package algo;

public class recur 
{
	/*
	재귀함수 활용 예시 1 - Factorial : 자연수 n에 대해서 1부터 n까지의 모든 자연수를 곱한 값
	factorial() 함수에 파라미터로 값을 넘길 경우 재귀함수로 반복하여 결괏값을 반환해 주는 함수
	factorial(5) = 5 * factorial(4)
	factorial(4) = 4 * factorial(3)
	factorial(3) = 3 * factorial(2)
	factorial(2) = 2 * factorial(1)
	factorial(1) = 1 * factorial(0)
	factorial(0) = 1
	그러므로, factorial(5)는 5 * 4 * 3 * 2 * 1 * 1 = 120이 됩니다.
	*/
	public static int factorial(int n)
	{
	  if (n == 0) 
	  { // 기본 케이스
	    return 1;
	  } 
	        
	  else 
	  { // 재귀 케이스
	     return n * factorial(n - 1);
	  }
	}
	
	
	/*
	재귀함수 활용 예시 2 - N자연수 합 계산
	sumNaturalNumber() 함수에 파라미터로 값을 넘길 경우 재귀함수를 반복하여 결과값을 반환해 주는 함수
	5라는 값을 파라미터로 넘겼을 때 아래와 같이 호출이 됩니다. 
	1+2+3+4+5의 결괏값인 15를 반환합니다.
	그러므로, sumNaturalNumber(5)는 1+2+3+4+5=15가 됩니다
	*/
    public static int sumNaturalNumber(int n) 
    {
        if (n == 1) 
        {
            return 1;
        } 
        
        else 
        {
            return n + sumNaturalNumber(n - 1);
        }
    }

    
	/*
	재귀함수 활용 예시 3 - 거듭제곱(pow) : 하나의 숫자(밑)를 다른 숫자(지수)만큼 곱하는 것
	파라미터로 base 밑과 exponent 지수를 인자로 받아서 거듭제곱을 수행하는 함수
	밑의 값 2와 지수값 5를 넣었을 때 2 x 2 x 2 x 2 x 2 값이 되어서 32가 출력
	Math.pow() 함수를 이용하여 동일한 기능을 처리
	*/
    public static int pow(int base, int exponent) 
    {
        if (exponent == 0) 
        {
            return 1;
        }
        
        else 
        {
            return base * pow(base, exponent - 1);
        }
    }
    
    
	/*
	재귀함수 활용 예시 4 - 문자열 뒤집기
	reverseString() 함수를 통해 문자열의 값이 0이 되면 문자열을 반환하고 
	그렇지 않으면 첫 번째 문자를 마지막 문자와 바꾸고 
	나머지 문자열에 대해 reverseString() 함수를 재귀적으로 호출한 결과를 반환
	*/
	public static String reverseString(String str) 
	{
	    if (str.length() == 0) 
	    {
	        return str;
	    }
	    
	    else 
	    {
	        return reverseString(str.substring(1)) + str.charAt(0);
	    }
	}
	
	
	/*
	재귀함수 이용한 알고리즘 1 - 피보나치 수열 : 이전 두 항의 합이 다음 항이 되는 수열
	첫째 항과 둘째 항이 1이고 이후 모든 항은 모든 항은 바로 앞 두항의 합으로 이루어지는 수열을 의미
	피보나치 수열의 예시 - [1, 1, 2, 3, 5, 8, 13, 21, 34,...]
	*/
	public static int fibonacci(int n) 
	{
	    if (n == 0) 
	    {
	        return 0;
	    }
	    
	    else if (n == 1) 
	    {
	        return 1;
	    }
	    
	    else 
	    {
	        return fibonacci(n-1) + fibonacci(n-2);
	    }
	}
	
	
	/*
	재귀함수 이용한 알고리즘 2 - 유클리드 호제법/알고리즘(Euclidean Algorithm) : 두 수의 “최대공약수(GCD)”를 찾기 위한 알고리즘
	큰 수를 작은 수로 나누어 떨어지게 하여 수를 반복적으로 취하여 나머지 0이 될 때까지 작동하는 방법을 의미
	작은 수가 최대공약수
	*/
	public static int gcd(int m, int n) 
	{
		
	    if (n == 0) 
	    {
	        return m;
	    } 
	    
	    else 
	    {
	        return gcd(n, m % n);
	    }
	}
	
	
	/*
	재귀함수 이용한 알고리즘 3 - 이진 탐색(Binary Search) 알고리즘 : 정렬된 배열에서 원하는 데이터를 빠르게 찾기 위한 알고리즘
	배열의 중간값을 선택한 후, 찾고자 하는 데이터와 중간값을 비교
	만약 중간값이 찾고자 하는 데이터보다 크다면, 중간값의 왼쪽 부분 배열에서 다시 중간값을 선택하여 비교
	중간값이 찾고자 하는 데이터보다 작다면, 중간값의 오른쪽 부분 배열에서 다시 중간값을 선택하여 비교
	이 과정을 반복하여 원하는 데이터를 찾기
	이진탐색은 데이터의 개수가 많을 때도 빠르게 데이터를 찾을 수 있기 때문에 많이 사용되는 알고리즘 중 하나
	
	높은 인덱스가 낮은 인덱스보다 크거나 같은지 확인
	1. 중간 값을 구합니다.
	2. 배열의 요소 값이 찾는 값과 동일하면 중간 값을 반환합니다.
	3. 중간 값이 키보다 큰 경우 : 낮은 인덱스와 중간 인덱스에서 1을 뺀 값을 가지고 함수를 재귀적으로 호출합니다.
	4. 중간 값이 키보다 작은 경우 : 중간 인덱스에 1을 더하고 높은 인덱스와 함께 함수를 재귀적으로 호출합니다
	*/
	public static int binarySearch(int[] arr, int low, int high, int key) 
	{
	    // 1. 높은 인덱스가 낮은 인덱스보다 크거나 같은지 확인
	    if (high >= low) 
	    {
	        // 2. 중간 값을 구합니다.
	        int mid = low + (high - low) / 2;

	        // 3. 배열의 요소 값이 찾는 값과 동일하면 중간 값을 반환
	        if (arr[mid] == key) 
	        {
	            return mid;
	        }
	        
	        // 4. 중간 값이 키보다 큰 경우 : 낮은 인덱스와 중간 인덱스에서 1을 뺀 값을 가지고 함수를 재귀호출
	        else if (arr[mid] > key) 
	        {
	            return binarySearch(arr, low, mid - 1, key);
	        }
	        
	        // 5. 중간 값이 키보다 작은 경우 : 중간 인덱스에 1을 더하고 높은 인덱스와 함께 함수를 재귀호출
	        else 
	        {
	            return binarySearch(arr, mid + 1, high, key);
	        }
	    }
	    // 6. 높은 인덱스가 낮은 인덱스보다 작으면 배열에서 키를 찾지 못했음을 나타내기 위해 -1을 반환
	    return -1;
	}
	
	
	/*
	재귀함수 이용한 알고리즘 4 - 이항계수(binomial theorem) 알고리즘 : 조합론에서 사용되며, n개의 서로 다른 원소에서 r개의 원소를 선택하는 경우의 수
	원소 n개 중에서 r개를 선택하는 경우의 수를 계산하는 함수
	1. r이 0이거나 n과 같으면 함수는 1을 반환합니다.
	2. 그렇지 않으면 k-1과 n-1인자로하여 자기 자신을 두 번 호출하고 두 결과의 합을 반환합니다.
	3. 이 과정은 k가 0이나 n과 같아질 때까지 반복됩니다.
	*/
	public static int binomialCoefficient(int n, int k) 
	{
	    if (k == 0 || k == n) 
	    {
	        return 1;
	    }
	    
	    else 
	    {
	        return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
	    }
	}
	
	

	public static void main(String[] args) 
	{
		System.out.println(factorial(5));
		System.out.println("=============================");
		System.out.println(sumNaturalNumber(5));
		System.out.println("=============================");
		System.out.println(pow(2,5));
		System.out.println("=============================");
		System.out.println(reverseString("abcdefg"));
		System.out.println("=============================");
		System.out.println(fibonacci(9));
		System.out.println("=============================");
		System.out.println(gcd(10, 40));
		System.out.println("=============================");
		int array[] = {1,2,3,4,5};
		System.out.println(binarySearch(array, 0, 4, 3));
		System.out.println("=============================");
		System.out.println(binomialCoefficient(10, 3));
	}

}
