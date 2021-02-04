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

const int MAX = 20 * 100000 + 1;

int N;
vector<int> list;
bool arr[MAX];
bool visited[20];

void input() {
	cin >> N;

	list.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> list[i];

		arr[list[i]] = true;
	}
}

void func(int cnt, int listSize, int sum, int min) {
	if (cnt == listSize) {
		arr[sum] = true;

		return;
	}

	for (int i = min; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(cnt + 1, listSize, sum + list[i], i + 1);
			visited[i] = false;
		}
	}
}

int minOutput() {
	for (int i = 1; i < MAX; i++) {
		if (!arr[i])
			return i;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 1; i <= N; i++)
		func(0, i, 0, 0);

	cout << minOutput();

	return 0;
}
