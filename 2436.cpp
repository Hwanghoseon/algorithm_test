#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

const int MAX = 1e9;

int N, M;
pair<int, int> result = { 1, MAX };

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void func(int n) {
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int x = i;
			int y = n / i;

			if (gcd(x * N, y * N) != N) continue;

			if (abs(x - y) < result.second - result.first) {
				if (x < y)
					result = { x, y };
				else
					result = { y, x };
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int num = M / N;

	func(num);

	cout << result.first * N << " " << result.second * N;

	return 0;
}
