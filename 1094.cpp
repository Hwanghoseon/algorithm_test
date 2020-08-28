#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 64;

	int X;
	cin >> X;

	int cnt = 0;
	while (n) {
		if (X >= n) {
			X -= n;
			cnt++;
		}

		n /= 2;
	}

	cout << cnt;

	return 0;
}
