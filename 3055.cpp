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
char board[MAX][MAX];
queue<pair<int, int>> water;
queue<pair<int, int>> animal;
bool visited[MAX][MAX];	// 고슴도치의 이동 여부 확인
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == '*')
				water.push(make_pair(i, j));
			else if (board[i][j] == 'S') {
				animal.push(make_pair(i, j));

				visited[i][j] = true;
			}
		}
}

int bfs() {
	int day = 0;

	while (!animal.empty()) {
		day++;

		int waterSize = water.size();

		// 물의 이동
		while (waterSize--) {
			int waterCurX = water.front().first;
			int waterCurY = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int waterNextX = waterCurX + dirX[i];
				int waterNextY = waterCurY + dirY[i];

				if (waterNextX >= 0 && waterNextX < N && waterNextY >= 0 && waterNextY < M) {
					if (board[waterNextX][waterNextY] == '.') {
						board[waterNextX][waterNextY] = '*';

						water.push({ waterNextX, waterNextY });
					}
				}
			}
		}

		// 고슴도치 이동
		int animalSize = animal.size();

		while (animalSize--) {
			int curX = animal.front().first;
			int curY = animal.front().second;
			animal.pop();

			for (int i = 0; i < 4; i++) {
				int nextX = curX + dirX[i];
				int nextY = curY + dirY[i];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
					// 고슴도치가 이동할 수있는 곳일 경우
					if (board[nextX][nextY] == '.' && !visited[nextX][nextY]) {
						animal.push({ nextX, nextY });

						visited[nextX][nextY] = true;
					}
					//비버의 굴에 도달한 경우
					else if (board[nextX][nextY] == 'D')
						return day;
				}
			}
		}
	}

	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int result = bfs();

	if (result == -1)
		cout << "KAKTUS";
	else cout << result;

	return 0;
}
