#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer =  1e9 * 10000;
    
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = answer * 10000;
    
    while(low <= high){
        long long mid = (low + high) / 2;
        
        long long sec = 0;
        for(int i = 0; i < times.size(); i++)
            sec += mid / times[i];
        
        if(sec >= n){
            answer = min(answer, mid);
            
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    return answer;
}
