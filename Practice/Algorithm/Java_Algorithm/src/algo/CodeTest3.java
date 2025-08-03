package algo;
import java.util.*;


public class CodeTest3 
{
/*
타겟 넘버
문제 설명
n개의 음이 아닌 정수들이 있습니다. 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

제한사항
주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
각 숫자는 1 이상 50 이하인 자연수입니다.
타겟 넘버는 1 이상 1000 이하인 자연수입니다.

입출력 예
numbers	target	return
[1, 1, 1, 1, 1]	3	5
[4, 1, 2, 1]	4	2

입출력 예 설명
입출력 예 #1
문제 예시와 같습니다.

입출력 예 #2
+4+1-2+1 = 4
+4-1+2-1 = 4
총 2가지 방법이 있으므로, 2를 return 합니다.

*/
	//타겟 넘버 답 1
    int answer = 0;

    public int target_solution(int[] numbers, int target) 
    {
        dfs(numbers, 0, target, 0);

        return answer;
    }

    // 깊이 우선 탐색
    public void dfs(int[] numbers, int depth, int target, int sum)
    {
        if(depth == numbers.length)
        { // 마지막 노드 까지 탐색한 경우
            if(target == sum) answer++;
        }
        
        else 
        {
            dfs(numbers, depth + 1, target, sum + numbers[depth]); // 해당 노드의 값을 더하고 다음 깊이 탐색
            dfs(numbers, depth + 1, target, sum - numbers[depth]); // 해당 노드의 값을 빼고 다음 깊이 탐색
        }
    }
    

    //타겟 넘버 답2
    public int target_solution1(int[] numbers, int target) 
    {
        int answer = 0;
        answer = dfs1(numbers, 0, 0, target);
        return answer;
    }
    
    int dfs1(int[] numbers, int n, int sum, int target) 
    {
        if(n == numbers.length) 
        {
            if(sum == target) 
            {
                return 1;
            }
            return 0;
        }
        
        return dfs1(numbers, n + 1, sum + numbers[n], target) + dfs1(numbers, n + 1, sum - numbers[n], target);
    }	


/*
네트워크
문제 설명
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 
예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 
컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 
정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.
컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 
네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

제한사항
컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
computer[i][i]는 항상 1입니다.


입출력 예
n	computers							return
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1


입출력 예 설명
예제 #1
아래와 같이 2개의 네트워크가 있습니다.


예제 #2
아래와 같이 1개의 네트워크가 있습니다.

*/

    // 네트워크 답안 1
    public int network_solution(int n, int[][] computers) 
    {
        int answer = 0;
        boolean[] visited = new boolean[computers.length];
        
        // Node visit information initialization
        for(int i = 0; i < computers.length; i++)
        {
            visited[i] = false;
        }
        
        for(int i = 0; i < computers.length; i++)
        {
            if(visited[i] == false)
            {
                answer++;
                dfs(i, visited, computers);
            }            
        }
        
        return answer;
    }
    
    public void dfs(int node, boolean[] visited, int[][] computers)
    {
        visited[node] = true;
        
        for(int i = 0; i < computers.length; i++)
        {
            if(visited[i] == false && computers[node][i] == 1)
            {
                dfs(i, visited, computers);
            }
        }
    }


/*
게임 맵 최단거리

문제 설명
ROR 게임은 두 팀으로 나누어서 진행하며, 상대 팀 진영을 먼저 파괴하면 이기는 게임입니다. 따라서, 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.
지금부터 당신은 한 팀의 팀원이 되어 게임을 진행하려고 합니다. 다음은 5 x 5 크기의 맵에, 당신의 캐릭터가 (행: 1, 열: 1) 위치에 있고, 상대 팀 진영은 (행: 5, 열: 5) 위치에 있는 경우의 예시입니다.

위 그림에서 검은색 부분은 벽으로 막혀있어 갈 수 없는 길이며, 흰색 부분은 갈 수 있는 길입니다. 캐릭터가 움직일 때는 동, 서, 남, 북 방향으로 한 칸씩 이동하며, 게임 맵을 벗어난 길은 갈 수 없습니다.
아래 예시는 캐릭터가 상대 팀 진영으로 가는 두 가지 방법을 나타내고 있습니다.

첫 번째 방법은 11개의 칸을 지나서 상대 팀 진영에 도착했습니다.
두 번째 방법은 15개의 칸을 지나서 상대팀 진영에 도착했습니다.


위 예시에서는 첫 번째 방법보다 더 빠르게 상대팀 진영에 도착하는 방법은 없으므로, 이 방법이 상대 팀 진영으로 가는 가장 빠른 방법입니다.
만약, 상대 팀이 자신의 팀 진영 주위에 벽을 세워두었다면 상대 팀 진영에 도착하지 못할 수도 있습니다. 예를 들어, 다음과 같은 경우에 당신의 캐릭터는 상대 팀 진영에 도착할 수 없습니다.
게임 맵의 상태 maps가 매개변수로 주어질 때, 캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return 하도록 solution 함수를 완성해주세요. 단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return 해주세요.

제한사항
maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로, n과 m은 각각 1 이상 100 이하의 자연수입니다.
n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 모두 1인 경우는 입력으로 주어지지 않습니다.
maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리, 1은 벽이 없는 자리를 나타냅니다.
처음에 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 위치에 있으며, 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치에 있습니다.
입출력 예
maps															answer
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]	11
[[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	-1

입출력 예 설명

입출력 예 #1
주어진 데이터는 다음과 같습니다.

캐릭터가 적 팀의 진영까지 이동하는 가장 빠른 길은 다음 그림과 같습니다.

따라서 총 11칸을 캐릭터가 지나갔으므로 11을 return 하면 됩니다.

입출력 예 #2
문제의 예시와 같으며, 상대 팀 진영에 도달할 방법이 없습니다. 따라서 -1을 return 합니다.
*/


// 게임 맵 최단거리 답지 1
    static final int[] rowArr = new int[]{1, -1, 0, 0},
            colArr = new int[]{0, 0, 1, -1};

