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

const int MAX = 1000;

int N;
vector<int> list(MAX);

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

void solution() {
	int idx = 0;
	int cnt = 1;
	stack<int> s;

	while (idx < N) {
		if (cnt == list[idx]) {
			cnt++;
			idx++;
		}
		else if (!s.empty() && s.top() == cnt) {
			cnt++;

			s.pop();
		}
		else {
			s.push(list[idx]);

			idx++;
		}
	}

	while (!s.empty()) {
		if (s.top() == cnt) {
			cnt++;

			s.pop();
		}
		else break;
	}

	if (s.empty()) cout << "Nice";
	else cout << "Sad";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
