#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 100;

int map[MAX][MAX];
long long cache[MAX][MAX];
int n;
int cnt = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

long long func(int x, int y) {
	if (x == n - 1 && y == n - 1)
		return 1;

	long long &result = cache[x][y];

	if (result != -1)
		return result;

	result = 0;

	// 오른쪽으로 이동할 경우
	if (map[x][y] + y < n)
		result += func(x, y + map[x][y]);

	// 아래쪽으로 이동할 경우
	if (map[x][y] + x < n)
		result += func(x + map[x][y], y);
	
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	memset(cache, -1, sizeof(cache));

	cout << func(0, 0);

	return 0;
}
