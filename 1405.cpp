#include<iostream>
#include<iomanip>

using namespace std;

const int MAX = 14 * 2 + 1;

int n;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dirX[] = { 1, -1, 0, 0 };
int dirY[] = { 0, 0, 1, -1 };
double chance[4];
double result;

void input() {
	cin >> n;

	for (int i = 0; i < 4; i++) {
		cin >> chance[i];

		chance[i] *= 0.01;
	}
}

void func(int cnt, int x, int y, double probability) { // 이동횟수, 좌표, 확률
	// 단순한 확률일 경우
	if (cnt == n) {
		result += probability;

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (!visit[nextX][nextY]) {
			visit[nextX][nextY] = true;
			func(cnt + 1, nextX, nextY, probability * chance[i]);
			visit[nextX][nextY] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	// 시작 지점 (14, 14)
	visit[14][14] = true;

	func(0, 14, 14, 1.0);

	//cout << result;
	cout << fixed;
	cout << setprecision(10) << result << "\n";

	return 0;
}
