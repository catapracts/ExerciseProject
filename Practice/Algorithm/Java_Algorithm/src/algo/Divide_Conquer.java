package algo;
import java.util.*;

public class Divide_Conquer 
{
	/*
	분할정복(Divide and Conquer Algorithm)
	- ‘큰 문제’를 ‘작은 문제’로 나누어서 해결하는 알고리즘 - 크고 방대한 문제를 해결할 때 유용
	- 구체적으로 하나의 큰 문제를 작은 부분 문제들로 나눕니다. 그리고 나눈 부분 문제를 해결하고 해결된 해들을 모아 원래의 문제를 해결해 나아가는 방식을 의미합니다.(분할 → 정복 → 결합 과정)
	
	
	*분할 정복과 동적 계획법 알고리즘 차이
	- 동적 계획법(Dynamic Programming)과 분할 정복(Divide and Conquer)은 서로 비슷한 알고리즘 기법이지만 ‘목적’과 '적용 대상’이 다릅니다.
	- 분할정복의 경우는 큰 문제를 작은 문제들로 나누어서 해결해 나아가면서 큰 수의 곱셈, 퀵 정렬 등과 같은 문제를 해결
	- 동적 계획법의 경우는 작은 문제들을 풀면서 그 결과를 저장해 나아가면서 전체 문제를 해결해 나가면서 최적화 문제나 최단 경로 문제등의 문제를 해결
	
	
	분할정복 알고리즘을 활용하여 문제를 해결하는 단계
	1.분할 : 첫번째로 문제를 작은 부분 문제들로 나눕니다.
	2.정복 : 두번째로 각각의 부분 문제를 해결합니다
	3.결합 : 세번째로 부분 문제들의 해를 모아서 원래 문제의 해를 구합니다
	
	
	분할정복 알고리즘 장/단점
	장점 : 문제 해결 과정 간편, 병렬 처리 수행, 빠른 속도, 문제 해결 전략 명확
	단점 : stack overflow, 추가 memory 필요, 효율↓, 추가 시간 소요
	
	
	분할정복 알고리즘의 시간 복잡도
	- T(n) = aT(n/b) + O(n^d)
	- Master theorem에 따라 결정
	- 빅오 표기법을 이용하였을 때 일반적으로 O(n log n)
	*시간 복잡도 : 알고리즘이 실행될 때 필요한 ‘입력 값’과 ‘연산 수행 시간’에 따라 효율적인 알고리즘을 나타내는 척도
	**Master theorem : T(n)을 분석하여 시간복잡도를 추정하는 데 유용한 방법
	***빅오 표기법 : 알고리즘의 입력 크기에 대해 수행 시간이 어떤 방식으로 증가하는지를 표기 / 최악의 경우의 시간 복잡도를 의미
	
	
	분할정복 활용 알고리즘 - 퀵 정렬(Quick Sort) / 이진 검색 알고리즘 / 병합 정렬 알고리즘
	*/
	
	

	//Quick Sort
	public static void quickSort(int[] arr, int left, int right) 
	{
	    if (left >= right) return;

	    int pivot = partition(arr, left, right);

	    quickSort(arr, left, pivot - 1);
	    quickSort(arr, pivot + 1, right);
	}


	 //분할 적용 : 주어진 구간에서 피봇을 선택하고, 분할을 수행하는 함수	
	public static int partition(int[] arr, int left, int right) 
	{
	    int pivot = arr[left];
	    int i = left + 1;
	    int j = right;

	    while (i <= j) 
	    {
	        while (i <= right && arr[i] < pivot) i++;
	        while (j >= left + 1 && arr[j] > pivot) j--;

	        if (i > j) 
	        {
	            swap(arr, left, j);
	        }
	        
	        else 
	        {
	            swap(arr, i, j);
	        }
	    }
	    return j;
	}


	//값 변경 : 배열에서 두 원소의 위치를 바꾸는 함수
	public static void swap(int[] arr, int i, int j) 
	{
	    int temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	}
	
	
	
	
	/*
	이진 검색 알고리즘 by 분할정복의 3단계
	1. 분할 : 배열을 절반으로 나누는 과정을 수행합니다.
	2. 정복 : 찾으려는 값이 절반 중 하나에 위치에 있는지 확인하는 부분 문제를 해결하는 과정을 수행합니다.
	3. 결합 : 배열을 절반으로 나누고, 찾으려는 값이 절반 중 하나에 위치해 있는지 확인하는 과정을 통해 부분문제를 모아서 해결하는 원래의 해를 구하는 과정을 수행합니다.
	int[] arr : 전체 배열
	int key : 찾고자 하는 요소
	*/
	
	public static void binSearch(int[] array, int key)
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
	}
	
	
	/*
	병합 정렬 알고리즘
	
	과정
	1. 리스트의 길이가 0 또는 1이면 이미 정렬된 것으로 본다.
	2. 그렇지 않으면 리스트를 두 개의 균등한 크기로 분할한다.
	3. 각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.
	4. 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다.
	*/
	
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right) 
    {
        int[] temp = new int[arr.length];
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) 
        {
            if (arr[i] <= arr[j]) 
            {
                temp[k++] = arr[i++];
            } 
            
            else 
            {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) 
        {
            temp[k++] = arr[i++];
        }

        while (j <= right) 
        {
            temp[k++] = arr[j++];
        }

        for (int index = left; index < k; index++) 
        {
            arr[index] = temp[index];
        }
    }
	
	
	public static void main(String[] args) 
	{
        int[] arr = { 5, 2, 4, 7, 1, 3, 2, 6 };
        mergeSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
	}

}
