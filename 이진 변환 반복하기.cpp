#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeroCnt = 0;
    int round = 0;
    
    while(s != "1"){
        string temp = "";
        int len = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') temp += "1";
            else zeroCnt++;
        }
        
        len = temp.length();
        s = "";
        
        while(len){
            if(len % 2 == 1) s += "1";
            else s += "0";
            len /= 2;
        }
        
        round++;
    }
    
    answer = {round, zeroCnt};
    
    return answer;
}