    static class Node 
    {
    	final int row;
    	final int col;
    	final int move;

    	public Node(int row, int col, int move)
    	{
    		this.row = row;
    		this.col = col;
    		this.move = move;
    	}
    }

    public int solution(int[][] maps) 
    {
    	int rowLength = maps.length, colLength = maps[0].length;
    	boolean[][] visited = new boolean[rowLength][colLength];

    	for(int i = 0; i < maps.length; i++) 
    	{
    		for(int j = 0; j < maps[i].length; j++) 
    		{
    			if(maps[i][j] == 0) visited[i][j] = true;
    		}
    	}


    	Queue<Node> queue = new LinkedList<>();
    	visited[0][0] = true;
    	queue.offer(new Node(0, 0, 1));
    	int min = Integer.MAX_VALUE;
    	while(!queue.isEmpty()) 
    	{

    		Node node = queue.poll();

    		for(int i = 0; i < 4; i++) 
    		{
    			int row = node.row + rowArr[i], col = node.col + colArr[i];
    			if(rowLength <= row || row < 0 || colLength <= col || col < 0) continue;
    			if(visited[row][col]) continue;
    
    			visited[row][col] = true;
    			queue.offer(new Node(row, col, node.move+1));
    			if(row == rowLength - 1 && col == colLength - 1) min = Math.min(min, node.move + 1);
    		}

    	}

    	return  min == Integer.MAX_VALUE ? -1 : min;
    }


/*
단어 변환

문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.
1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 "hit", target가 "cog", words가 ["hot","dot","dog","lot","log","cog"]라면 "hit" -> "hot" -> "dot" -> "dog" -> "cog"와 같이 4단계를 거쳐 변환할 수 있습니다.
두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
각 단어는 알파벳 소문자로만 이루어져 있습니다.
각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
begin과 target은 같지 않습니다.
변환할 수 없는 경우에는 0를 return 합니다.

입출력 예
begin	target	words	return
"hit"	"cog"	["hot", "dot", "dog", "lot", "log", "cog"]	4
"hit"	"cog"	["hot", "dot", "dog", "lot", "log"]	0

입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
target인 "cog"는 words 안에 없기 때문에 변환할 수 없습니다.
*/


    //단어 변환 답지1
    static boolean[] visited;
    static int answer1 = 0;
    
    public int solution(String begin, String target, String[] words) 
    {
        visited = new boolean[words.length];

        dfs(begin, target, words, 0);
        return answer1;
    }
    
