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
#include<climits>

using namespace std;

const int MAX = 50;

int N, M;
char board[MAX][MAX];

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
}

int solution() {
	int len = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int k = len; ; k++)
				if (i + k < N && j + k < M) {
					if (board[i][j] == board[i][j + k] && board[i][j] == board[i + k][j] && board[i][j] == board[i + k][j + k])
						len = k;
				}
				else break;

	len++;

	return len * len;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();

	return 0;
}
