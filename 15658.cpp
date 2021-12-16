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

int N;
int op[4];	// +, -, *, /
char arr[4] = { '+', '-', '*', '/' };
int list[100];
int maxNum = INT_MIN;
int minNum = INT_MAX;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> list[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];
}

int calculation(int op, int sum, int N) {
	if (op == 0)
		return sum + list[N];
	else if (op == 1)
		return sum - list[N];
	else if (op == 2)
		return sum * list[N];
	return sum / list[N];
}

void bt(int cnt, int sum) {
	if (cnt == N) {
		maxNum = max(maxNum, sum);
		minNum = min(minNum, sum);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			bt(cnt + 1, calculation(i, sum, cnt));
			op[i]++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	bt(1, list[0]);

	cout << maxNum << "\n" << minNum;

	return 0;
}
