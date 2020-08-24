#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

   int before = -1;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == before) continue;
        else{
            before = arr[i];
            
            answer.push_back(arr[i]);
        }
    }

    return answer;
}
