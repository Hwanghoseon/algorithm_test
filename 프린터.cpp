#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    while(!pq.empty()){
        int value = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(value == pq.top()){
            pq.pop();
            answer++;
            
            if(idx == location) break;
        }
        else{
            q.push(make_pair(value, idx));
        }
    }
    
    return answer;
}
