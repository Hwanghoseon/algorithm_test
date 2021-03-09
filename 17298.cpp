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

const int MAX = 1e6;

int N;
int list[MAX];
int answer[MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];
}

void solution() {
	stack<int> s;

	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= list[i])
			s.pop();

		if (s.empty()) answer[i] = -1;
		else answer[i] = s.top();

		s.push(list[i]);
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	return 0;
}
