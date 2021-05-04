#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        string temp1 = "";
        
        for(int j = n - 1; j >= 0; j--){
            int num = pow(2, j);
            
            if(arr1[i] < num) temp1 += " ";
            else{
                temp1 += "#";
                
                arr1[i] -= num;
            }
        }
        
        string temp2 = "";
        
        for(int j = n - 1; j >= 0; j--){
            int num = pow(2, j);
            
            if(arr2[i] < num) temp2 += " ";
            else{
                temp2+= "#";
                
                arr2[i] -= num;
            }
        }
        
        for(int j = 0; j < n; j++)
            if(temp1[j] == '#' || temp2[j] == '#') temp1[j] = '#';
        
        answer.push_back(temp1);
    }
    
    return answer;
}
