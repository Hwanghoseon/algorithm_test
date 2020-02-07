#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 8 + 1;

vector<int> arr;
vector<int> list;
bool visit[MAX];
int n, m;

void func(int cnt, int min) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";

		return;
	}

	for (int i = min; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = list[i];
			func(cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}

void init() {
	arr.resize(n);
	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	init();

	func(0, 0);
	
	return 0;
}
