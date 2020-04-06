#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

const int MAX = 100 + 1;

int dp[MAX];

void func(int x) {
	for (int i = 1; i <= MAX; i++) {
		int compare1 = pow(i, 2);
		int compare2 = pow(i + 1, 2);

		if (compare1 <= x && compare2 > x) {
			cout << i << "\n";
			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		func(n);
	}

	return 0;
}
