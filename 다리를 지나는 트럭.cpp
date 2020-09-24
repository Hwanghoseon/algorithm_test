#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> truck;
    int sum = 0;
    
    for(int i = 0; i < truck_weights.size(); i++){
        while(true){
            if(truck.size() == bridge_length){
                sum -= truck.front();
                truck.pop();
            }
            
            if(sum + truck_weights[i] <= weight) break;
            
            truck.push(0);
            answer++;
        }
        
        truck.push(truck_weights[i]);
        sum += truck_weights[i];
        answer++;
    }
    
    answer += bridge_length;
    
    return answer;
}
