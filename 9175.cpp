#include<iostream>
#include<string>
#include<map>

using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> n;

		map<string, int> clothes;

		for (int i = 0; i < n; i++) {
			string temp, type;
			cin >> temp >> type;

			clothes[type]++;
		}

		int result = 1;

		map<string, int>::iterator it;

		for (it = clothes.begin(); it != clothes.end(); it++)
			result *= (it->second + 1);

		cout << result - 1 << "\n";
	}

	return 0;
}
