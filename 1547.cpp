#include<iostream>
#include<queue>

using namespace std;

int cup[3] = { 1, 2, 3 };
int temp[3];
int n;
queue<pair<int, int>> q;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tempX, tempY;
		cin >> tempX >> tempY;

		q.push(make_pair(tempX, tempY));
	}
}

void func() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 3; i++) {
			if (cup[i] == x)
				cup[i] = y;
			else if (cup[i] == y)
				cup[i] = x;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	func();

	cout << cup[0];

	return 0;
}
