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

using namespace std;

const int MAX = 8;

int N, M;
int board[MAX][MAX];
vector<pair<int, int>> virus;
bool visited[MAX][MAX];
vector<pair<int, int>> candidate;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
int temp[MAX][MAX];
int result = 0;

void input() {
	cin >> N >> M;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2)
				virus.push_back({ i, j });
			else if (board[i][j] == 0)
				candidate.push_back({ i, j });
		}
}

void dfs(int x, int y) {
	temp[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if (!temp[nextX][nextY])
				dfs(nextX, nextY);
	}
}

int virusSize() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = board[i][j];

	for (int i = 0; i < virus.size(); i++)
		dfs(virus[i].first, virus[i].second);

	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0) cnt++;

	return cnt;
}

void func(int cnt, int min, int sizeNum) {
	if (cnt == 3) {
		result = max(result, virusSize());

		return;
	}

	for (int i = min; i < sizeNum; i++) {
		int curX = candidate[i].first;
		int curY = candidate[i].second;

		if (!visited[curX][curY]) {
			visited[curX][curY] = true;
			board[curX][curY] = 1;
			func(cnt + 1, i + 1, sizeNum);
			visited[curX][curY] = false;
			board[curX][curY] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0, candidate.size());

	cout << result;

	return 0;
}
