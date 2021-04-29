#include <vector>
#include <iostream>
using namespace std;

const int MAX = 3000 + 1;

bool primeNum[MAX];

void func(){
    primeNum[0] = primeNum[1] = true;
    
    for(int i = 2; i < MAX; i++)
        for(int j = i * i; j < MAX; j += i)
            primeNum[j] = true;
}

int solution(vector<int> nums) {
    func();
    
    int answer = 0;
    
    int N = nums.size();
    
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            for(int k = j; k < N; k++){
                if(i == j || i == k || j == k) continue;
                
                int sum = nums[i] + nums[j] + nums[k];
                
                if(!primeNum[sum]) answer++;
            }
        }
    }
    
    return answer;
}
