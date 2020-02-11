#include<iostream>
#include<vector>

using namespace std;

int k;
vector<pair<int, int>> v;

void fac(int num, int from, int by, int to) {
	if (num == 1)
		v.push_back(make_pair(from, to));
	else {
		fac(num - 1, from, to, by);
		v.push_back(make_pair(from, to));
		fac(num - 1, by, from, to);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	fac(k, 1, 2, 3);

	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}
