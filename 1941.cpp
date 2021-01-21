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

const int MAX = 5;

int board[MAX][MAX];
vector<pair<int, int>> candidate;
bool visited[MAX * MAX];
int result = 0;
bool list[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	for (int i = 0; i < MAX; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == 'S') 
				board[i][j] = 1;
			else board[i][j] = 0;

			candidate.push_back(make_pair(i, j));
		}
	}
}

void dfs(int x, int y) {
	if (!list[x][y]) return;

	list[x][y] = false;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < MAX && nextY >= 0 && nextY < MAX) {
			if (list[nextX][nextY])
				dfs(nextX, nextY);
		}
	}
}

// '소문난 칠공주'의 후보들이 연결되어있는지 dfs로 체크
bool isPossible() {
	for (int i = 0; i < MAX * MAX; i++) {
		if (visited[i]) {
			int curX = candidate[i].first;
			int curY = candidate[i].second;

			list[curX][curY] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (list[i][j]) {
				dfs(i, j);

				cnt++;
			}

	if (cnt == 1) return true;

	return false;
}

// 'S'는 1로 저장했기 때문에 합이 최소 4이상이 되어야 성립
void func(int cnt, int idx, int sum) {
	if (cnt == 7) {
		if (sum >= 4 && isPossible()) 
			result++;

		return;
	}

	if (idx == candidate.size()) return;

	int curX = candidate[idx].first;
	int curY = candidate[idx].second;

	// 칠공주일 경우
	visited[idx] = true;
	func(cnt + 1, idx + 1, sum + board[curX][curY]);

	// 칠공주가 아닐 경우
	visited[idx] = false;
	func(cnt, idx + 1, sum);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0, 0);

	cout << result;

	return 0;
}
