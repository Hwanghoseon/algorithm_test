int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    map<string, int> m;
    
    for(int i = 0; i < words.size(); i++)
        m[words[i]]++;
    
    // bfs
    queue<pair<string, int>> q;
    q.push({begin, 0});
    m[begin] = 0;
    
    while(!q.empty()){
        string curWord = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        
        if(curWord == target){
            answer = curCnt;
            
            break;
        }
        
        for(int i = 0; i < words.size(); i++){
            int cnt = 0;
            for(int j = 0; j < words[i].length(); j++){
                if(curWord[j] != words[i][j]) cnt++;
                
                if(cnt > 1) break;
            }
            
            if(cnt == 1 && m[words[i]] == 1){
                q.push({words[i], curCnt++});
                
                m[words[i]] = 0;
            }
        }
    }
    
    return answer;
}
