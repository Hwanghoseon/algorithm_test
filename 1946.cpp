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



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		int N;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;

			pq.push({ a, b });
		}

		int before = pq.top().second;
		pq.pop();

		int cnt = 1;
		
		while (!pq.empty()) {
			int cur = pq.top().second;
			pq.pop();

			if (before > cur) {
				cnt++;

				before = cur;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
