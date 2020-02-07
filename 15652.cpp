#include<iostream>
#include<vector>

using namespace std;

const int MAX = 8 + 1;

vector<int> arr;
int n, m;

void func(int cnt, int min) {
	if (m == cnt) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = min; i <= n; i++) {
		arr[cnt] = i;
		func(cnt + 1, i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	arr.resize(n);

	func(0, 1);

	return 0;
}
