#include<iostream>
#include<cmath>

using namespace std;

const int check = 125;

int gcd(int a, int b) {
	int c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!(i % 5)) {
			int temp = gcd(i, check);

			while (temp != 1) {
				temp /= 5;

				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}
