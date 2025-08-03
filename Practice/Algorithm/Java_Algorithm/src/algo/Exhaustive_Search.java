package algo;
import java.util.*;

public class Exhaustive_Search 
{
	/*
	완전 탐색(Exhaustive Search)
	- 알고리즘에서 사용되는 기법 중 하나로 ‘모든 가능한 경우의 수를 탐색’하여 ‘최적의 결과를 찾는 방법’을 의미
	- 모든 가능성을 고려하기 때문에 항상 최적의 해를 찾을 수 있음 but 경우의 수가 매우 많은 경우 시간과 메모리의 부담大 -> 문제의 특성에 따라 다른 탐색 기법을 사용을 권장
	- 종류 : 브루트 포스, 비트마스크, 백트래킹, 순열 탐색, 재귀함수, 비선형 구조 탐색(DFS,BFS)
	- 시간복잡도 순서 :  (효율)비트마스크 > DFS/BFS > Brute-Force > 재귀함수 > 순열 > 백트래킹(비효율)
	* 미 완전 탐색 = 모든 경우의 수를 고려하지 하지 않고 더 이상 탐색이 필요 없는 경우 그 루트를 끊어버리는 것
	(ex)가지치기(Pruning) = 재귀함수가 함수를 모든 경우의 수를 탐색하다가 결과를 찾아서 탐색을 중지하는 경우 루트를 끊는 경우
	 */
	
	
	/*
	브루트 포스(Brute-Force)
	- 모든 경우를 다 탐색하면서 결과를 얻는 알고리즘
	- 경우의 수가 작을 때 사용하는 것이 일반적 (ex)자물쇠의 비밀번호를 알 수 없는 경우
	- 수행하는데 오래 걸림 +  자원이 많이 소모 but 이론적으로 가능한 수를 모두 검색하기에 예상된 결과를 얻기 가능
	- 완전탐색에서 브루트 포스 = 모든 경우를 다 검사하여 원하는 값을 탐색하는 방법
	*브루트 포스를 이용한 공격방식 : 로그인 페이지에서 사용자 이름과 비밀번호를 입력하여 로그인하는 경우 해커들은 브루트 포스 알고리즘을 이용하여 가능한 모든 비밀번호를 시도하면서 로그인을 시도 -> 력한 비밀번호를 사용하고 로그인 시도 횟수를 제안
	*/
	
	// 브루트 포스(Brute-Force) 사용 예시 1 - 배열 탐색 : 배열에서 특정 값을 찾는 문제에서 브루트 포스 알고리즘은 배열을 모두 탐색하여 값을 찾는 방식으로 문제를 해결
	public static int findIndex(int[] arr, int target) 
	{
	    for (int i = 0; i < arr.length; i++) 
	    {
	        if (arr[i] == target) 
	        {
	            return i;
	        }
	    }
	    return -1;
	}	

	
	// 브루트 포스(Brute-Force) 사용 예시 2 - 문자열 비교 : 가능한 모든 문자열 쌍을 비교하여 최소값 또는 최대값을 찾는 방식으로 문제를 해결
	public static int stringCompare(String s1, String s2) 
	{
	    int n1 = s1.length(), n2 = s2.length();
	    int min = Math.min(n1, n2);

	    for (int i = 0; i < min; i++) 
	    {
	        if (s1.charAt(i) != s2.charAt(i)) 
	        {
	            return s1.charAt(i) - s2.charAt(i);
	        }
	    }

	    if (n1 == n2) 
	    {
	        return 0;
	    }
	    
	    else if (n1 > n2) 
	    {
	        return s1.charAt(min);
	    }
	    
	    else 
	    {
	        return s2.charAt(min);
	    }
	}	
	
	
	/*
	비트마스크(bitmask)
	- ‘이진수’를 ‘비트 연산’을 통해 경우의 수를 줄여가며 탐색하는 방식
	- 하나의 변수에 여러 개의 상태 정보를 저장할 수 있으며 이를 통해 복잡한 조건문을 간단하게 처리
	- 비트 연산을 사용하기 때문에 빠르게 계산할 수 있어서, 경우의 수가 많은 경우에 유용
	- 완전 탐색에서 비트마스크 = 모든 경우의 수를 이진수로 표현하여 빠르게 계산을 해 나아가는 방식
	*/
	
