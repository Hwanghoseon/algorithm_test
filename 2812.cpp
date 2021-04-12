#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

int N, K;
string input;

string solution() {
	cin >> N >> K >> input;

	stack<char> s;

	for (int i = 0; i < input.length(); i++) {
		while (K && !s.empty() && s.top() < input[i]) {
			s.pop();

			K--;
		}
		s.push(input[i]);
	}

	// 스택에 범위 이상의 수가 들어있을 경우
	while (K--) s.pop();

	string answer = "";

	while (!s.empty()) {
		answer += s.top();

		s.pop();
	}

	reverse(answer.begin(), answer.end());

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();
	
	return 0;
}
