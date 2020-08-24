#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    long long x = a;
    long long y = b;
    
    answer = (x + y) * (abs(x - y) + 1) / 2;
    
    return answer;
}
