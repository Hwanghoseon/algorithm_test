#include<iostream>
#include<string>

using namespace std;

const int MAX = 64 + 1;

int n;

int map[MAX][MAX];
int result[2];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string input;
		cin >> input;

		for (int j = 1; j <= n; j++)
			map[i][j] = input[j - 1] - '0';
	}
}

void func(int startX, int startY, int len) {
	int before = map[startX][startY];
	bool isEqual = true;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (before != map[startX + i][startY + j]) {
				isEqual = false;
				break;
			}
		}

		if (!isEqual) break;
	}

	if (!isEqual) {
		cout << "(";

		for (int i = 0; i < len; i += len / 2)
			for (int j = 0; j < len; j += len / 2)
				func(startX + i, startY + j, len / 2);

		cout << ")";
	}
	else
		cout << before;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(1, 1, n);

	return 0;
}
