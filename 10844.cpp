#include<iostream>

using namespace std;

const int MOD = 1000000000;

int list[101][10];
int num;

void Dp() {
	for (int i = 0; i < 10; i++)
		list[1][i] = 1;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				list[i][j] = list[i - 1][j + 1] % MOD;
			else if (j == 9)
				list[i][j] = list[i - 1][j - 1] % MOD;
			else
				list[i][j] = (list[i - 1][j - 1] + list[i - 1][j + 1]) % MOD;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num;

	Dp();

	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum = (sum + list[num][i]) % MOD;

	cout << sum;

	return 0;
}
