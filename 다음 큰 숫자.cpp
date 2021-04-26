#include <string>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

int checkCnt(int n){
    int cnt = 0;
    
    while(n){
        if(n % 2) cnt++;
        
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int num = checkCnt(n);
    
    for(int i = n + 1; i < MAX; i++){
        if(checkCnt(i) == num){
            answer = i;
            
            break;
        }
    }
    
    return answer;
}
