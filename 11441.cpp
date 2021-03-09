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

const int MAX = 1e5 + 1;

int N;
vector<int> list;

void input() {
	cin >> N;

	list.resize(N + 1);

	int sum = 0;
	int temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;

		sum += temp;

		list[i] = sum;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	int K;
	cin >> K;

	while (K--) {
		int from, to;
		cin >> from >> to;

		cout << list[to] - list[from - 1] << "\n";
	}

	return 0;
}
