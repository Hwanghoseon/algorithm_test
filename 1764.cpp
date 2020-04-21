#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> name;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		name[s] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (name.find(s) == name.end()) {}
		else {
			name[s] = 2;
			cnt++;
		}
	}

	cout << cnt << "\n";
	for (auto it = name.begin(); it != name.end(); it++)
		if (it->second == 2)
			cout << it->first << "\n";

	return 0;
}
