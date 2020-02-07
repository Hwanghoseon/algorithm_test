#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 8 + 1;

vector<int> arr;
vector<int> list;
bool visit[MAX];
int n, m;

void func(int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m; i++)
			cout << list[i] << " ";
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			list[cnt] = arr[i];
			func(cnt + 1);
			visit[i] = false;
		}
	}
}

void input() {
	arr.resize(n);
	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	input();

	func(0);

	return 0;
}
