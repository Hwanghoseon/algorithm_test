#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 8;

vector<int> list;
vector<int> arr;
bool visit[MAX];
int n, m;

void init() {
	cin >> n >> m;

	arr.resize(n);
	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

void func(int cnt, int min) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	int before = -1;
	for (int i = min; i < n; i++) {
		if (!visit[i] && (i == 0 || before != list[i])) {
			visit[i] = true;
			before = list[i];
			arr[cnt] = list[i];
			func(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	func(0, 0);

	return 0;
}
