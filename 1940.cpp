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

int N, M;
vector<int> list;

void input() {
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

int solution() {
	int cnt = 0;
	int startPoint = 0;
	int endPoint = N - 1;

	while (startPoint < endPoint) {
		int sum = list[startPoint] + list[endPoint];

		if (sum == M) {
			cnt++;

			startPoint++;
			endPoint--;
		}
		else if (sum < M)
			startPoint++;
		else endPoint--;
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
