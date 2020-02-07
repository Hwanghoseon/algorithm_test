#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1000000 + 1;

int Dp[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	Dp[1] = 0;

	for (int i = 2; i <= num; i++) {
		Dp[i] = Dp[i - 1] + 1;

		if (i % 2 == 0)
			Dp[i] = min(Dp[i], Dp[i / 2] + 1);
		if (i % 3 == 0)
			Dp[i] = min(Dp[i], Dp[i / 3] + 1);
	}

	cout << Dp[num];

	return 0;
}
