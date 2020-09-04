#include<iostream>

using namespace std;

const int MAX = 128 + 1;

int paper[MAX][MAX];
int n;
int result[2];	// white, blue

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];
}

void func(int x, int y, int len) {	// 좌측 상단의 좌표, 사각형의 길이
	int before = paper[x][y];
	bool check = true;	// 일치한 정사각형 여부 확인

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (paper[x+ i][y + j] != before) {
				check = false;
				break;
			}
		}
		if (!check) break;
	}

	if (check) result[before]++;
	else {
		func(x, y, len / 2);
		func(x, y + len / 2, len / 2);
		func(x + len / 2, y, len / 2);
		func(x + len / 2, y + len / 2, len / 2);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(1, 1, n);

	cout << result[0] << "\n" << result[1];

	return 0;
}
