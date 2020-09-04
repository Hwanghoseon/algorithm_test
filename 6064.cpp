#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int maxCnt = lcm(M, N);

		while(true) {
			if (x > maxCnt || (x - 1) % N + 1 == y)
				break;

			x += M;
		}

		if (x > maxCnt) cout << "-1\n";
		else cout << x << "\n";
	}

	return 0;
}
