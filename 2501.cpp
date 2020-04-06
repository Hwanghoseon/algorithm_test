#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10000;

int func(int x, int y) {
	int cnt = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0)
			cnt++;

		if (cnt == y)
			return i;
	}

	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << func(n, k);

	return 0;
}
