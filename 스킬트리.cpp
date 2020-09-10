#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> tree;    // 스킬, 우선순위
    
    for(int i = 0; i < skill.length(); i++)
        tree[skill[i]] = i + 1;
    
    for(int i = 0; i < skill_trees.size(); i++){
        int cnt = 1;
        bool isError = false;
        
        for(int j = 0; j < skill_trees[i].length(); j++){
            if(tree.find(skill_trees[i][j]) != tree.end()){
                if(tree[skill_trees[i][j]] != cnt){
                    isError = true;
                    break;
                }
                cnt++;
            }
        }
        if(!isError) answer++;
    }
    
    return answer;
}
