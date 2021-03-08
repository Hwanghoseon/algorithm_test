#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    while(true){
        // 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if(pq.size() == 1 && pq.top() < K){
            answer = -1;
            
            break;
        }
        
        // 모든 음식의 스코빌 지수를 K 이상으로 만들었을 경우
        if(pq.top() >= K) break;
        
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        
        pq.push(num1 + num2 * 2);
        
        answer++;
    }
    
    return answer;
}
