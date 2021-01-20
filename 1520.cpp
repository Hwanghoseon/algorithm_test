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

const int MAX = 500;

int N, M;
int board[MAX][MAX];
int cache[MAX][MAX];

void input() {
	cin >> M >> N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	memset(cache, -1, sizeof(cache));
}

int search(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return 1;

	int &result = cache[x][y];

	if (result != -1) return result;

	result = 0;

	// 위
	if (x - 1 >= 0 && board[x][y] > board[x - 1][y])
		result += search(x - 1, y);

	// 아래
	if (x + 1 < M && board[x][y] > board[x + 1][y])
		result += search(x + 1, y);

	// 왼쪽
	if (y - 1 >= 0 && board[x][y] > board[x][y - 1])
		result += search(x, y - 1);

	//오른쪽
	if (y + 1 < N && board[x][y] > board[x][y + 1])
		result += search(x, y + 1);

	return result;

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << search(0, 0);

	return 0;
}
