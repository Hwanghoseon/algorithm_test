#include <string>
#include <vector>

using namespace std;

int ranking[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int candidate = 0;
    int sameNum = 0;
    
    for(int i = 0; i < lottos.size(); i++){
        if(!lottos[i]){
            candidate++;
            
            continue;
        }
        for(int j = 0; j < win_nums.size(); j++){
            if(lottos[i] == win_nums[j])
                sameNum++;
        }
    }
    
    answer.push_back(ranking[sameNum + candidate]);
    answer.push_back(ranking[sameNum]);
    
    return answer;
}
