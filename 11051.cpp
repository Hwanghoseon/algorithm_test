#include<iostream>

using namespace std;

const int MAX = 1000 + 1;
const int MOD = 10007;

int n, k;
int list[MAX][MAX];

int func() {
	for (int i = 1; i <= n; i++) {
		list[i][1] = i;
		list[i][0] = list[i][i] = 1;
	}

	for (int i = 3; i <= n; i++)
		for (int j = 2; j < i; j++)
			list[i][j] = (list[i - 1][j - 1] + list[i - 1][j]) % MOD;

	return list[n][k] % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cout << func();

	return 0;
}
