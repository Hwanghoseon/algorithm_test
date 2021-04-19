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

const int MAX = 500;

int N, M, B;
int board[MAX][MAX];
int land[MAX];
int low = MAX;
int high = 0;
pair<int, int> result = { INT_MAX, 0 };	// sec, high

void input() {
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			land[board[i][j]]++;

			low = min(low, board[i][j]);
			high = max(high, board[i][j]);
		}
}

void func() {
	for (int k = low; k <= high; k++) {
		int sec = 0;
		int cnt = 0;	// 사용된 블록 갯수
		int block = B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] > k) {
					sec += (abs(board[i][j] - k) * 2);

					block += (abs(board[i][j] - k));
				}
				else {
					cnt += (abs(board[i][j] - k));

					sec += (abs(board[i][j] - k));
				}
			}
		}

		if (cnt > block) continue;

		if (sec < result.first) result = { sec, k };
		else if (sec == result.first) {
			if (k > result.second)
				result = { sec, k };
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << result.first << " " << result.second;

	return 0;
}
