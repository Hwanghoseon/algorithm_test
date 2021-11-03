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

const int MAX = 20000 + 1;

int N;

int func() {
	long long ans = 1;

	for (int i = 1; i <= N; i++) {
		ans *= i;

		while (ans % 10 == 0) ans /= 10;

		ans %= 10000000;
	}

	ans %= 10;

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << func();

	return 0;
}
