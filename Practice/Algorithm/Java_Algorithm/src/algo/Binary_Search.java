package algo;

import java.util.Arrays;

public class Binary_Search 
{
	/*
	이진탐색(Binary Search)
	- ‘정렬된 배열’에서 ‘특정 값’을 찾는 알고리즘
	
	- 탐색 범위를 절반씩 줄여나가기 때문에 선형탐색에 비해 빠른 속도 but 배열이 정렬되어 있어야 한다는 조건이 필요(정렬 작업이 필요)
	
	- 진행과정
	1. 배열의 ‘중간 값’을 선택하여 찾고자 하는 값과 비교합니다.
	2. 만약 중간 값이 찾고자 하는 값보다 크면 ‘배열 왼쪽 부분'에서 탐색을 진행하고, 값보다 작으면 ‘배열 오른쪽 부분'에서 탐색을 진행합니다.
	3. 이 과정에서 찾고자 하는 값이 나올 때까지 반복합니다.
	
	- 이진 탐색과 for문(선형 탐색)의 차이점 
	1. 일반적으로 이진 탐색을 이용하여 값을 찾는 방법이 for문을 이용하는 것보다 빠릅니다.
	2. 이진 탐색은 정렬된 배열에서 원하는 값을 찾는 알고리즘이며, 중간값을 찾아 탐색 범위를 반으로 줄이면서 값을 찾아갑니다.
	3. 이에 비해 for문은 배열 전체를 순회하면서 값을 찾기 때문에, 배열의 크기와 상관없이 속도가 일정하게 증가합니다.
	
	- 사용처
	1. 이진 탐색은 데이터가 오름차순으로 정렬되어 있을 때 특정한 값을 찾아야 할 때 사용합니다.
	2. 데이터의 양이 많을 경우에도 빠른 시간 내에 값을 찾을 수 있어 많이 활용되고 있습니다.
	- 성능 : 시간 복잡도 : O(logn)으로써 다른 정렬에 비해 상대적으로 매우 빠릅
	*/
	
	/*
	이분탐색
	arr {int[]}: 전체 배열
	key {int}: 찾고자 하는 요소
	- 예시로 int[] arr = {1, 3, 5, 8, 11, 15, 30, 32, 45}이고 key 값이 8인 경우의 이진탐색을 찾는 원리
	1. while문으로 구성
	1-1. low는 첫번째 인덱스, high는 마지막 인덱스를 지정합니다.
	1-2. 마지막 인덱스 보다 첫번째 인덱스가 같아지거나 작을 경우까지 순회합니다.
	1-3. 중간 값을 구합니다.
	1-4.1. 중간 값보다 찾으려는 값(key)가 큰 경우 중간 값에 1을 더하여 오른쪽 절반을 탐색합니다.
	1-4.2. 중간 값보다 찾으려는 값(key)가 작은 경우 중간 값에 1을 빼고 왼쪽 절반만 탐색합니다.
	1-4.3. 이외에 경우 중간 값을 최종값으로 반환합니다.
	1-5. 최종 탐색을 못한 경우 값은 -1로 반환합니다.
	 */
	public static int binSearchCourse(int array[], int key)
	{
	    int answer = 0;
	    // [STEP1] 시작 인덱스와 마지막 인덱스 값을 지정합니다.
	    int low = 0;
	    int high = array.length - 1;

	    // [STEP2] 마지막 인덱스를 보다 첫번째 인덱스가 같아지거나 작을 경우까지 순회합니다.
	    while (low <= high) 
	    {

	        // [STEP3] 중간 값을 구합니다.
	        int mid = (low + high) / 2;

	        // [CASE4-1] 중간 값보다 찾으려는 값(key)가 큰 경우 : 중간 값에 1을 더하여 오른쪽 절반을 탐색합니다.
	        if (array[mid] < key) 
	        {
	            low = mid + 1;
	        }
	        
	        // [CASE4-2] 중간 값보다 찾으려는 값(key)가 작은 경우 : 중간값에 1을 빼서 왼쪽 절반을 탐색합니다.
	        else if (array[mid] > key) 
	        {
	            high = mid - 1;
	        }
	        
	        // [CASE4-3] 해당 경우가 아니면 중간값을 최종 값으로 반환합니다.
	        else 
	        {
	            answer = mid;
	        }
	    }
	    
	    // [STEP5] 최종 탐색을 하지 못할 경우 -1을 반환합니다.
	    if (answer == 0) answer = -1;
	    
	    return answer;
	}
	
	
	
