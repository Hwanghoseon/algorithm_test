#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1000 + 1;

int list[MAX][MAX];
bool primeNum[MAX * MAX];

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int N = board.size();
    int M = board[0].size();
    
    for(int i = 1; i <= N; i++){
        int sum = 0;
        
        for(int j = 1; j <= M; j++){
            sum += board[i - 1][j - 1];
            
            list[i][j] = sum;
        }
    }
    
    for(int i = 1; i <= M; i++){
        int sum = 0;
        
        for(int j = 1; j <= N; j++){
            sum += list[j][i];
            
            list[j][i] = sum;
        }
    }
    
    int maxLen = max(N, M);
    int minLen = 1;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            for(int k = minLen; k <= maxLen; k++){
                if(i - k < 0 || j - k < 0) break;
                
                int temp = list[i][j] - list[i - k][j] - list[i][j - k] + list[i - k][j - k];
                
                if(temp == k * k) {
                    answer = max(answer, temp);
                    
                    minLen = k;
                    
                    continue;
                }
                else break;
            }
        }
    }
    
    return answer;
}
