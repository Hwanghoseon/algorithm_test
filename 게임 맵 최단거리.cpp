#include<vector>
#include <queue>

using namespace std;

const int MAX = 100;

int board[MAX][MAX];
int N, M;
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    board[0][0] = 0;
    
    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curSec = q.front().second;
        q.pop();
        
        if(curX == N - 1 && curY == M - 1) return curSec;
        
        for(int i = 0; i < 4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M){
                if(board[nextX][nextY]){
                    q.push({{nextX, nextY}, curSec + 1});
                    
                    board[nextX][nextY] = 0;
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    N = maps.size();
    M = maps[0].size();
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            board[i][j] = maps[i][j];
    
    answer = bfs();
    
    return answer;
}
