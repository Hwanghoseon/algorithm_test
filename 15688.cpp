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
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		pq.push(temp);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	while (!pq.empty()) {
		cout << pq.top() << "\n";

		pq.pop();
	}

	return 0;
}
