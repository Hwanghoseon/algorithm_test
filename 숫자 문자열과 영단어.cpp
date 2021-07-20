#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result = "";
    
    map<string, string> m;
    
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
    
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i]>= '0' && s[i] <= '9'){
            if(temp != ""){
                result += m[temp];
                
                temp = "";
            }
            result += s[i];
        }
        else{
            if(temp != "" && m[temp] >= "0" && m[temp] <= "9"){
                result += m[temp];
                
                temp = "";
            }
            temp += s[i];
        }
    }
    
    if(temp != "")
        result += m[temp];
    
    answer = stoi(result);
    
    return answer;
}
