#include<iostream>

using namespace std;

const int MAX = 40;

int n, m, k;
int r, c;
int paper[10][10];
int note[40][40];

bool check(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (paper[i][j] && note[x + i][y + j])
				return false;
		}
	}

	return true;
}

void printNote(int x, int y) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (paper[i][j])
				note[x + i][y + j] = 1;
}

void rotate() {
	int temp[10][10];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			temp[i][j] = paper[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			paper[i][j] = temp[r - 1 - j][i];

	swap(r, c);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	while (k--) {
		cin >> r >> c;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> paper[i][j];

		for (int rot = 0; rot < 4; rot++) {
			bool flag = false;
			
			for (int i = 0; i <= n - r; i++) {
				if (flag) break;
				for (int j = 0; j <= m - c; j++) {
					if (check(i, j)) {
						flag = true;
						printNote(i, j);
						break;
					}

				}
			}

			if (flag) break;
			rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += note[i][j];

	cout << cnt;

	return 0;
}
