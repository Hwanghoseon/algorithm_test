#include<iostream>

using namespace std;

const int MAX = 3 * 3 * 3 * 3 * 3 * 3 * 3 + 1;

int n;
int paper[MAX][MAX];
int result[3];	// -1, 0, 1

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];
}

void func(int startX, int startY, int len) {
	int before = -2;
	bool isEqual = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (before == -2) {
				before = paper[startX][startY];
				continue;
			}
			if (before != paper[startX + i][startY + j]) {
				isEqual = false;
				break;
			}
		}
		if (!isEqual) break;
	}

	if (!isEqual) {
		for (int i = 0; i < len; i += len / 3)
			for (int j = 0; j < len; j += len / 3)
				func(startX + i, startY + j, len / 3);
	}
	else
		result[before + 1]++;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(1, 1, n);

	for (int i = 0; i < 3; i++)
		cout << result[i] << "\n";

	return 0;
}
