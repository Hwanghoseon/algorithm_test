#include<iostream>
#include<cmath>

using namespace std;

int N, c, r;
int len;

int func(int x, int y, int n) {
	if (n == 2) {
		if (x == 0 && y == 0) return 0;
		else if (x == 0 && y == 1) return 1;
		else if (x == 1 && y == 0) return 2;
		else if (x == 1 && y == 1) return 3;
	}
	else {
		// (-, +)
		if (x < n / 2 && y < n / 2)
			return func(x, y, n / 2);
		// (+, +)
		else if (x < n / 2 && y >= n / 2)
			return n / 2 * n / 2 + func(x, y - n / 2, n / 2);
		// (-, -)
		else if (x >= n / 2 && y < n / 2)
			return n / 2 * n / 2 * 2 + func(x - n / 2, y, n / 2);
		// (+, -)
		else if (x >= n / 2 && y >= n / 2)
			return n / 2 * n / 2 * 3 + func(x - n / 2, y - n / 2, n / 2);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> c >> r;

	len = pow(2, N);

	cout << func(c, r, len);

	return 0;
}
