package algo;
import java.util.*;
import java.util.stream.*;

public class CodeTest 
{
	
	//문자열 출력하기
	public static void str_out()
	{
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
        String str = a;
        if(str.length()>=1 && str.length()<=1000000)
        {
            System.out.println(str);
        }
	}
	
	//실수의 정수 부분 출력하기
	public static int real_to_int(double flo)
	{
		int answer = 0;
		int result;
		if(flo>=0 && flo<=100)
		{
			result = (int)flo;
			answer = result;
			System.out.println(flo+"의 정수 부분은 "+result+"입니다.");
		}
		return answer;
	}
	
	/*
	정수 리스트 num_list와 정수 n이 주어질 때, num_list의 첫 번째 원소부터 마지막 원소까지 n개 간격으로 저장되어있는 원소들을 차례로 담은 리스트를 return하도록 solution 함수를 완성해주세요.
	*/
	public static int[] save_array(int[] num_list, int n)
	{
        int[] answer = {};
        int index = 0;
        int[] result = {};
        
        // 배열 크기지정
        if(num_list.length % n == 0) 
        {
        	answer = new int[num_list.length/n];
        }
        
        else 
        {
        	answer = new int[num_list.length/n + 1];
        }
        
        for(int i=0; i<num_list.length; i+=n) 
        {
        	answer[index] = num_list[i];
        	index++;
        }
        
        result=answer;        
        System.out.println(Arrays.toString(num_list)+"에서 "+n+"개 간격으로 저장되어 있는 원소들은"+Arrays.toString(result)+"입니다.");        
        return answer;
//        int[] answer = {};
//        int[] result = new int[num_list.length/n];
//        int i = 0;
//        int j = 0;
//        System.out.println(result.length);
//
//
//                for(int i = 0; i<result.length; i++)
//                {
//
//                	System.out.println(j);
//                	System.out.println(num_list[j]+"\n");
//                	result[i] = num_list[j];
//                	if(j>=num_list.length)
//                	{
//                		break;
//                	}
//                	j+=n;
//                	System.out.println(j);
//                	System.out.println(num_list[j]+"\n");
//                }
//        System.out.println(Arrays.toString(result));
//
//        //System.out.println(Arrays.toString(num_list)+"에서 "+n+"개 간격으로 저장되어 있는 원소들은"+Arrays.toString(result)+"입니다.");
//        
//        return result;
	}
	
	
	/*
	K번째 수
	문제 설명
	배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

	예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
	array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
	1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
	2에서 나온 배열의 3번째 숫자는 5입니다.
	
	배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, 
	commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.
	
	제한 사항
	array의 길이는 1 이상 100 이하입니다.
	array의 각 원소는 1 이상 100 이하입니다.
	commands의 길이는 1 이상 50 이하입니다.
	commands의 각 원소는 길이가 3입니다.
	
	입출력 예
	[1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
	[1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
	[1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.
	*/
	
	/*
	 내가 만든 답안
	 
    public static void knum_swap(int arr[], int index1, int index2)
    {
        int tmp = arr[index1];
        arr[index1]= arr[index2];
        arr[index2] = tmp;
    }
    
    public static void knum_Selection(int array[])
    {
    	for(int i = 0; i<array.length; i++)
    	{
    		int minimum_index = i;
    		
    		for(int j = i+1; j<array.length; j++)
    		{
    			if(array[j] < array[minimum_index])
    			{
    				minimum_index = j;
    			}
    		}
    		knum_swap(array, i, minimum_index);
    	}
    }
    
    
    public static void cut(int arr[], int i, int j)
    {
    	if(i != j) 
    	{
    		int array[] = new int[j-i+1];     
            int a = i;
            int b = j;

            if(b<b+1)
            {
                for(int x = 0; x<array.length; x++)
                {
                    array[x] = arr[a-1];
                    a++;
                }            
            }
            
            knum_Selection(array);
            
            System.out.println(Arrays.toString(arr)+"를 "+ i +"번째부터 "+j+"번째까지 "+"자른 후 정렬합니다."+Arrays.toString(array)+"의 "+i+"번째 숫자는 "+array[i-1]+"입니다.");
    	}
    	
    	if(i==j)
    	{
    		int array[] = new int[j-i+1];     

    		array[0] = arr[i-1];
    		
            System.out.println(Arrays.toString(arr)+"를 "+ i +"번째부터 "+j+"번째까지 "+"자른 후 정렬합니다."+Arrays.toString(array)+"의 "+"첫 번째 숫자는 "+array[0]+"입니다.");
    	}


    }
	
	
	public int[] knum(int[] array, int[][] commands)
	{
        int[] answer = {};
        
        int i, j, k;
        
        //먼저 자른 뒤, 정렬 후 출력
        
        //System.out.println(array+"를 "+i+"번째부터 +j+"번째까지 "+"자른 후 정렬합니다."++"의 "++"번째 숫자는 "++"입니다.");
        
        return answer;		
	}
	 */

