#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    int len = s.length();
    
    stack<char> alpha;
    
    for(int i = 0; i < len; i++){
        if(alpha.empty()) alpha.push(s[i]);
        // 해당 알파벳과 앞에 있는 알파벳이 동일한 경우
        else if(alpha.top() == s[i])
            alpha.pop();
        // 해당 알파벳과 앞에 있는 알파벳이 다른 경우
        else if(alpha.top() != s[i])
            alpha.push(s[i]);
    }
    
    if(alpha.empty()) answer = 1;
    
    return answer;
}
