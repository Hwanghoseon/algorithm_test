#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    long long c;
    
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    answer = arr[0];
    for(int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    
    return answer;
}
