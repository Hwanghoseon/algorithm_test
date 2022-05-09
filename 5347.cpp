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
#include<climits>

using namespace std;

long long N, M;

long long gcd(long long a, long long b) {
	long long c;

	while (b) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N >> M;

		cout << lcm(N, M) << "\n";
	}

	return 0;
}
