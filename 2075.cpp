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

const int MAX = 1500 + 1;

int board[MAX][MAX];
int N;
priority_queue<pair<int, pair<int, int>>> pq;	// value, n, m

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
}

int solution() {
	for (int i = 1; i <= N; i++)
		pq.push({ {board[N][i]}, {N, i} });

	int cnt = N - 1;

	while (cnt--) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		x--;

		pq.push({ {board[x][y]}, {x, y} });
	}

	return pq.top().first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
