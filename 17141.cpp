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

const int MAX = 50;

int N, M;
int board[MAX][MAX];
vector<pair<int, int>> candidate;	//	바이러스가 놓일 수 있는 빈칸
vector<pair<int, int>> arr;
int result = MAX * MAX;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) {
				candidate.push_back({ i, j });

				board[i][j] = 0;
			}
		}

	arr.resize(10);
}

int virusSec() {
	int temp[MAX][MAX];
	int sec = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == 1) 
				temp[i][j] = board[i][j];
			else
				temp[i][j] = 0;

	queue<pair<int, int>> virus;

	for (int i = 0; i < M; i++) {
		temp[arr[i].first][arr[i].second] = 2;

		virus.push({ arr[i].first, arr[i].second });
	}

	while (!virus.empty()) {
		int virusSize = virus.size();

		while (virusSize--) {
			int curX = virus.front().first;
			int curY = virus.front().second;
			virus.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
					if (!temp[nextX][nextY]) {
						temp[nextX][nextY] = 2;

						virus.push({ nextX, nextY });
					}
				}
			}
		}
		sec++;
	}

	sec--;	// 이미 바이러스가 퍼진 후에 한번 더 진행하기 때문에 1일 빼준다.

	bool isPossible = true;

	for (int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (!temp[i][j]) {
				isPossible = false;

				break;
			}

	if (!isPossible) return MAX * MAX;

	return sec;
}

void func(int cnt, int minIdx) {
	if (cnt == M) {
		result = min(result, virusSec());

		return;
	}

	for (int i = minIdx; i < candidate.size(); i++) {
		arr[cnt] = { candidate[i].first, candidate[i].second };
		func(cnt + 1, i + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, 0);

	if (result == MAX * MAX) cout << -1;
	else cout << result;

	return 0;
}
