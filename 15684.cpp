#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int map[30 + 1][10 + 1];
int cur[30 + 1][10 + 1];
int N, M, H;
int result = INT_MAX;
vector<pair<int, int>> candidate;

void input() {
	cin >> N >> H >> M;

	for (int i = 0; i < H; i++) {
		int from, to;
		cin >> from >> to;

		map[from][to] = 1;
	}

	for (int i = 1; i <= M; i++)
		for (int j = 1; j < N; j++)
			if (!map[i][j] && !map[i][j - 1] && !map[i][j + 1])
				candidate.push_back(make_pair(i, j));
}

bool isPossible() {
	for (int i = 1; i <= N; i++)
		cur[0][i] = i;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j - 1]) cur[i][j] = cur[i - 1][j - 1];
			else if (map[i][j]) cur[i][j] = cur[i - 1][j + 1];
			else cur[i][j] = cur[i - 1][j];
		}
	}

	for (int i = 1; i <= N; i++)
		if (cur[M][i] != i) return false;

	return true;
}

void func(int cnt, int now) {
	if (isPossible()) {
		result = min(result, cnt);

		return;
	}
	else
		if (cnt == 3) return;

	for (int i = now; i < candidate.size(); i++) {
		int curX = candidate[i].first;
		int curY = candidate[i].second;

		if (!map[curX][curY] && !map[curX][curY - 1] && !map[curX][curY + 1]) {
			map[curX][curY] = 1;
			func(cnt + 1, i + 1);
			map[curX][curY] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0);

	if (result == INT_MAX) result = -1;

	cout << result;

	return 0;
}
