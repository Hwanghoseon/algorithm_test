#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    stack<int> list;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            list.push(s[i]);
        else{
            if(list.empty()) return false;
            else
                list.pop();
        }
    }
    
    if(!list.empty()) return false;
    
    return answer;
}
