#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1000;

int tomato[MAX][MAX];
deque<pair<int, int>> dq;

int N, M;
int noTomato = 0;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

bool check() {
	int possible = M * N - noTomato;
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1)
				result++;
		}
	}

	return possible == result;
}

int bfs() {
	if (dq.empty())
		return -1;

	int day = 0;

	while (!dq.empty()) {
		int curSize = dq.size();

		for (int i = 0; i < curSize; i++) {
			int curX = dq.front().first;
			int curY = dq.front().second;

			dq.pop_front();

			for (int j = 0; j < 4; j++) {
				int nextX = curX + dirX[j];
				int nextY = curY + dirY[j];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
					if (!tomato[nextX][nextY]) {
						tomato[nextX][nextY] = 1;
						dq.push_back({ nextX, nextY });
					}
				}
			}
			if (dq.empty() && check())
				return day;
			else if (dq.empty() && !check())
				return -1;
		}
		day++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];

			if (tomato[i][j] == 1)
				dq.push_back({ i, j });
			else if (tomato[i][j] == -1)
				noTomato++;
		}
	}

	if (dq.size() == M * N - noTomato)
		cout << "0" << endl;
	else cout << bfs() << endl;

	return 0;
}
