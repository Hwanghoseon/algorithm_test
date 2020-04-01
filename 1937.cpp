#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 500 + 1;

int n;
int map[MAX][MAX];
int cache[MAX][MAX];

void input() {
	cin >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
}

int maxDay(int x, int y) {
	int &result = cache[x][y];

	if (result != -1)
		return result;

	result = 1;	// 첫날

	int temp;
	// 북
	if (x - 1 >= 0 && map[x - 1][y] > map[x][y]) {
		temp = 1 + maxDay(x - 1, y);

		result = max(result, temp);
	}
	// 남
	if (x + 1 < n && map[x + 1][y] > map[x][y]) {
		temp = 1 + maxDay(x + 1, y);

		result = max(result, temp);
	}
	// 서
	if (y - 1 >= 0 && map[x][y - 1] > map[x][y]) {
		temp = 1 + maxDay(x, y - 1);

		result = max(result, temp);
	}
	// 동
	if (y + 1 < n && map[x][y + 1] > map[x][y]) {
		temp = 1 + maxDay(x, y + 1);

		result = max(result, temp);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = maxDay(i, j);

			result = max(result, temp);
		}
	}

	cout << result;

	return 0;
}
