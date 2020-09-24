#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> pro, sp;
    
    for(int i = 0; i < speeds.size(); i++){
        pro.push(progresses[i]);
        sp.push(speeds[i]);
    }
    
    while(!pro.empty()){
        int cnt = 0;
        
        while(!pro.empty() && pro.front() >= 100){
            cnt++;
            pro.pop();
            sp.pop();
        }
        
        if(cnt) answer.push_back(cnt);
        
        for(int i = 0; i < pro.size(); i++){
            int curPro = pro.front();
            int curSp = sp.front();
            pro.pop();
            sp.pop();
            
            pro.push(curPro + curSp);
            sp.push(curSp);
        }
    }
    
    return answer;
}
