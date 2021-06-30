#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt = 0;
    
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == ' ') {
            cnt = 0;
            
            answer += s[i];
            continue;
        }
        
        cnt++;
        
        if(cnt % 2){
            //소문자일 경우
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = (s[i] - 'a') + 'A';
            
            answer += s[i];
        }
        else{
            // 대문자일 경우
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = (s[i] - 'A') + 'a';
            
            answer += s[i];
        }
    }
    
    return answer;
}
