#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAX = 20;

int N;
int graph[MAX][MAX];
int result = INT_MAX;
bool visited[MAX];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
}

int checkSum() {
	int sumStart = 0;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) continue;

		for (int j = 0; j < N; j++) {
			if (!visited[j]) continue;

			sumStart += graph[i][j];
		}
	}

	int sumLink = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		for (int j = 0; j < N; j++) {
			if (visited[j]) continue;

			sumLink += graph[i][j];
		}
	}

	return abs(sumStart - sumLink);
}

void bt(int cnt, int idx) {
	if (cnt == N / 2) {
		result = min(result, checkSum());

		return;
	}

	if (idx == N) return;

	// 스타트 팀
	visited[idx] = true;
	bt(cnt + 1, idx + 1);
	// 링크 팀
	visited[idx] = false;
	bt(cnt, idx + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bt(0, 0);

	cout << result;

	return 0;
}
