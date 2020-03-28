#include<iostream>
#include<string>

using namespace std;

const int MAX = 50;

int n;
string st[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> st[i];
}

void compare() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < st[0].size(); j++) {
			if (st[i][j] != st[i + 1][j])
				st[i + 1][j] = '?';
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	compare();

	for (int i = 0; i < st[0].size(); i++)
		cout << st[n - 1][i];

	return 0;
}
