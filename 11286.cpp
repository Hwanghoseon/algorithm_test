#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 절댓값 x, x

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num)
			pq.push(make_pair(abs(num), num));
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top().second << "\n";

				pq.pop();
			}
		}
	}

	return 0;
}
