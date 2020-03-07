#include<iostream>
#include<vector>

using namespace std;

const int MAX = 15 + 1;

vector<int> list;
int n;
int maxCnt = 0;

bool check(int x) {
	bool flag = true;
	int i = 1;

	while (i < x && flag) {
		if (list[i] == list[x] || abs(list[x] - list[i]) == x - i)
			flag = false;
		i++;
	}
	return flag;
}

void func(int cnt) {
	if (check(cnt)) {
		if (cnt == n) {
			maxCnt++;

			return;
		}

		for (int i = 1; i <= n; i++) {
			list[cnt + 1] = i;
			func(cnt + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	list.resize(MAX);

	func(0);

	cout << maxCnt;

	return 0;
}
