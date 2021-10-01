#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<cstdio>
#include<climits>

using namespace std;

const int MAX = 1e3 + 1;

int N;
int list[MAX];
map<string, int> m;

void input() {
	cin >> N;

	string st;
	for (int i = 0; i < N; i++) {
		cin >> st;

		m[st] = i;
	}
}

int solution() {
	int answer = 0;

	string st;
	for (int i = 0; i < N; i++) {
		cin >> st;

		list[i] = m[st];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (list[i] > list[j]) {
				answer++;

				break;
			}
		}
	}

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
