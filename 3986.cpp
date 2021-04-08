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

int solution() {
	int T;
	cin >> T;

	int cnt = 0;

	while (T--) {
		string input;
		cin >> input;

		stack<char> s;

		for (int i = 0; i < input.length(); i++) {
			if (s.empty() || s.top() != input[i])
				s.push(input[i]);
			else if (s.top() == input[i])
				s.pop();
		}

		if (s.empty()) cnt++;
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();

	return 0;
}
