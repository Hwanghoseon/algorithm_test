#include <string>
#include <vector>

using namespace std;

const int MAX = 60000 + 1;
const int MOD = 1000000007;

vector<int> dp(MAX);

int solution(int n) {
    int answer = 0;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    
    answer = dp[n];
    
    return answer;
}
