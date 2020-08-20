#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<pair<int, int>> list;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		list.push_back(make_pair(y, x));
	}

	sort(list.begin(), list.end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < n; i++)
		cout << list[i].second << " " << list[i].first << "\n";

	return 0;
}