    public static void dfs(String begin, String target, String[] words, int cnt) 
    {
        if (begin.equals(target)) 
        {
            answer1 = cnt;
            return;
        }

        for (int i = 0; i < words.length; i++) 
        {
            if (visited[i])
            {
                continue;
            }

            int k = 0;    // 같은 스펠링 몇개인지 세기
            for (int j = 0; j < begin.length(); j++) 
            {
                if (begin.charAt(j) == words[i].charAt(j)) 
                {
                    k++;
                }
            }

            if (k == begin.length() - 1) 
            {  // 한글자 빼고 모두 같은 경우
                visited[i] = true;
                dfs(words[i], target, words, cnt + 1);
                visited[i] = false;
            }
        }
    }


/*
아이템 줍기

문제 설명
다음과 같은 다각형 모양 지형에서 캐릭터가 아이템을 줍기 위해 이동하려 합니다.
지형은 각 변이 x축, y축과 평행한 직사각형이 겹쳐진 형태로 표현하며, 캐릭터는 이 다각형의 둘레(굵은 선)를 따라서 이동합니다.


만약 직사각형을 겹친 후 다음과 같이 중앙에 빈 공간이 생기는 경우, 다각형의 가장 바깥쪽 테두리가 캐릭터의 이동 경로가 됩니다.
단, 서로 다른 두 직사각형의 x축 좌표 또는 y축 좌표가 같은 경우는 없습니다.
즉, 위 그림처럼 서로 다른 두 직사각형이 꼭짓점에서 만나거나, 변이 겹치는 경우 등은 없습니다.


다음 그림과 같이 지형이 2개 이상으로 분리된 경우도 없습니다.
한 직사각형이 다른 직사각형 안에 완전히 포함되는 경우 또한 없습니다.
지형을 나타내는 직사각형이 담긴 2차원 배열 rectangle, 초기 캐릭터의 위치 characterX, characterY, 아이템의 위치 itemX, itemY가 solution 함수의 매개변수로 주어질 때, 캐릭터가 아이템을 줍기 위해 이동해야 하는 가장 짧은 거리를 return 하도록 solution 함수를 완성해주세요.


제한사항
rectangle의 세로(행) 길이는 1 이상 4 이하입니다.
rectangle의 원소는 각 직사각형의 [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y] 좌표 형태입니다.
직사각형을 나타내는 모든 좌표값은 1 이상 50 이하인 자연수입니다.
서로 다른 두 직사각형의 x축 좌표, 혹은 y축 좌표가 같은 경우는 없습니다.
문제에 주어진 조건에 맞는 직사각형만 입력으로 주어집니다.
charcterX, charcterY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
itemX, itemY는 1 이상 50 이하인 자연수입니다.
지형을 나타내는 다각형 테두리 위의 한 점이 주어집니다.
캐릭터와 아이템의 처음 위치가 같은 경우는 없습니다.
전체 배점의 50%는 직사각형이 1개인 경우입니다.
전체 배점의 25%는 직사각형이 2개인 경우입니다.
전체 배점의 25%는 직사각형이 3개 또는 4개인 경우입니다.


입출력 예
rectangle	characterX	characterY	itemX	itemY	result
[[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]]	1	3	7	8	17
[[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]]	9	7	6	1	11
[[1,1,5,7]]	1	1	4	7	9
[[2,1,7,5],[6,4,10,10]]	3	1	7	10	15
[[2,2,5,5],[1,3,6,4],[3,1,4,6]]	1	4	6	3	10


입출력 예 설명
입출력 예 #1
캐릭터 위치는 (1, 3)이며, 아이템 위치는 (7, 8)입니다. 위 그림과 같이 굵은 선을 따라 이동하는 경로가 가장 짧습니다.

입출력 예 #2
캐릭터 위치는 (9, 7)이며, 아이템 위치는 (6, 1)입니다. 위 그림과 같이 굵은 선을 따라 이동하는 경로가 가장 짧습니다.

입출력 예 #3
캐릭터 위치는 (1, 1)이며, 아이템 위치는 (4, 7)입니다. 위 그림과 같이 굵은 선을 따라 이동하는 경로가 가장 짧습니다.

입출력 예 #4, #5

설명 생략
*/


// 아이템 줍기 해결 1
    static String[][] shape;
    static int startX, startY, targetX, targetY, answer2, total;
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) 
    {
        shape = new String[52][52];
        startX = characterX; startY = characterY; targetX = itemX; targetY = itemY; 
        answer = total = 0;

        for(int i=0; i<52; i++) Arrays.fill(shape[i],""); // ""로 초기화

        for(int[] xy : rectangle)
        {
            int leftX = xy[0], rightX = xy[2], leftY = xy[1], rightY = xy[3];

            // 꼭지점 (왼쪽아래(LDX), 오른쪽아래(RDX), 왼쪽위(LUX), 오른쪽위(RUX))
            shape[leftX][leftY] = "LDX"; shape[rightX][leftY] = "RDX"; shape[leftX][rightY] = "LUX"; shape[rightX][rightY] = "RUX";

            for(int x=leftX+1; x<rightX; x++)
            {// 상(U), 하(D)
                shape[x][rightY] += "U"; shape[x][leftY] += "D";
            }

            for(int y=leftY+1; y<rightY; y++)
            {// 좌(L), 우(R)
                shape[leftX][y] += "L"; shape[rightX][y] += "R";
            }
        }

        followLine(characterX, characterY);

        return Math.min(answer2, total-answer);
    }

    public void followLine(int x, int y)
    {
        String location = shape[x][y];
        if(location.equals("RU") || location.equals("UR") || location.equals("LUX") || location.equals("U"))  x++;
        if(location.equals("LD") || location.equals("DL") || location.equals("RDX") || location.equals("D"))  x--;
        if(location.equals("LU") || location.equals("UL") || location.equals("LDX") || location.equals("L"))  y++;
        if(location.equals("RD") || location.equals("DR") || location.equals("RUX") || location.equals("R"))  y--;
        total++;
        if(x == targetX && y == targetY)    answer2 = total;
        if(x == startX && y == startY)      return;
        followLine(x, y);
    }


    
	public static void main(String[] args) 
	{

	}

}
