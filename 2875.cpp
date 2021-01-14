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

int W, M, K;

void solution() {
	int cnt = 0;	// 대회 불참하는 인원의 수

	// 여학생의 수가 홀수인 경우
	if (W % 2) {
		W--;
		cnt++;
	}

	if (W > 2 * M)
		cnt += (W - 2 * M);
	else if (W < 2 * M) {
		cnt += (M - W / 2);

		M = W / 2;
	}

	while (cnt < K) {
		M--;
		cnt += 3;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> W >> M >> K;

	solution();

	cout << M;

	return 0;
}
