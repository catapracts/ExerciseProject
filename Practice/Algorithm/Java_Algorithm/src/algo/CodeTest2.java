package algo;

import java.util.*;
import java.util.stream.Stream;
import java.io.*;


public class CodeTest2 
{
/*
최소 직사각형
문제 설명
명함 지갑을 만드는 회사에서 지갑의 크기를 정하려고 합니다. 다양한 모양과 크기의 명함들을 모두 수납할 수 있으면서, 작아서 들고 다니기 편한 지갑을 만들어야 합니다. 
이러한 요건을 만족하는 지갑을 만들기 위해 디자인팀은 모든 명함의 가로 길이와 세로 길이를 조사했습니다.
아래 표는 4가지 명함의 가로 길이와 세로 길이를 나타냅니다.
명함 번호	가로 길이	세로 길이
1		60		50
2		30		70
3		60		30
4		80		40
가장 긴 가로 길이와 세로 길이가 각각 80, 70이기 때문에 80(가로) x 70(세로) 크기의 지갑을 만들면 모든 명함들을 수납할 수 있습니다. 
하지만 2번 명함을 가로로 눕혀 수납한다면 80(가로) x 50(세로) 크기의 지갑으로 모든 명함들을 수납할 수 있습니다. 이때의 지갑 크기는 4000(=80 x 50)입니다.
모든 명함의 가로 길이와 세로 길이를 나타내는 2차원 배열 sizes가 매개변수로 주어집니다. 모든 명함을 수납할 수 있는 가장 작은 지갑을 만들 때, 지갑의 크기를 return 하도록 solution 함수를 완성해주세요.

제한사항
sizes의 길이는 1 이상 10,000 이하입니다.
sizes의 원소는 [w, h] 형식입니다.
w는 명함의 가로 길이를 나타냅니다.
h는 명함의 세로 길이를 나타냅니다.
w와 h는 1 이상 1,000 이하인 자연수입니다.


입출력 예
sizes											result
[[60, 50], [30, 70], [60, 30], [80, 40]]		4000
[[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]	120
[[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]	133


입출력 예 설명
입출력 예 #1
문제 예시와 같습니다.

입출력 예 #2
명함들을 적절히 회전시켜 겹쳤을 때, 3번째 명함(가로: 8, 세로: 15)이 다른 모든 명함보다 크기가 큽니다. 따라서 지갑의 크기는 3번째 명함의 크기와 같으며, 120(=8 x 15)을 return 합니다.

입출력 예 #3
명함들을 적절히 회전시켜 겹쳤을 때, 모든 명함을 포함하는 가장 작은 지갑의 크기는 133(=19 x 7)입니다.
*/
	// 최소 직사각형 답지 1
    public int rectangular_solution(int[][] sizes) 
    {
    	// 80*40 = 3200, 60*30 = 1800, 60*50 = 3000, 30*70 = 2100
    	// 가로*세로 크기 + 가로랑 세로 서로 교환해도 포용되는 크기
    	// 가로*세로 = 명함의 크기 = 수납 가능한 기준
    	// 모든 명함을 수납할 수 있는 가장 작은 지갑 만드는게 목적 = 최소공배수 찾는 거 같은데...?
        
    	int max_row = 0; //가로의 최대 길이
        int max_col = 0; // 세로의 최대 길이
        int answer = 0;
        
        for(int i=0;i<sizes.length;i++){ //긴 부분을 가로로 재배치
            if(sizes[i][0]<sizes[i][1]){
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
            if(max_row<sizes[i][0]) max_row = sizes[i][0]; // 최대값
            if(max_col<sizes[i][1]) max_col = sizes[i][1]; // 최대값
        }
        
        answer = max_col*max_row;
        
        return answer; //결과
    }
    
    
    // 최소 직사각형 답지 2
    public int rectangular_solution1(int[][] sizes) 
    {
        int length = 0, height = 0;
        for (int[] card : sizes) 
        {
            length = Math.max(length, Math.max(card[0], card[1]));
            height = Math.max(height, Math.min(card[0], card[1]));
        }
        
        int answer = length * height;
        return answer;
    }
	

/*
모의고사
문제 설명
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
입출력 예
answers	return
[1,2,3,4,5]	[1]
[1,3,2,4,2]	[1,2,3]
입출력 예 설명
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

모든 사람이 2문제씩을 맞췄습니다.
*/
/*
내가 쓴 답
    // 1번 : 12345반복, 2번 : 22제외 21,23,24,25반복, 3번 : 같은수2번 반복 + 순서=31245
    // 문제에 대한 답(answers) = random - 가장 높은 점수 받은 사람 출력 & 오름차순 정렬
    // 문제에 대한 답(answers)이랑 답변 일치하면 정답처리(저장), 불일치하면 오답처리(저장X), 맞은 개수 : 저장한 배열의 크기
    // 1,2,3,4,5 순서 반복 : 1,2,3,4,5 = 1 cycle / 21,23,24,25반복 : 21,23,24,25 = 1 cycle / 33,11,22,44,55반복 : 33,11,22,44,55 = 1 cycle
    // 정렬 - swap, insertion
    public static int[] exam_solution(int[] answers) 
    {
    	int[] answer1 = {1,2,3,4,5};
    	int answer11 = 0;
    	int[] answer2 = {2,1,2,3,2,4,2,5};
    	int answer22 = 0;
    	int[] answer3 = {3,3,1,1,2,2,4,4,5,5};
    	int answer33 = 0;
    	
    	System.out.println(answer11);
    	System.out.println(answer22);
    	System.out.println(answer33);
    	
    	for(int i = 0; i<answers.length; i++)
    	{
    		if(answers[i] == answer1[i]) answer11++;
    		if(answers[i] == answer2[i]) answer22++;
    		if(answers[i] == answer3[i]) answer33++;
    	}
    	
    	System.out.println(answer11);
    	System.out.println(answer22);
    	System.out.println(answer33);

        int[] answer = {};
        
        return answer;
    }
*/
    
    // 모의고사 답 -1
    public int[] exam_solution(int[] answers) 
    {
        int[] first = {1,2,3,4,5}; // 5개씩 반복
        int[] second = {2,1,2,3,2,4,2,5}; // 8개씩 반복
        int[] third = {3,3,1,1,2,2,4,4,5,5}; // 10개씩 반복
        int[] score = {0,0,0}; // 각 수포자들의 점수
        
        // 수포자들의 점수 계산
        for(int i=0; i<answers.length; i++) {
            if(answers[i] == first[i%5]) score[0]++;
            if(answers[i] == second[i%8]) score[1]++;
            if(answers[i] == third[i%10]) score[2]++;
        }
        
        // 최대 점수 구하기
        int max = Math.max(score[0], Math.max(score[1], score[2]));
        
        // 최대 점수를 가진 수포자 리스트 생성
        List<Integer> answ = new ArrayList<Integer>();
        for(int i=0; i<score.length; i++) if(max == score[i]) answ.add(i+1);
        
        int[] answer = new int[answ.size()];
        for(int i=0; i<answ.size(); i++){
            answer[i] = answ.get(i);
        }

        return answer;
    }
    
    
    // 모의고사 답 -2
    public static int[] exam_solution1(int[] answers) 
    {
        int[][] patterns = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };

        int[] hit = new int[3];
        for(int i = 0; i < hit.length; i++) 
        {
            for(int j = 0; j < answers.length; j++) 
            {
                if(patterns[i][j % patterns[i].length] == answers[j]) hit[i]++;
            }
        }

        int max = Math.max(hit[0], Math.max(hit[1], hit[2]));
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < hit.length; i++)
            if(max == hit[i]) list.add(i + 1);

