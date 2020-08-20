#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n;
vector<pair<pair<int, int>, string>> list;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		string name;
		
		cin >> num >> name;

		list.push_back(make_pair(make_pair(num, i), name));
	}

	sort(list.begin(), list.end());
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 0; i < n; i++)
		cout << list[i].first.first << " " << list[i].second << "\n";

	return 0;
}
