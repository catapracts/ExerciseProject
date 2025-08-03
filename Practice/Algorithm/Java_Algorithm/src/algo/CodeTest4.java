package algo;
import java.util.*;

public class CodeTest4 
{
/*
여행 경로

문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 "ICN" 공항에서 출발합니다.
항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
모든 공항은 알파벳 대문자 3글자로 이루어집니다.
주어진 공항 수는 3개 이상 10,000개 이하입니다.
tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
주어진 항공권은 모두 사용해야 합니다.
만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.


입출력 예
tickets	return
[["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]	["ICN", "JFK", "HND", "IAD"]
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]


입출력 예 설명
예제 #1
["ICN", "JFK", "HND", "IAD"] 순으로 방문할 수 있습니다.

예제 #2
["ICN", "SFO", "ATL", "ICN", "ATL", "SFO"] 순으로 방문할 수도 있지만 ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"] 가 알파벳 순으로 앞섭니다.
*/


	// 여행 경로 답 1
    boolean[] visited;
    ArrayList<String> allRoute; 
    
    public String[] travel_solution(String[][] tickets) 
    {
        String[] answer = {};
        int cnt = 0;
        visited = new boolean[tickets.length];
        allRoute = new ArrayList<>();
        
        dfs("ICN", "ICN", tickets, cnt);
        
        Collections.sort(allRoute);
        answer = allRoute.get(0).split(" ");
        
        return answer;
    }
    
