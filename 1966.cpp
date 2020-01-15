#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int count = 0;
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> p;
		
		int ipt;
		for (int i = 0; i < n; i++) {
			cin >> ipt;
			p.push(ipt);
			q.push({ i, ipt });
		}

		while (!p.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();

			if (value == p.top()) {
				p.pop();
				count++;
				if (index == m) {
					cout << count << endl;
					break;
				}
			}
			else q.push({ index, value });
		}
	}

	return 0;
}
