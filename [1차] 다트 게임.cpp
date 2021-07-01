#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int list[3];

int solution(string dartResult) {
    int answer = 0;
    
    string temp = "";
    int N;
    int cnt = 0;
    
    for(int i = 0; i < dartResult.length(); i++){
        while(dartResult[i] >= '0' && dartResult[i] <= '9'){
            temp += dartResult[i];
            
            i++;
        }
        
        N = stoi(temp);
        temp = "";
        
        if(dartResult[i] == 'D')
            N = pow(N, 2);
        else if(dartResult[i] == 'T')
            N = pow(N, 3);
        
        list[cnt] = N;
        
        if(i + 1 == dartResult.length()) break;
        
        if(dartResult[i + 1] == '*'){
            for(int j = cnt; j >= 0 && j >= cnt - 1; j--)
                list[j] *= 2;
            
            i++;
        }
        else if(dartResult[i + 1] == '#'){
            list[cnt] *= -1;
            
            i++;
        }
        
        cnt++;
    }
    
    for(int i = 0; i < 3; i++)
        answer += list[i];
    
    return answer;
}
