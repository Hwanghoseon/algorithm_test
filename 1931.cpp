#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100000;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> list;	// 끝나는 시간, 시작시간

	int n;
	cin >> n;

	list.resize(n);

	for (int i = 0; i < n; i++)
		cin >> list[i].second >> list[i].first;

	sort(list.begin(), list.end());

	int cnt = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].second < start) continue;

		start = list[i].first;
		cnt++;
	}

	cout << cnt;

	return 0;
}
