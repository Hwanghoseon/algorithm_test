#include<iostream>
#include<vector>

using namespace std;

const int MAX = 7 + 1;

vector<int> arr;
bool visit[MAX];
int n, m;

void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[cnt] = i;
		func(cnt + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	arr.resize(n);

	func(0);

	return 0;
}
