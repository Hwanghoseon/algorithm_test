#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1000000 + 1;

int solution(int n) {
    int answer = 0;
    
    vector<int> num(MAX);
    
    for(int i = 0; i < MAX; i++)
        num[i] = 1;
    
    num[1] = 0;
    for(long long i = 2; i < MAX; i++)
        for(long long j = i * i; j < MAX; j += i)
            if(num[j]) num[j] = 0;
    
    for(int i = 1; i <= n; i++)
        answer += num[i];
    
    return answer;
}
