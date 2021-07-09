#include <string>
#include <vector>

using namespace std;

const int MAX = 100 + 1;
const int MOD = 1000000007;

int board[MAX][MAX];
bool visited[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0; i < puddles.size(); i++)
        visited[puddles[i][1]][puddles[i][0]] = true;
    
    board[1][1] = 1;
    visited[1][1] = true;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(visited[i][j]) continue;
            
            board[i][j] = (board[i][j - 1] + board[i - 1][j]) % MOD;
        }
    }
    
    answer = board[n][m];
    
    return answer;
}
