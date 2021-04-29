#include <string>
#include <vector>

using namespace std;

const int MAX = 1e4;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= MAX; i++){
        int sum = 0;
        
        for(int j = i; sum + j <= n; j++){
            sum += j;
            
            if(sum == n) answer++;
        }
    }
    
    return answer;
}
