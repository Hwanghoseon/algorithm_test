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

const int MAX = 10;

int N, K;
vector<string> card;
set<string> list;
bool visited[MAX];

void input() {
	cin >> N >> K;

	card.resize(N);

	for (int i = 0; i < N; i++)
		cin >> card[i];
}

void func(int cnt, string st, int target) {
	if (cnt == K) {
		list.insert(st);

		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			func(cnt + 1, st + card[i], K);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func(0, "", K);

	cout << list.size();

	return 0;
}