	// 비트마스크(bitmask) 사용 예시 1 - 권한 관리 : 각 권한을 비트로 표현하여 하나의 정수값으로 나타내면 매우 간편
	public static final int PERMISSION_READ = 1 << 0; // 0001
	public static final int PERMISSION_WRITE = 1 << 1; // 0010
	public static final int PERMISSION_DELETE = 1 << 2; // 0100
	public static final int PERMISSION_EXECUTE = 1 << 3; // 1000
	int userPermission = PERMISSION_READ | PERMISSION_WRITE; // 0011
	int groupPermission = PERMISSION_READ | PERMISSION_EXECUTE; // 1001
	boolean hasReadPermission = (userPermission & PERMISSION_READ) != 0; // true
	boolean hasDeletePermission = (groupPermission & PERMISSION_DELETE) != 0; // false
	
	
	// 비트마스크(bitmask) 사용 예시 2 - 집합 관리 : 집합을 비트로 표현하여 메모리를 절약 - 예를 들어, 0부터 31까지의 정수 중에서 3, 5, 7번째 원소를 포함하는 집합을 나타내면 다음과 같이 표현
	int set = (1 << 3) | (1 << 5) | (1 << 7); // 0010 1010 1000
	boolean hasElement5 = (set & (1 << 5)) != 0; // true
	boolean hasElement6 = (set & (1 << 6)) != 0; // false
	
	
	// 비트마스크(bitmask) 사용 예시 3 -  상태 플래그 관리 : 여러 상태를 하나의 정수 값으로 나타내어 관리 - 예를 들어, 주어진 수가 2의 거듭제곱인지 여부를 판단
	public static final int FLAG_POWER_OF_TWO = 1 << 0; // 0001
	public static final int FLAG_NEGATIVE = 1 << 1; // 0010
	
	public void bitmask()
	{
		int number = 8; // 2의 거듭제곱
		int flags = 0;

		if ((number & (number - 1)) == 0) 
		{ // 2의 거듭제곱인 경우
			flags |= FLAG_POWER_OF_TWO;
		}

		if (number < 0) 
		{ // 음수인 경우
			flags |= FLAG_NEGATIVE;
		}

		if ((flags & FLAG_POWER_OF_TWO) != 0) 
		{
			System.out.println(number + " is power of two");
		}

		if ((flags & FLAG_NEGATIVE) != 0) 
		{
			System.out.println(number + " is negative");
		}
	}
	
	
	/*
	백트래킹(Backtracking)
	- 해결책으로 가는 도중에 막히게 되면 그 지점으로 다시 돌아가서 다른 경로를 탐색하는 방식
	- 주로 재귀함수를 사용하여 구현하며 스택을 이용하여서 사용하는 경우도 존재
	- 재귀함수를 이용하는 경우 해결책을 찾기 위해 생성, 검사, 선택, 이동, 되돌아가기 등 과정이 재귀적으로 수행
	- 스택을 이용하는 경우 이전 상태로 되돌아가기 위해 스택에 현재 상태를 저장하고, 되돌아갈 때 스택에서 상태를 꺼내오는 형태로 수행
	- 해결책을 찾아가는 도중에 막히게 되면 다시 돌아가서 다른 경로로 탐색을 하여 결국 모든 가능한 경우의 수를 탐색하여 해결책을 찾아가는 방식으로 사용
	*/
	
	
	
	/*
	순열 탐색(Permutation Search) 
	- 순열(서로 다른 n개 중에서 r개를 선택하여 숫자를 모든 순서대로 뽑는 경우)을 이용하여 모든 경우의 수를 탐색하는 방법
	순열 ex - 1, 2, 3 세 숫자 중에서 '2개를 선택'하여 숫자를 모든 순서대로 뽑는 경우 : [1,2] [1,3] [2,1] [2,3] [3.1]
	- 완전 탐색에서 순열 = 서로 다른 n개 중에서 r개를 선택해서 나열하면서 모든 경우의 수를 탐색하는 방식
	- Swap 배열, Visited 배열 이용해서 순열 구현 가능
	*/
	
    /*
    순열 탐색(Permutation Search) 사용 예시 1 -  Swap 배열 : 배열에서 두 요소의 위치를 바꿔가며 순열을 생성하는 방법 - 쉽게 구현할 수 있지만, 큰 데이터셋에서는 비효율적일 수도 있다.
    permute 탐색 - param : arr & k
    배열의 요소 값을 Swap - param : arr, i, j
	*/
	    static void permute(int[] array, int k) 
	    {
	        for (int i = k; i < array.length; i++) 
	        {
	            swap(array, i, k);
	            permute(array, k + 1);
	            swap(array, k, i);
	        }
	        
	        if (k == array.length - 1) 
	        {
	            System.out.println(Arrays.toString(array));
	        }
	    }

	    static void swap(int[] array, int i, int j) 
	    {
	        int temp = array[i];
	        array[i] = array[j];
	        array[j] = temp;
	    }	


	/*
	순열 탐색(Permutation Search) 사용 예시 2 -  Visited 배열 :  배열에서 '현재 인덱스의 값을 선택한 후' 해당 인덱스를 visited라는 배열에 체크 -> 이후, 다음 인덱스로 넘어가기 전 visited 배열에서 체크되지 않은 가장 작은 인덱스를 선택 :  마지막 인덱스까지 반복
	- swap을 이용한 배열보다 효율적
	*/

	/*
	깊이 우선 탐색(DFS: Depth-First Search) / 너비 우선 탐색(Breadth-First Search: BFS)
	- 비 선형 구조에서 주로 사용
	
	깊이 우선 탐색(DFS: Depth-First Search)
	- 루트 노드에서 시작하여 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법
	- 자료구조의 ‘스택’을 이용하여서 구현
	
	
	너비 우선 탐색(Breadth-First Search: BFS)
	- 루트 노드에서 시작하여 인접한 노드를 먼저 탐색하는 방법
	- 자료구조의 ‘큐’를 이용하여서 구현
	*/
	
	
	public static void main(String[] args) 
	{

	}

}
