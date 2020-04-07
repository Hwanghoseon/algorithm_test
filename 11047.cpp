#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int coin[10];

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= k) {
			int temp = k / coin[i];
			cnt += temp;
			k -= temp * coin[i];
		}
	}

	cout << cnt;

	return 0;
}
