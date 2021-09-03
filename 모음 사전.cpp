#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int list[150][6];

void func(){
    int sum = 0;
    
    list['A'][1] = 1;
    list['E'][1] = 2;
    list['I'][1] = 3;
    list['O'][1] = 4;
    list['U'][1] = 5;
    
    for(int i = 1; i < 5; i++){
        sum += pow(5, i);
        
        int temp = sum + 1;
        
        list['A'][i + 1] = 1;
        list['E'][i + 1] = 1 + temp * 1;
        list['I'][i + 1] = 1 + temp * 2;
        list['O'][i + 1] = 1 + temp * 3;
        list['U'][i + 1] = 1 + temp * 4;
    }
}

int solution(string word) {
    func();
    
    int answer = 0;
    
    for(int i = 0; i < word.length(); i++)
        answer += list[word[i]][5 - i];
    
    return answer;
}
