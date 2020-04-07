#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c, d;

	cin >> a >> b >> c >> d;

	long long bLen;
	long long dLen;

	long long len = 1;
	for (long long i = 1; ; i++) {
		len *= 10;

		if (b / len == 0) {
			bLen = len;
			break;
		}
	}

	len = 1;
	for (long long i = 1; ; i++) {
		len *= 10;

		if (d / len == 0) {
			dLen = len;
			break;
		}
	}

	long long result = (a * bLen) + b + (c * dLen) + d;

	cout << result;

	return 0;
}
