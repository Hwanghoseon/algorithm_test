#include<iostream>

using namespace std;

const int MAX = 1024 + 1;

int N, M;
int list[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int sum = 0;

		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;

			sum += temp;

			list[i][j] = sum;
		}
	}

	while (M--) {
		int startX, startY, endX, endY;
		cin >> startX >> startY >> endX >> endY;

		int result = 0;
		for (int i = startX; i <= endX; i++) {
			result += (list[i][endY] - list[i][startY - 1]);
		}

		cout << result << "\n";
	}

	return 0;
}
