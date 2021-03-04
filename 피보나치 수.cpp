#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;
const int MAX = 1e6 + 1;

int list[MAX];

int solution(int n) {
    int answer = 0;
    
    list[0] = 0;
    list[1] = 1;
    
    for(int i = 2; i < n + 1; i++)
        list[i] = (list[i - 2] + list[i - 1]) % MOD;
    
    answer = list[n];
    
    return answer;
}
