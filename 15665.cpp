#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 7;

vector<int> list;
vector<int> arr;
int n, m;

void init() {
	cin >> n >> m;

	list.resize(n);
	arr.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	int before = -1;
	for (int i = 0; i < n; i++) {
		if (i == 0 || before != list[i]) {
			before = list[i];
			arr[cnt] = list[i];
			func(cnt + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	func(0);

	return 0;
}