	/*
	2. 재귀함수를 이용
	2-1. 높은 인덱스가 낮은 인덱스보다 크거나 같은지 확인합니다.
	2-2. 중간 값을 구합니다.
	2-3. 배열의 요소 값이 찾는 값과 동일하면 중간 값을 반환합니다.
	2-4. 중간 값이 키보다 큰 경우 : 낮은 인덱스와 중간 인덱스에서 1을 뺀 값을 가지고 함수를 재귀적으로 호출합니다.
	2-5. 중간 값이 키보다 작은 경우 : 중간 인덱스에 1을 더하고 높은 인덱스와 함께 함수를 재귀적으로 호출합니다
	재귀를 사용하여 이진 알고리즘을 구현합니다.
	@param arr 배열, @param low 낮은 인덱스
	@param high 높은 인덱스, @param key 검색할 값
	@return
	*/
	public static int binarySearch(int[] arr, int low, int high, int key) 
	{
	    // 1. 높은 인덱스가 낮은 인덱스보다 크거나 같은지 확인합니다.
	    if (high >= low) 
	    {

	        // 2. 중간 값을 구합니다.
	        int mid = low + (high - low) / 2;

	        // 3. 배열의 요소 값이 찾는 값과 동일하면 중간 값을 반환합니다.
	        if (arr[mid] == key) 
	        {
	            return mid;
	        }
	        
	        // 4. 중간 값이 키보다 큰 경우 : 낮은 인덱스와 중간 인덱스에서 1을 뺀 값을 가지고 함수를 재귀적으로 호출합니다.
	        else if (arr[mid] > key) 
	        {
	            return binarySearch(arr, low, mid - 1, key);
	        }
	        
	        // 5. 중간 값이 키보다 작은 경우 : 중간 인덱스에 1을 더하고 높은 인덱스와 함께 함수를 재귀적으로 호출합니다
	        else 
	        {
	            return binarySearch(arr, mid + 1, high, key);
	        }
	    }

	    // 6. 높은 인덱스가 낮은 인덱스보다 작으면 배열에서 키를 찾지 못했음을 나타내기 위해 -1을 반환합니다.
	    return -1;
	}
	
	
	/*
	문자열 배열의 경우 이진/이분 탐색을 사용하는 경우 Arrays.binarySearch() 함수를 이용
	
	Arrays.binarySearch() 함수
	- 매개변수로 주어진 배열에서 원하는 값을 이진 탐색하여 인덱스를 반환
	- 해당 원소가 배열에 없다면 음수를 반환
	- 이진 탐색을 하기 전에 반드시 배열을 정렬
	public static int binarySearch(Object[] a, Object key)
	Object[] a = 탐색하고자 하는 배열
	Object key = 배열에서 찾으려는 값
	*/
	
	/*
	예시 - String[] 내에서 key 값을 찾기
	Arrays.binaraySearch() 함수를 이용하여 배열 내에 key 값이 존재하는지 확인
	이분탐색 : 문자열
	arr {int[]}: 전체 배열 key {int}: 찾고자 하는 요소
	*/
	
	public static int binSearchArray(String[] array, String key)
	{
	    int answer = 0;
	    Arrays.sort(array);
	    int result = Arrays.binarySearch(array, key);
	    if (result < 0) 
	    {
	        System.out.println("Element is not present in the array.");
	    } 
	    
	    else 
	    {
	        System.out.println("Element is present at index " + result);
	    }
	    
	    return result;
	}
	
	
	
	public static void main(String[] args) 
	{
		
	}

}