        int[] answer = new int[list.size()];
        int cnt = 0;
        for(int num : list)
            answer[cnt++] = num;
        return answer;
    }
   
   
/*   
문제 설명
사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다. 
사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.
단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 하도록 solution 함수를 완성해주세요.

제한사항
word의 길이는 1 이상 5 이하입니다.
word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있습니다.

입출력 예
word	result
"AAAAE"	6
"AAAE"	10
"I"	1563
"EIO"	1189

입출력 예 설명
입출력 예 #1
사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA", "AAA", "AAAA", "AAAAA", "AAAAE", ... 와 같습니다. "AAAAE"는 사전에서 6번째 단어입니다.

입출력 예 #2
"AAAE"는 "A", "AA", "AAA", "AAAA", "AAAAA", "AAAAE", "AAAAI", "AAAAO", "AAAAU"의 다음인 10번째 단어입니다.

입출력 예 #3
"I"는 1563번째 단어입니다.

입출력 예 #4
"EIO"는 1189번째 단어입니다.

*/ 
    public int vowels_solution(String word) 
    {
    	// A,E,I,O,U 순서대로 나오는 것 같다.
    	// 각 자리마다 5개 = 경우의 수로 보면 (5^5 = 3125)의 개수가 나온다.
    	// word = 단어 1개, word가 몇 번째 단어인지 return
        int answer = 0;
        return answer;
    }

    //모음사전 답 - 1
        static List<String> list;
        static String [] words = {"A", "E", "I", "O", "U"};
        public int vowels_solution1(String word) 
        {
            int answer = 0;
            list = new ArrayList<>();
            dfs("", 0);
            int size = list.size();
            
            for (int i = 0; i < size; i++) 
            {
                if (list.get(i).equals(word)) 
                {
                    answer = i;
                    break;
                }
            }
            
            return answer;
        }

        static void dfs(String str, int len) 
        {
            list.add(str);
            if (len == 5) return;
            for (int i = 0; i < 5; i++) 
            {
                dfs(str + words[i], len + 1);
            }
        }
    

    //모음사전 답 -2    
    public int solution(String word) 
    {
    	int answer = 0, per = 3905;
    	for(String s : word.split("")) answer += "AEIOU".indexOf(s) * (per /= 5) + 1;
        return answer;
    }

   
