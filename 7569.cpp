#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100;

typedef struct {
	int x, y, z;
}dir;

int tomato[MAX][MAX][MAX];
deque<dir> dq;

int N, M, H;
int noTomato = 0;
int dirX[] = { 1, -1, 0, 0 ,0 ,0 };
int dirY[] = { 0, 0, 1, -1, 0, 0 };
int dirZ[] = { 0, 0, 0, 0, 1, -1 };

bool check() {
	int possible = N * M * H - noTomato;
	int tomatoCnt = 0;

	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (tomato[i][j][k] == 1)
					tomatoCnt++;

	return tomatoCnt == possible;
}

int bfs() {
	if (dq.empty())
		return -1;

	int day = 0;

	while (!dq.empty()) {
		int curSize = dq.size();

		for (int i = 0; i < curSize; i++) {
			int curX = dq.front().x;
			int curY = dq.front().y;
			int curZ = dq.front().z;

			dq.pop_front();

			for (int j = 0; j < 6; j++) {
				int nextX = curX + dirX[j];
				int nextY = curY + dirY[j];
				int nextZ = curZ + dirZ[j];

				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && nextZ >= 0 && nextZ < H) {
					if (!tomato[nextX][nextY][nextZ]) {
						tomato[nextX][nextY][nextZ] = 1;
						dq.push_back({ nextX, nextY, nextZ });
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

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tomato[i][j][k];

				if (tomato[i][j][k] == 1)
					dq.push_back({ i, j, k });
				else if (tomato[i][j][k] == -1)
					noTomato++;
			}
		}
	}

	if (dq.size() == N * N * H - noTomato)
		cout << "0" << endl;
	else cout << bfs() << endl;

	return 0;
}
