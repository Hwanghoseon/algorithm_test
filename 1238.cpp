#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1000 + 1;

int N, M, X;
int town[MAX][MAX];

void input() {
	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {
		fill(town[i], town[i] + N + 1, 100000);

		town[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int from, to, value;
		cin >> from >> to >> value;

		town[from][to] = value;
	}
}

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (town[i][j] > town[i][k] + town[k][j])
					town[i][j] = town[i][k] + town[k][j];
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++)
		result = max(result, town[i][X] + town[X][i]);

	cout << result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	return 0;
}
