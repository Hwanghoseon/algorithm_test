#include <string>
#include <vector>

using namespace std;

vector<int> list;
int N;
int result = 0;

void dfs(int idx, int sum, int target){
    if(idx == N){
        if(sum == target)
            result++;
        
        return;
    }
    
    dfs(idx + 1, sum + list[idx], target);
    dfs(idx + 1, sum - list[idx], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    N = numbers.size();
    list.resize(N);
    
    for(int i = 0; i < N; i++)
        list[i] = numbers[i];
    
    dfs(0, 0, target);
    
    answer = result;
    
    return answer;
}
