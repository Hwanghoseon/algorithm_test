#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 500;

int map[MAX][MAX];
int N, M;
int result = 0;
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
bool visited[MAX][MAX];

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void func(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		result = max(result, sum);

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			if (!visited[nextX][nextY]) {
				visited[nextX][nextY] = true;
				func(nextX, nextY, cnt + 1, sum + map[nextX][nextY]);
				visited[nextX][nextY] = false;
			}
	}
}

int func2() {
	int maxSum = 0;

	// 정모양
	for (int i = 1; i < N; i++)
		for (int j = 1; j + 1 < M; j++)
			maxSum = max(maxSum, map[i][j - 1] + map[i][j] + map[i][j + 1] + map[i - 1][j]);

	// 우측으로 회전
	for (int i = 1; i + 1 < N; i++)
		for (int j = 0; j + 1 < M; j++)
			maxSum = max(maxSum, map[i - 1][j] + map[i][j] + map[i + 1][j] + map[i][j + 1]);

	// 좌측으로 회전
	for (int i = 1; i + 1 < N; i++)
		for (int j = 1; j < M; j++)
			maxSum = max(maxSum, map[i][j - 1] + map[i - 1][j] + map[i][j] + map[i + 1][j]);

	// 누워있는 경우
	for (int i = 0; i + 1 < N; i++)
		for (int j = 1; j + 1 < M; j++)
			maxSum = max(maxSum, map[i][j - 1] + map[i][j] + map[i][j + 1] + map[i + 1][j]);

	return maxSum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			func(i, j, 0, 0);
		}

	result = max(result, func2());

	cout << result;

	return 0;
}
