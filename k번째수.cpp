#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for(int i = 0; i < commands.size(); i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        
        temp.clear();
        for(int j = start; j <= end; j++)
            temp.push_back(array[j - 1]);
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[target - 1]);
    }
    
    return answer;
}
