#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int M;

string solution(int n, int t, int m, int p) {
    string answer = "0";
    
    M = t * m - 1;
    
    for(int i = 1; i <= M; i++){
        string temp = "";
        
        int N = i;
        
        while(N){
            int x = N % n;
            
            if(x < 10) 
                temp += (x + '0');
            else if(x == 10)
                temp += 'A';
            else if(x == 11)
                temp += 'B';
            else if(x == 12)
                temp += 'C';
            else if(x == 13)
                temp += 'D';
            else if(x == 14)
                temp += 'E';
            else if(x == 15)
                temp += 'F';
            
            N /= n;
        }
        
        reverse(temp.begin(), temp.end());
        
        answer += temp;
    }
    
    string result = "";
    
    int idx = p - 1;
    while(t--){
        result += answer[idx];
        
        idx += m;
    }
    
    return result;
}
