#include <string>
#include <vector>

using namespace std;

const int MAX = 30;

char temp[MAX][MAX];
bool isExist = true;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(isExist){
        isExist = false;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                temp[i][j] = board[i][j];
        
        // 같은 모양의 블록 지우기
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(board[i][j] == ' ') continue;
                
                if(board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]){
                    temp[i][j] = ' ';
                    temp[i + 1][j] = ' ';
                    temp[i][j + 1] = ' ';
                    temp[i + 1][j + 1] = ' ';
                    
                    isExist = true;
                }
            }
        }
        
        // 블록 아래로 떨어뜨리기
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = ' ';
        
        for(int j = 0; j < n; j++){
            int len = m - 1;
            
            for(int i = m - 1; i >= 0; i--){
                if(temp[i][j] != ' '){
                    board[len][j] = temp[i][j];
                    
                    len--;
                }
            }
        }
    }
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == ' ')
                answer++;
    
    return answer;
}
