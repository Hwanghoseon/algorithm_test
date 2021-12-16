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

long long solution(int N) {
	long long ans = 0;

	for (int i = 1; i <= N; i++) {
		int temp = N / i;

		ans += (temp * i);
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	cout << solution(N);

	return 0;
}
