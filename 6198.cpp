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

const int MAX = 80000;

int N;
vector<int> list(MAX);

long long solution() {
	long long sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];

	stack<int> s;

	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= list[i])
			s.pop();

		s.push(list[i]);

		sum += (s.size() - 1);
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();

	return 0;
}
