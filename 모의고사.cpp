#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> A = { 1, 2, 3, 4, 5 };
    vector<int> B = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> C = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int cntA = 0;
    int cntB = 0;
    int cntC = 0;
    int maxValue = 0;
    
    int check = 0;
    for(int i = 0; i < answers.size(); i++){
        if(i && !(i % 5)) check++;
        
        int temp = i - 5 * check;
        
        if(A[temp] == answers[i]) cntA++;
    }
    maxValue = cntA;
    answer.push_back(1);
    
    check = 0;
    for(int i = 0; i < answers.size(); i++){
        if(i && !(i % 8)) check++;
        
        int temp = i - 8 * check;
        
        if(B[temp] == answers[i]) cntB++;
    }
    
    if(maxValue == cntB) answer.push_back(2);
    else if(maxValue < cntB) {
            maxValue = cntB;
        
            answer.clear();
            answer.push_back(2);
        }
    
    check = 0;
    for(int i = 0; i < answers.size(); i++){
        if(i && !(i % 10)) check++;
        
        int temp = i - 10 * check;
        
        if(C[temp] == answers[i]) cntC++;
    }
    
    if(maxValue == cntC) answer.push_back(3);
    else if(maxValue < cntC){
            maxValue = cntC;
            
            answer.clear();
            answer.push_back(3);
        }
    
    return answer;
}
