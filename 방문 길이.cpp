#include <string>
using namespace std;

struct Dir{
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
};

const int MAX = 10 + 1;

Dir board[MAX][MAX];    // (5, 5)

int solution(string dirs) {
    int answer = 0;
    
    int x, y;
    x = y = 5;  // 중앙
    
    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i] == 'U'){
            int nextX = x - 1;
            
            if(nextX < 0) continue;
            
            if(!board[x][y].up) answer++;
            
            board[x][y].up = true;
            board[nextX][y].down = true;
            
            x = nextX;
        }
        else if(dirs[i] == 'D'){
            int nextX = x + 1;
            
            if(nextX >= MAX) continue;
            
            if(!board[x][y].down) answer++;
            
            board[x][y].down = true;
            board[nextX][y].up = true;
            
            x = nextX;
        }
        else if(dirs[i] == 'L'){
            int nextY = y - 1;
            
            if(nextY < 0) continue;
            
            if(!board[x][y].left) answer++;
            
            board[x][y].left = true;
            board[x][nextY].right = true;
            
            y = nextY;
        }
        else if(dirs[i] == 'R'){
            int nextY = y + 1;
            
            if(nextY >= MAX) continue;
            
            if(!board[x][y].right) answer++;
            
            board[x][y].right = true;
            board[x][nextY].left = true;
            
            y = nextY;
        }
    }
    
    
    
    
    /*
    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i] == 'U'){
            int nextX = x - 1;
            
            if(nextX < 0) continue;
            
            if(!board[nextX][y])
                answer++;
            
            x = nextX;
            
            board[x][y] = true;
        }
        else if(dirs[i] == 'D'){
            int nextX = x + 1;
            
            if(nextX >= MAX) continue;
            
            if(!board[nextX][y])
                answer++;
            
            x = nextX;
            
            board[x][y] = true;
        }
        else if(dirs[i] == 'L'){
            int nextY = y - 1;
            
            if(nextY < 0) continue;
            
            if(!board[x][nextY])
                answer++;
            
            y = nextY;
            
            board[x][y] = true;
        }
        else if(dirs[i] == 'R'){
            int nextY = y + 1;
            
            if(nextY >= MAX) continue;
            
            if(!board[x][nextY])
                answer++;
            
            y = nextY;
            
            board[x][y] = true;
        }
    }
    */
    
    return answer;
}
