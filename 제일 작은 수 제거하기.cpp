#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
        
    for(int i = 0; i < arr.size(); i++)
        pq.push(arr[i]);
    
    if(arr.size() == 1) {
        answer.push_back(-1);
        
        return answer;
    }
    
    for(int i = 0; i < arr.size(); i++)
        if(arr[i] != pq.top())
            answer.push_back(arr[i]);
    
    return answer;
}
