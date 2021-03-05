#include <string>
#include <vector>

using namespace std;

const int MAX = 200 + 1;

vector<int> graph[MAX];
bool visited[MAX];

void dfs(int x){
    if(visited[x]) return;
    
    visited[x] = true;
    
    for(int i = 0; i < graph[x].size(); i++){
        if(!visited[graph[x][i]])
            dfs(graph[x][i]);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j) continue;
            
            if(computers[i][j])
                graph[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            
            answer++;
        }
    }
    
    return answer;
}
