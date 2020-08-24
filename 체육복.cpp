#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n + 1);
    
    for(int i = 0; i < lost.size(); i++)
        student[lost[i]] += -1;
    
    for(int i = 0; i < reserve.size(); i++)
        student[reserve[i]] += 1;
    
    for(int i = 1; i <= n; i++){
        // 여벌의 체육복이 있는 경우
        if(student[i] == 1){
            if(i - 1 >= 1){
                if(student[i - 1] == -1){
                    student[i - 1]++;
                    student[i]--;
                }
            }
        }
        if(student[i] == 1){
            if(i + 1 <= n){
                if(student[i + 1] == -1){
                    student[i]--;
                    student[i + 1]++;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; i++)
        if(student[i] == 0 || student[i] == 1)
            answer++;
    
    return answer;
}
