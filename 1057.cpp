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

int N, a, b;

int solution() {
	cin >> N >> a >> b;

	int cnt = 1;

	while (N > 1) {
		if (N % 2 == 1) N++;
		if (a % 2 == 1) a++;
		if (b % 2 == 1) b++;

		if (a == b) break;

		a /= 2;
		b /= 2;

		cnt++;
		N /= 2;
	}

	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();

	return 0;
}
