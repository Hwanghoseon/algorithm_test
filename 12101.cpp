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

int N, K, cnt = 0;
vector<int> list;

void printNum() {
	for (int i = 0; i < list.size() - 1; i++)
		cout << list[i] << "+";
	cout << list[list.size() - 1];

	exit(0);
}

void bf(int sum) {
	if (sum == N) {
		cnt++;

		if (cnt == K) {
			printNum();
		}

		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum + i <= N) {
			list.push_back(i);
			bf(sum + i);
			list.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	bf(0);

	if (cnt < K) cout << "-1";

	return 0;
}
