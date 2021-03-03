#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> list;
    
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ')
            temp += s[i];
        else{
            int num = stoi(temp);
            
            list.push_back(num);
            
            temp = "";
        }
    }
    
    int num = stoi(temp);
    
    list.push_back(num);
    
    sort(list.begin(), list.end());
    
    answer += to_string(list[0]);
    answer += " ";
    answer += to_string(list[list.size() - 1]);
    
    return answer;
}