	   //K번째 수 - 답지 1
	   public int[] solution(int[] array, int[][] commands) 
	   {
	        int[] answer = new int[commands.length];

	        for(int i=0; i<commands.length; i++)
	        {
	            int[] temp = Arrays.copyOfRange(array, commands[i][0]-1, commands[i][1]);
	            Arrays.sort(temp);
	            answer[i] = temp[commands[i][2]-1];
	        }

	        return answer;
	    }
	   
	   
	   //K번째 수 - 답지 2
	   public static int[] solution1(int[] array, int[][] commands) 
		{ 
			int[] answer = new int[commands.length]; // 3
			int n = 0;
			
			for (int i = 0; i < commands.length; i++) 
			{
				int k = 0;
	                                    // new int[4] // new int[1] // new int[7]
				int[] list = new int[commands[i][1] - commands[i][0] + 1]; 
	                                     // j = 2 ~ 5 / j = 4 ~ 4 / j= 1 ~ 7
				for (int j = commands[i][0]; j <= commands[i][1]; j++) 
				{ 
					list[k++] = array[j - 1]; // {5,2,6,3} / {6} / {1,5,2,6,3,7,4}
				}
				
				Arrays.sort(list); // 오름차순 정렬 {2,3,5,6} / {6} / {1,2,3,4,5,6,7}
				answer[n++] = list[commands[i][2] - 1]; // {5,6,3}
			}
			
			return answer;
		}  
	   
	   
	 //K번째 수 - 답지 3
		public int[] solution2(int[] array, int[][] commands) 
		{
			int[] answer = new int[commands.length];
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			for (int i = 0; i < commands.length; i++) 
			{
				for (int j = commands[i][0]; j <= commands[i][1]; j++) 
				{ 
					list.add(array[j-1]);
					Collections.sort(list); // ArrayList 오름차순 정렬
				}
				
				answer[i] = list.get(commands[i][2] - 1); 
				list.clear();
			}

			return answer;
		}
	   
	 //K번째 수 - 답지 4
		public int[] solution3(int[] array, int[][] commands) 
		{
			int[] answer = new int[commands.length];

			for (int i = 0; i < commands.length; i++) 
			{
				int[] temp = Arrays.copyOfRange(array, commands[i][0] - 1, commands[i][1]); 
	            					   // 원본 배열, 복사할 시작인덱스, 복사할 끝인덱스

				Arrays.sort(temp); // 배열 오름차순 정렬
				answer[i] = temp[commands[i][2] - 1];
			}
			return answer;
		}
		
		
/*
가장 큰 수
문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.
0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.


제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
*/

/*
 가장 큰수 구하기 정렬 - 내가 만든 답안
	public static int factorial(int n)
	{
		if(n==0)
		{
			return 1;
		}
		
		else
		{
			return n*factorial(n-1);
		}
	}

	public static void transfer(int[] numbers)
	{
		// 문자형으로 변환
		String arr[] = new String[numbers.length];
		
		for(int i = 0; i<numbers.length; i++)
		{
			arr[i] = String.valueOf(numbers[i]);
		}
		
		System.out.println(Arrays.toString(arr));
		System.out.println(arr.getClass());
		System.out.println(arr[0].getClass());
		System.out.println(arr[0].getClass().getName());
		
		
		//조합 -> a, b, c : abc, acb, bac, bca, cab, cbc
		// 배열의 길이 = 조합해서 나올 수 있는 갯수 -> 팩토리얼
		String array1[] = new String[factorial(arr.length)];
		System.out.println(array1.length);
		// 배열의 값 = String으로 문자끼리 붙여진 것(not 계산)
		// 1개를 선택해서, 나머지 붙이고 그 다음거 선택해서 이어서 붙이고, ... = 붙인 거 저장할 공간 필요
		for(int j = 0; j<arr.length; j++)
		{
			array1[j] = arr[j]+arr[j+1]; 
		}
	}

	public String BiggestNum(int[] numbers) 
	{
       // 1. 숫자 조합하는 method -> 2. 숫자 정렬(비교)
       // 숫자가 아니라 문자로 출력해야함 - 형변환 필요
       // 배열에서 각 요소를 합이 아니라 이어서 붙여야 함 = 숫자로 들어와도 문자로 처리해야함
	   String answer = "";
	   return answer;
	}
*/		

		//큰수 구하기 답지 1
	    public String solution(int[] numbers) 
	    {
	        String[] arr = new String[numbers.length];
	        for (int i = 0; i < arr.length; i++) 
	        {
	            arr[i] = String.valueOf(numbers[i]);
	        }

	        Arrays.sort(arr, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));	        
	        if (arr[0].equals("0")) 
	        {
	           return "0";
	        }

