#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    
    sort(people.begin(), people.end());
    
    int high = people.size() - 1;
    int low = 0;
    
    while(low < high){
        if(people[low] + people[high] <= limit){
            low++;
            high--;
            answer--;
        }
        else
            high--;
    }
    
    return answer;
}
