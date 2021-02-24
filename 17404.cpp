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

const int MAX = 1e3 + 1;
const int INT = 1e7;

int N;
int list[MAX][3];
int result[2][3];
int costMin = INT_MAX;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> list[i][j];
}

int func() {
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++)
			result[0][i] = list[0][k];

		for (int i = 1; i < N; i++) {
			result[1][0] = min(result[0][1] + list[i][0], result[0][2] + list[i][0]);
			result[1][1] = min(result[0][0] + list[i][1], result[0][2] + list[i][1]);
			result[1][2] = min(result[0][0] + list[i][2], result[0][1] + list[i][2]);

			if (i == 1 || i == N - 1)
				result[1][k] = INT;

			for (int i = 0; i < 3; i++)
				result[0][i] = result[1][i];
		}

		for (int i = 0; i < 3; i++)
			costMin = min(costMin, result[0][i]);
	}

	return costMin;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << func();

	return 0;
}