    public void dfs(String start, String route, String[][] tickets, int cnt)
    {
        if(cnt == tickets.length)
        {
            allRoute.add(route);
            return;
        }
        
        for(int i=0; i<tickets.length; i++)
        {
            if(start.equals(tickets[i][0]) && !visited[i])
            {
                visited[i] = true;
                dfs(tickets[i][1], route+" "+tickets[i][1], tickets, cnt+1);
                visited[i] = false;
            }
        }
    }
	
	
/*	
퍼즐 조각 채우기

문제 설명
테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈 공간에 적절히 올려놓으려 합니다. 게임 보드와 테이블은 모두 각 칸이 1x1 크기인 정사각 격자 모양입니다. 이때, 다음 규칙에 따라 테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈칸에 채우면 됩니다.

조각은 한 번에 하나씩 채워 넣습니다.
조각을 회전시킬 수 있습니다.
조각을 뒤집을 수는 없습니다.
게임 보드에 새로 채워 넣은 퍼즐 조각과 인접한 칸이 비어있으면 안 됩니다.
다음은 퍼즐 조각을 채우는 예시입니다.


위 그림에서 왼쪽은 현재 게임 보드의 상태를, 오른쪽은 테이블 위에 놓인 퍼즐 조각들을 나타냅니다. 테이블 위에 놓인 퍼즐 조각들 또한 마찬가지로 [상,하,좌,우]로 인접해 붙어있는 경우는 없으며, 흰 칸은 퍼즐이 놓이지 않은 빈 공간을 나타냅니다. 모든 퍼즐 조각은 격자 칸에 딱 맞게 놓여있으며, 격자 칸을 벗어나거나, 걸쳐 있는 등 잘못 놓인 경우는 없습니다.
이때, 아래 그림과 같이 3,4,5번 조각을 격자 칸에 놓으면 규칙에 어긋나므로 불가능한 경우입니다.


3번 조각을 놓고 4번 조각을 놓기 전에 위쪽으로 인접한 칸에 빈칸이 생깁니다.
5번 조각의 양 옆으로 인접한 칸에 빈칸이 생깁니다.
다음은 규칙에 맞게 최대한 많은 조각을 게임 보드에 채워 넣은 모습입니다.



최대한 많은 조각을 채워 넣으면 총 14칸을 채울 수 있습니다.
현재 게임 보드의 상태 game_board, 테이블 위에 놓인 퍼즐 조각의 상태 table이 매개변수로 주어집니다. 규칙에 맞게 최대한 많은 퍼즐 조각을 채워 넣을 경우, 총 몇 칸을 채울 수 있는지 return 하도록 solution 함수를 완성해주세요.

제한사항
3 ≤ game_board의 행 길이 ≤ 50
game_board의 각 열 길이 = game_board의 행 길이
즉, 게임 보드는 정사각 격자 모양입니다.
game_board의 모든 원소는 0 또는 1입니다.
0은 빈칸, 1은 이미 채워진 칸을 나타냅니다.
퍼즐 조각이 놓일 빈칸은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
table의 행 길이 = game_board의 행 길이
table의 각 열 길이 = table의 행 길이
즉, 테이블은 game_board와 같은 크기의 정사각 격자 모양입니다.
table의 모든 원소는 0 또는 1입니다.
0은 빈칸, 1은 조각이 놓인 칸을 나타냅니다.
퍼즐 조각은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
game_board에는 반드시 하나 이상의 빈칸이 있습니다.
table에는 반드시 하나 이상의 블록이 놓여 있습니다.


입출력 예
game_board	table	result
[[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,1,0,0,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]]	[[1,0,0,1,1,0],[1,0,1,0,1,0],[0,1,1,0,1,1],[0,0,1,0,0,0],[1,1,0,1,1,0],[0,1,0,0,0,0]]	14
[[0,0,0],[1,1,0],[1,1,1]]	[[1,1,1],[1,0,0],[0,0,0]]	0


입출력 예 설명
입출력 예 #1
입력은 다음과 같은 형태이며, 문제의 예시와 같습니다.


입출력 예 #2
블록의 회전은 가능하지만, 뒤집을 수는 없습니다.
*/	


// 퍼즐 조각 채우기 답 - 1	
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};

    public int solution(int[][] game_board, int[][] table) 
    {
        int answer = -1;

        boolean[][] visitedTable = new boolean[table.length][table.length];
        boolean[][] visitedBoard = new boolean[game_board.length][game_board.length];
        List<List<int[]>> boardList = new ArrayList<>();
        List<List<int[]>> tableList = new ArrayList<>();

        for (int i = 0; i < table.length; i++)
        {
            for (int j = 0; j < table.length; j++)
            {

                if (table[i][j] == 1 && !visitedTable[i][j])
                {
                    bfs(i, j, visitedTable, table, 1, tableList);
                }

                if (game_board[i][j] == 0 && !visitedBoard[i][j])
                {
                    bfs(i, j, visitedBoard, game_board, 0, boardList);
                }
            }
        }

        answer = findBlock(boardList, tableList);

        return answer;
    }

    public int findBlock(List<List<int[]>> board, List<List<int[]>> table)
    {
        int size = 0;
        int tableLen = table.size();
        int boardLen = board.size();
        boolean[] visitedBoard = new boolean[boardLen];
        for (int i = 0; i < tableLen; i++)
        {
            List<int[]> tablePoints = table.get(i);
            for (int j = 0; j < boardLen; j++)
            {
                List<int[]> boardPoints = board.get(j);

                if (tablePoints.size() == boardPoints.size() && !visitedBoard[j])
                { //좌표 개수 같을때
                    if(isRotate(boardPoints, tablePoints))
                    { //회전해서 맞는지 확인
                        size += tablePoints.size();
                        visitedBoard[j] = true;
                        break;
                    }
                }
            }

        }

        return size;
    }

    public boolean isRotate(List<int[]> board, List<int[]> table)
    {
        boolean isCollect = false;

        board.sort((o1, o2) -> {
            return o1[0] > o2[0]?1 : o1[0] < o2[0]?-1 : Integer.compare(o1[1], o2[1]);
        });

        for (int i = 0; i < 4; i++){ //table퍼즐 0, 90, 180, 270도 회전

            table.sort((o1, o2) -> {
                return o1[0] > o2[0]?1 : o1[0] < o2[0]?-1 : Integer.compare(o1[1], o2[1]);
            });
            int nearZeroX = table.get(0)[0];
            int nearZeroY = table.get(0)[1];

            for (int j = 0; j < table.size(); j++)
            {
                table.get(j)[0] -= nearZeroX;
                table.get(j)[1] -= nearZeroY;
            }


            boolean isCollectPoint = true;
            for (int j = 0; j < board.size(); j++)
            { //좌표 비교
                int[] boardPoint = board.get(j);
                int[] tablePoint = table.get(j);

                if (boardPoint[0] != tablePoint[0] || boardPoint[1] != tablePoint[1])
                {
                    isCollectPoint = false;
                    break;
                }
            }

            if (isCollectPoint)
            {
                isCollect = true;
                break;
            } 
            
            else{ //90도 회전 : x,y -> y, -x
                for(int j = 0; j < table.size(); j++)
                {
                    int temp = table.get(j)[0];
                    table.get(j)[0] = table.get(j)[1];
                    table.get(j)[1] = -temp;
                }
            }
        }
        return isCollect;

    }



    public void bfs(int currentX, int currentY, boolean[][] visited, int[][] graph,
                      int blockOrEmpty, List<List<int[]>> list)
    {

        Queue<int[]> queue = new LinkedList<>();
        visited[currentX][currentY] = true;
        queue.add(new int[]{currentX, currentY});
        List<int[]> subList = new ArrayList<>();
        subList.add(new int[]{currentX-currentX, currentY-currentY});

        while (!queue.isEmpty())
        {
            int[] pop = queue.remove();
            int popX = pop[0];
            int popY = pop[1];

            for (int i = 0; i < 4; i++)
            {
                int nextX = popX + dx[i];
                int nextY = popY + dy[i];
                if (nextX < 0 || nextX >= graph.length || nextY < 0 || nextY >= graph.length)
                {
                    continue;
                }
                
                if (!visited[nextX][nextY] && graph[nextX][nextY] == blockOrEmpty)
                {

                    visited[nextX][nextY] = true;
                    queue.add(new int[]{nextX, nextY});
                    subList.add(new int[]{nextX-currentX, nextY-currentY});
                }
            }
        }
        list.add(subList);
    }
	
	
	
	
	
	
	
	
	

	public static void main(String[] args) 
	{

	}

}