/*   
전력망 둘로 나누기
문제 설명
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다. 당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다. 
이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.
송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다. 전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 
두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.


제한사항
n은 2 이상 100 이하인 자연수입니다.
wires는 길이가 n-1인 정수형 2차원 배열입니다.
wires의 각 원소는 [v1, v2] 2개의 자연수로 이루어져 있으며, 이는 전력망의 v1번 송전탑과 v2번 송전탑이 전선으로 연결되어 있다는 것을 의미합니다.
1 ≤ v1 < v2 ≤ n 입니다.
전력망 네트워크가 하나의 트리 형태가 아닌 경우는 입력으로 주어지지 않습니다.

입출력 예
n	wires												result
9	[[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]	3
4	[[1,2],[2,3],[3,4]]									0
7	[[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]				1


입출력 예 설명
입출력 예 #1
다음 그림은 주어진 입력을 해결하는 방법 중 하나를 나타낸 것입니다.
4번과 7번을 연결하는 전선을 끊으면 두 전력망은 각 6개와 3개의 송전탑을 가지며, 이보다 더 비슷한 개수로 전력망을 나눌 수 없습니다.
또 다른 방법으로는 3번과 4번을 연결하는 전선을 끊어도 최선의 정답을 도출할 수 있습니다.

입출력 예 #2
다음 그림은 주어진 입력을 해결하는 방법을 나타낸 것입니다.
2번과 3번을 연결하는 전선을 끊으면 두 전력망이 모두 2개의 송전탑을 가지게 되며, 이 방법이 최선입니다.

입출력 예 #3
다음 그림은 주어진 입력을 해결하는 방법을 나타낸 것입니다.
3번과 7번을 연결하는 전선을 끊으면 두 전력망이 각각 4개와 3개의 송전탑을 가지게 되며, 이 방법이 최선입니다.
*/ 

    // 전력망 둘로 나누기 예제 - 1
    static ArrayList<Integer>[] graph;
    static int min;
    
    static int dfs(int v, boolean[] visited) 
    {
        visited[v] = true;
        int cnt = 1;
 
        for (int next : graph[v]) {
            if (!visited[next]) {
                cnt += dfs(next, visited);
            }
        }
 
        return cnt;
    }
    
    public int two_divide_solution1(int n, int[][] wires) 
    {
        graph = new ArrayList[n + 1];
        min = Integer.MAX_VALUE;
 
        // 그래프 ArrayList 초기화. 노드 개수만큼 ArrayList 생성
        for (int i = 1; i <= n; i++) 
        {
            graph[i] = new ArrayList<>();
        }
 
        // 양방향 간선 구조이므로 두 번 add를 해준다
        for (int i = 0; i < wires.length; i++) 
        {
            int v1 = wires[i][0];
            int v2 = wires[i][1];
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
 
        for (int i = 0; i < wires.length; i++) 
        {
            int v1 = wires[i][0];
            int v2 = wires[i][1];
 
            boolean[] visited = new boolean[n + 1];
 
            // 해당 간선을 그래프에서 제거
            graph[v1].remove(Integer.valueOf(v2));
            graph[v2].remove(Integer.valueOf(v1));
 
            int cnt = dfs(1, visited); // 임의의 시작점에서 dfs 탐색
 
            int diff = Math.abs(cnt - (n - cnt));
            min = Math.min(min, diff);
 
            // 그래프에 다시 간선 추가
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
 
        return min;
    }
    
    
  //전력망 둘로 나누기 예제 - 2
    int N, min1;
    int[][] map;
    int[] vst;
    
    int dfs(int n)
    {
        vst[n] = 1;
        int child = 1;
        for(int i = 1; i <= N; i++) 
        {
            if(vst[i] == 0 && map[n][i] == 1) 
            {
                vst[i] = 1;
                child += dfs(i);
            }
        }
        
        min1 = Math.min(min1, Math.abs(child - (N - child)));
        return child;
    }

    public int two_divide_solution2(int n, int[][] wires) 
    {
        N = n;
        min = n;
        map = new int[n+1][n+1];
        vst = new int[n+1];
        for(int[] wire : wires) 
        {
            int a = wire[0], b = wire[1];
            map[a][b] = map[b][a] = 1;
        }
        
        dfs(1);
        return min;
    }


/*
카펫
문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.
Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.
Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.


제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.


입출력 예
brown	yellow	return
10		2		[4, 3]
8		1		[3, 3]
24		24		[8, 6]
*/
    // 카펫 답 - 1
    public int[] carpet_solution(int brown, int yellow) 
    {
        int[] answer = new int[2];
        int sum = brown + yellow;
        
        for (int i = 3; i < sum; i++) 
        {
            int j = sum / i;
            
            if (sum % i == 0 && j >= 3) 
            {
                int col = Math.max(i, j);
                int row = Math.min(i, j);
                int center = (col - 2) * (row - 2);
                
                if (center == yellow) 
                {
                    answer[0] = col;
                    answer[1] = row;
                    return answer;
                }
            }
        }
        return answer;
    }
    
    
    // 카펫 답 - 2
    public int[] carpet_solution1(int brown, int red) 
    {
        int a = (brown+4)/2;
        int b = red+2*a-4;
        int[] answer = {(int)(a+Math.sqrt(a*a-4*b))/2,(int)(a-Math.sqrt(a*a-4*b))/2};
        return answer;
    }    
 


/*
피로도
문제 설명
XX게임에는 피로도 시스템(0 이상의 정수로 표현합니다)이 있으며, 일정 피로도를 사용해서 던전을 탐험할 수 있습니다. 
이때, 각 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있습니다. 
"최소 필요 피로도"는 해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도를 나타내며, "소모 피로도"는 던전을 탐험한 후 소모되는 피로도를 나타냅니다. 
예를 들어 "최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상 이어야 하며, 던전을 탐험한 후에는 피로도 20이 소모됩니다.
이 게임에는 하루에 한 번씩 탐험할 수 있는 던전이 여러개 있는데, 한 유저가 오늘 이 던전들을 최대한 많이 탐험하려 합니다. 
유저의 현재 피로도 k와 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열 dungeons 가 매개변수로 주어질 때, 유
저가 탐험할수 있는 최대 던전 수를 return 하도록 solution 함수를 완성해주세요.


제한사항
k는 1 이상 5,000 이하인 자연수입니다.
dungeons의 세로(행) 길이(즉, 던전의 개수)는 1 이상 8 이하입니다.
dungeons의 가로(열) 길이는 2 입니다.
dungeons의 각 행은 각 던전의 ["최소 필요 피로도", "소모 피로도"] 입니다.
"최소 필요 피로도"는 항상 "소모 피로도"보다 크거나 같습니다.
"최소 필요 피로도"와 "소모 피로도"는 1 이상 1,000 이하인 자연수입니다.
서로 다른 던전의 ["최소 필요 피로도", "소모 피로도"]가 서로 같을 수 있습니다.


입출력 예
k	dungeons				result
80	[[80,20],[50,40],[30,10]]	3


입출력 예 설명
현재 피로도는 80입니다.

만약, 첫 번째 → 두 번째 → 세 번째 던전 순서로 탐험한다면

현재 피로도는 80이며, 첫 번째 던전을 돌기위해 필요한 "최소 필요 피로도" 또한 80이므로, 첫 번째 던전을 탐험할 수 있습니다. 첫 번째 던전의 "소모 피로도"는 20이므로, 던전을 탐험한 후 남은 피로도는 60입니다.
남은 피로도는 60이며, 두 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 50이므로, 두 번째 던전을 탐험할 수 있습니다. 두 번째 던전의 "소모 피로도"는 40이므로, 던전을 탐험한 후 남은 피로도는 20입니다.
남은 피로도는 20이며, 세 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 30입니다. 따라서 세 번째 던전은 탐험할 수 없습니다.
만약, 첫 번째 → 세 번째 → 두 번째 던전 순서로 탐험한다면

현재 피로도는 80이며, 첫 번째 던전을 돌기위해 필요한 "최소 필요 피로도" 또한 80이므로, 첫 번째 던전을 탐험할 수 있습니다. 첫 번째 던전의 "소모 피로도"는 20이므로, 던전을 탐험한 후 남은 피로도는 60입니다.
남은 피로도는 60이며, 세 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 30이므로, 세 번째 던전을 탐험할 수 있습니다. 세 번째 던전의 "소모 피로도"는 10이므로, 던전을 탐험한 후 남은 피로도는 50입니다.
남은 피로도는 50이며, 두 번째 던전을 돌기위해 필요한 "최소 필요 피로도"는 50이므로, 두 번째 던전을 탐험할 수 있습니다. 두 번째 던전의 "소모 피로도"는 40이므로, 던전을 탐험한 후 남은 피로도는 10입니다.
따라서 이 경우 세 던전을 모두 탐험할 수 있으며, 유저가 탐험할 수 있는 최대 던전 수는 3입니다.
*/
    	// 피로도 예제 1
        static boolean[] visited;  
        static int count = 0;  
      
        public int tired_solution(int k, int[][] dungeons) 
        {  
            visited = new boolean[dungeons.length];  
            dfs(0, k, dungeons);  
            return count;  
        }  
          
        private void dfs(int depth, int fatigue, int[][] dungeons)
        {  
            for (int i = 0; i < dungeons.length; i++)
            {  
                if (visited[i] || dungeons[i][0] > fatigue) 
                {  
                    continue;  
                }
                
                visited[i] = true;  
                dfs(depth + 1, fatigue - dungeons[i][1], dungeons);  
                visited[i] = false;  
            }
            count = Math.max(count, depth);  
        }
        
        
        //피로도 예제 2
        int dfs(int k, int[][] dungeons) 
        {
            int cnt = 0;
            for(int[] d : dungeons) 
            {
                int a = d[0], b = d[1];
                if(a <= k) 
                {
                    d[0] = 9999;
                    cnt = Math.max(1 + dfs(k - b, dungeons), cnt);
                    d[0] = a;
                }
            }
            return cnt;
        }
        
        public int tired_solution1(int k, int[][] dungeons) 
        {
            int answer = -1;
            return dfs(k, dungeons);
        }



        //피로도 예제 - 3
        public int ans = 0;
        public int tired_solution2(int k, int[][] dungeons) 
        {
            dfs(k,dungeons,0);
            return ans;
        }
        
        public void dfs(int k,int[][]d,int a)
        {
            ans = Math.max(a,ans);
            for(int i =0;i<d.length;i++) if(k>=d[i][0]) dfs(k - d[i][1], Stream.concat(Arrays.stream(Arrays.copyOfRange(d, 0, i)), 
            		Arrays.stream(Arrays.copyOfRange(d, i + 1, d.length))).toArray(int[][]::new), a + 1);
        }


/*
소수 찾기

문제 설명
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.


제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

입출력 예
numbers	return
"17"	3
"011"	2

입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

11과 011은 같은 숫자로 취급합니다.
*/
        //소수 판단 예제 1
        static ArrayList<Integer> arr = new ArrayList<>();
        static boolean[] check = new boolean[7];
        
    	//소수 판단
    	static boolean prime(int n) 
    	{
    		if(n<2) return false;
    		
    		for(int i=2; i*i<=n; i++) {
    			if(n % i == 0) return false;
    		}
    		
    		return true;
    	}
    	
    	//백트래킹
    	static void dfs(String str, String temp, int m) {
    		
                if(temp.length() == m)
                {
                    int num = Integer.parseInt(temp);
                    if(!arr.contains(num))
                    {
                        arr.add(num);
                    }
                }
            
                for(int i=0; i<str.length(); i++)
                {
                    if(!check[i])
                    {
                    	
                        check[i] = true;
                        temp += str.charAt(i);
                        dfs(str, temp, m);
                        check[i] = false;
                        temp = temp.substring(0, temp.length()-1);
                    }
                }
    		
    	}

        public int decimal_number_solution(String numbers) 
        {
            int answer = 0;
            for(int i=0; i<numbers.length(); i++){
                dfs(numbers,"",i+1);
            }
            
            for(int i=0; i<arr.size(); i++){
                if(prime(arr.get(i))) answer++;              
            }
            
            return answer;
        }
        
        
   //소수 판단 예제2
   public int decimal_number_solution1(String numbers) 
   {
      HashSet<Integer> set = new HashSet<>();
      permutation("", numbers, set);
      int count = 0;
      while(set.iterator().hasNext())
      {
        int a = set.iterator().next();
        set.remove(a);
        if(a==2) count++;
        if(a%2!=0 && isPrime(a))
        {
            count++;
        }
      }        
      return count;
   }

   public boolean isPrime(int n)
   {
     if(n==0 || n==1) return false;
     for(int i=3; i<=(int)Math.sqrt(n); i+=2)
     {
        if(n%i==0) return false;
     }
     return true;
   }

    public void permutation(String prefix, String str, HashSet<Integer> set) 
    {
       int n = str.length();
       //if (n == 0) System.out.println(prefix);
       if(!prefix.equals("")) set.add(Integer.valueOf(prefix));
       for (int i = 0; i < n; i++)
              permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n), set);
    }




	public static void main(String[] args) 
	{
//		int answers[]= new int[5];
//		for(int i = 0; i<5; i++)
//		{
//			answers[i] = (int)(Math.random()*5)+1;
//		}
//		System.out.println(Arrays.toString(answers));
//		exam_solution(answers);

	}

}
