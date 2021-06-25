#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    
    // 1단계
    for(int i = 0; i < new_id.length(); i++)
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = char(new_id[i] - 'A') + 'a';
    
    // 2단계
    for(int i = 0; i < new_id.length(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer.push_back(new_id[i]);
    }
    
    temp = answer;
    answer = "";
    
    // 3단계
    for(int i = 0; i < temp.length() - 1; i++){
        if(temp[i] == '.' && temp[i] == '.'){
            while(temp[i] == '.') i++;
            
            i--;
            
            answer.push_back('.');
        }
        else answer.push_back(temp[i]);
    }
    answer.push_back(temp[temp.length() - 1]);
    
    // 4단계
    if(answer[answer.length() - 1] == '.')
        while(answer[answer.length() - 1] == '.') answer.pop_back();
    
    reverse(answer.begin(), answer.end());
    
    if(answer[answer.length() - 1] == '.')
        while(answer[answer.length() - 1] == '.') answer.pop_back();
    
    reverse(answer.begin(), answer.end());
    
    // 5단계
    if(answer == "") answer = "a";
    
    // 6단계
    while(answer.length() > 15)
        answer.pop_back();
    
    while(answer[answer.length() - 1] == '.') answer.pop_back();
    
    temp = answer[answer.length() - 1];
    
    // 7단계
    while(answer.length() < 3)
        answer += temp;
    
    return answer;
}
