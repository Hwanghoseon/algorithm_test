#include<iostream>
#include<queue>

using namespace std;

int n, k;

void func() {
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int cnt = 0;

	cout << "<";
	while (!q.empty()) {
		cnt++;

		if (cnt % k) {
			int temp = q.front();

			q.pop();
			q.push(temp);
		}
		else {
			cout << q.front();
			q.pop();

			if (!q.empty()) cout << ", ";
			else cout << ">";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	func();

	return 0;
}
