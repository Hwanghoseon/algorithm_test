#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> month(13);
    vector<string> list = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
    month[2] = 29;
    month[4] = month[6] = month[9] = month[11] = 30;
    
    for(int i = 2; i <= 12; i++)
        month[i] += month[i - 1];
    
    int cnt = month[a - 1] + b;
    
    cnt %= 7;
    
    string answer = "";
    answer = list[cnt];
    
    return answer;
}
