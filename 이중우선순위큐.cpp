#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e6;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
priority_queue<pair<int, int>> maxHeap;
bool visited[MAX];

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++){
        char op = operations[i][0];
        string temp = "";
        
        for(int j = 2; j < operations[i].length(); j++)
            temp += operations[i][j];
        
        int num = stoi(temp);
        
        if(op == 'I'){
            maxHeap.push({num, i});
            minHeap.push({num, i});
            visited[i] = true;
        }
        else{
            if(num == 1){
                // maxHeap
                while(!maxHeap.empty() && !visited[maxHeap.top().second])
                    maxHeap.pop();

                if(!maxHeap.empty()){
                    visited[maxHeap.top().second] = false;
                    
                    maxHeap.pop();
                }
            }
            else{
                // minHeap
                while(!minHeap.empty() && !visited[minHeap.top().second])
                    minHeap.pop();
                
                if(!minHeap.empty()){
                    visited[minHeap.top().second] = false;
                    
                    minHeap.pop();
                }
            }
        }
    }
    
    while(!maxHeap.empty() && !visited[maxHeap.top().second]) maxHeap.pop();
    while(!minHeap.empty() && !visited[minHeap.top().second]) minHeap.pop();
    
    if(maxHeap.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxHeap.top().first);
        answer.push_back(minHeap.top().first);
    }
    
    return answer;
}
