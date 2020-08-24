#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 단어의 길이가 짝수일 경우
    if(s.length() % 2)
        answer += s[s.length() / 2];
    
    // 단어의 길이가 홀수일 경우
    else{
        answer += s[s.length() / 2 - 1];
        answer += s[s.length() / 2];
    }
    
    return answer;
}
