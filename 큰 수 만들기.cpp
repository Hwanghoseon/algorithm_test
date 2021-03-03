#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.size() - k;    // 찾아야하는 숫자의 크기
    int startIdx = 0;   // 현재 인덱스 위치
    int cnt = 0;    // 숫자를 찾은 갯수
    
    int n = len;
    while(n--){
        char temp = -1 + '0';
        int nextIdx;
        for(int i = startIdx; (number.size() - startIdx >= len - cnt) && i <= (k + cnt); i++){
            if(temp < number[i]){
                temp = number[i];
                nextIdx = i + 1;
            }
        }
        answer += temp;
        cnt++;
        startIdx = nextIdx;
    }
    
    return answer;
}