	        StringBuilder answer = new StringBuilder();
	        for (int i = 0; i < arr.length; i++) 
	        {
	            answer.append(arr[i]);
	        }
	        return answer.toString();
	    }
	    
	    
		//큰수 구하기 답지 2
	    public String solution1(int[] numbers) 
	    {
	        List<String> result = Arrays.stream(numbers).mapToObj(n -> String.valueOf(n)).collect(Collectors.toList());
	        Collections.sort(result, (s1, s2) -> (s2+s1).compareTo(s1+s2));

	         if(result.get(0).equals("0")) 
	         {
	             return "0";
	         }

	         return result.stream().collect(Collectors.joining());
	     }


	  //큰수 구하기 답지 3
	    public String solution2(int[] numbers) 
	    {
	        String[] nums = new String[numbers.length];

	        for (int i=0; i<nums.length; i++) 
	            nums[i] = numbers[i] + "";

	        Arrays.sort(nums, new Comparator<String>() 
	        {
	            public int compare(String o1, String o2) 
	            {
	                return (o2 + o1).compareTo(o1 + o2);
	            }
	        });

	        String ans = "";
	        for (int i=0; i<numbers.length; i++)
	            ans += nums[i];

	        return ans.charAt(0) == '0' ? "0" : ans;
	    }


/*
H-Index

문제 설명
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.
어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.
어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

제한사항
과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.
논문별 인용 횟수는 0회 이상 10,000회 이하입니다.

입출력 예 설명
이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 
그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.

citations : [3, 0, 6, 1, 5]
return : 3

*/
	    

/*
 내 답안 - 12.5 
 
	   public static int hIndex(int[] citations) 
	   {
		   // 전체 n편 중 h번 이상 인용된 것들, h번 이하 인용된 것들 -> h의 최댓값 = H-index
		   // 매개변수 int형 배열, H-index를 return
		   // A가 가진 B를 보고 이걸 기준으로 가장 큰 게 return
		   // 발표한 논문의 수는 5편 -> 배열 크기
		   System.out.println(citations.length);
		   // 3편의 논문은 3회 이상 인용, 나머지 2편의 논문은 3회 이하 인용 -> 배열의 요소의 크기
		   int[] hindex = new int[citations.length];
		   int[] nhindex = new int[citations.length];
		   int result1 = 0;
		   int result2 = 0;
		   for(int i = 0; i<citations.length; i++)
		   {
			   if(citations[i]>=3)
			   {
				   hindex[i] = citations[i];
				   result1 += 1;
			   }
			   
			   if(citations[i]<3)
			   {
				   nhindex[i] = citations[i];
				   result2 += 1;
			   }
		   }
		   // 과학자의 H-Index는 3 -> 배열의 요소의 크기 중 3이상인 것들의 수
	        int answer = 0;
	        answer = result1;


	        System.out.println("이 과학자가 발표한 논문의 수는 "
	        +citations.length+"이고, 그중 "+result1+"편의 논문은 3회 이상 인용되었습니다. 그리고 나머지 "
	        +result2+"편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 "+result1+"입니다.");
	        return answer;
	        //*여기서는 main에서 써야하니까 static 붙였지, 프로그래머스에서는 static 안 붙인다.
	    }
*/

	    /*
	    H-index는 보통 맨 뒤쪽에 있으므로 오름차순하여 찾는다면 더 빨리 찾을 수 있습니다.
		1. citations를 오름차순 정렬한다.
		2. 맨 앞의 논문 인용 수(citations)부터 반복문을 시작하여 논문의 개수(discussionCount)를 하나씩 줄여갑니다.
		3. 위 설명에서는 내림차순을 하여 설명했지만 여기서는 오름차순을 했기 때문에, 반대로 논문 인용 수가 논문의 개수보다 크거나 같아지면 그 수가 H-index가 됩니다.
	     */
	    public static int hIndexSolution(int[] citations) 
	    {
	        int answer = 0;
	        Arrays.sort(citations);
	 
	        for (int i = 0; i < citations.length; i++) {
	            int discussionCount = citations.length - i;
	 
	            if (citations[i] >= discussionCount) {
	                answer = discussionCount;
	                break;
	            }
	        }
	        return answer;
	    }










	public static void main(String[] args) 
	{
		
		//str_out();
		//real_to_int(69.32);
		//int arr[] = {4,2,6,1,7,6};
		//int n=2;
		//save_array(arr, n);
//		int arr[] = {1,5,2,6,3,7,4};
//		int i = 2, j = 5;
//		int a=1, b = 1;
//		int c = 1, d = 7;
//		cut(arr, i, j);
//		cut(arr, a, b);
//		cut(arr, c, d);
//		int[][] commands;
//		knum();
//		int arr[] = {3, 30, 34, 5, 9};
//		transfer(arr);
//		int citations[] = {3, 0, 6, 1, 5};
//		hIndex(citations);
		
	}

}
