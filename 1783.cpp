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

int N, M;

int solution() {
	int ans;

	if (N == 1)	ans = 1;
	else if (N < 3) {
		ans = (M + 1) / 2;

		if (ans >= 4) ans = 4;
	}
	else if (M <= 4)
		ans = M;
	else if (M < 7)
		ans = 4;
	else
		ans = M - 2;

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	cout << solution();

	return 0;
}
