#include <vector>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
int temp;
int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

void dfs(int x, int y, int m, int n, int num){
    if(!map[x][y]) return;
    
    map[x][y] = 0;
    temp++;
    
    for(int i = 0; i < 4; i++){
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];
        
        if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
            if(map[nextX][nextY] == num)
                dfs(nextX, nextY, m, n, num);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            map[i][j] = picture[i][j];
    
    int sectorCnt = 0;
    int maxSize = 0;
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            if(map[i][j]){
                temp = 0;
                dfs(i, j, m, n, map[i][j]);
                
                sectorCnt++;
                maxSize = max(maxSize, temp);
            }
        }
    
    vector<int> answer(2);
    answer[0] = sectorCnt;
    answer[1] = maxSize;
    
    return answer;
}
