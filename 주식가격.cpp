#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); i++){
        int cnt = 1;
        for(int j = i + 1; j < prices.size(); j++){
            if(prices[i] > prices[j]) break;
            cnt++;
        }
        if(cnt == prices.size() - i) cnt--;
        answer.push_back(cnt);
    }
    
    return answer;
}
