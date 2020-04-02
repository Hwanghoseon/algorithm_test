#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1000;

int n, m;
int map[MAX][MAX];
int cache[MAX][MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int maxCandy(int x, int y) {
	int &result = cache[x][y];

	if (result != -1)
		return result;

	result = map[x][y];

	int temp;
	// (r + 1, c)
	if (y + 1 < m) {
		temp = map[x][y] + maxCandy(x, y + 1);

		result = max(result, temp);
	}
	// (r, c + 1)
	if (x + 1 < n) {
		temp = map[x][y] + maxCandy(x + 1, y);

		result = max(result, temp);
	}
	// (r + 1, c + 1)
	if (x + 1 < n && y + 1 < m) {
		temp = map[x][y] + maxCandy(x + 1, y + 1);

		result = max(result, temp);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	cout << maxCandy(0, 0);

	return 0;
}
