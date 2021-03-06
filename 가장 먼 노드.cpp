#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20000 + 1;

vector<int> graph[MAX];
bool visited[MAX];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    // bfs
    queue<pair<int, int>> q;    // node, len
    q.push({1, 0});
    visited[1] = true;
    
    int curNum = 0;
    while(!q.empty()){
        int curX = q.front().first;
        int curLen = q.front().second;
        q.pop();
        
        if(curNum < curLen){
            curNum = curLen;
            
            answer = 1;
        }
        else if(curNum == curLen)
            answer++;
        
        for(int i = 0; i < graph[curX].size(); i++){
            int nextX = graph[curX][i];
            
            if(nextX >= 1 && nextX <= n)
                if(!visited[nextX]){
                    q.push({nextX, curLen + 1});
                    
                    visited[nextX] = true;
                }
        }
    }
    
    return answer;
}
