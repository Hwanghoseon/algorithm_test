#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> list;
    
    for(int i = 0; i < numbers.size(); i++)
        list.push_back(to_string(numbers[i]));
    
    sort(list.begin(), list.end(), desc);
    
    for(int i = 0; i < list.size(); i++)
        answer += list[i];
    
    if(answer[0] == '0') return "0";
    
    return answer;
}
