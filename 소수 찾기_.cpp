#include <string>
#include <vector>

using namespace std;

const int MAX = 1e7;

int list[MAX];
string st = "";
int result = 0;
bool visited[7];
string arr;

void func(){
    for(int i = 2; i <= MAX; i++)
        list[i] = i;
    
    for(int i = 2; i * i <= MAX; i++){
        if(!list[i]) continue;
        
        for(int j = i * i; j <= MAX; j += i)
            list[j] = 0;
    }
}

void backtracking(int cnt, int target){
    if(cnt == target){
        int temp = stoi(st);
        
        if (list[temp]) {
			list[temp] = 0; // 이미 처리한 소수는 더 이상 필요X

			result++;
		}
    }
    
    for(int i = 0; i < arr.length(); i++){
        if(!cnt && arr[i] == '0') continue;
        
        if(!visited[i]){
            visited[i] = true;
            st += arr[i];
            backtracking(cnt + 1, target);
            st.pop_back();
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    func();
    
    arr = numbers;
    for(int i = 1; i <= numbers.length(); i++)
        backtracking(0, i);
    
    answer = result;
    
    return answer;
}
