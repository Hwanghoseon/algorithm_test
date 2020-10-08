#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10;

int N;
int map[MAX][MAX];
bool visited[MAX];
vector<int> result;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
}

void func(int cnt, int start, int n, int sum) {
	if (cnt == N) {
		bool isCycle = false;

		if (map[n][start]) {
			isCycle = true;
			sum += map[n][start];
		}

		if (isCycle)
			result.push_back(sum);
		else return;
	}

	for (int i = 0; i < N; i++) {
		if (map[n][i] && !visited[i]) {
			visited[i] = true;
			func(cnt + 1, start, i, sum + map[n][i]);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < N; i++) {
		visited[i] = true;

		func(1, i, i, 0);

		visited[i] = false;
	}

	sort(result.begin(), result.end());

	cout << result[0];

	return 0;
}
